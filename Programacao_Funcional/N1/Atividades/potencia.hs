pot :: Int -> Int -> Int
pot _ y | y == 0 = 1
pot x y = x*pot x (y-1)