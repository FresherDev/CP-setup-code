#include <bits/stdc++.h>

using namespace std;

#define Cerr cerr << "\nTest: "
#define endl "\n"
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define fastio { ios_base::sync_with_stdio(false), cin.tie(NULL); }
#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define for1(i, n) for(int i = 1; i <= (int)(n); i++)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); i++)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)

#ifdef RICARDO
	#define bug(x) cerr << #x << " = " << (x) << endl;
	#define block if(1)
#else
	#define bug(x) "IDINGO"
	#define block if(0)
#endif


template<class T> bool mini(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool maxi(T &a, T b) { return a < b ? (a = b, true) : false; }

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;
typedef vector<vi> vvi;
typedef long long i64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;
typedef pair<i64, i64> pi64;
typedef double ld;

//=================================================CODE=================================================//

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.precision(10);
	cout << fixed;
#ifdef RICARDO		
	freopen("i", "r", stdin);
#endif
	int n, m, s, t;	

	cin >> n >> m >> s >> t;
	--s, --t;

	vvi G(n);
	forn(i, m) {
		int u, v;
		cin >> u >> v;
		--u, --v;

		G[u].pb(v);
		G[v].pb(u);
	}	

	vi visit(n, 0), d(n, 0);
	int dem = 0;
	function <void(int)> dfs = [&] (int s) {
	  	visit[s] = 1;
	  	++dem; d[s] = dem;

	  	for (int v : G[s]) {
	  		if (!visit[v]) {
	  			dfs(v);
	  		}
	  	}
	};

	dfs(s);
	if (d[t]) cout << d[t] << endl;
	else cout << "-1" << endl; 
#ifdef RICARDO
	cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}