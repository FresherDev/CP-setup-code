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
typedef unsigned long long ui64;
typedef pair<i64, ui64> pui64;
typedef vector<ui64> vui64;
typedef vector<pui64> vpui64;
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
	int n, m;	

	cin >> n >> m;
	int s = 0, f = n - 1; 

    vector<pair<int, int>> G[n];        
	vi mark(n + 5, 0);

	forn(i, m) {
		int u, v;
		int w;

		cin >> u >> v >> w;
		--u, --v;

		G[u].pb(mp(v, w));
		G[v].pb(mp(u, w));        	
	}

	vui64 d(n + 5,  ULLONG_MAX);
	vi par(n + 5);
	stack<int> ans;    
	function <void(int, int)> print = [&] (int s, int f) {
	  	while (f != s) {
	  		ans.push(f);
	  		f = par[f];
	  	}	
	  	ans.push(s);
	};

	function <void(int, int)> dijkstra = [&] (int s, int f) {
	  	priority_queue<pi64, vpi64, greater<pi64>> pq;
	  	d[s] = 0;
	  	pq.push(mp(0, s));

	  	while (!pq.empty()) {
	  		int u = pq.top().se;
	  		pq.pop();
	  		if (mark[u]) continue;
	  		if (u == f) break;

	  		mark[u] = 1;
	  		forn(i, G[u].size()) {
	  			int v = G[u][i].fi;
	  			i64 w = G[u][i].se;

	  			if (d[v] > d[u] + w) {
	  				d[v] = d[u] + w;
	  				par[v] = u;
	  				pq.push(mp(d[v], v));
	  			}
	  		}
	  	}
	};

	dijkstra(s, f);
//	bug(d[f]);
	if (d[f] == ULLONG_MAX) cout << -1 << endl;
	else {
		print(s, f);
		while(!ans.empty()) {
			cout << ans.top() + 1 << " ";
			ans.pop();
		}	
	}

#ifdef RICARDO
	cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}       