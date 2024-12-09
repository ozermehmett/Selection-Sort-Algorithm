import Data.Time

selectionSort :: (Ord a) => [a] -> [a]
selectionSort [] = []
selectionSort xs = minElement : selectionSort rest
  where
    minElement = findMin xs
    rest = remove minElement xs

findMin :: (Ord a) => [a] -> a
findMin [x] = x
findMin (x:xs) = min x (findMin xs)

remove :: Eq a => a -> [a] -> [a]
remove _ [] = []
remove e (x:xs)
  | e == x    = xs
  | otherwise = x : remove e xs

importNumbersFromFile :: FilePath -> IO [Int]
importNumbersFromFile filePath = do
  contents <- readFile filePath
  let numbers = map read (words contents) :: [Int]
  return numbers

measureTime :: FilePath -> IO ()
measureTime filePath = do
  startTime <- getCurrentTime
  
  numbers <- importNumbersFromFile filePath

  let sortedNumbers = selectionSort numbers

  endTime <- getCurrentTime
  
  let diff = diffUTCTime endTime startTime

  putStrLn $ "Sorted list: " ++ show (take 5 sortedNumbers)
  putStrLn $ "processing time: " ++ (show diff)

