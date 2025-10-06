#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>>d={{-1,0},{0,1},{1,0},{0,-1}};
bool isvalid(int n, int m,int i ,int j,vector<vector<char>>&v,vector<vector<bool>>&visited)
{
  return i<n && i>=0 && j<m && j>=0  && v[i][j]!='#' && !visited[i][j]  ;
}
void solve() {
  int n,m;
  cin>>n>>m;
  vector<vector<char>>grid(n,vector<char>(m));
  set<pair<int,int>>exter;
  queue<pair<int,int>>q;
  pair<int,int>src;
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++)
    {
      cin>>grid[i][j];
    if((grid[i][j]!='#' && grid[i][j]!='M') && i==n-1 || i==0 || j==0 || j==m-1)
    {
      exter.insert({i,j});
      if(grid[i][j]=='A')
      {
        yes;
        cout<<0<<endl;
        return;
      }
    }
    if(grid[i][j]=='A' || grid[i][j]=='M')
    {
     
      if(grid[i][j]=='A')
      {
        src={i,j};
      }
      else{
         q.push({i,j});
      }
    }
    }
   
  }
  q.push(src);
  string dr="URDL";
  vector<vector<bool>>visited(n,vector<bool>(m,false));
 vector<vector<pair<int,int>>> parent(n, vector<pair<int,int>>(m, {-1, -1}));
  vector<vector<int>>dirused(n,vector<int>(m,-1));
  while(!q.empty())
  {
    auto pp=q.front();
    visited[pp.first][pp.second]=true;
    q.pop();
    for(int k=0;k<4;k++)
    {
      int dx=d[k].first+pp.first;
      int dy=d[k].second+pp.second;
     
      if(isvalid(n,m,dx,dy,grid,visited))
      {
       
        if(grid[pp.first][pp.second]=='A' && grid[dx][dy]=='.')
        {
        visited[dx][dy]=true;
        parent[dx][dy]={pp.first,pp.second};
        dirused[dx][dy]=k;
        q.push({dx,dy});
        grid[dx][dy]='A';
        if (exter.find({dx, dy}) != exter.end()) {
                        cout << "YES\n";
                        vector<char> path;
                        pair<int, int> cur = {dx, dy};
                        while (cur != src) {
                            int direction = dirused[cur.first][cur.second];
                            path.push_back(dr[direction]);
                            cur = parent[cur.first][cur.second];
                        }
                        reverse(path.begin(), path.end()); 
                        cout << path.size() << endl;
                        for (char c : path) {
                            cout << c;
                        }
                        cout << endl;
                        return;
                    }
        }
        else if( grid[dx][dy]=='.'){
          visited[dx][dy]=true;
        parent[dx][dy]={pp.first,pp.second};
        dirused[dx][dy]=k;
        q.push({dx,dy});
        grid[dx][dy]='M';
        }
      }
    }
  }
  no;
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
