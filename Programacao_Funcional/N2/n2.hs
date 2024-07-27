{-# LANGUAGE OverloadedStrings #-}

import System.Random
import Data.Time.Clock
import Data.Time.Clock.POSIX (getPOSIXTime, posixSecondsToUTCTime)
import Data.Aeson
import qualified Data.ByteString.Lazy as B

-- Função para gerar uma semente a partir do tempo atual
sementeAtual :: IO StdGen
sementeAtual = do
    tempoAtual <- round . (* 1000000) . toRational <$> getPOSIXTime
    return $ mkStdGen tempoAtual

-- Função para gerar números aleatórios
gerarNumerosAleatorios :: StdGen -> Int -> [Int]
gerarNumerosAleatorios _ 0 = []
gerarNumerosAleatorios gen n =
    let (value, newGen) = randomR (0, 100) gen
    in value : gerarNumerosAleatorios newGen (n - 1)

-- Merge Sort
mergesort :: Ord a => [a] -> [a]
mergesort [] = []
mergesort [x] = [x]
mergesort xs =
    let (as, bs) = splitAt (length xs `div` 2) xs
    in merge (mergesort as) (mergesort bs)
  where
    merge [] ys = ys
    merge xs [] = xs
    merge (x:xs) (y:ys)
        | x <= y    = x : merge xs (y:ys)
        | otherwise = y : merge (x:xs) ys

-- Selection Sort
selection_sort :: Ord a => [a] -> [a]
selection_sort [] = []
selection_sort xs = let (y, ys) = removeMin xs in y : selection_sort ys
  where
    removeMin [x] = (x, [])
    removeMin (x:xs)
        | x < m     = (x, m:ms)
        | otherwise = (m, x:ms)
      where
        (m, ms) = removeMin xs

-- Função para medir o tempo de execução de uma ação
medirTempo :: (Ord a) => ([a] -> [a]) -> [a] -> IO NominalDiffTime
medirTempo sortFn xs = do
    inicio <- getCurrentTime
    let _ = sortFn xs
    fim <- getCurrentTime
    return $ diffUTCTime fim inicio

-- Executa ambos os algoritmos de ordenação para diferentes tamanhos de lista e armazena os resultados em um arquivo JSON
main :: IO ()
main = do
    gen <- sementeAtual
    let tamanhos = [10000, 20000, 30000, 40000, 50000, 60000, 70000, 80000, 90000, 100000]
    
    resultados <- mapM (\n -> do
        let numeros = gerarNumerosAleatorios gen n
        
        -- Medindo o tempo do mergesort
        tempoMerge <- medirTempo mergesort numeros
        
        -- Medindo o tempo do selection sort
        tempoSelection <- medirTempo selection_sort numeros
        
        return $ object
            [ "quantidade_elementos" .= n
            , "tempo_merge_sort" .= show tempoMerge
            , "tempo_selection_sort" .= show tempoSelection
            ]
        ) tamanhos
    
    -- Escrever os resultados em um arquivo JSON
    B.writeFile "/home/marcony/Documents/Programas/Programacao_Funcional/N2/dados.json" (encode resultados)
