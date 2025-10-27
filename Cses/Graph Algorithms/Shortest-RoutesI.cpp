#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
void solve() {
  int n,m;cin>>n>>m;
  vector<vector<pair<ll,ll>>> adj(n);
  for(int i=0;i<m;i++){
    ll u,v;cin>>u>>v;
    ll w;cin>>w;
    u--;v--;
    adj[u].push_back({v,w});
  }
   vector<ll> distance(n, LLONG_MAX);
    vector<bool> processed(n ,false);
    priority_queue<pair<ll, ll>> q;
    distance[0] = 0;
    q.push({0, 0});
    while (!q.empty()) {
        ll a = q.top().second;
        q.pop();
        if (processed[a]) continue;
        processed[a] = true;
        for (auto u : adj[a]) {
            ll b = u.first, w = u.second;
            if (distance[a] + w < distance[b]) {
                distance[b] = distance[a] + w;
                q.push({-distance[b], b});
            }
        }
    }
  for(auto e : distance){
    cout<<e<<" ";
  }
  cout<<endl;
}
signed main()
{
    int _;
    _ = 1;
    while (_--)
    {
        solve();
    }
    return 0;
}
