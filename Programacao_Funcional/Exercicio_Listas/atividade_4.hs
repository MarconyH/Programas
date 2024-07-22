type Pino = Int
type Movimento = (Pino, Pino)

hanoi :: Int -> [String]
hanoi n = hanoi' n 1 2 3
  where
    hanoi' :: Int -> Pino -> Pino -> Pino -> [String]
    hanoi' 0 _ _ _ = []
    hanoi' n origem destino auxiliar =
        hanoi' (n-1) origem auxiliar destino ++
        [(show origem ++ " -> " ++ show destino)] ++
        hanoi' (n-1) auxiliar destino origem
