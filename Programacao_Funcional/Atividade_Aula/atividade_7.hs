inverte :: [Char] -> [Char]
inverte [] = []
inverte (a:as) = inverte as ++ (a:[])