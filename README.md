# Prime Numbers Checking By Threading

In this assignment, you will implement a multi-threaded program (using C/C++) that will check for Prime
Numbers in a range of numbers. The program will create T worker threads to check for prime numbers
in the given range (T will be passed to the program with the Linux command line). Each of the threads
work on a part of the numbers within the range.

Your program should have two global shared variables: numOfPrimes, which will track the total number
of prime numbers found by all threads. TotalNums: which will count all the processed numbers in the
range. In addition, you need to have an array (PrimeList) which will record all the founded prime
numbers.

When any of the threads starts executing, it will print its number (0 to T-1), and then the range of
numbers that it is operating on. When all threads are done, the main thread will print the total number
of prime numbers found, in addition to printing all these numbers.
You should write two versions of the program: The first one doesn’t consider race conditions, and the
other one is thread-safe. The input will be provided in an input file (in.txt), and the output should be
printed to an output file (out.txt). The number of worker threads will be passed through the command
line, as mentioned earlier.

The input will simply have two numbers range0 and range1, which are the beginning and end of the
numbers to check for prime numbers, inclusive. The list of prime numbers will be written to the output
file (out.txt), all the other output lines (e.g. prints from threads) will be printed to the standard output
terminal (STDOUT)
