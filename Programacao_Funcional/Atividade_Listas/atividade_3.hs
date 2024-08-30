import Data.List (maximumBy, minimumBy)

dada_lista :: [(String, Int)]
dada_lista = [("joao", 21 :: Int), ("alex", 32 :: Int), ("alosio", 12 :: Int), ("maria", 45 :: Int)]

-- Função que retorna o nome da pessoa mais velha
nomeMaisVelho :: [(String, Int)] -> String
nomeMaisVelho lista = fst $ maximumBy (\(_, idade1) (_, idade2) -> compare idade1 idade2) lista

-- Função que retorna o nome da pessoa mais nova
nomeMaisNovo :: [(String, Int)] -> String
nomeMaisNovo lista = fst $ minimumBy (\(_, idade1) (_, idade2) -> compare idade1 idade2) lista

-- Função opcional que retorna o nome da pessoa mais velha e da mais nova simultaneamente
maisVelhoEMaisNovo :: [(String, Int)] -> (String, String)
maisVelhoEMaisNovo lista = (nomeMaisVelho lista, nomeMaisNovo lista)
