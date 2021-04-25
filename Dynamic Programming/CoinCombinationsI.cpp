#include <bits/stdc++.h>
 
using namespace std;
 
#define all(x) x.begin(), x.end()
#define sz(x) i(int) x.size()
#define endl "\n"
 
typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> ii;
typedef pair <ll, ll> pll;
 
const ll mod = 1e9+7;
 
int main(){
	int n, m;
	cin >> n >> m;
	vector <int> v(n), dp(m+1, 0);
	for(auto &i : v)
		cin >> i;
	dp[0] = 1;
	for(int i = 1; i <= m; i++)
		for(int j = 0; j < n; j++)
			if(v[j] <= i)
				dp[i] += dp[i-v[j]]%mod, dp[i] %= mod;;
	cout << dp[m] << endl;
	return 0;
