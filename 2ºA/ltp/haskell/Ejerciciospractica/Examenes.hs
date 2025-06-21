module Examenes where

    zipp :: [a] -> [b] -> [c] -> [(a,b,c)]
    zipp (x:xs) (y:ys) (z:zs) = (x,y,z) : zipp xs ys zs
    zipp _ _ _ = []

    data Tree a = Void | Branch a (Tree a) (Tree a) deriving Eq
    
    -- calcula la suma de valores del árbol
    sizeTree Void = 0
    sizeTree (Branch a b c) = a + sizeTree(b) + sizeTree(c)

    -- calcula el número de ramas del árbol
    valueTree Void = 0
    valueTree (Branch _ b c) = 1 + sizeTree(b) + sizeTree(c)

    equilibrado (Branch _ b c) = sizeTree(b) == sizeTree (c)

    instance (Ord a) => Ord (Tree a) where 
        a < b = sizeTree a < sizeTree b
        a <= b = sizeTree a <= sizeTree b
    
    mapfilter :: (a -> a) -> (a -> Bool) -> [a] -> [a]
    mapfilter _ _  [] = []
    mapfilter f g (x:xs) = y : mapfilter f g (xs) 
        where y = if g x then f x else x 

    data BinTreeInt = Voidy | Nodey Int BinTreeInt BinTreeInt deriving (Eq, Show)

    sumMaxPath :: BinTreeInt -> Int
    sumMaxPath Voidy = 0
    sumMaxPath (Nodey a _ c) = a + sumMaxPath c

    type Title = String
    type Authors = [String]
    type Duration = Float
    type Languages = Int
    data Obra = Obra Title Authors
    data Audiovisual = Audiovisual Obra Duration Languages
    class Translation a where
    translated :: a -> Bool
    translations :: a -> Int

    instance Translations Audiovisual where
        translated (Audiovisual _ _ z) = z > 1
        translations (Audiovisual _ _ z) = z - 1