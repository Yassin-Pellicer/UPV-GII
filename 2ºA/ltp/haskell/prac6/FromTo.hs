module FromTo where
    import Queue 

    toList :: Queue a -> [a]
    toList a 
        |(isEmpty a) = []
        |otherwise = first(a) : toList(dequeue(a))

    fromList :: [a] -> Queue a
    fromList [] = empty
    fromList (x:xs) = enqueue x (fromList(xs))