#include <bits/stdc++.h>
 
using namespace std;
 
#define all(x) x.begin(), x.end()
#define sz(x) (int) x.size()
#define endl '\n'
 
typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> ii;
 
#define maxn 210101
 
vector <ll> ft, v;
 
// update: O(log n)
void update(int i, int delta){
	for(; i < maxn; i += i&-i)
		ft[i] += delta;
}
 
// build: O(n log n)
void build(int n){
	ft.assign(maxn, 0);
	for(int i = 1; i <= n; i++)
		update(i, v[i]);
}
 
// query: O(log n)
ll query(int i){
	ll sum = 0;
	for(; i; i -= i&-i)
		sum += ft[i];
	return sum;
}
 
// query: O(log n)
ll query(int l, int r){
	return query(r)-(l == 1 ? 0 : query(l-1));
}
 
int main(){
	int n, q;
	cin >> n >> q;
	v.assign(n+1, 0);
	for(int i = 1; i <= n; i++)
		cin >> v[i];
	build(n);
	while(q--){
		int o;
		cin >> o;
		if(o == 1){
			int k, u;
			cin >> k >> u;
			update(k, u-v[k]);
			v[k] = u;
			//update(k, v[k]);
		}
		else{
			int l, r;
			cin >> l >> r;
			cout << query(l, r) << endl;
		}
	}
	return 0;
}
