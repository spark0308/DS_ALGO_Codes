#include<bits/stdc++.h>
using namespace std;

bool minSubsetDifference(vector<int> arr, int n){
    int total = 0;
    for(int i=0; i<n; i++) total+=arr[i];
    int s = total/2;
    
    vector<bool> prev(s+1, 0);
    vector<bool> curr(s+1, 0);

    prev[0] = curr[0] = true;
    prev[arr[0]] = true;

    for(int i=1; i<n; i++){
        for(int j=1; j<=s; j++){
            int notTake = prev[j];
            int take = false;
            if(j >= arr[i])take = prev[j-arr[i]];
            curr[j] = notTake || take;
        }
        prev = curr;
    }
    
    for(int i=s; i>=0; i--){
        if(prev[i]){
            return (total-(2*i));
        }
    }
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(auto &x: arr){
        cin>>x;
    }

    cout<<minSubsetDifference(arr, n)<<endl;
}