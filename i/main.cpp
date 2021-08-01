#include <iostream>
#include <sstream>
#include <vector>
#include <math.h>

void splitToIntVector(std::string s, std::vector<int> &out)
{
    std::stringstream ss(s);
    std::string word;
    while (ss >> word)
    {
        int parsed = 0;
        std::stringstream num(word);
        num >> parsed;
        out.push_back(parsed);
    }
}
void findIndividualNum(){
    std::string input;
    std::vector<int> values;
    getline(std::cin, input);
    splitToIntVector(input, values);
    int count = 0;
    for (int i =2; i <= values[1]; i++){
        bool isMult = false;
        for (int j = 2; j <= values[0] && i % j == 0; j++){
            isMult = true;
            break;
        }
        if (!isMult){
            std::cout<<"i: "<<i <<"\n";
            count++;
        }
    }
    std::cout << count << "\n";
}
int main(){
    std::string inputN;
    int N;

    getline(std::cin, inputN);
    std::stringstream num(inputN);
    num >> N;
    for (int i = 0; i < N; i++)
    {
        findIndividualNum();
    }
}