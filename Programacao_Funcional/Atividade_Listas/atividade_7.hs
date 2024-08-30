-- Função para retornar o valor na n-ésima posição de uma lista
n_posicao :: Int -> [a] -> a
n_posicao n lista
  | n > 0 && n <= length lista = lista !! (n - 1)
  | otherwise = error "Índice fora do limite da lista"
