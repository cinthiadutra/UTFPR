Simulado P2
Condições de conclusão
Na tarde de ontem, os servidores de várias plataformas de estatísticas competitivas de CS:GO ficaram instáveis, causando falhas na atualização do ranking mundial de jogadores. Com isso, diversas equipes profissionais e sites de análise ficaram sem acesso aos dados mais recentes.

Você foi convocado para ajudar a reconstruir o sistema de rankings dos jogadores e gerar relatórios para os analistas responsáveis pela recuperação dos dados.

Para isso, o sistema central está recebendo informações sobre jogadores de diferentes regiões do mundo. Você deverá implementar um sistema para salvar e processar essas informações.

a) (5 pontos)
Aloque dinamicamente um vetor de Jogadores de tamanho 5. Cada Jogador é uma estrutura que contém:

País (string tam: 20)
Nick do jogador (string tam: 20)
Quantidade de vitórias (inteiro)
Quantidade de derrotas (inteiro)
Os países possíveis são: Brasil, EUA, França, Inglaterra, China e Japão.

b) (10 pontos)
Receba os dados de diversos jogadores e vá armazenando neste vetor.
A cada vez que o tamanho do vetor se tornar insuficiente, realoque seu tamanho aumentando o vetor em 5 unidades.

Ao receber o valor "fim" como entrada de um país, o sistema de entradas deverá parar e o tamanho do vetor deve ser ajustado exatamente à quantidade de jogadores cadastrados.

c) (5 pontos)
Salve os dados em um arquivo BINÁRIO chamado "players.dat".
Feche o arquivo e libere a memória utilizada pelo vetor.

d) (5 pontos)
Abra o arquivo gerado anteriormente e carregue os dados em um vetor de Jogadores alocado dinamicamente.

e) (5 pontos)
Calcule o total de vitórias e derrotas em cada país.
Exiba os dados na tela e gere um arquivo MODO TEXTO chamado "ranking_report.txt" no seguinte formato:

PAIS       |WINS |LOSSES| WINRATE|
Brasil     |   80|    30|     72%|
EUA        |  200|    50|     80%|
França     |   80|     5|     94%|
Inglaterra |  100|    12|     89%|
China      |  117|     3|     97%|
Japão      |   45|     5|     90%|
A taxa de vitória (WINRATE) deve ser calculada da seguinte forma:

WINRATE = (vitórias / (vitórias + derrotas)) * 100
Obs: Caso você tenha problemas com a alocação dinâmica, faça um vetor estático de tamanho 10 e prossiga no código. Você perderá os pontos dessa parte, mas continuará normalmente com a nota da parte de arquivos.

Dados de exemplo:

PAIS       |JOGADOR      |WINS|LOSSES|
EUA        |FallenX      | 100|     30|
Brasil     |AceBR        |  50|     20|
Inglaterra |SharpAim     |  70|      8|
Brasil     |SniperBR     |  20|      5|
Brasil     |RushMaster   |  10|      5|
Japão      |Kitsune      |  45|      5|
EUA        |FlashKing    |  25|      5|
EUA        |HeadHunter   |  50|     10|
França     |ParisShot    |  50|      4|
China      |DragonFPS    | 117|      3|
França     |NicoAim      |  30|      1|
Inglaterra |UKLegend     |  30|      4|
EUA        |SmokePlayer  |  25|      5|
Extra)
Faça o arquivo .h referente ao seu programa e utilize a técnica de Include Guard.