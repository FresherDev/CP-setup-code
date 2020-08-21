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

struct node {
  	int i, j, w;

  	node(int i, int j, int w) {
  		this->i = i;
  		this->j = j;
  		this->w = w;
  	}
};

bool operator> (const node &a, const node &b) {
	return a.w > b.w;
}

const int N = 105;
int c[N][N];

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

	int n, m, x, y;

	cin >> n >> m >> x >> y;
                
	int ai, aj, bi, bj, ni, nj;
	forn(i, n) {
		forn(j, m) {
			char tmp;
			cin >> tmp;
			//bug(tmp);
			if (tmp == 'A') {
				ai = i;
				aj = j;
				c[i][j] = x + 1;
			} else if (tmp == 'N') {
				ni = i;
				nj = j;
				c[i][j] = y + 1;
			} else if (tmp == 'B') {
				bi = i;
				bj = j;
				c[i][j] = 1;
			} else if (tmp != '#') {
				c[i][j] = (tmp - '0') + 1;
			} else c[i][j] = -1;
		}
	} 	

	function <bool(int, int)> check = [&] (int i, int j) {
		return (i >= 0 && j >= 0 && i < n && j < m && c[i][j] != -1);
	};

	i64 d[105][105], mark[105][105];
	function <void()> reset = [&] () {
	  	forn(i, n) {
	  		forn(j, m) {
	  			d[i][j] = INT_MAX;
	  			mark[i][j] = 0;
	  		}
	  	}

//	  	cout << "finish reset" << endl;
	};

	function <void(int, int, int, int)> dijkstra = [&] (int si, int sj, int fi, int fj) {
//		cout << "dijkstra..." << endl;
		reset();
	  	d[si][sj] = 0;
	  	priority_queue<node, vector<node>, greater<node>> pq;
	  	pq.push(node(si, sj, 0));

	  	while (!pq.empty()) {
	  		int ui = pq.top().i;
	  		int uj = pq.top().j;
	  		pq.pop();

	  		if (mark[ui][uj]) continue;
	  		if (ui == fi && uj == fj) break;

	  		mark[ui][uj] = 1;

	  		forn(i, 4) {
	  			int vi = ui + td[i];
	  			int vj = uj + tc[i];
	  			int w = c[vi][vj];

	  			if (check(vi, vj) && d[vi][vj] > d[ui][uj] + w) {
	  				d[vi][vj] = d[ui][uj] + w;
	  				pq.push(node(vi, vj, d[vi][vj]));
	  			} 
	  		}
	  	}  	                	
	};

	i64 ans = 0;
	dijkstra(bi, bj, ai, aj);
	ans += d[ai][aj];
	dijkstra(ai, aj, ni, nj);
	ans += d[ni][nj];
	dijkstra(ni, nj, bi, bj);
	ans += d[bi][bj];

	if (ans >= INT_MAX) cout << "NO" << endl;
	else cout << ans << endl;

#ifdef RICARDO
	cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}	