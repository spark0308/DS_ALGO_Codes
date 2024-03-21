#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        string s;
        int ans =0;

        cin>>n;
        cin>>s;

        for(int i=0; i<=n-3;){
            //cout<<i<<" ";
            bool sameLoop = false;
            if(s[i] == 'm' && s[i+1] == 'a' && s[i+2] == 'p'){
                ans += 1;
                i = i+2;
                //cout<<"MAP\n";
                sameLoop = true;
            }
            if(s[i] == 'p' && s[i+1] == 'i' && s[i+2] == 'e'){
                //cout<<"PIE\n";
                if(!sameLoop) ans += 1;
                sameLoop = true;
                i = i+3;
            }

            if(!sameLoop) i++;
        }
        //cout<<endl;
        cout<<ans<<endl;
    }
    
}