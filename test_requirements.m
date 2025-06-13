% ✨ Verificação de Requisitos com Simulação em Tempo Contínuo
clc; clear; close all;

% 1. Executa o script do projeto anterior (ajuste o nome se necessário)
run('controlador_cal.m');  % <- troque pelo nome real do seu script, se diferente

% 2. Sample & Hold do controlador digital
Gc_sh = d2c(Gc, 'zoh');  % Conversão ZOH

% 3. Sistema em malha fechada no contínuo
sys_total_cont = feedback(Gc_sh * G_s, 1)

% 4. Simulação no tempo contínuo
t_cont = 0:1e-4:2;
u_step = ones(size(t_cont));
[y_cont, t_out] = lsim(sys_total_cont, u_step, t_cont);

% 5. Gráfico da resposta ao degrau
figure;
plot(t_out, y_cont, 'b', 'LineWidth', 1.5); grid on;
xlabel('Tempo (s)');
ylabel('Saída');
title('Resposta ao Degrau - Sistema Contínuo com Controlador Digital');

% --- 6. Análise de desempenho ---
y_final = y_cont(end);
[y_peak, idx_peak] = max(y_cont);
Mp_calc = (y_peak - y_final) / y_final * 100;
tp_calc = t_out(idx_peak);

% Detecta oscilação
[~, locs_pks] = findpeaks(y_cont, t_out, 'MinPeakProminence', 0.005);
oscillatory = numel(locs_pks) >= 2;

if oscillatory
    T_osc = locs_pks(2) - locs_pks(1);
    wd_calc = 2*pi / T_osc;
    N_calc = round((2*pi) / (T * wd_calc));
else
    wd_calc = NaN;
    N_calc = NaN;
end

% --- 7. Gráfico no plano-s ---
poles_sys = pole(sys_total_cont);

figure;
plot(real(poles_sys), imag(poles_sys), 'bo', 'MarkerSize', 10, 'LineWidth', 2); hold on;
plot(real(s_d), imag(s_d), 'rx', 'MarkerSize', 10, 'LineWidth', 2);
plot(real(conj(s_d)), imag(conj(s_d)), 'rx', 'MarkerSize', 10, 'LineWidth', 2);
xline(0, '--k'); yline(0, '--k'); grid on;
xlabel('Parte Real'); ylabel('Parte Imaginária');
title('Plano-s: Polos do Sistema vs Polos Desejados');
legend('Polos do Sistema', 'Polos Desejados');

% --- 8. Comparativo final ---
fprintf('\n--- VERIFICAÇÃO DOS REQUISITOS ---\n');
fprintf('> Tempo de amostragem usado (T): %.6f s\n', T);
fprintf('\n-- Requisitos de Projeto --\n');
fprintf('Sobressinal desejado: %.2f %%\n', Mp);
fprintf('Tempo de pico desejado: %.4f s\n', tp);
fprintf('Número de amostras por ciclo desejado: %d\n', N);
fprintf('Polos desejados (s): %.4f ± %.4fi\n', real(s_d), imag(s_d));

fprintf('\n-- Resultados Obtidos --\n');
fprintf('Sobressinal obtido: %.2f %%\n', Mp_calc);
fprintf('Tempo de pico obtido: %.4f s\n', tp_calc);
if oscillatory
    fprintf('Número estimado de amostras por ciclo: %d\n', N_calc);
    fprintf('Frequência angular estimada (wd): %.4f rad/s\n', wd_calc);
else
    fprintf('Sistema não apresentou resposta oscilatória\n');
end
fprintf('Polos reais do sistema (s):\n');
disp(poles_sys);
