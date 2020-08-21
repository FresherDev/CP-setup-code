#include <bits/stdc++.h>

using namespace std;

const int td[4] = {-1, 0, 0, +1};
const int tc[4] = {0, -1, +1, 0};
int visit[50][50];
char grid[100][100];
vector<pair<int, int>> q;

bool check (int i, int j, int r, int c) {
    return (i >= 0 && j >= 0 && i < r && j < c);
}

void dfs (int r, int c, int pacman_r, int pacman_c, int food_r, int food_c){
    //your logic here
    visit[pacman_r][pacman_c] = 1;
    q.push_back({pacman_r, pacman_c});
    
    for (int i = 0; i < (int)q.size(); ++i) {
        int ui = q[i].first;
        int uj = q[i].second;
        for (int j = 0; j < 4; ++j) {
            int vi = ui + td[j];
            int vj = uj + tc[j];
            if (check(vi, vj, r, c) && !visit[vi][vj] && grid[vi][vj] != '%') {
                visit[vi][vj] = 1;
                q.push_back({vi, vj});
                
                if (vi == food_r && vj == food_c) return ;
            }
        }
    }
    
}

int main(void) {
	freopen("i", "r", stdin);

    int r, c, pacman_r, pacman_c, food_r, food_c;
    
    cin >> pacman_r >> pacman_c;
    cin >> food_r >> food_c;
    cin >> r >> c;
                                          
    for(int i=0; i<r; i++) {
        for(int j = 0; j < c; ++j) {
        	char c;

        	cin >> c;
        	grid[i][j] = c;
        }
    }

    dfs (r, c, pacman_r, pacman_c, food_r, food_c);
    reverse(q.begin(), q.end());
    for (int i = 0; i < (int)q.size(); ++i) {
        cout << q[i].first << " " << q[i].second << endl;
    }
    return 0;
}