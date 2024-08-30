-- Estrutura para armazenar os dados de uma pessoa
data Pessoa = Pessoa {
    nome :: String,
    idade :: Int,
    endereco :: Endereco
} deriving (Show, Eq)

-- Estrutura para armazenar o endereço
data Endereco = Endereco {
    rua :: String,
    casa :: String,
    cidade :: String
} deriving (Show, Eq)

-- Função de ordenação alfabética pelo nome
instance Ord Pessoa where
    compare p1 p2 = compare (nome p1) (nome p2)

-- Função para adicionar ou atualizar uma pessoa na lista
atualizarPessoa :: Pessoa -> [Pessoa] -> [Pessoa]
atualizarPessoa novaPessoa [] = [novaPessoa]
atualizarPessoa novaPessoa (p:ps)
    | nome novaPessoa == nome p = novaPessoa : ps  -- Substitui se os nomes forem iguais
    | nome novaPessoa < nome p  = novaPessoa : p : ps  -- Insere antes de uma pessoa com nome maior
    | otherwise = p : atualizarPessoa novaPessoa ps  -- Continua buscando a posição correta

-- Função para localizar uma pessoa pelo nome
buscarPessoa :: String -> [Pessoa] -> Maybe Pessoa
buscarPessoa _ [] = Nothing
buscarPessoa nomeBusca (p:ps)
    | nomeBusca == nome p = Just p
    | nomeBusca < nome p  = Nothing  -- Lista está ordenada, então podemos parar a busca
    | otherwise = buscarPessoa nomeBusca ps

-- Função que retorna o número de pessoas em uma determinada cidade
contarPorCidade :: String -> [Pessoa] -> Int
contarPorCidade _ [] = 0
contarPorCidade cidadeBusca (p:ps)
    | cidadeBusca == cidade (endereco p) = 1 + contarPorCidade cidadeBusca ps
    | otherwise = contarPorCidade cidadeBusca ps

-- Função para calcular a média de idade da população
mediaIdade :: [Pessoa] -> Double
mediaIdade [] = 0
mediaIdade ps = fromIntegral (sum (map idade ps)) / fromIntegral (length ps)
