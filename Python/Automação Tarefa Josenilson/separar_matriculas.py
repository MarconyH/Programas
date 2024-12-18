import csv
from io import StringIO

def criar_csv(dados_str, nome_arquivo):
    # Converter a string para um objeto StringIO
    dados_io = StringIO(dados_str)

    # Nome das colunas
    colunas = ["Código", "Matrícula", "Nome", "CPF", "Data de Nascimento", "Idade"]

    # Ler os dados do StringIO usando csv.reader e converter para um formato adequado
    leitor_csv = csv.reader(dados_io, delimiter=' ')
    dados_lista = [linha for linha in leitor_csv if linha]

    # Ajustar a formatação dos dados
    for linha in dados_lista:
        # Combinar os campos do nome
        nome_completo = ' '.join(linha[2:])

        # Adicionar os campos ajustados
        linha[2:] = [nome_completo]

    # Adicionar as colunas aos dados
    dados_com_colunas = [colunas] + dados_lista

    # Escrever os dados no arquivo CSV
    with open(nome_arquivo, mode='w', newline='') as arquivo_csv:
        escritor_csv = csv.writer(arquivo_csv)
        escritor_csv.writerows(dados_com_colunas)

    print(f'O arquivo {nome_arquivo} foi criado com sucesso.')

# Exemplo de uso
dados_str = """
1 20232T.I.CAX0231 Adriel Mota Alves 638.159.963-41 26/10/2007 16 anos
2 20232T.I.CAX0209 Ana Alice dos Santos Marques 637.126.943-77 23/02/2008 15 anos, 8 meses
3 20232T.I.CAX0166 Ana Beatriz da Silva da Conceição 630.963.763-01 13/10/2007 16 anos, 1 mês
4 20232T.I.CAX0227 Ana Lais da Silva Ribeiro 633.327.483-60 11/04/2006 17 anos, 7 meses
5 20232T.I.CAX0175 Ana Paula da Silva Conceição 624.329.963-56 03/05/2007 16 anos, 6 meses
6 20232T.I.CAX0190 Andreia Suzanny do Nascimento
Oliveira Chaves 631.488.683-07 26/02/2008 15 anos, 8 meses
7 20232T.I.CAX0212 Antonio Alves da Luz Filho 623.664.803-42 13/02/2008 15 anos, 9 meses
8 20232T.I.CAX0013 Arthur Kevin de Sousa Diogo 624.599.343-19 21/06/2006 17 anos, 4 meses
9 20232T.I.CAX0223 Cássio Gomes da Silva 629.051.773-22 10/04/2007 16 anos, 7 meses
10 20232T.I.CAX0213 Clebson Júnior Bejamim dos Santos
Filho 613.341.393-00 03/05/2006 17 anos, 6 meses
11 20232T.I.CAX0159 Daniel da Silva Lima 627.347.823-67 29/08/2007 16 anos, 2 meses
12 20232T.I.CAX0194 David Arley dos Santos Pereira 627.267.533-02 17/04/2007 16 anos, 7 meses
13 20232T.I.CAX0015 Dayvison de Abreu da Silva 121.532.003-50 17/05/2006 17 anos, 6 meses
14 20232T.I.CAX0160 Deivid Cauãn Sodré Frazão 631.118.493-17 27/01/2008 15 anos, 9 meses
15 20232T.I.CAX0206 Edmário da Silva Luz 052.457.043-40 02/04/2006 17 anos, 7 meses
16 20232T.I.CAX0192 Ellen Vitória de Souza Gadelha 626.748.953-14 17/01/2007 16 anos, 10 meses
17 20232T.I.CAX0207 Emilly Silva dos Santos 627.457.123-06 14/02/2008 15 anos, 9 meses
18 20232T.I.CAX0185 Erison Heick da Silva Sena 635.320.613-50 04/05/2007 16 anos, 6 meses
19 20232T.I.CAX0228 Evelyn Lauanne da Silva Simião 615.835.333-70 18/07/2007 16 anos, 3 meses
20 20232T.I.CAX0225 Eyke Harlley de Sousa Freire 626.059.753-39 26/04/2007 16 anos, 6 meses
21 20232T.I.CAX0016 Felipe dos Santos Lima 632.151.983-98 28/06/2007 16 anos, 4 meses
22 20232T.I.CAX0211 Felipe Kelvin Moura Figueredo 633.249.103-58 17/10/2006 17 anos
23 20232T.I.CAX0216 Francilene Cardoso da Costa 634.299.293-26 04/05/2008 15 anos, 6 meses
24 20232T.I.CAX0210 Geiciane Keila de Sousa Alves 616.822.813-61 25/07/2007 16 anos, 3 meses
25 20232T.I.CAX0208 Grazielle Vieira Rodrigues 632.915.153-90 12/11/2007 16 anos
26 20232T.I.CAX0183 Guilherme Francisco Nascimento da
Silva 616.805.173-25 28/01/2007 16 anos, 9 meses
27 20232T.I.CAX0222 Ithan Lucas Barbosa Trovão 627.968.643-40 19/07/2007 16 anos, 3 meses
28 20232T.I.CAX0167 Izack Costa Carvalho 633.015.013-38 08/05/2007 16 anos, 6 meses
29 20232T.I.CAX0219 Jardielle da Silva de Parvalho 634.580.053-82 30/01/2007 16 anos, 9 meses
30 20232T.I.CAX0115 Jefferson da Costa Cavalcante 619.546.333-78 04/10/2006 17 anos, 1 mês
31 20232T.I.CAX0018 Jeyssethainnara Ferreira Sales 636.272.513-18 27/06/2007 16 anos, 4 meses
32 20232T.I.CAX0122 João Gabriel de Carvalho Durans 612.028.753-19 26/10/2006 17 anos
33 20232T.I.CAX0218 Karleandro dos Santos Silva 638.607.553-66 13/06/2008 15 anos, 5 meses
34 20232T.I.CAX0164 Kelle Juliana Souza de Carvalho 624.346.353-26 16/04/2007 16 anos, 7 meses
35 20232T.I.CAX0224 Kelliny Thais dos Santos Machado 619.007.723-45 06/04/2006 17 anos, 7 meses
36 20232T.I.CAX0199 Lais Silva de Amorim 634.524.923-89 22/05/2006 17 anos, 5 meses
37 20232T.I.CAX0201 Lara Raysa Texeira Silva 113.584.893-94 08/01/2007 16 anos, 10 meses
38 20232T.I.CAX0189 Lavínia Lohany Garrido Saturnino 625.521.033-24 21/08/2007 16 anos, 2 meses
39 20232T.I.CAX0188 Leidy Laianny Palhano Pereira 046.933.412-66 11/03/2008 15 anos, 8 meses
40 20232T.I.CAX0182 Luis Henrique Barbosa Feitoza 630.600.133-65 06/08/2006 17 anos, 3 meses
41 20232T.I.CAX0169 Luis Henrique de Oliveira Silva 626.752.363-22 02/05/2006 17 anos, 6 meses
42 20232T.I.CAX0221 Lysia Nirvana Castro Gonçalves 067.201.503-08 12/10/2005 18 anos, 1 mês
43 20232T.I.CAX0187 Magno Adriano Martins Junior 625.381.073-18 01/06/2006 17 anos, 5 meses
44 20232T.I.CAX0229 Marcos Ronilson Barros Araújo 614.836.393-39 10/07/2006 17 anos, 4 meses
45 20232T.I.CAX0232 Maria Akeilma da Conceição Costa 633.074.323-11 11/11/2008 15 anos
46 20232T.I.CAX0191 Maria Daniele Sousa Silva 637.919.593-95 20/07/2007 16 anos, 3 meses
47 20232T.I.CAX0178 Maria Eduarda Araújo Rodrigues 630.562.353-83 15/04/2007 16 anos, 7 meses
48 20232T.I.CAX0181 Maria Evyllin dos Reis Araújo 624.760.903-52 24/12/2007 15 anos, 10 meses
49 20232T.I.CAX0214 Maria Fernanda da Silva Sousa 538.053.898-33 18/12/2008 14 anos, 11 meses
50 20232T.I.CAX0165 Maria Yasmin de Sousa dos Santos 621.715.623-74 26/04/2006 17 anos, 6 meses
51 20232T.I.CAX0195 Mikaely Ferreira da Silva de Sousa 626.749.913-80 21/02/2007 16 anos, 8 meses
52 20232T.I.CAX0226 Patrícia Mel Silva de Oliveira 613.662.023-50 23/01/2006 17 anos, 9 meses
53 20232T.I.CAX0161 Paulo Everton dos Santos da Costa 634.223.763-80 12/06/2019 4 anos, 5 meses
54 20232T.I.CAX0017 Priscila Nunes Pimentel do Nascimento 122.144.533-26 12/08/2006 17 anos, 3 meses
55 20232T.I.CAX0217 Renata Dias Aguiar 627.597.703-54 02/08/2007 16 anos, 3 meses
56 20232T.I.CAX0200 Rillary Rocha Conceição 630.791.143-37 28/09/2008 15 anos, 1 mês
57 20232T.I.CAX0198 Rosangela de Sousa Palhares 627.639.333-94 25/04/2006 17 anos, 6 meses
58 20232T.I.CAX0230 Ryan Lucas Pereira Costa 634.805.843-30 03/12/2007 15 anos, 11 meses
59 20232T.I.CAX0186 Suely Maria de Freitas Machado 618.293.273-21 05/08/2007 16 anos, 3 meses
60 20232T.I.CAX0193 Valéria Santos Conceição 632.631.173-00 31/12/2007 15 anos, 10 meses
61 20232T.I.CAX0220 Victor Hugo da Silva Moreira 084.442.683-05 12/05/2008 15 anos, 6 meses
62 20232T.I.CAX0196 Vynicius Rosa Alvin 063.915.873-02 30/03/2007 16 anos, 7 meses
63 20232T.I.CAX0197 Wanderson Clemente de Sales 638.039.133-90 06/01/2008 15 anos, 10 meses
64 20232T.I.CAX0163 Wemerson Vieira de Castro 629.718.773-88 30/03/2007 16 anos, 7 meses
"""

criar_csv(dados_str, "ListaAlunosCoroata.csv")
