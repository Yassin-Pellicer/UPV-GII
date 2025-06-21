module AddRange where
    addRange :: Int -> Int -> Int
    addRange x y = if x < y then x + addRange(x+1) y else
                   if x == y then x else
                   addRange x y  