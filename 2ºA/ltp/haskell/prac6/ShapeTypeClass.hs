module ShapeTypeClass where
    type Side = Float
    type Apothem = Float
    type Radius = Float

    type Height = Float
    type Volume = Float

    type Base = Float
    type Depth = Float
    type Area = Float

    class Shape a where
        perimeter :: a -> Float
        area :: a -> Float

    data Pentagon = Pentagon Side Apothem 
    data Circle = Circle Radius 

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