#include<bits/stdc++.h>
using namespace std;

int requiredChocolates(int V, vector<pair<int, int>> adj[]){
    vector<pair<int, int>> adjRev[V];
    int inDegree[V] = {0};
    for(int i=0; i<V; i++){
        for(auto it: adj[i]){
            adjRev[it.first].push_back({i, it.second});
            inDegree[i]++;
        }
    }

    queue<int> q;
    int chocos[V];
    fill(chocos, chocos + V, 1);
    for(int i=0; i<V; i++){
        if(inDegree[i] == 0) q.push(i);
    }

    int ans =0;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        ans += chocos[node];

        for(auto it: adjRev[node]){
            inDegree[it.first]--;
            chocos[it.first] = max(chocos[it.first], chocos[node] + it.second);

            if(inDegree[it.first] == 0){
                q.push(it.first);
            }
        }
    }
    
    return ans;
}

int main(){
    int N, M;
    cin>>N>>M;

    vector<pair<int, int>> wishlist[N];

    for(int i=0; i<M; i++){
        int x, y, m;
        cin>>x>>y>>m;
        wishlist[x-1].push_back({y-1, m});
    }

    int ans = requiredChocolates(N, wishlist);

    cout<<ans<<endl;
}

/*
15 12
1 2 1
4 5 2
5 6 2
6 8 3
7 6 1
8 5 6
5 9 2
9 10 4
10 11 8
11 6 7
12 6 5
13 12 11


output: 6
*/
