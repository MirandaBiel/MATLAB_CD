load('variaveis.mat')

% Parâmetros do sistema
b = 4.479;
a = 15.873;
L = 0.5 + 0.019;

% Geração do vetor de tempo com base nos dados medidos
tempo = valores_w_medidos(:, 1);              % Supondo que a primeira coluna é o tempo
w_medido = valores_w_medidos(:, 2);           % Segunda coluna são os valores medidos

% Cálculo da resposta teórica
y_teorico = (4 * b / a) * (1 - exp(-a * (tempo - L))) .* (tempo >= L);

% Plotagem dos resultados
plot(tempo, w_medido, 'b', 'LineWidth', 1.5); hold on;
plot(tempo, y_teorico, 'r--', 'LineWidth', 2);
xlabel('Tempo (s)');
ylabel('Saída');
legend('Dados medidos', 'Resposta teórica');
title('Comparação entre valores medidos e resposta teórica do sistema');
grid on;
