#include<bits/stdc++.h>
using namespace std;

vector<int> safeStates(int V, vector<int> adj[]){
    vector<int> adjRev[V];

    for(int i=0; i<V; i++){
        for(auto it: adj[i]){
            adjRev[it].push_back(i);
        }
    }
    
    int inDegree[V] = {0};

    for(int i=0; i<V; i++){
        for(auto it: adjRev[i]){
            inDegree[it]++;
        }
    }

    queue<int> q;
    for(int i=0; i<V; i++){
        if(inDegree[i] == 0){
            q.push(i);
        }
    }

    vector<int> safeStates;

    while (!q.empty())
    {
        /* code */
        int node = q.front();
        q.pop();

        safeStates.push_back(node);

        for(auto it: adjRev[node]){
            inDegree[it]--;
            if(inDegree[it] == 0){
                q.push(it);
            }
        }
    }
    
    sort(safeStates.begin(), safeStates.end());

    return safeStates;
}

int main()
{
    int n, m;
    cin>>n>>m;
    vector<int> adj[n];

    for(int i=0; i<m; i++){
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
    }

    vector<int> ans = safeStates(n, adj);

    for(auto x: ans){
        cout<<x<<" ";
    }
    cout<<endl;
}