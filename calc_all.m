%% Parte 1 – Ajuste do modelo sem atraso variável
load('variaveis.mat')

% Extração dos dados
tempo = valores_w_medidos(:, 1);    % Tempo
w_medido = valores_w_medidos(:, 2); % Valores medidos

% Função de resposta teórica sem atraso variável (apenas [b, a])
modelo = @(params, t) (4 * params(1) / params(2)) .* ...
                      (1 - exp(-params(2) * max(0, t - 0.5)));

modelo_vect = @(params, t) arrayfun(@(ti) modelo(params, ti), t);

% Estimativas iniciais [b, a]
params_iniciais = [4, 15];

% Ajuste com lsqcurvefit
opcoes = optimoptions('lsqcurvefit', 'Display', 'iter');
[param_otim, ~] = lsqcurvefit(modelo_vect, params_iniciais, tempo, w_medido, [], [], opcoes);

% Parâmetros ajustados
b = param_otim(1);
a = param_otim(2);

% Resposta ajustada
y_teorico_otim = modelo_vect(param_otim, tempo);

% Plot do ajuste
figure;
plot(tempo, w_medido, 'b', 'LineWidth', 1.5); hold on;
plot(tempo, y_teorico_otim, 'r--', 'LineWidth', 2);
xlabel('Tempo (s)'); ylabel('Saída');
legend('Dados medidos', 'Resposta teórica (ajustada)');
title('Ajuste da resposta teórica sem atraso variável');
grid on;

fprintf('Parâmetros otimizados:\n');
fprintf('b = %.4f\n', b);
fprintf('a = %.4f\n', a);

%% Parte 2 – Projeto do controlador digital baseado em a e b ajustados

% 1. Parâmetros fornecidos
Mp = 4;       % Sobressinal (%)
tp = 0.25;    % Tempo de pico (s)
N = 20;       % Amostras por ciclo

% 2. Cálculo dos parâmetros do sistema de 2ª ordem
zeta = sqrt(log(Mp/100)^2 / (pi^2 + log(Mp/100)^2));
wn = pi / (tp * sqrt(1 - zeta^2));
wd = wn * sqrt(1 - zeta^2);
sigma = zeta * wn;

% 3. Tempo de amostragem
T = 2*pi / (N * wd);
st = T;

% 4. Polos desejados no plano z
s_d = -sigma + 1j*wd;
z_d = exp(s_d*T);
z_d_conj = conj(z_d);

% 5. Planta contínua e discretização
s = tf('s');
G_s = b / (s*(s+a));
G_z = c2d(G_s, T, 'zoh');

% 6. Coeficientes da planta G(z)
[numGz, denGz] = tfdata(G_z, 'v');
Gz = G_z;

% 7. Cancelamento de polo (usuário escolhe)
p1 = roots(denGz);   % Polos
z1 = roots(numGz);   % Zeros

fprintf('\nPolos da planta em z:\n');
for i = 1:length(p1)
    fprintf('Polo %d: %.4f + %.4fi\n', i, real(p1(i)), imag(p1(i)));
end

idx = input('Digite o número do polo que deseja cancelar (1 ou 2): ');
if idx < 1 || idx > length(p1)
    error('Polo inválido. Escolha um índice entre 1 e %d.', length(p1));
end
z_c = p1(idx);   % Zero do controlador

% 8. Cálculo do ângulo para atender condição de fase
z = z_d;

theta_G = sum(angle(z - z1)) - sum(angle(z - p1));
theta_Gc = pi - theta_G;
theta_z_c = angle(z - z_c);
phi_required = theta_z_c - theta_Gc;

% Cálculo do polo do controlador
imag_z = imag(z);
real_z = real(z);
theta_p = phi_required;
p_c = real_z - imag_z / tan(theta_p);

% 9. Cálculo do ganho K_control
num_eval = abs(polyval(numGz, z) * (z - z_c));
den_eval = abs(polyval(denGz, z) * (z - p_c));
K_control = den_eval / num_eval;

% 10. Controlador digital Gc(z)
z_tf = tf('z', T);
Gc = K_control * (z_tf - z_c) / (z_tf - p_c);

% 11. Sistema em malha fechada
T_total = feedback(Gc*Gz, 1);

% 12. Simulações
t = 0:T:2;

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

% 13. Lugar das raízes com polos desejados
figure;
rlocus(Gc * Gz);
hold on;
plot(real(z_d), imag(z_d), 'rx', 'MarkerSize', 10, 'LineWidth', 2);
plot(real(z_d_conj), imag(z_d_conj), 'rx', 'MarkerSize', 10, 'LineWidth', 2);
title('Lugar das Raízes com Polos Desejados');
