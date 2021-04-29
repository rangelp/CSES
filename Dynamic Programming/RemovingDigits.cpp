#include <bits/stdc++.h>
 
using namespace std;
 
#define all(x) x.begin(), x.end()
#define sz(x) (int) x.size()
#define endl '\n'
 
typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> ii;
typedef pair <ll, ll> pll;
 
#define maxn 1010101
 
int dp[maxn];
 
int solve(int n){
	if(n <= 0)
		return n == 0 ? 0 : 1<<30;
	int &ans = dp[n];
	if(~ans)
		return ans;
	ans = 1<<30;
	string num = to_string(n);
	for(auto i : num)
		ans = min(ans, 1+solve(n-(i-'0')));
	return ans;
}
 
int main(){
	int n;
	cin >> n;
	memset(dp, -1, sizeof dp);
	cout << solve(n) << endl;
	return 0;
}
