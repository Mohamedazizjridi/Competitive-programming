// Graph coloring and check bipartied Graph : no Odd cycle 
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

void solve() {
  int n,m;cin>>n>>m;
  vector<vector<int>> edge(n);
  for(int i=0;i<m;i++){
    int u,v;cin>>u>>v;
    u--;v--;
    edge[u].push_back(v);
    edge[v].push_back(u);
  }
  vector<bool>visited(n,false);
  vector<int>group(n,0);
  stack<int>ss;
  for(int i=0;i<n;i++){
    if(!visited[i]){
      ss.push(i);
      group[i]=1;
      while(!ss.empty()){
        auto e =ss.top();
        visited[e]=true;
        ss.pop();
        for(auto f : edge[e]){
          if(!visited[f]){
            if(group[f]==0){
              group[f]=3-group[e];
              visited[f]=true;
              ss.push(f);
            }
          }
          else{
            if(group[f]==group[e]){
                cout<<"IMPOSSIBLE"<<endl;
                return;
            }
          }
        }
      }
    }
  }
  for(auto e : group){
    cout<<e<<" ";
  }
  cout<<endl;
}
signed main()
{
    int _;
    _ = 1;
   // cin >> _;
 
    while (_--)
    {
        solve();
    }
    return 0;
}
