# Bankers-Algorithm-For-OS

Written in Ubuntu Linux v20.04.3
Compiled using g++ v9.3.0

To run: 
-Compile using the line: "g++ banker.cpp -o banker".
-Run using the line "./banker".
-When prompted, enter the number of resources and processes
(3 and 5, respectively for this case).
-Enter name of text file with resource information
(in this case, use the attatched "numbers.txt" file).
-The program will then check to see if the resources are
in a safe state and return the safe order if they are.

I made this program modular in order to accomodate more
resources and processes if desired, hence the requirement
to enter them at the start.

The way the input file is set up is that each line is a cell
table with no white space. It starts with Allocation and goes
down the column, then Max and down the column, then Available
at the end. (this is better illustrated in the numbers.txt
file attatched)

How this program works is that it takes in the file and
reads it line by line (which is cell by cell of the table).
The first few lines (exact amount determined by # of processes)
are put into a 2d matrix for Allocation (called alloc in-code)
the next few are put in a 2d matrix called max, and the last
line is put in a 1d matrix called available. Then a 1d matrix
called work is set equal to available, and then the program 
loops through the alloc and max matricies, checking to see if
there's enough memory for the current process. If so, it is
set equal to true in another matrix called safeState and
the process # is added to a matrix called safeOrder. Once the
safety of the processes is determined, the result and order 
(if safe) is printed to the user.
