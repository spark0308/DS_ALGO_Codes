#include<bits/stdc++.h>
using namespace std;

vector<int> * createGraph(int n, int m){
    vector<int> *adj = new vector<int>[n+1];
    for(int i=0; i<m; i++) {
        int u, v;
        cin>> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    return adj;
}

vector<int> bfsOfGraph(int V, vector<int> adj[]){
    int vis[V] = {0};
    vis[0] = 1;
    queue<int> q;
    q.push(0);
    vector<int> bfs;
    while (!q.empty())
    {
        int node = q.front();
        cout<<node<<endl;
        q.pop();
        bfs.push_back(node);

        for(auto it : adj[node]){
            if(!vis[it]) {
                vis[it] = 1;
                q.push(it);
            }
        }
    }
    
    return bfs;
    
}

int main(){
    int n, m;
    cin>>n>>m;
    vector<int>  *adj;
    adj = createGraph(n, m);

    vector<int> bfs = bfsOfGraph(n, adj);

    for(auto x: bfs){
        cout<<x<<" ";
    }
    cout<<endl;
}