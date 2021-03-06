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

	cin >> m >> n;
	s = 1, t = n;
	vvi c(n + 2), f(n + 2);
	for1(i, n) {
		c[i].resize(n + 2);
		f[i].resize(n + 2);
	}
	      
	forn(i, m) {
		int u, v, w;

		cin >> u >> v >> w;
		c[u][v] += w;
	}

	vi trace(n + 2);
	function <bool()> bfs = [&] () {
	  	for1(i, n) trace[i] = 0;
	  	queue<int> q;
	  	q.push(s); trace[s] = n + 1;
	  	while (!q.empty()) {
	  		int u = q.front(); q.pop();
	  		for1(v, n) {
	  			if (!trace[v] && c[u][v] > f[u][v]) {
	  				trace[v] = u;
	  				if (v == t) return 1;

	  				q.push(v);
	  			}
	  		}
	  	}

	  	return 0;
	};

	function <void()> inc = [&] () {
		int delta = INT_MAX, u, v = t;
		do {
			u = trace[v];
			delta = min(delta, c[u][v] - f[u][v]);
			v = u;
		} while (v != s);

		v = t;
		do {
			u = trace[v];
			f[u][v] += delta;
			f[v][u] -= delta;
			v = u;
		} while (v != s);
	};

	while(bfs()) inc();

	int flow = 0;
	for1(i, n - 1) if (f[i][n] > 0) flow += f[i][n];

	cout << flow << endl;
#ifdef RICARDO
	cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}