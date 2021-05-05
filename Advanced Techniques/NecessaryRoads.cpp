#include <bits/stdc++.h>
 
using namespace std;
 
#define all(x) x.begin(), x.end()
#define sz(x) (int) x.size()
#define endl '\n'
 
typedef long long ll;
typedef tuple <int, int, int> tp;
typedef pair <int, int> ii;

#define maxn 101010

vector <int> g[maxn];
vector <ii> ans;
vector <int> in, low, see;
int cnt;

void dfs(int u, int p){
	in[u] = low[u] = cnt++;
	see[u] = 1;
	for(auto v : g[u]){
		if(!see[v]){
			dfs(v, u);
			low[u] = min(low[u], low[v]);
			if(low[v] > in[u])
				ans.push_back({u, v});
		}	
		else if(v != p)
			low[u] = min(low[u], in[v]);
	}
}

void tarjan(int n){
	cnt = 0;
	see.assign(n+1, 0);
	in.assign(n+1, 0);
	low.assign(n+1, 0);
	for(int i = 1; i <= n; i++)
		dfs(i, i);
}

int main(){
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
 	tarjan(n);
	cout << sz(ans) << endl;
	for(auto [i, j] : ans)
		cout << i << " " << j << endl;
	return 0;
}
