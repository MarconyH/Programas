import Data.List (group)

-- Função que comprime uma sequência de caracteres iguais em uma string
comprine :: String -> String
comprine [] = []
comprine xs = concatMap comprimeGrupo (group xs)
  where
    comprimeGrupo :: String -> String
    comprimeGrupo grp
      | length grp > 3 = 'I' : show (length grp) ++ [head grp]
      | otherwise = grp
