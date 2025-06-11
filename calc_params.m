load('variaveis.mat')

% Extração dos dados
tempo = valores_w_medidos(:, 1);    % Tempo
w_medido = valores_w_medidos(:, 2); % Valores medidos

% Função de resposta teórica com parâmetros [b, a, L_var]
modelo = @(params, t) (4 * params(1) / params(2)) .* ...
                      (1 - exp(-params(2) * max(0, t - (0.5 + params(3)))));

% Vetor de tempo adaptado para funcionar no modelo vetorialmente
modelo_vect = @(params, t) arrayfun(@(ti) modelo(params, ti), t);

% Estimativas iniciais para os parâmetros [b, a, L_var]
params_iniciais = [4, 15, 0.02]; % chute inicial: b, a, L_var

% Ajuste com lsqcurvefit
opcoes = optimoptions('lsqcurvefit', 'Display', 'iter');
[param_otim, ~] = lsqcurvefit(modelo_vect, params_iniciais, tempo, w_medido, [], [], opcoes);

% Parâmetros ajustados
b_otim = param_otim(1);
a_otim = param_otim(2);
L_otim = param_otim(3);
L_total = 0.5 + L_otim;

% Resposta teórica com parâmetros ajustados
y_teorico_otim = modelo_vect(param_otim, tempo);

% Plotagem
figure;
plot(tempo, w_medido, 'b', 'LineWidth', 1.5); hold on;
plot(tempo, y_teorico_otim, 'r--', 'LineWidth', 2);
xlabel('Tempo (s)');
ylabel('Saída');
legend('Dados medidos', 'Resposta teórica (ajustada)');
title('Ajuste automático da resposta teórica');
grid on;

% Exibe parâmetros encontrados
fprintf('Parâmetros otimizados:\n');
fprintf('b       = %.4f\n', b_otim);
fprintf('a       = %.4f\n', a_otim);
fprintf('L_var   = %.4f\n', L_otim);
fprintf('L_total = %.4f s\n', L_total);
