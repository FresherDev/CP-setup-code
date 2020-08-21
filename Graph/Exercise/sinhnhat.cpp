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
	int n, d, e;

	cin >> n >> d >> e;

	int s = 2 * n + d + e + 1, t = 2 * n + d + e + 2;
	vvi G(t + 5, vi(t + 5)), c(t + 5, vi(t + 5)), f(t + 5, vi(t + 5, 0)); 
	for1(i, d) {
		G[s].pb(i);
//		G[i].pb(s);
		c[s][i] = 1;
//		c[i][s] = 1;
	}
	for1(i, n) {
		G[d + i].pb(d + n + i);
//		G[d + n + i].pb(d + i);                                                                                   
		c[d + i][d + n + i] = 1;
//		c[d + n + i][d + i] = 1;
	}

	for1(i, n) {
		int tmp, tmp2, k;

		cin >> tmp >> tmp2;
		forn(j, tmp) {
			cin >> k;
			G[k].pb(d + i);
//			G[d + i].pb(k);
			c[k][d + i] = 1;
//			c[d + i][k] = 1;     
		}

		forn(j, tmp2) {
			cin >> k;
			G[d + n + i].pb(d + 2 * n + k);
//			G[d + 2 * n + k].pb(d + n + i);
			c[d + n + i][d + 2 * n + k] = 1;
//			c[d + 2 * n + k][d + n + i] = 1;            		
		}
	}

	for1(i, e) {
		G[d + 2 * n + i].pb(t);
		c[d + 2 * n + i][t] = 1;
	}

//	for1(i, t) {
//		for (int j : G[i]) cout << j << " ";
//		cout << endl;
//	}

	vi trace(t + 5);
	int flow = 0;
	function <void()> inc = [&] () {
	  	int new_flow = INT_MAX, u, v = t;

	  	do {
	  		u = trace[v];
	  		new_flow = min(new_flow, c[u][v] - f[u][v]);
	  		v = u;
	  	} while (v != s);

	  	v = t;
	  	do {
	  		u = trace[v];
	  		f[u][v] += new_flow;
	  		f[v][u] -= new_flow;
	  		v = u;
	  	} while (v != s);

	  	flow += new_flow;
	};

	function <bool()> bfs = [&] () {
	  	fill(all(trace), 0);
	  	trace[s] = t + 5;
	  	queue<int> q;
	  	q.push(s);

	  	while (!q.empty()) {
	  		int u = q.front(); q.pop();

	  		for (int v = 1; v <= t; ++v) {
	  			if (!trace[v] && c[u][v] > f[u][v]) {
	  				trace[v] = u;
	  				if (v == t) return 1;
	  				q.push(v);	
	  			}
	  		}
	  	}

	  	return 0;
	};

	while (bfs()) inc();

	cout << flow << endl;
	
#ifdef RICARDO
	cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}	