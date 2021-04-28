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
	ll x;
	cin >> x;
	for(ll n = 1; n <= x; n++){
		ll ans = (n*n*(n*n-1)/2)-4*(n-1)*(n-2);
		cout << ans << endl;
	}
	return 0;
}
