#include <bits/stdc++.h>
 
using namespace std;
 
#define all(x) x.begin(), x.end()
#define sz(x) (int) x.size()
#define endl '\n'
 
typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> ii;
typedef pair <ll, ll> pll;
 
#define maxn 201010
 
ll seg[4*maxn], v[maxn], lazy[4*maxn];
 
void build(int i, int l, int r){
	if(l == r){
		seg[i] = v[l];
		return;
	}
	int md = (l+r)/2, nxt = 2*i;
	build(nxt, l, md);
	build(nxt+1, md+1, r);
	seg[i] = seg[nxt]+seg[nxt+1];
}
 
void push(int i, int l, int r){
	if(lazy[i]){
		seg[i] += (r-l+1)*1LL*lazy[i];
		if(l != r){
			int nxt = 2*i;
			lazy[nxt] += lazy[i];
			lazy[nxt+1] += lazy[i];
		}
		lazy[i] = 0;
	}
}
 
void update(int i, int l, int r, int x, int y, int p){
	push(i, l, r);
	if(l > y or r < x)
		return;
	if(l >= x and r <= y){
		lazy[i] += p;
		push(i, l, r);
		return;
	}
	int md = (l+r)/2, nxt = 2*i;
	update(nxt, l, md, x, y, p);
	update(nxt+1, md+1, r, x, y, p);
	seg[i] = seg[nxt]+seg[nxt+1];
}
 
ll get(int i, int l, int r, int x, int y){
	push(i, l, r);
	if(l > y or r < x)
		return 0;
	if(l >= x and r <= y)
		return seg[i];
	int md = (l+r)/2, nxt = 2*i;
	return get(nxt, l, md, x, y)+get(nxt+1, md+1, r, x, y);
}
 
int main(){
	int n, q;
	cin >> n >> q;
	for(int i = 0; i < n; i++)
		cin >> v[i];
	build(1, 0, n-1);
	while(q--){
		int o;
		cin >> o;
		if(o == 1){
			int l, r, p;
			cin >> l >> r >> p;
			update(1, 0, n-1, l-1, r-1, p);
		}
		else{
			int k;
			cin >> k;
			cout << get(1, 0, n-1, k-1, k-1) << endl;
		}
	}
	return 0;
}
