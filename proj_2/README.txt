
Boggle game functions
compile solver with:
bbsolver: g++ -Wall -Wextra BogSolver.cpp Dictionary.cpp solverMain.cpp -o bbsolver

Files:
BogSolver.h
BogSolver.cpp
Dictionary.h
Dictionary.cpp
bog_structs.h
solverMain.cpp


compile checker with:
bbchecker: g++ -Wextra -Wall BogValidator.cpp Dictionary.cpp checkerMain.cpp -o bbchecker

Files:
BogValidator.h
BogValidator.cpp
Dictionary.h
Dictionary.cpp
bog_structs.h
checkerMain.cpp

compile scorer with:
bbscorer: g++ -Wall -Wextra BogScorer.cpp scorerMain.cpp -o bbscorer

Files:
BogScorer.h
BogScorer.cpp
scorerMain.cpp
