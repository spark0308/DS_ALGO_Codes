#include<bits/stdc++.h>
using namespace std;
#define ll long long

string solveOR(int k, string a, string b){
    string res = "";
    for(int i=0; i<k; i++){
        if(a[i] == '1' || b[i] == '1') res += "1";
        else res += "0";
    }
    return res;
}

int binToInt(int k, string res)
{
    int ans =0;
    for(int i=k-1, j=-1; i>=0; i--, j++){
        if(j== -1 && res[i] == '1') ans += 1;
        if(res[i] == '1') ans += (1 * (2<<j));
    }

    return ans;
}

void permutations(int i, int temp, int n, int k, vector<string> a, set<int> &ans){
    if(i == n){
        ans.insert(temp);
        return;
    }

    permutations(i+1, temp | binToInt(k, a[i]), n, k, a, ans);
    permutations(i+1, temp, n, k, a, ans);
}

set<int> findAllOrs(int n, int k, vector<string> a){
    set<int> ans;
    permutations(0, 0, n, k, a, ans);

    return ans;
}

string solution(int n, int k, vector<string> a){
    set<int> allOrs = findAllOrs(n, k, a);

    for(int i = 1; i<(2<<k); i++){
        if(allOrs.find(i) == allOrs.end()) return "NO";
    }

    return "YES";
}

int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n, k;
        cin>>n>>k;

        vector<string> a(n);

        for(int i=0; i<n; i++) cin>>a[i];

        cout<<solution(n, k, a);
    }
}