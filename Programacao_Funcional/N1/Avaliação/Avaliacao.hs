-- Formula Catalan
catalan :: Integer -> Integer
catalan 0 = 1
catalan n = (fact (2*n)) div ((fact n) * (fact (n+1)))
  where
    fact 0 = 1
    fact m = m * fact (m - 1)
--a
n_catalan :: Integer -> Integer
n_catalan n
    | n < 0     = error "Insira um valor positivo"
    | otherwise = catalan n

--b
v_catalan :: Integer -> Bool
v_catalan n = v_catalan_extra n 0
    where
        v_catalan_extra :: Integer -> Integer -> Bool
        v_catalan_extra n m
            | catalan m == n = True
            | catalan m > n  = False
            | otherwise        = v_catalan_extra n (m + 1)

--c
qnt_catalan :: Integer -> Integer
qnt_catalan n = qnt_catalan_extra n 0
    where
        qnt_catalan_extra :: Integer -> Integer -> Integer
        qnt_catalan_extra n i
            | catalan i < n = qnt_catalan_extra n (i + 1)
            | otherwise = i

--d
soma_catalan :: Integer -> Integer -> Integer
soma_catalan a b = sum [catalan n | n <- [0..], catalan n >= a && catalan n <= b]