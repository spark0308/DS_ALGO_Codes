#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        vector<long long> arr(n);
        vector<int> sets(n, 0);
        for(int i = 0; i<n; i++){
            int x;
            cin>>x;
            if(x == (i+1)) sets[i] = 1;
        }

        int ans = 0;
        for(int i=0; i<n; i++){
            if(sets[i] == 1){
                ans +=1;
                if(sets[i+1] == 1) i++;
            }
        }
        cout<<ans<<endl;

    }
    
}