# 15Puzzle
An app that finds a solution to a 15 puzzle with different methods

To start the application:

execName.exe method order initialStateFilename solutionFilename

method: bfs / dfs / astr

order: permutation of possible movements R, L, U, D. If the astr method is chosen, then we choose the hamming or manhatan heurestics (hamm / manh)

initialStateFilename: a text file containing the initial state of the puzzle e.g 
1,2,3,4 
5,6,7,8 
9,10,11,0 
13,14,15,12

solutionFilename: the file in which the solution will be written

sample program launch: 15Puzzle.exe bfs DRLU initialState.txt solution.txt