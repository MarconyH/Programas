-- Letra a
impar = [x|x <- [1..100], odd x]

-- Letra b
par = [x|x <- [10..100], even x]

-- Letra c
impar_n (n) = [x | x <- [1..n], odd x]

-- Letra d
multiplo_5_3 (n) = [x | x <- [1..n], mod x 3 == 0 && mod x 5 == 0]

-- Letra e
num_quadrado (n) = [(x, x*x) | x <- [1..n]]

-- Letra f
indice_3_4 = [(x,y) | x <- [1..3], y <- [1..4]]

-- Letra g
indice_n_m (n,m)= [(x,y) | x <- [1..n], y <- [1..m]]