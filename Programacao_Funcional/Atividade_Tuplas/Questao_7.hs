import Data.Bool

triangulo :: (Float, Float, Float) -> (String, Float)
teste :: (Float, Float, Float) -> Bool
modulo :: Float -> Float

modulo x
    | x < 0 = (-x)
    | otherwise = x

teste (a, b, c) = (((modulo(b - c)) < a) && (a < (b + c)))

triangulo (a, b, c)
    | not (teste (a, b, c) && teste (b, a, c) && teste (c, a, b)) = ("Nao Existe", 0)
    | a == b && a == c = ("Equilatero", a+b+c)
    | a /= b && a /= c && b /= c = ("Escaleno", a+b+c)
    | otherwise = ("Isosceles", a+b+c)