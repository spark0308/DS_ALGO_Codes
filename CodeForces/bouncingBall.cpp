#include <bits/stdc++.h>
using namespace std;

int solution(int n, vector<int> wallHeight){
    int left = 0;
    int right = 0;
    int ans = 0;

    for(auto x: wallHeight) right += x;

    for(auto x: wallHeight){
        if(x != 0){
            left += x;
            right -= x;
        }
        else{
            if((left-right) == 0 || (left-right) == 1) ans++;
            if((right-left) == 0 || (right-left) == 1) ans++;
        }
    }

    return ans;
}

int main() {
	int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        vector<int> wallHeight(n);

        for(int i=0; i<n; i++){
            cin>>wallHeight[i];
        }

        cout<<solution(n, wallHeight)<<endl;
    }
    

}
