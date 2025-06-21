module DaysAmonth where

    leapYear :: Int -> Bool
    leapYear x = if mod x 4 == 0 then (if mod x 400 == 0 then True else
                 if mod x 100 == 0 then False else True)
                 else False 

    daysamonth :: Int -> Int -> Int
    daysamonth x y
        | (x == 2) && (leapYear y) = 29
        | (x == 1) || (x == 3) || (x == 5) || (x == 7) || (x == 8) || (x == 10) || (x == 12) = 31
        | (x == 4) || (x == 6) || (x == 9) || (x == 11) = 30
        | otherwise = 28