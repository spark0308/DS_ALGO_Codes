#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll solution(int n, int k, int h){
    int stepInTime = ceil(h/k);
    stepInTime = max(1, stepInTime);

    //cout<<"StepInTime: "<<stepInTime<<endl;

    if(stepInTime >= n) return 0;

    int jumpStart = stepInTime + 1;
    //cout<<"JumpStart: "<<jumpStart<<endl;
    ll ans = 0;
    ll x = min(h-stepInTime-1, n - stepInTime + 1);

    //cout<<x<<endl;
    ans = (x * (x +1 ))/2;

    ll y = max(0, (n - h + 1));
    //cout<<y<<endl;
    ans += y * n;

    return ans;
}

int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n, k, h;
        cin>>n; //a & b cannot be greater than 'n';
        cin>>k; //frog has to climb wall in 'k' seconds
        cin>>h; //well has height of 'h' units;

        cout<<solution(n, k, h)<<endl;
    }
    
}