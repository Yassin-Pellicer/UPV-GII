module Areas where
    import qualified Circle as Circle
    import qualified Triangle as Triangle

    main = do
        putStrLn("The area of a circle of radius 2 is: " ++ show(Circle.area 2))
        putStrLn("The area of a rectangle of base 4 and heigth 5 is: " ++ show(Triangle.area 4 5))