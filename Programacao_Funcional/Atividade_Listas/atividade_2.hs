conv_int_str :: [Int] -> [String]
conv_int_str xs = map (\x -> lookup x dic_10) xs
  where
    dic_10 = [(0, "zero"), (1, "um"), (2, "dois"), (3, "tres"), (4, "quatro"), 
              (5, "cinco"), (6, "seis"), (7, "sete"), (8, "oito"), (9, "nove")]

    lookup :: Int -> [(Int, String)] -> String
    lookup x dic = case Prelude.lookup x dic of
      Just value -> value
      Nothing -> error "Número fora do intervalo"
