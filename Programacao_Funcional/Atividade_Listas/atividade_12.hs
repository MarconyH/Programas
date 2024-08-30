import Data.List (sort)

-- Função que ordena e mescla duas listas
mergeAndSort :: Ord a => [a] -> [a] -> [a]
mergeAndSort xs ys = merge (sort xs) (sort ys)

-- Função que mescla duas listas ordenadas em uma lista ordenada
merge :: Ord a => [a] -> [a] -> [a]
merge [] ys = ys
merge xs [] = xs
merge (x:xs) (y:ys)
  | x <= y    = x : merge xs (y:ys)
  | otherwise = y : merge (x:xs) ys
