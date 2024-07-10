import Data.Char

converte :: Char -> (Char,Char,Int)

converte x = (x, toUpper x, ord x)