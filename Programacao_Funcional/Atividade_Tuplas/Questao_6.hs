equacao :: (Float, Float, Float) -> (Float, Float)

equacao (a, b, c)
    | b*b - 4 * a * c < 0 = (-99999,-99999)
    | otherwise = ((((-b) + sqrt(b*b - 4 * a * c))/2*a), (((-b) - sqrt(b*b - 4 * a * c))/2*a))