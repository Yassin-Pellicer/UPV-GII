module Sumfacts where
    sumfacts :: Int -> Int
    sumfacts 0 = 0
    sumfacts x = fact(x) + sumfacts(x-1)

    fact :: Int -> Int
    fact 0 = 1
    fact n = n * fact (n-1) 