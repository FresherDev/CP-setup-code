#include <bits/stdc++.h>
 
using namespace std;
 
signed main() {
//	freopen("i", "r", stdin);
//	freopen("obt.inp", "r", stdin);
//	freopen("obt.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); 

	int n, m, id = 0, total = 0;
 
	cin >> n >> m;

	vector<vector<int>> G(n);
	for (int i = 0; i < m; ++i) {
		int u, v;
 
		cin >> u >> v;
		--u, --v;
		G[u].push_back(v);
	}
 
	vector<int> ids(n, 0), low(n, 0), onStack(n, 0);
	stack<int> q;
 
	function<void(int s)> dfs = [&] (int s) {
	  	q.push(s);
	  	onStack[s] = 1;
	  	ids[s] = low[s] = ++id;
 
	  	for (int v : G[s]) {
	  		if (!ids[v]) dfs(v);
	  		if (onStack[v]) {
	  			low[s] = min(low[s], low[v]);
	  		}
	  	}
 
	  	if (ids[s] == low[s]) {
	  		while (!q.empty()) {
				int node = q.top();
				q.pop();
				onStack[node] = 0;
				low[node] = total;
				if (node == s) break;	  		
	  		}
	  		++total;
	  	}
 
	};
 
	function<void()> solve = [&] () {          
	  	for (int i = 0; i < n; ++i) {
	  		if (!ids[i]) {
	  			dfs(i);
	  		}
	  	}
	};
 
	solve();
 
	vector<int> isDead(total);
	for (int i = 0; i < total; ++i) isDead[i] = 1;
	for (int i = 0; i < n; ++i) {
		for (int j : G[i]) {
			if (low[i] != low[j]) isDead[low[j]] = 0;
		}
	}
 
	int ans = 0;
	for (int i = 0; i < total; ++i) if (isDead[i]) ++ans;
                                          
	cout << ans << endl;
//	cout << total << endl;
}