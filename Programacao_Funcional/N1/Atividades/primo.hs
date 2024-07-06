primo :: Int -> Bool
primo n = verifica_primo n n-1

verifica_primo :: Int -> Int -> Bool
verifica_primo n m | m == 1 = True
verifica_primo n m | n `mod` m == 0 = False
verifica_primo n m = verifica_primo n (m-1)

nprimo :: Int -> Int
nprimo n = nprimoextra 2 n  

nprimoextra :: Int -> Int -> Int
nprimoextra n m
    | m == 0    = n - 1  
    | primo n   = nprimoextra (n + 1) (m - 1)  
    | otherwise     = nprimoextra (n + 1) m  
