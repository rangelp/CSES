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
	ll n, ans = 1;
	cin >> n;
	for(ll i = 1; i <= n; i++)
		ans *= 2, ans %= mod;
	cout << ans << endl;
	return 0;
}
