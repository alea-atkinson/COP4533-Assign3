void genInput(int K, int n, int m);
std::vector<std::string> readInput(std::map<char, int>&  alphabet);
std::string getCommonSubsequence(std::string A, std::string B, std::vector<std::vector<int>> &M, int i, int j);
int getMaxSequenceValue(std::string A, std::string B, std::vector<std::vector<int>> &M, std::map<char, int>& alphabet);
void genOutput(int max, std::string subsequence);