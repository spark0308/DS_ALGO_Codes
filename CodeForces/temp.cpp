#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	long long t;
	cin>>t;
	while(t--){
	    long long n;
	    cin>>n;
	    std::vector<long long> A(n);
	    
	    for(auto &x: A) cin>>x;
	    
	    map<long long, long long> mp;
	    for(auto x: A){
	        mp[x]++;
	    }
	    
	    long long minCost = INT_MAX;
	    for(auto x: mp){
            long long temp = x.first * (n - x.second);

            if(temp < minCost) minCost = temp;
        }
        long long temp = 1 * (n - mp[1]);
        cout<<min(minCost, temp)<<endl;
	}

}
