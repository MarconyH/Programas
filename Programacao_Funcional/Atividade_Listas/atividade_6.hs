inserir_posicao_x :: [Int] -> Int -> Int -> [Int]
inserir_posicao_x lista n elemento = inicio ++ [elemento] ++ fim
  where
    (inicio, fim) = splitAt (n - 1) lista