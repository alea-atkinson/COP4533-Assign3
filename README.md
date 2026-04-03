# COP4533 Programming Assignment 3
Alea Atkinson (UFID: 97449634) and Kristen Moy (UFID: 20004111)
### To Run:
1. Clone the repository into a code editor such as vs code
2. To genereate a sequence.exe file, run the following command in the terminal: **g++ -o sequence sequence.cpp**
3. To run the executable, run the following command in the terminal: **./sequence k n m**. you must provide 3 command line arguments. The first argument k determines the number of letters in the alphabet in order of a to z, and the second and third determine the number of letters in strings A and B respectively. ex. ./sequence 3 5 4 runs with an alphabet from a to c and strings of lengths 5 and 4.
4. Running the executable will automatically create a randomlly generated input file with the specified input format with random alphabet values ranging from 1 to 50. This file is created in the io folder: io/input.txt
5. Running the executable will also create an output file in io: io/output.txt. This file allows you to view the results of the HVLCS algorithm. This result is also printed to the console. Ex. 53 {\n} ab indiates that the max value subsequence is ab with a total value of 53. 
### View Written Questions
* The written answers can be accessed in the written folder
* For question 1, the ten files (both input and output) used in the runtime graph are located in the written/io
* All written answers are located in written/written_questions.pdf
