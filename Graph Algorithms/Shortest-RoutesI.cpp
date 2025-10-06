#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve() {
  int n,m;cin>>n>>m;
  vector<vector<pair<int,int>>> edge(n);
  for(int i=0;i<m;i++){
    int u,v;cin>>u>>v;
    int w;cin>>w;
    u--;v--;
    edge[u].push_back({v,w});
    edge[v].push_back({u,w});
  }
  vector<bool>visited(n,false);
  priority_queue<pair<int,int>>pq;
  vector<int>dist(n,INT_MAX);
  pq.push({0,0});
  dist[0]=0;
  while(!pq.empty()){
    auto[w,c]=pq.top();
    pq.pop();
    if(visited[c]) continue;
    visited[c]=true;
    for(auto [e,x] :  edge[c]){
      if(dist[c]+x<dist[e]){
        dist[e]=dist[c]+x;
        pq.push({-dist[e],e});
      }
    }
  }
  for(auto e : dist){
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
