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
	int n, x;
	cin >> n >> x;
	vector <int> v(n);
	for(auto &i : v)
		cin >> i;
	sort(all(v));
	int i = 0, j = n-1, ans = 0;
	while(i <= j){
		if(v[j]+v[i] > x){
			 j--;
		}
		else
			i++, j--;
		ans++;
	}
	cout << ans << endl;
	return 0;
}
