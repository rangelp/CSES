#include <bits/stdc++.h>
 
using namespace std;
 
#define all(x) x.begin(), x.end()
#define sz(x) (int) x.size()
#define endl '\n'
 
typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> ii;
typedef pair <ll, ll> pll;
 
#define maxn 210101
 
vector <int> g[maxn], cc, fst;
 
void dfs(int u, int color){
	cc[u] = color;
	for(auto v : g[u])
		if(cc[v] == -1)
			dfs(v, color);
}
 
int main(){
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int u, v;
		cin >> u >> v;
		g[u].emplace_back(v);
		g[v].emplace_back(u);
	}
	cc.assign(n+1, -1);
	fst.assign(n+1, -1);
	int color = 0;
	int tot = 0;
	for(int i = 1; i <= n; i++){
		if(cc[i] == -1){
			fst[color] = i;
			dfs(i, color++);
			tot++;
		}
	}
	cout << color-1 << endl;
	if(color-1){
		for(int i = 1; i < color; i++)
			cout << fst[0] << " " << fst[i] << endl;
	}
	return 0;
}
