#include<iostream>
#include<vector>
using namespace std;

int solution(int n, vector<int> arr){
    int a, b;
    b = arr[0];
    int ans = b;
    for(int i=1; i<n; i++){
        if(arr[i] > b){
            ans += (arr[i] - b);
            ans += arr[i];
            b = arr[i];
        }
        else{
            ans += arr[i];
        }
    }
    
    ans += arr[0];

    return ans;
}

int main(){
    int t, n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> arr = vector<int>(n-1);
        for(int i=0; i<n-1; i++){
            cin>>arr[i];
        }

        cout<<solution(n-1, arr)<<endl;
    }
    return 0;
}
