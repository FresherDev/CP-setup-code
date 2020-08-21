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

	int c[105][105];
	char a[105][105];
	forn(i, n) {
		forn(j, m) {
			char tmp;
			cin >> tmp;
			switch (tmp) {
				case 'A':
					c[i][j] = 3;
					break;
			   	case 'B':
			   		c[i][j] = 5;
			   		break;
			   	case 'C':
			   		c[i][j] = 2;
			   		break;
			   	case 'D':
			   		c[i][j] = 7;
			   		break;
			}
			a[i][j] = tmp;
		}
	}
    
	function <bool(int, int, int, int)> check = [&] (int i, int j, int u, int v) {
	  	if (i >= 0 && j >= 0 && i < n && j < m) {
	  		if (a[u][v] == 'A') {
		  		if (j > v && a[i][j] == 'B') return 0;
		  		else if (i < u && a[i][j] == 'B') return 0;
			  		
//		  		bug(i); bug(j);
//		  		bug(u); bug(v);
//		  		bug(a[i][j]); bug(a[u][v]);
		  		return 1;
		  	} else if (a[u][v] == 'B') {
		  		if (j < v && a[i][j] == 'A') return 0;
		  		else if (i > u && a[i][j] == 'A') return 0;
	  		
	  			return 1;
		  	} else if (a[u][v] == 'C') {
	  			if (j < v && a[i][j] == 'D') return 0;
	  			else if (i < u && a[i][j] == 'D') return 0;

	 	 		return 1;
		  	} else {
	  			if (j > v && a[i][j] == 'C') return 0;
	  			else if (i > u && a[i][j] == 'C') return 0;
	  		
	  			return 1;
	  		}
	  	}

        return 0;      
	};

	int d[105][105], mark[105][105];
	forn(i, n) {
		forn(j, m) {
			d[i][j] = INT_MAX;
			mark[i][j] = 0;
		}
	}

	function <void()> dijkstra = [&] () {
	  	priority_queue<node, vector<node>, greater<node>> pq;
	  	d[si][sj] = 0;
	  	pq.push(node(si, sj, 0));

	  	while (!pq.empty()) {
	  		int ui = pq.top().i;
	  		int uj = pq.top().j;
//	  		bug(a[ui][uj]);
	  		pq.pop();

	  		if (mark[ui][uj]) continue;
	  		if (ui == fi && uj == fj) {
	  			cout << d[fi][fj] + c[si][sj] << endl;
	  			break;
	  		}
	  		mark[ui][uj] = 1;

	  		forn(i, 4) {
	  			int vi = ui + td[i];
	  			int vj = uj + tc[i];
	  			int w = c[vi][vj];

	  			if (check(vi, vj, ui, uj) && d[vi][vj] > d[ui][uj] + w) {
	  				d[vi][vj] = d[ui][uj] + w;
	  				pq.push(node(vi, vj, d[vi][vj]));	
	  			}
	  		}
	  	}
	};

	dijkstra();

#ifdef RICARDO
	cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}	