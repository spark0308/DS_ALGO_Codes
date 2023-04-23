#include<bits/stdc++.h>
using namespace std;

#define ll long long

string solution(int n, string u){
    vector<char> alph;
    vector<int> count;
    int t = 0;
    char temp = u[0];
    u = u + '0';
    string ans = "";
    for(int i=0; i<n+1; i++){
        if(temp == u[i]){
            t++;
        }
        else{
            alph.push_back(temp);
            count.push_back(t);
            temp = u[i];
            t = 1;
        }
    }

    for(int i=0; i<alph.size(); i++){
        if(count[i] < 3){
            for(int j = 0; j<count[i]; j++){
                ans += alph[i];
            }
        }
        else{
            if(count[i]%2){
                ans += alph[i];
            }
            else{
                ans += alph[i];
                ans += alph[i];
            }
        }
    }

    return ans;
}

int main(){
    ll t;
    cin>>t;
    while (t--)
    {
        int n;
        string u, ans = "";
        cin>>n;
        cin>>u;
        
        ans = solution(n, u);

        cout<<ans<<endl;
    }
    
}