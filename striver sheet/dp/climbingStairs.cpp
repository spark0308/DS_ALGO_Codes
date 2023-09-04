#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
     ll number_of_steps;
     cin >> number_of_steps;

     int prev = 1, prev2 = 0;

     for(int i=2; i<=number_of_steps; i++){
        int curr_step = prev + prev2;
        prev2 = prev;
        prev = curr_step;
     }

     cout << prev << endl;
}