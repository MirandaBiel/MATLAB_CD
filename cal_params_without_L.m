load('variaveis.mat')

% Extração dos dados
tempo = valores_w_medidos(:, 1);    % Tempo
w_medido = valores_w_medidos(:, 2); % Valores medidos

% Função de resposta teórica sem atraso (apenas [b, a])
modelo = @(params, t) (4 * params(1) / params(2)) .* ...
                      (1 - exp(-params(2) * max(0, t - 0.5))); % atraso fixo de 0.5 s

% Vetor de tempo adaptado para funcionar no modelo vetorialmente
modelo_vect = @(params, t) arrayfun(@(ti) modelo(params, ti), t);

% Estimativas iniciais para os parâmetros [b, a]
params_iniciais = [4, 15]; % chute inicial: b, a

% Ajuste com lsqcurvefit
opcoes = optimoptions('lsqcurvefit', 'Display', 'iter');
[param_otim, ~] = lsqcurvefit(modelo_vect, params_iniciais, tempo, w_medido, [], [], opcoes);

% Parâmetros ajustados
b_otim = param_otim(1);
a_otim = param_otim(2);

% Resposta teórica com parâmetros ajustados
y_teorico_otim = modelo_vect(param_otim, tempo);

% Plotagem
figure;
plot(tempo, w_medido, 'b', 'LineWidth', 1.5); hold on;
plot(tempo, y_teorico_otim, 'r--', 'LineWidth', 2);
xlabel('Tempo (s)');
ylabel('Saída');
legend('Dados medidos', 'Resposta teórica (ajustada)');
title('Ajuste da resposta teórica sem atraso variável');
grid on;

% Exibe parâmetros encontrados
fprintf('Parâmetros otimizados:\n');
fprintf('b       = %.4f\n', b_otim);
fprintf('a       = %.4f\n', a_otim);
