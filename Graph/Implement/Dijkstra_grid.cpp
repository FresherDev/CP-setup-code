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

const int N = 305;
const int M = 305;

struct node {
	int i, j, w;
	node(int i, int j, int w) {
		this->i = i;
		this->j = j;
		this->w = w;
	}
};

bool operator>(const node &v1, const node &v2) {
	return v1.w > v2.w;
}

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

	int n, m, si, sj, fi, fj;

	cin >> n >> m >> si >> sj >> fi >> fj;
	--si, --sj, --fi, --fj;
                    
    int a[N][M];
	forn(i, n) {
		forn(j, m) {
			cin >> a[i][j];
		}
	}	
	
	int d[N][M], mark[N][M];
	forn(i, n) {
		forn(j, m) {
			d[i][j] = INT_MAX;
			mark[i][j] = 0;
		}
	}

	function <bool(int, int)> check = [&] (int i, int j) {
	  	return (i >= 0 && j >= 0 && i < n && j < m);
	};

	function <void(int, int)> dijkstra = [&] (int si, int sj) {
	  	priority_queue<node, vector<node>, greater<node>> pq;
	  	d[si][sj] = 0;   
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
	  			int w = a[vi][vj];

	  			if (check(vj, vj) and d[vi][vj] > d[ui][uj] + w) {
	  				d[vi][vj] = d[ui][uj] + w;
	  				pq.push(node(vi, vj, d[vi][vj]));
	  			}
	  		}
	  	}
	};

	dijkstra(si, sj);

	cout << d[fi][fj] << endl;
#ifdef RICARDO
	cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}	