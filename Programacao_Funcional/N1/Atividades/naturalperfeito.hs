perfeito :: Int -> Bool
perfeito n = n == somadivisores n 1 0

somadivisores :: Int -> Int -> Int -> Int
somadivisores n d s
    | d >= n = s
    | n `mod` d == 0 = somadivisores n (d + 1) (s + d)
    | otherwise = somadivisores n (d + 1) s
