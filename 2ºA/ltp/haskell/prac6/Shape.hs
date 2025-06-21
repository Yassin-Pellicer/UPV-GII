module Shape where
    type Side = Float
    type Apothem = Float
    type Radius = Float

    data Shape = Pentagon Side Apothem | Circle Radius deriving (Eq, Show)

    perimeter :: Shape -> Float
    perimeter (Pentagon s a) = 5 * s
    perimeter (Circle r) = 2 * pi * r

    area :: Shape -> Float
    area (Pentagon l a) = (5*l*a)/2
    area (Circle r) = 2 * pi * r * r