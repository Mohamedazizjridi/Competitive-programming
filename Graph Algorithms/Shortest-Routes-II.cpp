#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve() {
  int n;cin>>n;
  int m;cin>>m;
  int q;cin>>q;
  vector<vector<ll>>dist(n,vector<ll>(n,LLONG_MAX/2));
  for(int i=0;i<m;i++){
    ll a,b,w;cin>>a>>b>>w;
    a--;b--;
    dist[a][b]=min(dist[a][b],w);
    dist[b][a]=min(dist[b][a],w);
  }
  for(int i=0;i<n;i++){
    dist[i][i]=0;
  }
  for(int k=0;k<n;k++){
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
      }
    }
  }
  while(q--){
    int a,b;cin>>a>>b;
    a--;b--;
    if(dist[a][b]>=LLONG_MAX/2){
      cout<<-1<<endl;
    }
    else{
      cout<<dist[a][b]<<endl;
    }
  }
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
