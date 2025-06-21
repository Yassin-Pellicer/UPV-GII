module ShapeTypeClassV2 where
    type Side = Float
    type Apothem = Float
    type Radius = Float

    type Height = Float
    type Volume = Float

    type Base = Float
    type Depth = Float
    type Area = Float

    class (Eq a, Show a) => Shape a where
        perimeter :: a -> Float
        area :: a -> Float

    data Pentagon = Pentagon Side Apothem 
    data Circle = Circle Radius

    instance Eq Pentagon where
        a == b = area a == area b
    instance Eq Circle where
        a == b = area a == area b
    instance Show Pentagon where
        show p = "Pentagon with area " ++ show (area p)
    instance Show Circle where
        show p = "Circle with area " ++ show (area p)

    instance Shape Pentagon where
        perimeter (Pentagon s a) = 5 * s
        area (Pentagon l a) = (5*l*a)/2
    instance Shape Circle where
        perimeter (Circle r) = 2 * pi * r
        area (Circle r) = 2 * pi * r * r

    volumePrism :: (Shape a) => a -> Height -> Volume
    volumePrism base height = (area base) * height

    surfacePrism :: (Shape a) => a -> Height -> Area
    surfacePrism base height = 2 * (area base) + (perimeter base) * height

    -- se instancia en la variable "a" la clase shape, de manera que se pueda
    -- aplicar a los objetos Circulo y Pentagono los métodos de esta clase