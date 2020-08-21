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

int d[255][255][255];

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.precision(10);
	cout << fixed;
#ifdef RICARDO		
	freopen("i", "r", stdin);
#endif
	int n, m, k;

	cin >> n >> m >> k;

	//vector<vector<vector<int>>> d(n + 1, vi(m + 1));

	forn(i, n + 5) {
		forn(j, m + 5) {
			forn(l, k + 5) {
				d[i][j][l] = -1;
			}
		}
	}

	vector<pair<int, pair<int, int>>> q;
	function <int()> bfs = [&] () {
	  	d[n][m][k] = 0;
	  	q.pb(mp(n, mp(m, k)));

	  	forn (i, q.size()) {
	  		int tmp = q[i].fi;
	  		int tmp2 = q[i].se.fi;
	  		int tmp3 = q[i].se.se;
	  		if (tmp == tmp2 and tmp2 == tmp3) {
	  			return d[tmp][tmp2][tmp3];
	  		}

	  		if (tmp > tmp2) {
	  			if (d[tmp - tmp2][tmp2][tmp3] == -1) {
	  				d[tmp - tmp2][tmp2][tmp3] = d[tmp][tmp2][tmp3] + 1;
	  				q.pb(mp(tmp - tmp2, mp(tmp2, tmp3)));
	  			}	
	  		}
	  		if (tmp > tmp3) {
	  			if (d[tmp - tmp3][tmp2][tmp3] == -1) {
	  				d[tmp - tmp3][tmp2][tmp3] = d[tmp][tmp2][tmp3] + 1;
	  				q.pb(mp(tmp - tmp3, mp(tmp2, tmp3)));
	  			}	
	  		}
	  		if (tmp2 > tmp) {
	  			if (d[tmp][tmp2 - tmp][tmp3] == -1) {
	  				d[tmp][tmp2 - tmp][tmp3] = d[tmp][tmp2][tmp3] + 1;
	  				q.pb(mp(tmp, mp(tmp2 - tmp, tmp3)));
	  			}	
	  		}
	  		if (tmp2 > tmp3) {
	  			if (d[tmp][tmp2 - tmp3][tmp3] == -1) {
	  				d[tmp][tmp2 - tmp3][tmp3] = d[tmp][tmp2][tmp3] + 1;
	  				q.pb(mp(tmp, mp(tmp2 - tmp3, tmp3)));
	  			}	
	  		}
	  		if (tmp3 > tmp) {
	  			if (d[tmp][tmp2][tmp3 - tmp] == -1) {
	  				d[tmp][tmp2][tmp3 - tmp] = d[tmp][tmp2][tmp3] + 1;
	  				q.pb(mp(tmp, mp(tmp2, tmp3 - tmp)));
	  			}	
	  		}
	  		if (tmp3 > tmp2) {
	  			if (d[tmp][tmp2][tmp3 - tmp2] == -1) {
	  				d[tmp][tmp2][tmp3 - tmp2] = d[tmp][tmp2][tmp3] + 1;
	  				q.pb(mp(tmp, mp(tmp2, tmp3 - tmp2)));
	  			}	
	  		}    	
	  	}

	  	return -1;
	};

	cout << bfs() << endl;

#ifdef RICARDO
	cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}