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
void printRemainingLen(){
    std::string input;
    std::vector<int> values;
    getline(std::cin, input);
    splitToIntVector(input, values);
    for (int i =0; i < values[2]; i++){
        if (values[0]>values[1]){
            values[0] = (int)floor((float)values[0]/2);
        } else{
            values[1] = (int)floor((float)values[1]/2);
        }
    }
    if (values[0]>values[1]){
        std::cout << values[0] << " " <<values[1];
    } else {
        std::cout << values[1] << " " <<values[0];
    }
    std::cout << "\n";
}
int main(){
    std::string inputN;
    int N;

    getline(std::cin, inputN);
    std::stringstream num(inputN);
    num >> N;
    for (uint i = 0; i < N; i++)
    {
        printRemainingLen();
    }
}