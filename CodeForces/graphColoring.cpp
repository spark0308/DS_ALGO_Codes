#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> createGraph(int nodes, int edges, vector<int> from, vector<int> to){
    vector<vector<int>> graph(nodes+1);

    for(int i=0; i<edges; i++){
        graph[from[i]].push_back(to[i]);
        graph[to[i]].push_back(from[i]);
    }

    return graph;
}

set<int> usedColors(int node, vector<vector<int>> graph, vector<int> coloredNodes){
    queue<int> adjNodes;
    set<int> colors;

    for(auto x: graph[node]){
        adjNodes.push(x);
        colors.insert(coloredNodes[x]);
    }

    while (!adjNodes.empty())
    {
        int temp = adjNodes.front();
        adjNodes.pop();
        
        for(auto x: graph[temp]){
            colors.insert(coloredNodes[x]);
        }
    }
    
    return colors;
}

int travers(int v, int color, int V, int m, vector<vector<int>> graph, vector<int> coloredNodes){
    coloredNodes[v] = color;
    if(v == V){
        // for(int i=1; i<V+1; i++){
        //     cout<<coloredNodes[i]<<" ";
        // }
        // cout<<endl;
        return 1;
    }
    int ans = 0;

    set<int> usedColor = usedColors(v+1, graph, coloredNodes);
    // for(auto x = usedColor.begin(); x != usedColor.end(); x++){
    //     cout<<*x<<" ";
    // }
    // cout<<endl;
    for(int c=0; c<m; c++){
        if(usedColor.find(c) == usedColor.end()){
            ans += travers(v+1, c, V, m, graph, coloredNodes);
        }
    }

    return ans;
}

int allPossibleColors(int m, int nodes, vector<vector<int>> graph){
    vector<int> colors(nodes+1, -1);
    int ans = 0;
    for(int c = 0; c<m; c++){
        ans += travers(1, c, nodes, m, graph, colors);
    }

    return ans;
}

int main(){
    int m, nodes, edges;
    cin>>m>>nodes>>edges;

    vector<int> from(edges);
    vector<int> to(edges);

    for(auto &x: from) cin>>x;
    for(auto &x: to) cin>>x;

    vector<vector<int>> graph = createGraph(nodes, edges, from, to);

    // for(int i=0; i<=nodes; i++){
    //     cout<<i<<": ";
    //     for(auto x: graph[i]) cout<<x<<" ";
    //     cout<<endl;
    // }

    cout<<allPossibleColors(m, nodes, graph)<<endl;
}