#include <bits/stdc++.h>
 
using namespace std;
 
#define all(x) x.begin(), x.end()
#define sz(x) (int) x.size()
#define endl '\n'
 
typedef long long ll;
typedef tuple <int, int, int> tp;
typedef pair <int, int> ii;

ll dp[70][300][2]; 
int sz;
string s;

ll solve(int i, int sum, bool warning){
	if(i == sz)
		return sum;
	ll &ans = dp[i][sum][warning];
	if(ans != -1)
		return ans;
	ans = 0;
	for(int j = 0; j <= 1; j++){
		if(warning){
			if(j > s[i]-'0')
				continue;
			ans += solve(i+1, sum+j, !(j < s[i]-'0'));
		}
		else
			ans += solve(i+1, sum+j, false);		
	}
	return ans;
}

ll solve(ll n){
	s = bitset <60> (n).to_string();
	sz = sz(s);
	memset(dp, -1, sizeof dp);
	return solve(0, 0, true);
}

int main(){
	ll n;
	cin >> n;
	cout << solve(n) << endl;
	return 0;
}
