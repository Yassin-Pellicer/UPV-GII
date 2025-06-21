import Data.List

isSorted [] = True

isSorted (x:xs) = fst $ foldl' step (True, x) xs
    where step (b, x) y = (b && (x <= y), y)
