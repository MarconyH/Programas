-- 1


p :: Int -> Int -> Int 
p _ 0 = 1
p x y = x * potencia x (y-1)


-- 2


pr :: Int -> Int -> Bool
pr _ 1 = True
pr x y
        | mod x y == 0 = False
        | otherwise = pr x (y-1)

aPr :: Int -> Int -> Int
aPr x y
            | y == 1 && eh_primo == True = x
            | eh_primo == True = aPr (x+1) (y-1)
            | otherwise = aPr (x+1) y

            where 
                    eh_primo = pr x (x-1)

nPr :: Int -> Int
nPr 1 = 2
nPr x = aPr 2 x


-- 3

fibonacci :: Int -> Int
fibonacci 1 = 0
fibonacci 2 = 1
fibonacci x = fibonacci(x - 1) + fibonacci(x - 2)

-- 4

aux :: Int -> Int -> Int
aux _ 1 = 1
aux x i
        | mod x i == 0 = i + aux x (i-1)
        | otherwise = aux x (i-1
        )
Perfeito :: Int -> Bool
Perfeito n 
        | aux n (n-1) == n = True
        | otherwise = False


-- 5

f :: Int -> Int
f 1 = 1
f n 
    | ((mod n 2) == 0) = 1 + f (div n 2)
    | otherwise = 1 + f ( (n * 3) + 1)
