module EJERCICIOS where

    -- EJ3

    -- divisors :: Int -> Int -> [Int]
    -- divisors x y = if x == 1 then [x] else 
    --              if mod x y == 0 then y : divisors x (y+1)
    --              else divisors x (y+1)

    divisors :: Int -> [Int]
    divisors x = [y | y <- [1..x] , (x `mod` y) == 0 ]

    -- EJ4

    member :: Int -> [Int] -> Bool
    member _ [] = False
    member x (y:ys) = if y == x then True else member x (ys)

    -- EJ5

    isPrime x = divisors x == [1,x]

    primeList = [y | y <- [1..] , isPrime y ]

    primes:: Int -> [Int]
    primes x = take x primeList

    -- EJ6

    -- evenList :: [Int] -> [Int]
    -- evenList [] = []
    -- evenList (x:xs) = if mod x 2 == 0 then x : evenList xs else evenList xs

    evenList :: [Int] -> [Int]
    evenList xs = [y | y <- xs, even y]

    evenPos :: [Int] -> [Int]
    evenPos xs = [i | i <- [0..length xs -1], even (xs !! i)]

    -- EJ7

    ins :: Int -> [Int] -> [Int]
    ins y [] = [y]
    ins y (x:xs) = if y < x then y:x:xs else x : ins y (xs)

    -- EJ8

    iSort :: [Int] -> [Int]
    iSort [] = []
    iSort (x:xs) = ins x (iSort xs)

    -- EJ9

    doubleList :: [Int] -> [Int]
    doubleList xs = map (2*) xs

    