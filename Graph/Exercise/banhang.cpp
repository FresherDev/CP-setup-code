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

const int N = 500;
int d[N][N];

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

	vector<pair<int, int>> G[n + 5];
	forn(i, m) {
		int u, v, w;

		cin >> u >> v >> w;
		--u, --v;
		G[u].pb({v, w});
	}
	
	vi mark(n + 3, 0);

	forn(i, n) {
		forn(j, n) {
			if (i != j) d[i][j] = INT_MAX;
		}
	}

	function <void(int)> dijkstra = [&] (int s) {
	  	priority_queue<pi64, vpi64, greater<pi64>> pq;
	  	d[s][s] = 0;
	  	pq.push({0, s});

	  	while (!pq.empty()) {
	  		int u = pq.top().se;
	  		pq.pop();
	  		if (mark[u]) continue;
	  		
	  		mark[u] = 1;
	  		forn(i, G[u].size()) {
	  			int v = G[u][i].fi;
	  			int w = G[u][i].se;

	  			if (d[s][v] > d[s][u] + w) {
	  				d[s][v] = d[s][u] + w;
	  				pq.push({d[s][v], v});
	  			}
	  		}
	  	}
	};

	forn(i, n) {
		fill(all(mark), 0);
		dijkstra(i);
	}

	i64 ans = 0;
	forn(i, n) {
		ans = max(ans, 1LL * (d[s][i] + d[i][s]));
	}

	cout << ans << endl;

	ans = LLONG_MAX;
	int res = 0, tmp = 0;

	forn(i, n) {
		forn(j, n) {
			tmp += d[i][j] + d[j][i];
		}
                 
		if (tmp <= ans) {
			ans = tmp; 
			res = i;
		}

		tmp = 0;
	}

	cout << res + 1 << endl;
#ifdef RICARDO
	cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}	