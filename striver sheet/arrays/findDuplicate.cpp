#include<bits/stdc++.h>
using namespace std;

int findDuplicateFreqMethod(vector<int> arr, int n){

    vector<int> freq(n+1, 0);
    
    for(auto x: arr){
        freq[x]++;
    }

    for(int i=0; i<=n; i++){
        if(freq[i] > 1)
            return i;
    }

    return 0;
}

int findDuplicateDetectCycleMethod(vector<int> arr, int n){
    int slow=arr[0], fast=arr[0];

    do{
        slow = arr[slow];
        fast = arr[arr[fast]];
    }
    while(slow != fast);

    fast = arr[0];

    while(slow != fast){
        slow = arr[slow];
        fast = arr[fast];
    }

    return slow;
}

int main(){
    int n;
    cin>>n;

    vector<int> arr(n);

    for(auto &x: arr){
        cin >> x;
    }

    //solution Function;
    int res = findDuplicateDetectCycleMethod(arr, n);

    cout<<res<<endl;

    return 0;
}