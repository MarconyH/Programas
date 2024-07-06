primo :: Int -> Bool
primo n = verifica_primo n n-1

verifica_primo :: Int -> Int -> Bool
verifica_primo n m | m == 1 = True
verifica_primo n m | n `mod` m == 0 = False
verifica_primo n m = verifica_primo n (m-1)

fib :: Int -> Int
fib n
    | n == 0    = 0
    | n == 1    = 1
    | otherwise = fib (n - 1) + fib (n - 2)

fibprimo :: Int -> Int
fibprimo n
    | n <= 0    = error "Número deve ser positivo"
    | otherwise = nfibprimo n 0 

nfibprimo :: Int -> Int -> Int
nfibprimo n i
    | primo (fib i) && n == 1 = fib i
    | primo (fib i)           = nfibprimo (n - 1) (i + 1)
    | otherwise                           = nfibprimo n (i + 1)
