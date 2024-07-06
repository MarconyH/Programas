--comentario
{-# OPTIONS_GHC -Wno-unrecognised-pragmas #-}
{-# HLINT ignore "Use camelCase" #-}
type Meutipo = (String, Int, Char)
pessoa :: Int -> Meutipo

pessoa rg
        | rg == 1 = ("Joao", 12, 'm')
        | rg == 2 = ("Maria", 21, 'f')
        | rg == 3 = ("Ana", 18, 'f')
        | rg == 4 = ("Paulo", 65, 'm')
        | rg == 5 = ("Marcony", 50, 'm')
        | otherwise = ("Nao existem mais registros", 0, 'x')

idade :: Meutipo -> Int

idade (x, y, z) = y

sexo :: Meutipo -> Char

sexo (x, y, z) = z

menor_idade :: Int -> Int -> Meutipo

menor_idade x y
        | x > y = menor_idade y x
        | x == y = pessoa x
        | idade (pessoa x) > idade (pessoa y) = menor_idade (x+1) y
        | idade (pessoa y) > idade (pessoa x) = menor_idade x (y-1)

soma_idade :: Int -> Int -> Int

soma_idade x y
        | x > y = soma_idade y x
        | x == y = idade (pessoa x)
        | otherwise = idade(pessoa x) + soma_idade (x+1) y

media_idade :: Int -> Int -> Float

media_idade x y
        | x > y = media_idade y x
        | x == y = fromIntegral (idade (pessoa x))
        | otherwise = fromIntegral (soma_idade x y)/fromIntegral (y-x+1)

-- contar quantos masculinos e quantos femininos

masc_fem :: Int -> Int -> String

masc_fem x y = result
    where
        
        masc :: Int -> Int
        masc x
            | sexo(pessoa x) == 'm' = 1
            | otherwise = 0

        countm :: Int -> Int -> Int
        countm x y
            | x > y = countm y x
            | x == y = masc x
            | otherwise = masc x + countm (x+1) y

        fem :: Int -> Int
        fem x
            | sexo(pessoa x) == 'f' = 1
            | otherwise = 0

        countf :: Int -> Int -> Int
        countf x y
            | x > y = countf y x
            | x == y = fem x
            | otherwise = fem x + countf (x+1) y
        
        result = "Quantidade de Homens: " ++ show (countm x y) ++ "\n Quantidade de Mulheres:" ++ show (countf x y) 