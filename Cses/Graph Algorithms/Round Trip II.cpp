// Detect Cycle in Directed Graph 
#include<bits/stdc++.h>
using namespace std;

void solve() {
  int n;cin>>n;
  int m;cin>>m;
  vector<vector<int>>edge(n);
  for(int i=0;i<m;i++){
    ll a,b;cin>>a>>b;
    a--;b--;
    edge[a].push_back(b);
  }
  vector<int>prev(n,-1);
  vector<bool>visited(n,false);
  vector<bool>instack(n,false);
  for(int i=0;i<n;i++){
    if(!visited[i]){
      stack<int>ss;
      ss.push(i);
      while(!ss.empty()){
        int e=ss.top();
        if(!visited[e]){
          visited[e]=true;
          instack[e]=true;
        }
        else{
          instack[e]=false;
          ss.pop();
          continue;
        }
        for(auto f : edge[e]){
          if(!visited[f]){
            ss.push(f);prev[f]=e;
          }
          else if(instack[f]){
            vector<int>cycle;
            cycle.push_back(f);
            int cur=e;
            while(cur!=f){
              cycle.push_back(cur);
              cur=prev[cur];
            }
            cycle.push_back(f);
            reverse(all(cycle));
            cout<<cycle.size()<<endl;
            for(auto g : cycle){
              cout<<g+1<<" ";
            }
            cout<<endl;
            return;
          }
        }
      }
    }
  }
  cout<<"IMPOSSIBLE"<<endl;
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
