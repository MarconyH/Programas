dic_10 = [(0,"zero"), (1,"um"), (2,"dois"), (3,"tres"), (4,"quatro"), (5,"cinco"), (6,"seis"), (7,"sete"), (8,"oito"), (9, "nove")]

conv_int_str :: [Int] -> [String]

compara :: Int -> [(Int, String)] -> String

compara x y
    | x == fst (head y) = snd (head y)
    | otherwise = (compara x (tail y))

conv_int_str x
    | null x = []
    | otherwise = (compara (head x) dic_10):conv_int_str (tail x)