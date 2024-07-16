maior :: [Int] -> (Int, Int)

maior [] = (0,0)
maior (x:xs) = ((maior_num xs x), (pos (maior_num xs x) (x:xs)))

maior_num :: [Int] -> Int -> Int

maior_num x y
    | null x = y
    | (head x) <= y = maior_num (tail x) y
    | otherwise = maior_num (tail x) (head x)

pos :: Int -> [Int] -> Int

pos y (x:xs)
    | x == y = 1
    | x /= y = 1 + pos y xs