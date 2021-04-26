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
	int n, m, k;
	cin >> n >> m >> k;
	vector <int> a(n), b(m);
	for(auto &i : a)
		cin >> i;
	for(auto &i : b)
		cin >> i;
	sort(all(a)), sort(all(b));
	int i = 0, j = 0, ans = 0;
	while(i < n and j < m){
		if(abs(a[i]-b[j]) <= k)
			i++, j++, ans++;
		else if(a[i]-b[j] > k)
			j++;
		else
			i++;
	}
	cout << ans << endl;
	return 0;
}
