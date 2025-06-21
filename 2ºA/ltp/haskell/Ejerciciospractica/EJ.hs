module Ejers where
    import Data.Char (ord)
    
    --Binary tree
    data BinTree = Leaf (Int) | Node (BinTree) (BinTree)
    tree = Node (Node (Leaf 1) (Leaf 2)) (Leaf 3)

    -- show
    instance Show (BinTree) where
        show (Leaf x) = (show x)
        show (Node x y) = "(N "++(show x)++" "++(show y)++")"

    -- sumar todas las hojas del árbol
    addLeaves :: BinTree -> Int
    addLeaves (Node x y) = (addLeaves x) + (addLeaves y)
    addLeaves (Leaf x) = x

    -- darle la vuelta al árbol
    flipTree :: BinTree -> BinTree
    flipTree (Node x y) = Node (flipTree y) (flipTree x)
    flipTree (Leaf x) = Leaf x

    -- muestra la hoja con el número más alto del árbol
    maxTree :: BinTree -> Int
    maxTree (Node x y) = max (maxTree x) (maxTree y)
    maxTree (Leaf x) = x

    --Tree
    data Tree a = Hoja a | Nodo (Tree a) a (Tree a)
    tree2 = (Nodo (Nodo (Hoja 1) 4 (Hoja 2)) 3 (Hoja 2))

    -- mostrar únicamente la rama izquierda del árbol    
    leftBranch :: Tree a -> [a]
    leftBranch (Nodo x a y) = [a] ++ leftBranch (x)
    leftBranch (Hoja a) = [a]

    rev :: [a] -> [a]
    rev (x:xs) = rev(xs) ++ [x]
    rev [] = []

    -- triple map
    mapB :: (a -> b -> c) -> [a] -> [b] -> [c]
    mapB f [] _ = []
    mapB f _ [] = []
    mapB f (x:xs) (y:ys) = f (x) (y) : mapB f (xs) (ys)

    trans :: [Int] -> [Int]
    trans (x:xs) = [x*(x+1)] ++ trans(xs)
    trans [] = []

    reverse' :: [a] -> [a]
    reverse' [] = []
    reverse' (x:xs) = reverse'(xs) ++ [x]

    -- myUnzip
    myUnzip :: [(a,b)] -> ([a],[b])
    myUnzip [] = ([], [])
    myUnzip ((x,y):resto) = (x:xs,y:ys) where (xs, ys) = myUnzip resto

    -- coordinates
    coords :: Int -> Int -> [(Int, Int)]
    coords x y = [(n, m) | n <- [0..x], m <- [0..y]]

    -- pyramid
    pyramid :: Int -> [[Int]]
    pyramid n = [[1..x] | x <-[1..n]]

    -- how are you?
    foo :: IO ()
    foo = do {
        putStrLn "First name?";
        fname <- getLine;
        putStrLn "Name?";
        name <- getLine;
        putStrLn("Hello "++ fname ++ " "++ name ++", how are you?")
        }

    -- loop until q
    revelar :: IO ()
    revelar = do {
        putStrLn "Introduce un caracter ";
        c <- getChar;
        if c == 'q' then putStrLn "adios jajaskd" else do {putStrLn (show (ord c)); revelar}
        }

    -- type declarations

    type Area = Float
    type Volume = Float
    type Side = Float
    type Radius = Float
    data Square = ASquare Side deriving Show
    data Rectangle = ARectangle Side Side deriving Show
    data Circle = ACircle Radius deriving Show
    data Cube = ACube Side deriving Show
    data Sphere = ASphere Radius deriving Show

    -- area function for squares, rectangles and circles
    -- volume function for cubes and spheres
    class MyArea a where 
        area :: a -> Area
    class MyVolume a where
        volume :: a -> Volume
    
    instance MyArea Square where
        area (ASquare l) = l * l
    instance MyArea Rectangle where
        area (ARectangle l a) = l * a
    instance MyArea Circle where
        area (ACircle r) = r * r * 3.1415
    instance MyVolume Cube where
        volume (ACube l) = l * l * l
    instance MyVolume Sphere where
        volume (ASphere r) = r * r * r * 3.1415

    -- Type classes conveniently solve both of these problems. 
    -- They allow us to declare which types are instances of which class, and
    -- to provide definitions of the overloaded operations associated with a class. 

    -- Employee
    type Name = String
    type Age = Int
    type Employee = (Name, Age)

    empleado1 = ("fernando",33)
    empleado2 = ("augusto",45)
    empList = [("fernando, 20"), ("fernando, 56"), ("fernando, 40"), ("fernando, 23")]

    youngest :: [Employee] -> Employee
    youngest x = youngestAux (head x) (tail x)
    youngestAux x [] = x
    youngestAux (n1, e1) ((n2, e2):xs)
        | e1>e2 = youngestAux (n2 ,e2) xs
        | otherwise = youngestAux (n1, e2) xs

    -- la función coge la lista de empleados, la separa en cabeza y cuerpo
    -- mediante head y tail y la pasa como parametros a la función Aux, la cual
    -- se encarga de comparar los segundos elementos de las dos primeras
    -- tuplas en cabeza de la lista. si el primer elemento es menor que el
    -- segundo, entonces este se convierte en la nueva cabeza de la lista.
    -- el segundo elemento no se reinserta en la lista, por lo que la lista
    -- reduce su tamaño en 1. El caso base de recursión se da cuando la lista
    -- queda con un único elemento.

    younger :: Employee -> Employee -> Employee
    younger (n1, e1) (n2, e2) = if e1 < e2 then (n1, e1) else (n2, e2)

    youngest2 :: [Employee] -> Employee
    youngest2 [x] = x
    youngest2 (x:y:xs) = youngest2 ((younger x y):xs)

    -- factorial:
    fac :: Int -> Int
    fac 1 = 1
    fac n = fac(n-1)*n

    reversey [] = []
    reversey (x:xs) = (reversey xs)++[x]