#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        int sum = 0;
        while(n > 0){
            sum += n%2;
            n = n/2;
        }

        if(sum%2 == 0) cout<<"EVEN";
        else cout<<"ODD";
    }
    
}