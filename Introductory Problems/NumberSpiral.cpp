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
	int t;
	cin >> t;
	while(t--){
		ll x, y;
		cin >> x >> y;
		ll n = max(x, y);	
		ll dim = n*n-(n-1);
		if(!(n&1))	
			swap(x, y);
		cout << (x == n ? dim-(n-y) : dim+(n-x)) << endl;
	}
	return 0;
