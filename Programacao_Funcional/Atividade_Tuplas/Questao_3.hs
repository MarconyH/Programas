import Data.Char

analisa_letra :: Char -> (Char, Char, Int)

analisa_letra x
    | isLower(x) = (x, toUpper(x), ord(x))
    |otherwise = ((x, toLower(x), ord(x)))