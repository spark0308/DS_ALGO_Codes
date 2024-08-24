#include <bits/stdc++.h>
using namespace std;

int solution(int a, int b)
{
    int ans = 0;
    while (a != b)
    {
        if (a > b)
        {
            if (a % 2 == 0)
                ans += a / 2;
            else
                ans += (a / 2) + 1;

            a = a / 2;
        }
        else
        {
            if (b % 2 == 0)
                ans += b / 2;
            else
                ans += (b / 2) + 1;

            b = b / 2;
        }
    }

    return ans;
}

int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        
        cout<<solution(a, b)<<endl;
    }
}