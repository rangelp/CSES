#include <bits/stdc++.h>
 
using namespace std;
 
#define all(x) x.begin(), x.end()
#define sz(x) i(int) x.size()
#define endl "\n"
 
typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> ii;
typedef pair <ll, ll> pll;
 
int main(){
	int n;
	cin >> n;
	vector <int> v(n);
	for(auto &i : v)
		cin >> i;
	ll ans = 0;
	for(int i = 1; i < n; i++){
		if(v[i] < v[i-1]){
			ans += abs(v[i-1]-v[i]);
			v[i] += abs(v[i-1]-v[i]);
		}
	}
	cout << ans << endl;
	return 0;
}
