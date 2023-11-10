#include<bits/stdc++.h>
using namespace std;

bool allSubSet(int i, int k, int n, vector<int> arr){
    if(k == 0) return true;
    if(i == 0) return (arr[0] == k);

    int notTake = allSubSet(i-1, k, n, arr);
    int take = false;
    if(k >= arr[i]) allSubSet(i-1, k-arr[i], n, arr);

    return notTake || take;
}

bool canPartition(vector<int> arr, int n){
    int total = 0;
    for(int i=0; i<n; i++) total+=arr[i];

	if(total%2 == 1) return false;
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

    return prev[s];
}

int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }
    }
    
}