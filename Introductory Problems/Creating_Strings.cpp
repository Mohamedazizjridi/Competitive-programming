 #include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define x27pert              \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);             \
    cout << setiosflags(ios::fixed) << setprecision(15);
using ll = long long;
void solve() {
  string s;
  cin>>s;
  sort(all(s));
  vector<string>d;
  do {
	d.pb(s);
} 
while (next_permutation(s.begin(), s.end()));
cout<<d.size()<<endl;
for(auto e : d)
{
  cout<<e<<endl;
}
}
signed main()
{
    x27pert;
    int _;
    _ = 1;
   // cin >> _;
 
    while (_--)
    {
        solve();
    }
    return 0;
}
