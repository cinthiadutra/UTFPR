Simulado 2026
Condições de conclusão
Exercício – Sistema de Ranking de CS:GO
Você foi contratado para desenvolver partes do sistema de ranking de jogadores de CS:GO. Implemente as etapas abaixo em linguagem C.

a) Definição de tipos
Crie um tipo enumerado (enum) para representar as patentes dos jogadores:

1 - Ferro
2 - Bronze
3 - Prata
4 - Ouro
5 - Diamante
6 - Imortal

Declare uma struct para armazenar os dados de um jogador com os campos:
nome (string)
vitórias (int)
derrotas (int)
patente (enum)
pontos (int)

b) Entrada de dados
Implemente uma função que leia do teclado os dados de 6 jogadores e os armazene em um vetor.
Regras:

Não aceitar valores negativos para vitórias, derrotas ou pontos.
Se um valor inválido for digitado, solicitar a entrada novamente até que seja válido.

c) Cálculo do Winrate (tabela)
Crie uma função que exiba uma tabela alinhada com o nome e a taxa de vitórias (winrate) de cada jogador. Use a fórmula:

winrate = (vitórias / (vitórias + derrotas)) * 100.0

Implemente uma função auxiliar que receba vitórias e derrotas (por valor) e retorne o winrate. Chame essa função uma vez por jogador.

d) Jogador líder por patente
Implemente uma função que receba um número de 1 a 6 (patente) e retorne a estrutura do jogador líder daquela patente (o jogador com mais pontos naquela patente). Na main, solicite ao usuário a patente desejada e exiba os dados do líder.

e) Busca por nome
Implemente uma função que busque um jogador pelo nome digitado. A função deve retornar, por referência, os seguintes valores do jogador encontrado:

número de vitórias
número de derrotas
A exibição final desses dados deve ser feita na main(), usando os valores retornados pela função de busca.

f) Soma recursiva de partidas
Implemente uma função recursiva que calcule a soma total de partidas disputadas por todos os jogadores (soma de vitórias + derrotas). Chame essa função na main() e exiba o resultado.

Observações importantes
Cada item de b a f deve ser implementado em uma função separada.
Não é permitido o uso de variáveis globais.
Utilize parâmetros adicionais onde necessário.
Exemplo de execução (entrada simulada)
Entrada (via teclado) — 6 jogadores:

Nome: s1mple     | Vitórias: 30 | Derrotas: 10 | Patente: 6 | Pontos: 2500
Nome: FalleN     | Vitórias: 25 | Derrotas: 15 | Patente: 6 | Pontos: 2300
Nome: coldzera   | Vitórias: 40 | Derrotas: 20 | Patente: 5 | Pontos: 1900
Nome: kennyS     | Vitórias: 18 | Derrotas: 22 | Patente: 4 | Pontos: 1200
Nome: ZywOo      | Vitórias: 10 | Derrotas: 5  | Patente: 3 | Pontos: 800
Nome: Gaules     | Vitórias: 5  | Derrotas: 15 | Patente: 1 | Pontos: 400


Saída esperada (exemplos)

Tabela com winrate (item c)

Nome    Winrate (%)
s1mple    75.00
FalleN    62.50
coldzera    66.67
kennyS    45.00
ZywOo    66.67
Gaules    25.00


Consulta: jogador líder por patente (item d)
Entrada: Patente = 6

Saída:
Jogador líder da patente Imortal:
Nome: s1mple
Vitórias: 30
Derrotas: 10
Pontos: 2500


Busca por nome (item e)
Entrada: nome = "FalleN"

Saída:
Dados encontrados:
Vitórias: 25
Derrotas: 15

Soma total de partidas (recursão) (item f)
Saída:
Total de partidas disputadas: 200
(Cálculo: 30+10 + 25+15 + 40+20 + 18+22 + 10+5 + 5+15 = 200)

Última atualização: quarta-feira, 30 set. 2026, 17:02