#include <bits/stdc++.h>
 
using namespace std;
 
#define all(x) x.begin(), x.end()
#define sz(x) (int) x.size()
#define endl '\n'
 
typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> ii;
typedef pair <ll, ll> pll;
 
#define maxn 1010
 
const ll mod = 1e9+7;
 
char g[maxn][maxn];
ll dp[maxn][maxn];
int dx[] = {1, 0}, dy[] = {0, 1};
int n;
 
bool in(int x, int y){
	if(x < 0 or x >= n or y < 0 or y >= n)
		return false;
	return g[x][y] == '.';
}
 
ll solve(int x, int y){
	if(g[x][y] == '*')
		return 0;
	if(x == n-1 and y == n-1)
		return 1;
	ll &ans = dp[x][y];
	if(~ans)
		return ans;
	ans = 0;
	for(int i = 0; i < 2; i++){
		int nx = x+dx[i], ny = y+dy[i];
		if(in(nx, ny))
			ans += solve(nx, ny)%mod, ans %= mod;
	}
	return ans;
}
 
int main(){
	cin >> n;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			cin >> g[i][j];
	memset(dp, -1, sizeof dp);
	cout << solve(0, 0) << endl;
	return 0;
}
