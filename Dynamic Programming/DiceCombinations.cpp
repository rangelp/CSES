#include <bits/stdc++.h>
 
using namespace std;
 
#define all(x) x.begin(), x.end()
#define sz(x) (int) x.size()
#define endl '\n'
 
typedef long long ll;
typedef tuple <int, int, int> tp;
typedef pair <int, int> ii;

const ll mod = 1e9+7;

int main(){
	int n;
	cin >> n;
	vector <ll> dp(n+2, 0);
	dp[0] = 1;
	//dp[i] = number ways to form i.
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= 6; j++)
			if(i-j >= 0)
				dp[i] += dp[i-j]%mod, dp[i] %= mod;
	cout << dp[n] << endl;
	return 0;
}
