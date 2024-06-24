#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while (t--)
    {
        /* code */
        long long n, k, x;
        cin>>n>>k>>x;

        long long ans = static_cast<int>(log2(x)) + 1;

        //cout<<ans<<endl;

        if(k <= ans) cout<<"Yes\n";
        else cout<<"No\n";
    }
    
}