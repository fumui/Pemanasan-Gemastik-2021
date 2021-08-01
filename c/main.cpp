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
int sumSubmatrix(std::vector<std::vector<int>> &matrix, int x1, int y1, int x2, int y2)
{
    int sum = 0;
    for (int x = x1-1; x < x2; x++)
    {
        for (int y = y1-1; y < y2; y++)
        {
            sum += matrix[x][y];
        }
    }
    return sum;
}
int main()
{
    std::string inputMatrixInfo;
    std::vector<std::vector<int>> matrix;
    std::vector<int> matrixInfo, sums;

    getline(std::cin, inputMatrixInfo);
    splitToIntVector(inputMatrixInfo, matrixInfo);
    for (int i = 0; i < matrixInfo[0]; i++)
    {
        std::string inputMatrixRow;
        std::vector<int> matrixRow;
        getline(std::cin, inputMatrixRow);
        splitToIntVector(inputMatrixRow, matrixRow);
        matrix.push_back(matrixRow);
    }
    for (int i = 0; i < matrixInfo[2]; i++)
    {
        std::string inputSubmatrixPos;
        std::vector<int> submatrixPos;
        getline(std::cin, inputSubmatrixPos);
        splitToIntVector(inputSubmatrixPos, submatrixPos);
        sums.push_back(sumSubmatrix(matrix, submatrixPos[0], submatrixPos[1], submatrixPos[2], submatrixPos[3]));
    }
    for (int sum : sums){
        std::cout<<sum<<"\n";
    }
}