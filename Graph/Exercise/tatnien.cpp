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
typedef vector<pi64> vpi64;
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
	int n, m, s;
	
	cin >> n >> m >> s;
	--s;

	vector<pair<int, int>> G[n + 3];
	forn(i, m) {
		int u, v, w;

		cin >> u >> v >> w;
		--u, --v;
		G[u].pb({v, w});
		G[v].pb({u, w});
	}
	
	vi d(n + 3, INT_MAX), mark(n + 3, 0);
	function <void(int)> dijkstra = [&] (int s) {
		d[s] = 0;
		priority_queue<pi64, vpi64, greater<pi64>> pq;
		pq.push({0, s});

	  	while (!pq.empty()) {
	  		int u = pq.top().se;
	  		pq.pop();
	  		if (mark[u]) continue;
	  		mark[u] = 1;

	  		forn(i, G[u].size()) {
	  			int v = G[u][i].fi;
	  			int w = G[u][i].se;

	  			if (d[v] > d[u] + w) {
	  				d[v] = d[u] + w;
	  				pq.push({d[v], v});
	  			}
	  		}
	  	}
	};

	dijkstra(s);

	i64 ans = 0;
	forn(i, n) {
		maxi(ans, 1LL * d[i]);
	}

	cout << ans * 2 << endl;

#ifdef RICARDO
	cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}	