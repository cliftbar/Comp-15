compile solver with 
clang++ -g -Wall -Wextra BogSolver.cpp Dictionary.cpp main.cpp -o bbsolver
files:
BogSolver.h
BogSolver.cpp
Dictionary.h
Dictionary.cpp
bog_structs.h
*main.cpp

compile checker with 
clang++ -g -Wextra -Wall BogValidator.cpp Dictionary.cpp main.cpp -o bbchecker
files:
BogValidator.h
BogValidator.cpp
Dictionary.h
Dictionary.cpp
bog_structs.h