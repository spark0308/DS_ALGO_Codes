#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n, m;
    cin >> n >> m;
    vector<vector<pair<ll, ll>>> graph(n);
    vector<ll> dp(n, 1ll), indegree(n), outdegree(n);
    for(int i = 0; i < m; ++i){
        ll x, y, w;
        cin >> x >> y >> w;
        --x, --y;
        graph[y].push_back({x, w});
        ++indegree[x];
        ++outdegree[y];
    }
    priority_queue<pair<ll, ll>> q;
    for(int i = 0; i < n; ++i)
    {
        q.push({-indegree[i], i});
    }
    ll ans = 0;
    while(q.size())
    {
        int indu, u;
        tie(indu, u) = q.top();
        q.pop();
        if(indu == 0)
        {
            ans += dp[u];
            for(auto x : graph[u])
            {
                dp[x.first] = max(dp[x.first], dp[u] +  x.second);
                --indegree[x.first];
                q.push({-indegree[x.first], x.first});
            }
        }
    }
    cout << ans;
    return 0;
}