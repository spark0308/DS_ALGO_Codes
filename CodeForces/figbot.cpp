#include <bits/stdc++.h>
using namespace std;

string solution(int N, int X, int Y, string S)
{
    vector<int> euDistances;

    int initX = 0;
    int initY = 0;

    euDistances.push_back(X + Y);
    for (auto x : S)
    {
        if (x == 'L')
        {
            initX -= 1;
            int temp = abs(X - initX) + abs(Y - initY);
            euDistances.push_back(temp);
        }
        else if (x == 'R')
        {
            initX += 1;
            int temp = abs(X - initX) + abs(Y - initY);
            euDistances.push_back(temp);
        }
        else if (x == 'U')
        {
            initY += 1;
            int temp = abs(X - initX) + abs(Y - initY);
            euDistances.push_back(temp);
        }
        else if (x == 'D')
        {
            initY -= 1;
            int temp = abs(X - initX) + abs(Y - initY);
            euDistances.push_back(temp);
        }
    }

    for (int i = 1; i <= N; i++)
    {
        if(euDistances[i] == i) return "YES";
        if(euDistances[i] < i){
            int temp = i-euDistances[i];
            if(temp%2 == 0) return "YES";
        }
    }

    return "NO";
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x, y;
        string s;
        cin >> n >> x >> y;
        cin >> s;

        cout<<solution(n, x, y, s)<<endl;
    }
}