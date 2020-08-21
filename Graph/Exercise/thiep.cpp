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

pii thiep[1005],bia[1005];
int n,m,s,t,a[2005][2005],trace[2005],f[2005][2005],ans;
vector<int> c[2005];
bool findpath()
{
    for(int i=1;i<=n;++i)
		trace[i]=0;
    queue<int> q; q.push(s);
    trace[s]= n+1;
    while (!q.empty())
    {
        int u=q.front(); q.pop();
        for (int i=0;i<c[u].size();++i)
        {
            int v=c[u][i];
			if (!trace[v]&&a[u][v]>f[u][v])
            {
				trace[v]=u;
				if (v==t) return true;
				q.push(v);
			}
        }
    }
    return false;
}

void incflow()
{
    int mn,u,v;
	mn=INT_MAX;
	v=t;
    do
    {
        u=trace[v];
        mn=min(mn,a[u][v]-f[u][v]);
        v=u;
    } while (v!=s);
	v=t;
    do
    {
        u=trace[v];
        //cout<<u<<" ";
        f[u][v]+=mn;
		f[v][u]-=mn;
        v=u;
    } while (v!=s);
    ans+=mn;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(10);
	cout << fixed;
#ifdef RICARDO		
	freopen("i", "r", stdin);
#endif
ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  cin>>n>>m;
  for(int i=1;i<=n;++i)
    {
        a[n+m+1][i]=1;
        c[n+m+1].push_back(i); c[i].push_back(n+m+1);
        cin>>thiep[i].fi>>thiep[i].se;
    }
  for(int i=1;i<=m;++i)
    {
        a[n+i][n+m+2]=1;
        c[n+i].push_back(n+m+2);
        cin>>bia[i].fi>>bia[i].se;
    }
  for(int i=1;i<=n;++i)
  {
      for(int j=1;j<=m;++j)
        if ((thiep[i].fi<=bia[j].fi&&thiep[i].se<=bia[j].se)||(thiep[i].fi<=bia[j].se&&thiep[i].se<=bia[j].fi))
           {
               a[i][n+j]=1;
               c[i].push_back(n+j);
               c[n+j].push_back(i);
           }
  }
  n+=m+2;
  s=n-1; t=n;
  while(findpath()) incflow();
  cout<<ans<<endl;;
/*	int n, m;	

	cin >> n >> m;
	int s = n + m + 1, t = n + m + 2;

	vvi G(n + m + 5), c(n + m + 5, vi(n + m + 5)), f(n + m + 5, vi(n + m + 5));
	vi w(n + m + 5), h(n + m + 5), d(n + m + 5), r(n + m + 5);
	for1(i, n) {
		G[s].pb(i); G[i].pb(s);
		c[s][i] = 1;
		cin >> w[i] >> h[i];
	}

	for1(i, m) {
		G[n + i].pb(t);
		c[n + i][t] = 1;
		cin >> d[i] >> r[i];
	}
      
	for1(i, n) {
	 	for1(j, m) {
	 		if ((w[i] <= d[j] && h[i] <= r[j]) || (w[i] <= r[j] && h[i] <= d[j])) {
	 			G[i].pb(n + j);
	 			G[n + j].pb(i);
	 			c[i][n + j] = 1;
	 		}
	 	}
	}

	int flow = 0;
	vi trace(n + m + 5);
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
	  	for1(i, n) trace[i] = 0;
	  	trace[s] = n + 1;
	  	queue<int> q;
	  	q.push(s);

	  	while (!q.empty()) {
	  		int u = q.front(); q.pop();
	  		for1(i, G[u].size()) {
	  			int v = G[u][i];
	  			if (!trace[v] && c[u][v] > f[u][v]) {
	  				trace[v] = u;
	  				if (v == t) return 1;
	  				q.push(v);
	  			}
	  		}
	  	}

	  	return 0;
	};

	n += m + 2;  
	while (bfs()) inc();

	cout << flow << endl; */
#ifdef RICARDO
	cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}	
