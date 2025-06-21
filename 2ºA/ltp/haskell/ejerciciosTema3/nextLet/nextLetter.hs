import Data.Char;

nextLetter x
    | isUpper x = if x == 'Z' then 'A' else chr (ord x + 1)
    | isLower x = if x == 'z' then 'a' else chr (ord x + 1)
    | otherwise = x

main = print (nextLetter 'j')