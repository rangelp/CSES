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

/*a^b^c mod m = a^(b^c mod n) mod m, where n = φ(m) Euler's totient function.
If m is prime, then n = m-1.
*/ 

ll fexp(ll b, ll e, ll md){
	ll ans = 1;
	while(e){
		if(e&1)
			ans = (ans%md*b%md)%md;
		e >>= 1;
		b = (b%md*b%md)%md;
	}
	return ans%md;
}
 
int main(){
	int n;
	cin >> n;
	while(n--){
		ll a, b, c;
		cin >> a >> b >> c;
		cout << fexp(a, fexp(b, c, mod-1), mod)<< endl;
	}
	return 0;
}
