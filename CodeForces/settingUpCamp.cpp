#include<bits/stdc++.h>
using namespace std;

int solution(int a, int b, int c){
    int ans = 0;

        ans = b/3;
        int temp = 3 - b%3;
        if(temp != 3){
            if(c < temp) return -1;
        }

        if(temp < 3) ans += 1;
        c -= temp;
        ans += a;
        ans += c/3;
        if(c%2 != 0) ans += 1;

        return ans;
}

int main(){
    int t;
    cin >> t;

    while (t--)
    {
        int a, b, c;
        cin>>a>>b>>c;

        cout<<solution(a, b, c)<<endl;
    }
    
}