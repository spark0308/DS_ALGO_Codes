#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ll t;
    cin>>t;
    while (t--)
    {
        /* code */
        string matching;
        cin>>matching;

        int ans = 1;
        int ques = 0;
        for(auto x: matching){
            if(x == '?'){
                ques++;
            }
        }
        
        if(ques == 0){
            if(stoi(matching) == 0)
                ans = 0;
        }
        
        if(matching[0] == '0'){
            ans = 0;
        }
        else if(matching[0] == '?'){
            ans *= 9;
            for(int i=0; i<ques-1; i++)
                ans *= 10;
        }
        else{
            for(int i=0; i<ques; i++)
                ans *= 10;
        }

        cout<<ans<<endl;
    }
    
}