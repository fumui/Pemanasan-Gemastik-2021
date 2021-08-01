#include <iostream>
#include <sstream>
#include <vector>
#include <math.h>
#include <cmath>

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
int main(){
    std::string inputMinMax, inputABC;
    double min, max, A, B, C, count = 0;
    
    getline(std::cin, inputMinMax);
    std::stringstream num(inputMinMax);
    num >> min;
    num >> max;

    getline(std::cin, inputABC);
    std::stringstream abc(inputABC);
    abc >> A;
    abc >> B;
    abc >> C;
    if (A == 0 || B == 0 || C == 0){
        std::cout<<count<<"\n";
        return;
    }
    for (double i = min; i <= max; i++)
    {
        bool modA = std::fmod(i,A) == 0;
        bool modB = std::fmod(i,B) == 0;
        bool modC = std::fmod(i,C) == 0;
        if (modA ^ modB ^ modC){
            count++;
        }
    }
    std::cout<<count<<"\n";
}