#include <bits/stdc++.h>
 
using namespace std;
 
#define all(x) x.begin(), x.end()
#define sz(x) (int) x.size()
#define endl '\n'
 
typedef long long ll;
typedef tuple <int, int, int> tp;
typedef pair <int, int> ii;

#define maxn 202020

struct info{
	int type;
	ll v, lazy;
	info(){
		v = lazy = type = 0;
	}
};

info seg[4*maxn];
ll v[maxn];

void build(int i, int l, int r){
	if(l == r){
		seg[i].v = v[l];
		return;
	}
	int md = (l+r)/2, nxt = 2*i;
	build(nxt, l, md);
	build(nxt+1, md+1, r);
	seg[i].v = seg[nxt].v+seg[nxt+1].v;
}

void push(int i, int l, int r){
	if(seg[i].type == 1)
		seg[i].v += (r-l+1)*1LL*seg[i].lazy;
	else
		seg[i].v = (r-l+1)*1LL*seg[i].lazy;
	if(l != r){
		int nxt = 2*i;
		if(seg[i].type == 1){
			if(seg[nxt].type != 0)
				seg[nxt].lazy += seg[i].lazy;
			else{
				seg[nxt].lazy = seg[i].lazy;
				seg[nxt].type = seg[i].type;
			}
			if(seg[nxt+1].type != 0)
				seg[nxt+1].lazy += seg[i].lazy;
			else{
				seg[nxt+1].lazy = seg[i].lazy;
				seg[nxt+1].type = seg[i].type;
			}
		}
		else{
			seg[nxt].lazy = seg[nxt+1].lazy = seg[i].lazy;
			seg[nxt].type = seg[nxt+1].type = seg[i].type;
		}
	}
	seg[i].type = seg[i].lazy = 0;
}

void update(int i, int l, int r, int x, int y, int var, int type){
	if(seg[i].type != 0)
		push(i, l, r);
	if(l > y or r < x)
		return;
	if(l >= x and r <= y){
		if(type == 1)
			seg[i].type = 1;
		else
			seg[i].type = 2;
		seg[i].lazy = var;
		push(i, l, r);
		return;
	}
	int md = (l+r)/2, nxt = 2*i;
	update(nxt, l, md, x, y, var, type);
	update(nxt+1, md+1, r, x, y, var, type);
	seg[i].v = seg[nxt].v+seg[nxt+1].v;
}

ll get(int i, int l, int r, int x, int y){
	if(seg[i].type != 0)
		push(i, l, r);
	if(l > y or r < x)
		return 0;
	if(l >= x and r <= y)
		return seg[i].v;
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
			int l, r, k;
			cin >> l >> r >> k;
			update(1, 0, n-1, l-1, r-1, k, o);
		}
		else if(o == 2){
			int l, r, k;
			cin >> l >> r >> k;
			update(1, 0, n-1, l-1, r-1, k, o);
		}
		else{
			int l, r;
			cin >> l >> r;
			cout << get(1, 0, n-1, l-1, r-1) << endl;
		}
	}
	return 0;
}
