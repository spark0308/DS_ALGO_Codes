#include <bits/stdc++.h>
using namespace std;

#define ll long long

bool canCrossWell(int a, int b, int k, int h){
    int startPosition = 0;
    for(int i = 0; i < k; i++){
        startPosition += a;
        if(startPosition >= h) return true;
        startPosition -= b;
    }
    return false;
}

ll solution(int n, int k, int h)
{
    int ans = 0;
    for(int a = 1; a<= n; a++){
        for(int b = 1; b <= n; b++){
            if(canCrossWell(a, b, k, h)){
                cout<<"("<<a<<","<<b<<"), ";
                ans++;
            }
        }
        cout<<endl;
    }
    return ans;
}

int main()
{

    int n, k, h;
    cin >> n; // a & b cannot be greater than 'n';
    cin >> k; // frog has to climb wall in 'k' seconds
    cin >> h; // well has height of 'h' units;

    cout << solution(n, k, h) << endl;
}