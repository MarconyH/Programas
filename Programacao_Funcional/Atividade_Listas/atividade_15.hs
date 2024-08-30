-- Função que retorna a intersecção de duas listas
interseccao :: [Int] -> [Int] -> [Int]
interseccao xs ys = [x | x <- xs, x `elem` ys]
