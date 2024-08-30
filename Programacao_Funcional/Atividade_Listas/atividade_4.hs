del_posicao_n :: [Int] -> Int -> [Int]
del_posicao_n lista n = take (n - 1) lista ++ drop n lista
