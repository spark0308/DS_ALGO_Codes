#include <bits/stdc++.h>
using namespace std;

void solution(vector<int> s){
    vector<int> winningTimes = {0, 1, 1, 2,2,2,2,3,3,3,3,3,3,3,3,4};
    vector<int> ans(16);

    vector<pair<int, int>> skills;

    for(int i=0; i<16; i++){
        skills.push_back({s[i], i});
    }


    sort(skills.begin(), skills.end());

    for(int i=0; i<16; i++){
        ans[skills[i].second] = winningTimes[i];
    }

    for(auto x: ans) cout<<x<<" ";
    cout<<endl;
}

int main() {
	int t;
	cin>>t;
	while(t--){
	    
	    vector<int> s(16);

        for(int i=0; i<16; i++) cin>>s[i];
	    solution(s);
	}

}
