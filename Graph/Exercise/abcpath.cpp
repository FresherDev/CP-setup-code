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
	const int td[8] = {1, -1, 0, 0, -1, -1, 1, 1};
	const int tc[8] = {0, 0, 1, -1, -1, 1, 1, -1};

	int n, m, idx = 0;

	while (1) {
		cin >> n >> m;         

		if (n == 0 || m == 0) break;
		++idx;

	    char a[100][100];            
		vvi visit(n + 5, vi(m + 5, 0));

//		cout << n << " " << m << endl;
		forn(i, n) {
			forn(j, m) {
				char c;
				cin >> c;
				a[i][j] = c;
			}
		}

		function <bool(int, int, int, int)> check = [&] (int i, int j, int vi, int vj) {
			return (a[vi][vj] == a[i][j] + 1 && vi >= 0 && vj >= 0 && vi < n && vj < m);
		};

		int ans = INT_MIN;
		function <void(int, int, int)> dfs = [&] (int si, int sj, int len) {
			visit[si][sj] = 1;
			forn(i, 8) {
				int vi = si + td[i];
				int vj = sj + tc[i];

				if (check(si, sj, vi, vj) && visit[vi][vj] == 0) {
					dfs(vi, vj, len + 1);
				}
			}

			ans = max(ans, len);
		};
            
		forn(i, n) {
			forn(j, m) {
				if (a[i][j] == 'A') {
					dfs(i, j, 1);       
				}
			}
		}

		cout << "Case " << idx << ": " << ans << endl;
	}
#ifdef RICARDO
	cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}