#include <bits/stdc++.h>
 
using namespace std;
 
#define all(x) x.begin(), x.end()
#define sz(x) (int) x.size()
#define endl '\n'
 
typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> ii;
typedef pair <ll, ll> pll;
 
const ll mod = 1e9+7;
 
int main(){
	int n, m;
	cin >> n >> m;
	vector <int> v(n);
	for(auto &i : v)
		cin >> i;
	vector <ll> dp(m+1, 0);
	dp[0] = 1;
	for(int i = 0; i < n; i++)
		for(int j = 1; j <= m; j++)
			if(v[i] <= j)
				dp[j] += dp[j-v[i]]%mod, dp[j] %= mod;
	cout << dp[m] << endl;
	return 0;
}
