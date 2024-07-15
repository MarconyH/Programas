soma_lista :: [Int] -> Int
soma_lista [] = 0
soma_lista (x:xs) = x + soma_lista xs