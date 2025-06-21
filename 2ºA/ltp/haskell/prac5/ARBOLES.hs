module Arboles where
    data Tree a = Leaf a | Branch (Tree a) (Tree a) deriving Show

    -- EJEMPLO (CONTAR HOJAS ÁRBOL)

    numleaves :: Tree a -> Int
    numleaves (Leaf x) = 1
    numleaves (Branch x y) = numleaves x + numleaves y

    -- EJ12 (SYMMETRIC)

    symmetric :: Tree a -> Tree a
    symmetric (Leaf x) = (Leaf x)
    symmetric (Branch x y) = (Branch (symmetric y) (symmetric x))

    exampleTreeOne = Branch (Leaf 0) (Branch (Leaf 0) (Leaf 1))

    -- EJ13

    treeToList :: Tree a -> [a]
    treeToList (Leaf x) = [x]
    treeToList (Branch x y) = treeToList x ++ treeToList y

    listToTree :: [a] -> Tree a
    listToTree (x:xs) 
        | null xs = Leaf x
        | otherwise = Branch (Leaf x) (listToTree xs)

    data BinTreeInt = Void | Node Int (BinTreeInt) (BinTreeInt) deriving Show
    treeB1 = Void
    treeB2 = (Node 5 Void Void)
    treeB3 = (Node 5 (Node 3(Node 1 Void Void)(Node 4 Void Void))(Node 6 Void (Node 8 Void Void)))

    -- EJ14

    insTree :: Int -> BinTreeInt -> BinTreeInt
    insTree e Void = Node e Void Void
    insTree e (Node x izq der) 
        | e <= x = Node x (insTree e izq) der
        | e > x  = Node x izq (insTree e der)
    
    -- EJ15

    listToBinTree :: [Int] -> BinTreeInt
    listToBinTree (x:xs) 
        | null (x:xs) = Void
        | null (xs) = Node x Void Void
        | otherwise = insTree x (listToBinTree (xs))                                                                                                                                                                                                                                                    

    -- EJ16

    treeElem :: Int -> BinTreeInt -> Bool
    treeElem x Void = False
    treeElem x (Node y b1 b2)
        | x == y = True
        | x > y = treeElem x b2
        | x < y = treeElem x b1 