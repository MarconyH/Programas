-- Função que roda a lista para a esquerda
rodarEsquerda :: Int -> [a] -> [a]
rodarEsquerda n xs = drop n xs ++ take n xs
