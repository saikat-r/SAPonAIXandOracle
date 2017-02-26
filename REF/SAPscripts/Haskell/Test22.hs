main = do putStrLn "What is 2 + 2?"
          x <- readLn
          if x == 4
              then putStrLn "You're right!" ; 
					z <- readLn
              else putStrLn "You're wrong!"
					z <- readLn