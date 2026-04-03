#include "sequence.h"


int main(int argc, char* argv[]){
    //check for incorrect arguments
    if(argc<4){
        std::cout<<"Not enough arguments."<<std::endl;
        return -1;
    }
    else if(std::stoi(argv[1])>26){
        std::cout<<"K cannot be greater than 26."<<std::endl;
    }
    else if(std::stoi(argv[2])<1 || std::stoi(argv[3])<1){
        std::cout<<"n and m must be greater than 0."<<std::endl;
    }
    //generate input file
    genInput(std::stoi(argv[1]), std::stoi(argv[2]), std::stoi(argv[3]), "io/input.txt");
    //initialize data structures
    std::map<char, int>  alphabet;
    std::vector<std::string> strings= readInput(alphabet, "io/input.txt");
    std::vector<std::vector<int>> M;
    //get values
    int max=getMaxSequenceValue(strings[0], strings[1], M, alphabet);
    std::string sequence= getCommonSubsequence(strings[0], strings[1], M, strings[0].length(), strings[1].length());
    //format output
    genOutput(max, sequence);
    return 0;

    
}

void genInput(int K, int n, int m, std::string file){
    //K MUST BE LESS THAN OR EQUAL TO 26
    std::ofstream input(file);
   
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

std::vector<std::string> readInput(std::map<char, int>&  alphabet, std::string file){

    std::ifstream input(file);
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
    else if(A.at(i - 1) == B.at(j - 1))
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
     output.close();
}

void runtime(){

    std::map<char, int>  alphabet;
    std::vector<std::vector<int>> M;
    for(int i=0; i<10; i++){
        genInput(26, 25+(i*10), 25+(i*10), "written/io/input_"+ std::to_string(i+1) +".txt");
        std::vector<std::string> strings= readInput(alphabet, "written/io/input_"+ std::to_string(i+1) +".txt");
        auto start = std::chrono::steady_clock::now();
        int max=getMaxSequenceValue(strings[0], strings[1], M, alphabet);
        std::string sequence= getCommonSubsequence(strings[0], strings[1], M, strings[0].length(), strings[1].length());
        auto end = std::chrono::steady_clock::now();
        auto diff = end - start;
        std::cout<< i << ": "<< (std::chrono::duration_cast<std::chrono::microseconds>(diff)).count()<<std::endl;
        //format output
        std::ofstream output("written/io/output_"+ std::to_string(i+1) +".txt");
        output << max << std::endl << sequence;
        output.close();
        alphabet.clear();
        M.clear();
    }
    
}
