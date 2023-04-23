#include<bits/stdc++.h>
using namespace std;

void mergeArray(vector<int> arr1, vector<int> arr2, int n, int m){
    int gap = (n+m)/2;

    while (gap > 0)
    {
        int i=0, j = gap;
        while(j < (n+m-1)){
            if(j < n && arr1[i] > arr1[j])
                swap(arr1[i], arr1[j]);
            else if(j > n && arr1[i] > arr2[j-n])
                swap(arr1[i], arr2[j-n]);
            else if(j > n && i > n && arr2[i-n] > arr2[j-n])
                swap(arr2[i-n], arr2[j-n]);
            
            i++; j++;
        }
        gap =  gap/2;
    }

    for(auto x: arr1)
        cout<<x<<" ";
    
    for(auto x: arr2)
        cout<<x<<" ";
    cout<<endl;
    
}

int main(){
    int n, m;
    cin>>n>>m;

    vector<int> arr1(n);
    vector<int> arr2(m);

    for(auto &x: arr1){
        cin>>x;
    }

    for(auto &x: arr2){
        cin>>x;
    }

    mergeArray(arr1, arr2, n, m);

    return 0;
}