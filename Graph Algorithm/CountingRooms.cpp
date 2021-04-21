#include <bits/stdc++.h>
 
using namespace std;
 
#define all(x) x.begin(), x.end()
#define sz(x) (int) x.size()
#define endl '\n'
 
typedef long long ll;
typedef tuple <int, int, int> tp;
typedef pair <int, int> ii;

#define maxn 1010

char g[maxn][maxn];
int see[maxn][maxn], dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
int n, m;

bool in(int x, int y){
	if(x < 0 or x >= n or y < 0 or y >= m)
		return false;
	return g[x][y] == '.' and see[x][y] == 0;
}

void dfs(int x, int y){
	see[x][y] = 1;
	for(int i = 0; i < 4; i++){
		int nx = x+dx[i], ny = y+dy[i];
		if(in(nx, ny))
			dfs(nx, ny);
	}
}

int main(){
	cin >> n >> m;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			cin >> g[i][j];
	int ans = 0;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			if(g[i][j] == '.' and see[i][j] == 0)
				ans++, dfs(i, j);
	cout << ans << endl;
	return 0;
}
