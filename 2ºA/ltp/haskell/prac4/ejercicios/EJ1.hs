module NumCbetw2 where
    import Data.Char
    antchar :: Char -> Char
    antchar c = chr ((ord c) - 1)
    
    numCbetw2 :: Char -> Char -> Int
    numCbetw2 c1 c2
        | c1 > c2 = 1 + numCbetw2 (antchar c1) c2
        | c2 > c1 = 1 + numCbetw2 c1 (antchar c2)
        | c1 == c2 = (-1)
