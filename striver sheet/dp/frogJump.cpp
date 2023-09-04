#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll calculate_mimimum_reqired_energy(ll steps, vector<ll> heights){
    ll dp[steps];

    dp[0] = 0;
    dp[1] = heights[1];

    for(ll i=2; i<steps; i++){
        ll energy1 = dp[i-1] + abs(heights[i] - heights[i-1]);
        ll energy2 = dp[i-2] + abs(heights[i] - heights[i-2]);
        dp[i] = min(energy1, energy2);
    }

    return dp[steps-1];
}

int main(){
    ll steps;
    cin >> steps;
    vector<ll> height(steps);

    for(ll i = 0; i<steps; i++){
        cin>> height[i];
    }

    ll ans = calculate_mimimum_reqired_energy(steps, height);

    cout<< ans << endl;
}