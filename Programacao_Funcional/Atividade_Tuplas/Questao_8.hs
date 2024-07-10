base :: Int -> (Int, String, String, Char)
base x
    | x == 0 = (1793, "Pedro  Paulo", "MESTRE", 'M')
    | x == 1 = (1793, "Pedro Paulo", "MESTRE", 'M')
    | x == 2 = (1234, "Maria da Silva", "DOUTOR", 'F')
    | x == 3 = (5678, "João Pereira", "DOUTOR", 'M')
    | x == 4 = (9876, "Ana Souza", "MESTRE", 'F')
    | x == 5 = (3456, "Carlos Oliveira", "DOUTOR", 'M')
    | x == 6 = (6543, "Juliana Santos", "MESTRE", 'F')
    | x == 7 = (7890, "Lucas Costa", "MESTRE", 'M')
    | x == 8 = (2345, "Beatriz Almeida", "DOUTOR", 'F')
    | x == 9 = (8765, "Rodrigo Nunes", "MESTRE", 'M')
    | x == 10 = (4321, "Camila Ferreira", "DOUTOR", 'F')
    | x == 11 = (9870, "Gustavo Pereira", "MESTRE", 'M')
    | x == 12 = (6541, "Fernanda Silva", "DOUTOR", 'F')
    | x == 13 = (3452, "Mateus Santos", "MESTRE", 'M')
    | x == 14 = (7896, "Mariana Costa", "DOUTOR", 'F')
    | x == 15 = (8761, "Rafael Oliveira", "MESTRE", 'M')
    | x == 16 = (1239, "Carolina Souza", "DOUTOR", 'F')
    | x == 17 = (5674, "Thiago Almeida", "MESTRE", 'M')
    | x == 18 = (2349, "Laura Nunes", "DOUTOR", 'F')
    | x == 19 = (8901, "Paulo Fernandes", "MESTRE", 'M')
    | x == 20 = (0, "", "", '0')

matricula (a,b,c,d) = a
nome (a,b,c,d) = b
titulo (a,b,c,d) = c
sexo (a,b,c,d) = d

--Letra a)

doutor :: (Int, String, String, Char) -> Int
doutor x
    | titulo x == "DOUTOR" = 1
    | otherwise = 0

numero_doutores :: Int -> Int
numero_doutores x
    | x == 0 = doutor (base x)
    |otherwise = doutor (base x) + numero_doutores (x-1)

--Letra b)

mulher :: (Int, String, String, Char) -> Int
mulher x
    | sexo x == 'F' = 1
    | otherwise = 0

numero_mulheres :: Int -> Int
numero_mulheres x
    | x == 0 = mulher (base x)
    |otherwise = mulher (base x) + numero_mulheres (x-1)

--Letra c)

mestre_homem :: (Int, String, String, Char) -> Int
mestre_homem x
    | sexo x == 'M' && titulo x == "MESTRE" = 1
    | otherwise = 0

numero_mestre_homem :: Int -> Int
numero_mestre_homem x
    | x == 0 = mestre_homem (base x)
    |otherwise = mestre_homem (base x) + numero_mestre_homem (x-1)

--Letra d)

menor :: Int -> Int -> Int
menor x y
    | x <= 0 = y
    | matricula (base x) < matricula (base y) = menor (x-1) x
    | otherwise = menor (x-1) y

menor_matricula x = (nome (base (menor (x-1) x)))