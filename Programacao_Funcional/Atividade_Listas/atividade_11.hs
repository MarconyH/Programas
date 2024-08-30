fibonacci :: [Integer]
fibonacci = 0 : 1 : zipWith (+) fibonacci (tail fibonacci)

fibonacciN :: Int -> [Integer]
fibonacciN n
  | n <= 0    = []
  | otherwise = take n fibonacci