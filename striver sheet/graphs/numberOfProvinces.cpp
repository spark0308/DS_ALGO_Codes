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

void dfs(int node, vector<int> adj[], int vis[], vector<int> &ls){
    vis[node] = 1;
    ls.push_back(node);

    for(auto it: adj[node]){
        if(!vis[it]){
            dfs(it, adj, vis, ls);
        }
    }
}

int CountProvince(int V, vector<int> adj[]){
    int vis[V] = {0};
    int start = 0;
    int count = 0;
    vector<int> ls;
    for(int i=0; i<V; i++){
        if(vis[i] != 1){
            count++;
            start = i;
            dfs(i, adj, vis, ls);
        }
    }
    return count;
}

int main(){
    int n, m;
    cin>>n>>m;
    vector<int>  *adj;
    adj = createGraph(n, m);

    cout<<CountProvince(n, adj)<<endl;

}