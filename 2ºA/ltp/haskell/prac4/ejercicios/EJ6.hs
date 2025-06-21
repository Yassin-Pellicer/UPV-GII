module Remainder where
    remainder :: Int -> Int -> Int
    remainder x y = if x > y then remainder (x-y) y else
                    if x == y then 0 else
                    x