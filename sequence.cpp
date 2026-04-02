#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include <sstream>
#include <algorithm>
#include "sequence.h"


int main(){
    std::map<char, int>  alphabet;
    std::vector<std::string> strings= readInput(alphabet);
    std::cout<< "string a: "<< strings[0] <<std::endl;
    std::cout<< "string b: "<< strings[1] <<std::endl;
    for (const auto& [letter, value] : alphabet) {
        std::cout << letter << ": " << value << "\n";
    }
    std::vector<std::vector<int>> M;
    std::cout<< getMaxSequenceValue(strings[0], strings[1], M, alphabet);   
    //genOutput(getMaxSequenceValue(strings[0], strings[1], M, alphabet), getCommonSubsequence(strings[0], strings[1], M, strings[0].length(), strings[1].length()));
    return 0;
}

void genInput(int K, int n, int m){
    //K MUST BE LESS THAN OR EQUAL TO 26
    std::ofstream input("io/input.txt");
   
    input << K << std::endl; //write K
   
    char alphChar;
    int randValue;
    for(int i=0; i<K; i++){
        alphChar= 'a' + i; //sequential letter of alphabet
        randValue= 1 + rand() % 50; //random value from 1 to 50
        input << alphChar << " " << randValue << std::endl;
    }
    std::string A;
    for(int i=0; i<n; i++){
       A += 'a' + rand() % K; //random character from first to last letter of alphabet
    }
    std::string B;
    for(int i=0; i<m; i++){
       B += 'a' + rand() % K; //random character from first to last letter of alphabet
    }

    input << A << std::endl;
    input << B << std::endl;

    input.close();
}

std::vector<std::string> readInput(std::map<char, int>&  alphabet){

    std::ifstream input("io/input.txt");
    std::string line;
    std::vector<std::string> strings;
    int count=0;
    int k;
    while(getline(input, line)){
        if (count==0){
            k= stoi(line);
        }
        else if ((count-1)<k){
            std::stringstream ss(line);
            std::string word;
            char character;
            ss >> character; //read character
            ss >> alphabet[character]; //read value
            }
    
        else{
            strings.push_back(line);
        }
        count++;
        
    }
    return strings;

} 

int getMaxSequenceValue(std::string A, std::string B, std::vector<std::vector<int>> &M, std::map<char, int>& alphabet)
{
    int maxValue = 0;

    // Initialize the solution vector M to 0
    M.resize(A.length()+1, std::vector<int>(B.length()+1, 0)); //array is of string lengths+1 to account for 0 positions

    // Calculate the values 
    for(int i = 1; i < A.length()+1; i++)
    {
        int value = 0;

        for(int j = 1; j < B.length()+1; j++)
        {
            if(A.at(i-1) == B.at(j-1)) //index A and B according to array policy using i and j
            {
                M[i][j] = alphabet[A[i-1]] + M[i-1][j-1]; //add alphabet value to previous
            }
            else
            {
                M[i][j] =  M[i-1][j-1]; //added value = 0
            }

            M[i][j] = std::max({M[i][j], M[i][j-1], M[i-1][j]}); 
            
            if(M[i][j] > maxValue)
            {
                maxValue = M[i][j];
            }
        }
    }
    
    return maxValue;
}

std::string getCommonSubsequence(std::string A, std::string B, std::vector<std::vector<int>> &M, int i, int j)
{
    // Backtracking
    if (i == 0 || j == 0)
    {
        return "";
    }
    else if(A.at(i) == B.at(j))
    {
        return getCommonSubsequence(A, B, M, i - 1, j - 1) + A[i - 1];
    }
    else if(M[i - 1][j] > M[i][j - 1])
    {
        return getCommonSubsequence(A, B, M, i - 1, j);
    }
    else if(M[i][j - 1] >= M[i - 1][j])
    {
        return getCommonSubsequence(A, B, M, i, j - 1);
    }
}

void genOutput(int max, std::string subsequence){
     std::ofstream output("io/output.txt");
     output << max << std::endl << subsequence;
     std::cout << max << std::endl << subsequence;
}

