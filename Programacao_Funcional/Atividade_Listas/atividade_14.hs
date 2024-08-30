-- Função que verifica se um número é divisível por todos os divisores de uma lista
divisivelPorTodos :: [Int] -> Int -> Bool
divisivelPorTodos divisores x = all (\d -> x `mod` d == 0) divisores

-- Função que filtra a lista de números para retornar apenas os divisíveis por todos os divisores
filtra_divisores :: [Int] -> [Int] -> [Int]
filtra_divisores divisores xs = filter (divisivelPorTodos divisores) xs
