#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <math.h>
#include <bits/stdc++.h>
struct Village
{
    std::string name;
    int x, y, p;

    int distanceTo(Village b){
        int xDis = abs(b.x - x);
        int yDis = abs(b.y - y);
        return (int)floor(sqrt((xDis*xDis)+(yDis*yDis)));
    }
};

void parseVillages(std::string s, Village& a, Village& b)
{
    std::stringstream ss(s);
    std::string word;

    for (int i = 0; ss >> word; i++)
    {
        int parsed = 0;
        std::stringstream num(word);
        switch (i)
        {
        case 0:
            a.name = word;
            break;
        case 1:
            num >> parsed;
            a.x = parsed;
            break;
        case 2:
            num >> parsed;
            a.y = parsed;
            break;
        case 3:
            num >> parsed;
            a.p = parsed;
            break;
        case 4:
            b.name = word;
            break;
        case 5:
            num >> parsed;
            b.x = parsed;
            break;
        case 6:
            num >> parsed;
            b.y = parsed;
            break;
        case 7:
            num >> parsed;
            b.p = parsed;
            break;
        default:
            break;
        }
    }
}
bool cmp(std::pair<std::string, int>& a, std::pair<std::string, int>& b)
{
    return a.second > b.second;
}
std::vector<std::pair<std::string, int> > sort(std::map<std::string, int>& M)
{
    std::vector<std::pair<std::string, int> > A;
    for (auto& it : M) {
        A.push_back(it);
    }
    std::sort(A.begin(), A.end(), cmp);
    return A;
}
int main(){
    std::string inputN;
    int N;
    std::vector<std::string> out;
    std::map<std::string, int> distMap;
    getline(std::cin, inputN);
    std::stringstream num(inputN);
    num >> N;
    for (int i = 0; i < N; i++)
    {
        std::string inputVillages;
        getline(std::cin, inputVillages);
        Village a, b;
        parseVillages(inputVillages, a, b);
        std::string key = a.name + " " + b.name;
        distMap.insert(std::pair<std::string, int>(key, a.distanceTo(b)));
    }
    auto sorted = sort(distMap);
    for (auto& it : sorted) {
        std::cout << it.first << ' ' << it.second << "\n";
    }
}