#include<bits/stdc++.h>
// LOngest path + check is there an infinte score 
using namespace std;
using ll = long long;
using ld = long double;
void solve() {
    int n, m;
    cin >> n >> m;
    vector<tuple<ll,ll,ll>> edges;
    vector<vector<pair<ll,ll>>> adj(n);
    vector<vector<int>> adj_nodes(n);
    for(int i=0;i<m;i++){
        ll a,b,w; cin >> a >> b >> w;
        a--; b--;
        adj[a].pb({b,-w});
        edges.push_back({a,b,-w});
        adj_nodes[a].push_back(b);
    }
    
    const ll INF = LLONG_MAX/4;
    vector<ll> distance(n, INF);
    distance[0] = 0;
    for(int i=0;i<n-1;i++){
        bool any = false;
        for(auto [a,b,w] : edges){
            if(distance[a] != INF && distance[a] + w < distance[b]){
                distance[b] = distance[a] + w;
                any = true;
            }
        }
        if(!any) break; // optimsation 
    }

    vector<char> affected(n, false);
    queue<int> q;
    for(auto &t : edges){
        ll a,b,w; tie(a,b,w) = t;
        if(distance[a] != INF && distance[a] + w < distance[b]){
            if(!affected[b]){
                affected[b] = true;
                q.push(b);
            }
        }
    }

    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int v : adj_nodes[u]){
            if(!affected[v]){
                affected[v] = true;
                q.push(v);
            }
        }
    }

    if(affected[n-1]){
        cout << -1 << "\n";
        return;
    }
    if(distance[n-1] == INF){
        cout << - (ll)0 << "\n";
    } else {
        cout << -distance[n-1] << "\n";
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
