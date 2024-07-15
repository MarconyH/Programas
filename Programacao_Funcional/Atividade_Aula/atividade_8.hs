ordena :: [Int] -> [Int]
ordena [] = []
ordena (x:xs) = insere x (ordena xs)

insere :: Int -> [Int] -> [Int]
insere x [] = x:[]
insere x (c:cs)
    | x <= c = x:c:cs
    | otherwise = c:(insere x cs)