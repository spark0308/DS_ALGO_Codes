#include<bits/stdc++.h>
using namespace std;

int main(){
    int x, y, t;
    cin>>t;
    while(t--){
        cin>>x>>y;

        int kilos = x*5;
        if(kilos >= y){
            cout<<"Yes\n";
        }
        else{
            cout<<"No\n";
        }
    }
}