#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll solution(vector<ll> arr, ll y){
    ll ans = 0;
    ll arrOr = 0;

    for(auto x: arr){
        arrOr = arrOr | x;
    }

    string binary1 = "";
    string binary2 = "";

    while(arrOr > 0){
        if(arrOr % 2 == 1)
            binary1 = binary1.append("1");
        else
            binary1 = binary1.append("0");
        
        arrOr /= 2;
    }

    while(y > 0){
        if(y % 2 == 1)
            binary2 = binary2.append("1");
        else
            binary2 = binary2.append("0");
        
        y /= 2;
    }

    cout<<binary1<<endl<<binary2<<endl;


    return ans;
    
}

int main(){
    int t;
    cin>>t;
    while(t--){
        ll n, y;
        cin>>n>>y;
        vector<ll> arr(n);
        for(auto &x: arr){
            cin>>x;
        }

        cout<<solution(arr, y)<<endl;
    }
}