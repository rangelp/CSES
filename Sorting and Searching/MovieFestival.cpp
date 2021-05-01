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
	vector <ii> v(n);
	for(auto &[i, j] : v)
		cin >> i >> j;
	sort(all(v), [](ii a, ii b){
			if(a.second != b.second)
				return a.second < b.second;
			return a.first < b.first;
		}
	);
	int ans = 0, l = 0;
	for(auto [i, f] : v){
		if(i >= l){
			ans++;
			l = f;
		}
	}
	cout << ans << endl;
	return 0;
}
