#include <iostream>
#include <fstream>
#include <map>
#include <sstream>
#include <vector>
#include "sequence.h"


int main(){
    std::map<char, int>  alphabet;
    std::vector<std::string> strings= readInput(alphabet);
    std::cout<< "string a: "<< strings[0] <<std::endl;
    std::cout<< "string b: "<< strings[1] <<std::endl;
    for (const auto& [letter, value] : alphabet) {
        std::cout << letter << ": " << value << "\n";
    }
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


int compute(){

}

void genOutput(){

}

