module Max where
    max' :: Int -> Int -> Int
    max' x y = if x > y then x else
               if x < y then y else
               if x == y then y else
               0 