#include <bits/stdc++.h>
 
using namespace std;
 
#define all(x) x.begin(), x.end()
#define sz(x) (int) x.size()
#define endl '\n'
 
typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> ii;
typedef pair <ll, ll> pll;
 
#define maxn 202020
 
int seg[4*maxn], v[maxn];
 
void build(int i, int l, int r){
	if(l == r){
		seg[i] = v[l];
		return;
	}
	int md = (l+r)/2, nxt = 2*i;
	build(nxt, l, md);
	build(nxt+1, md+1, r);
	seg[i] = min(seg[nxt], seg[nxt+1]);
}
 
void update(int i, int l, int r, int p, int x){
	if(l > p or r < p)
		return;
	if(l == p and r == p){
		seg[i] = x;
		return;
	}
	int md = (l+r)/2, nxt = 2*i;
	update(nxt, l, md, p, x);
	update(nxt+1, md+1, r, p, x);
	seg[i] = min(seg[nxt], seg[nxt+1]);
}
 
int get(int i, int l, int r, int x, int y){
	if(l > y or r < x)
		return 1<<30;
	if(l >= x and r <= y)
		return seg[i];
	int md = (l+r)/2, nxt = 2*i;
	return min(get(nxt, l, md, x, y), get(nxt+1, md+1, r, x, y));
}
 
int main(){
	int n, q;
	cin >> n >> q;
	for(int i = 0; i < n; i++)
		cin >> v[i];
	build(1, 0, n-1);
	while(q--){
		int op;
		cin >> op;
		if(op == 1){
			int k, u;
			cin >> k >> u;
			update(1, 0, n-1, k-1, u);
		}
		else{
			int l, r;
			cin >> l >> r;
			cout << get(1, 0, n-1, l-1, r-1) << endl;
		}
	}
	return 0;
}
