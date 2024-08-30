-- Função auxiliar que verifica se uma string é prefixo de outra
isPrefix :: String -> String -> Bool
isPrefix [] _ = True
isPrefix _ [] = False
isPrefix (x:xs) (y:ys) = (x == y) && isPrefix xs ys

-- Função principal que busca por sub-strings no início das strings da lista
busca_sub :: String -> [String] -> [String]
busca_sub _ [] = []
busca_sub sub (x:xs)
  | isPrefix sub x = x : busca_sub sub xs
  | otherwise      = busca_sub sub xs
