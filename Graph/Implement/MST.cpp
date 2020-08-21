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
typedef pair<int, pii> piii;
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
	vi par(n + 3);

	for1(i, n) par[i] = i;

	vector<piii> E;
	forn(i, m) {
		int u, v, w;

		cin >> u >> v >> w;
		E.pb(mp(w, mp(u, v)));
	}
	sort(rall(E));

	function <int(int)> Par = [&] (int u) {
	  	return par[u] == u ? u : par[u] = Par(par[u]);
	};

	function <int(int, int)> dsu = [&] (int u, int v) {
	  	if ((u = Par(u)) == (v = Par(v))) return 0;

	   	return par[u] = v, 1;
	};

	int total = 0;
	while (1) {
		forn(i, E.size()) {
			int u = E[i].se.fi, v = E[i].se.se;
			total += E[i].fi;

			if (Par(u) != Par(v)) {
				dsu(u, v);
			}

			if (Par(s) == Par(t)) {
				cout << total << endl;
				return 0;
			}
		}
	}
#ifdef RICARDO
	cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}