#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll calculate_mimimum_reqired_energy(ll steps, vector<ll> heights){
    //ll dp[steps];

    ll prev = 0;
    ll prev2 = heights[1];

    for(ll i=2; i<steps; i++){
        ll energy1 = prev + abs(heights[i] - heights[i-1]);
        ll energy2 = prev2 + abs(heights[i] - heights[i-2]);
        ll curr = min(energy1, energy2);

        prev2 = prev;
        prev = curr;
    }

    return prev;
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