#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve() {
  int n;cin>>n;
  int m;cin>>m;
  vector<vector<int>>edge(n);
  vector<int>indegree(n);
  for(int i=0;i<m;i++){
    ll a,b;cin>>a>>b;
    a--;b--;
    edge[a].push_back(b);
    indegree[b]++;
  }
  vector<bool>visited(n,false);
  queue<int>q;
  for(int i=0;i<n;i++){
    if(indegree[i]==0) q.push(i);
  }
  int idx=0;
  vector<int>topo(n);
  while(!q.empty()){
    auto e =q.front();
    q.pop();
    for(auto child : edge[e]){
      indegree[child]--;
      if(indegree[child]==0){
        q.push(child);
      }
    }
    topo[idx++]=e;
  }
  // DP on DAG 
    vector<int> dp(n, -1);
    vector<int> pred(n, -1);
    dp[0] = 1; // starting node
    for (int i = 0; i < n; i++) {
        int u = topo[i];
        if (dp[u] == -1) continue; // skip nodes not reachable from 1
        for (int v : edge[u]) {
            if (dp[u] + 1 > dp[v]) {
                dp[v] = dp[u] + 1;
                pred[v] = u;
            }
        }
    }
    if(dp[n-1]==-1){
      cout<<"IMPOSSIBLE"<<endl;
      return;
    }
    // answer: dp[n-1]
    cout << dp[n-1] << endl;
    
    // reconstruct path
    vector<int> path;
    for (int cur = n-1; cur != -1; cur = pred[cur])
        path.push_back(cur + 1);
    reverse(path.begin(), path.end());
    for (int x : path) cout << x << " ";
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
