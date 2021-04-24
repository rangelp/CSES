#include <bits/stdc++.h>
 
using namespace std;
 
#define all(x) x.begin(), x.end()
#define sz(x) (int) x.size()
#define endl "\n"
 
typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> ii;
typedef pair <ll, ll> pll;
 
#define maxn 1010
 
char g[maxn][maxn], dir[] = "UDLR";
int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
int dist[maxn][maxn];
int n, m, xf, yf, xi, yi;
tuple <int, int, int> path[maxn][maxn];
 
bool in(int x, int y){
	if(x < 0 or x >= n or y < 0 or y >= m)
		return false;
	return g[x][y] != '#' and dist[x][y] == 0x3f3f3f3f;
}
 
bool bfs(){
	memset(dist, 0x3f3f3f3f, sizeof dist);
	dist[xi][yi] = 0;
	queue <ii> q;
	q.push({xi, yi});
	while(!q.empty()){
		auto [x, y] = q.front();
		q.pop();
		if(x == xf and y == yf)
			return true;
		for(int i = 0; i < 4; i++){
			int nx = x+dx[i], ny = y+dy[i];
			if(in(nx, ny)){
				dist[nx][ny] = 1+dist[x][y];
				q.push({nx, ny});
				path[nx][ny] = make_tuple(x, y, i);
			}
		}
	}
	return false;
}
 
void rec(int x, int y){
	if(x == xi and y == yi)
		return;
	auto [nx, ny, i] = path[x][y];
	rec(nx, ny);
	cout << dir[i];
}
 
int main(){
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> g[i][j];
			if(g[i][j] == 'A')
				xi = i, yi = j;
			if(g[i][j] == 'B')
				xf = i, yf = j;
		}
	}
	bool ans = bfs();
	if(ans){
		cout << "YES" << endl;
		cout << dist[xf][yf] << endl;
		rec(xf, yf);
		cout << endl;
	}
	else
		cout << "NO" << endl;
	return 0;
}
