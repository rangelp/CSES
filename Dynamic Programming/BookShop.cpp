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
	int n, c;
	cin >> n >> c;
	vector <int> w(n), v(n);
	for(auto &i : w)
		cin >> i;
	for(auto &i : v)
		cin >> i;
	int dp[n+1][c+1];
	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= c; j++){
			if(i == 0 or j == 0){
				dp[i][j] = 0;
				continue;
			}
			dp[i][j] = dp[i-1][j];
			if(w[i-1] <= j)
				dp[i][j] = max(dp[i][j], v[i-1]+dp[i-1][j-w[i-1]]);
		}
	}
	cout << dp[n][c] << endl;
	return 0;
}
