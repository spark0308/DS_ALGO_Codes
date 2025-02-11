#include <bits/stdc++.h>
using namespace std;

long long maxMatrixSum(vector<vector<int>>& matrix) 
{
    int negativeNumber = 0;
    long long matrixAbsoluteSum = 0;
    int minimumAbsoluteNumber = abs(matrix[0][0]);      

    for(auto x: matrix)
    {
        for(auto y: x)
        {
            if(y < 0) negativeNumber += 1;
            int currentAbsNumber = abs(y);
            matrixAbsoluteSum += currentAbsNumber;
            if(minimumAbsoluteNumber > currentAbsNumber) minimumAbsoluteNumber = currentAbsNumber;
        }
    }


    if(negativeNumber % 2 == 0) return matrixAbsoluteSum;
    else return (matrixAbsoluteSum - (2 * minimumAbsoluteNumber));

}

int main()
{

}