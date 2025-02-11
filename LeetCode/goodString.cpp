#include <bits/stdc++.h>
using namespace std;

int recursiveSolution(int str, int low, int high, int zero, int one)
{
    if(str > high) return 0;
    if(str == high) return 1;
    if(str >= low && str < high)
    {
        return 1 + recursiveSolution(str + zero, low, high, zero, one) + recursiveSolution(str + one, low, high, zero, one);
    }
    return recursiveSolution(str + zero, low, high, zero, one) + recursiveSolution(str + one, low, high, zero, one);
}

int countGoodString(int low, int high, int zero, int one)
{
    return recursiveSolution(0, low, high, zero, one);
}

int main()
{
    int zero, one, low, high;
    cin>>low>>high>>zero>>one;

    cout<<countGoodString(low, high, zero, one)<<endl;
}