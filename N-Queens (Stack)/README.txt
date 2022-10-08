Compilation/Execution of N-Queens program:

Method 1: Makefile
make
./nqueens
(or "make run" to compile and execute at the same time)

Method 2: With bash script (run.sh)
./run.sh

Interaction with program:
1. Input integer n to define the number of queens and the size of the board (n x n)
2. Observe how each queen is being pushed to the stack and how they are popped from it if the existing position of the queens does not generate a correct solution  
2. Observe the results of the N-Queens problem: 
    If there is not a valid solution, the program will output a message to tell the user. 
    If there is a valid solution, an n x n board will be displayed with the correct position of queens and their coordinates.
