bubblePass :: Ord a => [a] -> [a]
bubblePass [] = []
bubblePass [x] = [x]
bubblePass (x:y:xs)
  | x > y     = y : bubblePass (x:xs)
  | otherwise = x : bubblePass (y:xs)

bubbleSort :: Ord a => [a] -> [a]
bubbleSort lista
  | lista == sorted = lista
  | otherwise       = bubbleSort sorted
  where
    sorted = bubblePass lista