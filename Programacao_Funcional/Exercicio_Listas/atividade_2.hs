listaFibonacci :: Int -> [Int]
listaFibonacci n
    | n <= 0    = []
    | otherwise = take n fibs
    where
        fibs = 0 : 1 : proximos 0 1
        proximos a b = next : proximos b next
            where next = a + b