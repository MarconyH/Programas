module Operacoes (
    restoDivisao,
    divisaoInteira,
    mdc,
    mmc
) where

restodivisao :: Int -> Int -> Int
restodivisao _ 0 = error "Indeterminação"
restodivisao x y = x `mod` y

divisaointeira :: Int -> Int -> Int
divisaointeira _ 0 = error "Indeterminação"
divisaointeira x y = x `div` y

mdc :: Int -> Int -> Int
mdc a b
    | b == 0    = a
    | otherwise = mdc b (a `mod` b)

mmc :: Int -> Int -> Int
mmc a b = (abs a * abs b) `div` (mdc a b)
