// Counting Rooms
 #include<bits/stdc++.h>
using namespace std;
using ll = long long;
vector<pair<int,int>>d={{-1,0},{0,1},{1,0},{0,-1}};
bool isvalid(int n, int m,int i ,int j,vector<vector<char>>&v,vector<vector<bool>>&visited)
{
  return i<n && i>=0 && j<m && j>=0  && v[i][j]!='#' && !visited[i][j]  ;
}
void solve() {
  int n,m;cin>>n>>m;
  vector<vector<char>>g(n,vector<char>(m));
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      cin>>g[i][j];
    }
  }
  stack<pair<int,int>>st;
  vector<vector<bool>>visited(n,vector<bool>(m,false));
  ll cnt=0;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      if(isvalid(n,m,i,j,g,visited)){
        st.push({i,j});
        cnt++;
        while(!st.empty()){
          auto [i,j]=st.top();
          visited[i][j]=true;
          st.pop();
          for(auto [dx,dy] :d){
            int x=i+dx;
            int y=dy+j;
            if(isvalid(n,m,x,y,g,visited)){
              st.push({x,y});
            }
          }
        }
      }
    }
  }
  cout<<cnt<<endl;
}
signed main()
{    int _;
    _ = 1;
   // cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}
