#include <bits/stdc++.h>
#define maxN 100010
#define inf INT_MAX
#define ll long long
using namespace std;

typedef pair<ll,ll> ii;
vector<ii> a[maxN];
int n,m;
long long d[maxN],ds[maxN],dt[maxN];

void dijkstra(long long d[],int s)
{
    for (int i=1;i<=n;++i) d[i]=inf;
    d[s]=0;
    priority_queue<ii,vector<ii>,greater<ii>> pq;
    pq.push(ii(0,s));
    while (!pq.empty())
    {
        int u=pq.top().second;
        pq.pop();
        for (int i=0;i<(int)a[u].size();++i)
        {
            int v=a[u][i].first;
            int w=a[u][i].second;
            if (d[v]>d[u]+w)
            {
                d[v]=d[u]+w;
                pq.push(ii(d[v],v));
            }
        }
    }
}

int main()
{
    freopen("i", "r", stdin);

    int s,t;
    scanf("%d%d%d%d",&n,&m,&s,&t);

    while (m--)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        a[u].push_back(ii(v,w));

    }

    dijkstra(ds,s);
    dijkstra(dt,t);

    ll tmp=ds[t]+dt[s],tmp2=inf,ans=0;
    for(int i=1;i<=n;++i)
    {
        if (i!=s&&i!=t)
        {
            if (ds[i] == 1) tmp2 = min(tmp2, dt[i]);
            else if (dt[i] == 1) tmp2 = min(tmp2, ds[i]);
            else ans += ds[i] + dt[i];
        }
    }

//    for (int i=1;i<=n;++i)
//    {
//        if (i!=s&&i!=t)
//        {
//            dijkstra(d,i);
//            if (ds[i]!=0&&d[t]!=0&&dt[i]!=0&&d[s]!=0) res=min(res,ds[i]+d[t]+dt[i]+d[s]);
//        }
//    }

    if (tmp2 != inf) printf("%lld",max(tmp,ans+tmp2));
    else cout << max(tmp, ans);
    //if (res!=inf) printf("%lld",res); else printf("-1");
    //if (res!=0) cout<<res+tmp; else cout<<-1;
    return 0;
}
