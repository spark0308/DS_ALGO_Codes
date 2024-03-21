#include<bits/stdc++.h>
using namespace std;

int maxStrength(int n, vector<int> arr){
    vector<int> dp(n);
    dp[0] = arr[0];
    sort(arr.begin(), arr.end());
    
    int max = 0;

    for(int i=0; i<n; i++){
        int temp = arr[i] * (n-i);
        if(temp > max) max = temp;
    }

    return max;
}

int main(){
    int t;
    cin>>t;
    
    while (t--)
    {
        /* code */
        int n;
        cin>>n;
        vector<int> arr(n);
        for(auto &x: arr){
            cin>>x;
        }

        cout<<maxStrength(n, arr)<<endl;
    }
}
    