#include <bits/stdc++.h>
 
using namespace std;
 
#define all(x) x.begin(), x.end()
#define sz(x) (int) x.size()
#define endl '\n'
 
typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> ii;
typedef pair <ll, ll> pll;
 
int main(){
	int n, m;
	cin >> n >> m;
	int v[n+1];
	for(int i = 1; i <= n; i++)
		cin >> v[i];
	int dp[n+1][m+1];
	memset(dp, 0x3f3f3f3f, sizeof dp);
	for(int i = 0; i <= n; i++)
		dp[i][0] = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			dp[i][j] = dp[i-1][j];
			if(v[i] <= j)
				dp[i][j] = min({dp[i][j], 1+dp[i][j-v[i]], 1+dp[i-1][j-v[i]]});
		}
	}
	cout << (dp[n][m] >= 0x3f3f3f3f ? -1 : dp[n][m]) << endl;
	return 0;
}
