type Date = (Int, Int, Int)

dias_data (d,m,a) = d + m * 30 + a * 356

diferenca_data :: Date -> Date -> Int

diferenca_data d1 d2
    | d1 > d2 = diferenca_data d2 d1
    | otherwise = dias_data(d2) - dias_data(d1)