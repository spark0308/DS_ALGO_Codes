#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        vector<long> arr(n);
        //vector<int> prefixSum(n, 0);
        for(auto &x: arr){
            cin>>x;
        }
        long sum = arr[0];
        long highest = arr[0] * 2;
        for(int i=1; i<n; i++){
            long temp = sum + (arr[i]*2);
            sum += arr[i];
            if(temp > highest) highest = temp; 
        }

        cout<<highest<<endl;
    }

}