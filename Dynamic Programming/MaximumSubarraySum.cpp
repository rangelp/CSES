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
	int n;
	cin >> n;
	vector <ll> v(n);
	for(auto &i : v)
		cin >> i;
	ll mxl = 0, mnc = 0;
	for(auto i : v){
		mnc = max(0ll, mnc+i);
		mxl = max(mxl, mnc);
	}
	if(mxl == 0){
		ll mx = -1<<30;
		for(auto i : v)
			mx = max(mx, i);
		mxl = mx;
	}
	cout << mxl << endl;
	return 0;
}
