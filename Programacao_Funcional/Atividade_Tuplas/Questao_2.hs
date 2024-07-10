type Meutipo = (String, Int, Char)
pessoa :: Int -> Meutipo

pessoa rg
    | rg == 1 = ("Joao", 12, 'm')
    | rg == 2 = ("Maria", 21, 'f')
    | rg == 3 = ("Ana", 18, 'f')
    | rg == 4 = ("Paulo", 65, 'm')
    | rg == 5 = ("Marcony", 50, 'm')
    | otherwise = ("Nao existem mais registros", 9999, 'x')



nome :: Meutipo -> String
idade :: Meutipo -> Int
sexo :: Meutipo -> Char

nome (x,y,z) = x
idade (x,y,z) = y
sexo (x,y,z) = z

--Letra a)

menor_idade_ate :: Int -> String

menor :: Int -> Int -> String
menor x y
    | x == 0 = nome(pessoa y)
    | idade(pessoa x) < idade(pessoa y) = menor (x-1) x
    | idade(pessoa x) > idade(pessoa y) = menor (x-1) y

menor_idade_ate x
    | x == 1 = nome (pessoa x)
    | otherwise = menor (x-1) x

--Letra b)

idade_media_ate :: Int -> Float
soma_idade_ate :: Int -> Int

soma_idade_ate x
    | x == 1 = idade(pessoa x)
    |otherwise = idade(pessoa x) + soma_idade_ate (x-1)

idade_media_ate x = fromIntegral((soma_idade_ate x)) / fromIntegral(x)

--Letra c)

masc :: Int -> Int
masc x
    | sexo(pessoa x) == 'm' = 1
    | otherwise = 0

countm :: Int -> Int -> Int
countm x y
    | x > y = countm y x
    | x == y = masc x
    | otherwise = masc x + countm (x+1) y

--Letra d)

maior_idade :: Int -> Int -> Meutipo

maior_idade x y
        | x > y = maior_idade y x
        | x == y = pessoa x
        | idade (pessoa x) < idade (pessoa y) = maior_idade (x+1) y
        | idade (pessoa y) < idade (pessoa x) = maior_idade x (y-1)