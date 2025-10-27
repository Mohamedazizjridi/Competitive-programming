#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <class T>
using ordered_set = tree<T, null_type, less<T>,rb_tree_tag, tree_order_statistics_node_update>;
    #define int long long
    #define XTRABYTE ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<setiosflags(ios::fixed)<<setprecision(15);
    using ll = long long;
    using db = long double; // or double if tight TL
    using str = string;
    using pi = pair<int,int>;
    #define mp make_pair
    #define f first
    #define s second
    #define tcT template<class T
    tcT> using V = vector<T>;
    tcT, size_t SZ> using AR = array<T,SZ>;
    using vi = V<int>;
    using vb = V<bool>;
    using vpi = V<pi>;
    #define sz(x) int((x).size())
    #define all(x) begin(x), end(x)
    #define sor(x) sort(all(x))
    #define allr(x) rbegin(x), rend(x)
    #define rsz resize
    #define pb push_back
    #define ft front()
    #define bk back()
    #define FOR(i,a,b) for (int i = (a); i < (b); ++i)
    #define F0· R(i,a) FOR(i,0· ,a)
    #define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
    #define R0· F(i,a) ROF(i,0· ,a)
    #define rep(a) F0· R(_,a)
    #define each(a,x) for (auto& a: x)

    void _print(int x) { cerr << x; }
    void _print(unsigned long long x) { cerr << x; }
    void _print(char x) { cerr << '\'' << x << '\''; }
    void _print(const string &x) { cerr << '\"' << x << '\"'; }
    void _print(bool x) { cerr << (x ? "true" : "false"); }
    void solve() {
         int n, m;
        cin >> n >> m;
        vector<string> grid(n);
        for (int i = 0; i < n; i++) cin >> grid[i];
        queue<pair<int,int>> q;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '*') {
                    q.push({i, j});
                }
            }
        }
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            int nx = x + 1;
            if (nx < n && grid[nx][y] == '.') {
                swap(grid[x][y], grid[nx][y]);
                q.push({nx, y});
            }
        }

        for (auto &row : grid)
            cout << row << "\n";
    
    cout<<endl;
    }
    signed main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    XTRABYTE;
    int _;
    _=1; 
    cin>>_;
    while(_--)
    {
    solve();
    }
    return 0;
    }