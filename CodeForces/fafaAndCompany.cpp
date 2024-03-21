#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int ans = 1;
    for(int i=2; i<=sqrt(n); i++){
        if(n%i == 0){
            if(n/i == i) ans++;
            else ans += 2;
        }
    }

    cout<<ans;
}