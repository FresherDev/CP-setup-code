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
	const int td[4] = {1, -1, 0, 0};
	const int tc[4] = {0, 0, 1, -1};

	int n, m;

	cin >> n >> m;

	vvi a(n + 5, vi(m + 5, 0));
	int si, sj, ti, tj;
	forn(i, n) {
		forn(j, m) {
			char c;

			cin >> c;
			if (c == '*') {
				a[i][j] = -1;
			} else if (c == 'C') {
				si = i;
				sj = j;
			} else if (c == 'B') {
				ti = i;
				tj = j;
			}
		}
	}

	vvi d(n + 5, vi(m + 5, 0));

	function <bool(int, int)> check = [&] (int i, int j) {
		return (i >= 0 && j >= 0 && i < n && j < m);
	};

	function <int()> bfs = [&] () {
	  	queue<pii> q;
	  	q.push({si, sj});
	  	d[si][sj] = 0; a[si][sj] = -1;
	  	
	  	while (!q.empty()) {
	  		int ui = q.front().fi;
	  		int uj = q.front().se;
	  		q.pop();

	  		if (a[ti][tj] == -1) return d[ti][tj];

	  		forn(i, 4) {
	  			int vi = ui + td[i];
	  			int vj = uj + tc[i];

	  			if (check(vi, vj) and a[vi][vj] != -1) {
	  				q.push({vi, vj});
	  				d[vi][vj] = d[ui][uj] + 1;
	  				a[vi][vj] = -1;
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