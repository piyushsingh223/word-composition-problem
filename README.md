# word-composition-problem
coding assignment solution for impledge.

Steps to run the code :- 

1. open any c++ ide or online compiler like GDB Compiler
2. copy and paste the code in the ide
3. upload the input files given
4. run the code
5. A output file will be created where output will be printed.


Code Explanation :- 

std::chrono header file have been used for handling time measurements.
There is a comparison function (mycmp) used for sorting the words. 
It compares strings based on their length first and then lexicographically if they have the same length.
input strings are taken and stored both in vector as well as an unordered set(Hash set).
Then vector of strings is sorted using the mycmp comparartor.
The sorted words is iterated in reverse order because the longest string will be at the last index of the vector.
For each word temp, initialize templen as its size, and reset the boolean vector dp to all false. 
then, Check if the substrings(subparts) of temp are in the set st, update the dp vector based on certain conditions.
then we Print the results.
In the main function , measure the time taken to run the solve function, and print the time. 
The solve function does the actual processing and output generation.

so this is the code explanation. i have also added some comments in the code for better readability of the code.

