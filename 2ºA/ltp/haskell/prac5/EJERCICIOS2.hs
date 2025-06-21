module EJERCICIOS2 where
    import Data.Char

    -- EJ11

    type Person = String
    type Book = String
    type Database = [(Person, Book)]

    exampleBase :: Database
    exampleBase = [("Alicia","El nombre de la rosa"),("Juan", "La hija del canibal"),("Pepe","Odesa"),("Alicia","La ciudad de las bestias")]

    obtain :: Database -> Person -> [Book]
    obtain dBase person = [book | (thisPerson, book) <- dBase, thisPerson == person]

    borrow :: Database -> Book -> Person -> Database
    borrow dBase person book = dBase ++ [(person, book)]

    return' :: Database -> Person -> Book -> Database
    return' dBase person book = [(personA, bookA) | (personA, bookA) <- dBase, (personA /= person && bookA /= book)]


