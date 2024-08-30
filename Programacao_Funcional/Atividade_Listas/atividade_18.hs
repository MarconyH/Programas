import Data.Char (isDigit)

-- Função que descomprime uma string
descomprine :: String -> String
descomprine [] = []
descomprine (x:xs)
    | x == 'I' = replicate n char ++ descomprine rest
    | otherwise = x : descomprine xs
  where
    (digits, rest) = span isDigit xs
    n = read digits :: Int
    char = head rest
    rest' = tail rest
