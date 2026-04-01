#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include "sequence.h"

int main(){
    return 0;
}

void genInput(int K){

}

int compute(){

}

int getMaxSequenceValue(std::string A, std::string B, std::map<char, int> alphabet)
{
    int maxValue = 0;

    // Initialize the solution vector M to 0
    std::vector<std::vector<int>> M;
    for(int i = 0; i < A.length(); i++)
    {
        for(int j = 0; j < B.length(); j++)
        {
            M[i][j] = 0;
        }
    }

    // Calculate the values 
    for(int i = 0; i < A.length(); i++)
    {
        int value = 0;

        for(int j = 0; j < B.length(); j++)
        {
            if(i == j)
            {
                int value = alphabet[j];
            }

            M[i][j] = std::max(value + M[i - 1][j - 1], M[i][j-1]);
            maxValue = M[i][j];
        }
    }
    
    return maxValue;
}

void genOutput(){

}