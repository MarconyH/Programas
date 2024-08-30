-- Função para verificar se uma lista é um palíndromo
palindromo :: Eq a => [a] -> Bool
palindromo lista = lista == reverse lista
