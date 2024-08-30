-- Função para filtrar os números ímpares
filtrarImpares :: [Int] -> [Int]
filtrarImpares = filter odd

-- Função de ordenação simples (Bubble Sort)
bubbleSort :: [Int] -> [Int]
bubbleSort [] = []
bubbleSort lista = bubbleSort (init pass) ++ [last pass]
  where
    pass = bubble lista

    bubble :: [Int] -> [Int]
    bubble [x] = [x]
    bubble (x:y:xs)
      | x > y     = y : bubble (x:xs)
      | otherwise = x : bubble (y:xs)

-- Função principal para filtrar e ordenar os números ímpares
imparesOrdenados :: [Int] -> [Int]
imparesOrdenados lista = bubbleSort (filtrarImpares lista)
