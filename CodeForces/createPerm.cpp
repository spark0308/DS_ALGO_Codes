#include <bits/stdc++.h>
using namespace std;

void solution(int n){
    vector<int> ans(n);
    int value = (n%2 == 0) ? n/2 : n/2 + 1;
    for(int i=1, j=0; i<= value; i++, j+=2){
        ans[j]=i;
    }
    for(int i=value+1, j=1; i<=n; i++, j+=2){
        ans[j]=i;
    }

    for(auto x: ans)cout<<x<<" ";
    cout<<endl;
}

int main() {
	int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;

        solution(n);
    }
    

}
