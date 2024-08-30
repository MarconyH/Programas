-- Função que cria uma lista onde o número i é repetido i vezes, começando de n até 1
repete :: Int -> [Int]
repete n = concatMap (\x -> replicate x x) [n, n-1 .. 1]
