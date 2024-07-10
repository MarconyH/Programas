
type Tupla = (Int, Int, Int, Int)

ordena :: Tupla -> Tupla
acessa_elemento :: Int -> Tupla -> Int
inserir_elemento :: Int -> Int -> Tupla -> Tupla
--trocar_elemento :: Int -> Int -> Int -> Tupla -> Tupla
menor :: Int -> Int -> Tupla -> (Int, Int)
bubble_sort :: Int -> Int -> Tupla -> Tupla


acessa_elemento x t
    | x == 0 = selec_0 t
    | x == 1 = selec_1 t
    | x == 2 = selec_2 t
    | x == 3 = selec_3 t
        where
            selec_0 (a, b, c, d) = a
            selec_1 (a, b, c, d) = b
            selec_2 (a, b, c, d) = c
            selec_3 (a, b, c, d) = d

menor x y t
        | x > y = menor y x t
        | x == y = ((acessa_elemento x t), x)
        | (acessa_elemento x t) > (acessa_elemento y t) = menor (x+1) y t
        | otherwise = menor x (y-1) t

inserir_elemento x y t
    | x == 0 = inserir_0 t
    | x == 1 = inserir_1 t
    | x == 2 = inserir_2 t
    | x == 3 = inserir_3 t
    where
        inserir_0 (a, b, c, d) = (y, b, c, d)
        inserir_1 (a, b, c, d) = (a, y, c, d)
        inserir_2 (a, b, c, d) = (a, b, y, d)
        inserir_3 (a, b, c, d) = (a, b, c, y)

trocar_elemento (p1, p2, e, t) = (inserir_elemento p2 (acessa_elemento p1 t) (inserir_elemento p1 e t))

bubble_sort x y t
    | x == y = t
    | otherwise = bubble_sort (x+1) y (trocar_elemento (x, (snd (menor x y t)), (fst (menor x y t)), t))

ordena x
    | otherwise = (bubble_sort 0 3 x)