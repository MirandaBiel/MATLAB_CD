clc; clear; close all;

% 1. Parâmetros fornecidos
a = 11.661;
b = 1.515;
Mp = 3.25;     % Sobressinal (%)
tp = 0.15;     % Tempo de pico (s)
N = 20;        % Número de amostras por ciclo

% 2. Cálculo de parâmetros do sistema de 2ª ordem
zeta = sqrt(log(Mp/100)^2 / (pi^2 + log(Mp/100)^2));
wn = pi / (tp * sqrt(1 - zeta^2));
wd = wn * sqrt(1 - zeta^2);
sigma = zeta * wn;

% 3. Cálculo do tempo de amostragem
T = 2*pi / (N * wd);

% 4. Polos desejados no plano z
s_d = -sigma + 1j*wd;
z_d = exp(s_d*T);         % Mapeamento s -> z
z_d_conj = conj(z_d);

% 5. Planta contínua e discretização
s = tf('s');
G_s = b / (s*(s+a));
G_z = c2d(G_s, T, 'zoh');

% 6. Coeficientes da planta G(z)
[numGz, denGz] = tfdata(G_z, 'v');
Gz = G_z;

% 7. Cancelamento de polo (usuário escolhe)
p1 = roots(denGz);   % Polos da planta em z
z1 = roots(numGz);   % Zeros da planta em z

fprintf('Polos da planta em z:\n');
for i = 1:length(p1)
    fprintf('Polo %d: %.4f + %.4fi\n', i, real(p1(i)), imag(p1(i)));
end

idx = input('Digite o número do polo que deseja cancelar (1 ou 2): ');
if idx < 1 || idx > length(p1)
    error('Polo inválido. Escolha um índice entre 1 e %d.', length(p1));
end
z_c = p1(idx);     % Zero do controlador cancela esse polo

% 8. Condição de fase: cálculo do polo do controlador
z = z_d;           % z_d é o polo desejado

% Calcula o ângulo da planta
theta_G = sum(angle(z - z1)) - sum(angle(z - p1))      

% Calcula o ângulo que o controlador deve possuir
theta_Gc = pi - theta_G        

% Calcula o ângulo do zero do controlador
theta_z_c = angle(z - z_c)       

% Soma dos ângulos dos polos e subtração do zero (cancelamento)
phi_required = theta_z_c - theta_Gc


% Cálculo do polo do controlador
imag_z = imag(z);
real_z = real(z);
theta_p = phi_required;
p_c = real_z - imag_z / tan(theta_p) % z - p_c forma o ângulo necessário

% 9. Condição de módulo: cálculo do ganho K
num_eval = abs(polyval(numGz, z) * (z - z_c));
den_eval = abs(polyval(denGz, z) * (z - p_c));
K = den_eval / num_eval;

% 10. Controlador digital Gc(z)
z_tf = tf('z', T);
Gc = K * (z_tf - z_c) / (z_tf - p_c);

% 11. Sistema em malha fechada
T_total = feedback(Gc*Gz, 1);

% 12. Simulações
t = 0:T:5;

% Degrau
figure;
step(T_total, t);
title('Resposta ao Degrau');

% Onda quadrada
u = square(2*pi*t);
[y, t_out] = lsim(T_total, u, t);
figure;
plot(t_out, y, 'b'); hold on;
plot(t_out, u, '--k');
title('Resposta à Onda Quadrada');
legend('Saída', 'Entrada');

% 13. LGR com marcação dos polos desejados
figure;
rlocus(Gc * Gz);
hold on;
plot(real(z_d), imag(z_d), 'rx', 'MarkerSize', 10, 'LineWidth', 2);
plot(real(z_d_conj), imag(z_d_conj), 'rx', 'MarkerSize', 10, 'LineWidth', 2);
title('Lugar das Raízes com Polos Desejados');
