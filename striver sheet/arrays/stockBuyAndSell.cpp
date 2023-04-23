#include<bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> prices){
    int lowest = prices[0];
    int maxProfit = 0;

    for(int x: prices){
        if(lowest > x)
            lowest = x;
        if(x - lowest > maxProfit)
            maxProfit = x - lowest;
    }

    return maxProfit;
}

int main(){
    int n;
    cin>>n;
    vector<int> prices(n);

    for(auto &x: prices){
        cin>>x;
    }
    
    cout<<maxProfit(prices)<<endl;
}