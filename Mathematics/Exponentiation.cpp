#include <bits/stdc++.h>
 
using namespace std;
 
#define all(x) x.begin(), x.end()
#define sz(x) (int) x.size()
#define endl '\n'
 
typedef long long ll;
typedef tuple <int, int, int> tp;
typedef pair <int, int> ii;

const ll mod = 1e9+7;

ll fexp(ll b, ll e){
	ll ans = 1;
	while(e){
		if(e&1)
			ans = (ans*b)%mod;
		e >>= 1;
		b = (b*b)%mod;
	}
	return ans;
}

int main(){
	int n;
	cin >> n;
	while(n--){
		ll b, e;
		cin >> b >> e;
		cout << fexp(b, e) << endl;
	}
	return 0;
}
