replica_char :: Char -> Int -> [Char]
replica_char c n
    | n == 0 = []
    | otherwise = c:replica_char c (n-1)