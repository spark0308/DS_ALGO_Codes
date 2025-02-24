#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
        void dfs(string tiles, string ans, set<string> &ansSet, int n){
            ansSet.insert(ans);
            if(n == 0) return;
            
            for(int i=0; i<n; i++){
                dfs(tiles.substr(0,i) + tiles.substr(i+1), ans + tiles[i], ansSet, n-1);
            }
        }

        int numTilePossibilities(string tiles){
            set<string> ansSet;
            dfs(tiles, "", ansSet, tiles.size());
            return ansSet.size()-1;
        }
};

int main(){
    Solution s;
    string tiles;
    cin>>tiles;
    cout << s.numTilePossibilities(tiles) << endl;
    return 0;
}