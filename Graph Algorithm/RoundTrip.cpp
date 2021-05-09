#include <bits/stdc++.h>
 
using namespace std;
 
#define all(x) x.begin(), x.end()
#define sz(x) (int) x.size()
#define endl '\n'
 
typedef long long ll;
typedef tuple <int, int, int> tp;
 
#define maxn 101010
 
vector <int> g[maxn], see, parent;
int start, _end;
 
bool dfs(int u, int p){
	see[u] = 1;
	for(auto v : g[u]){
		if(v != p){
			if(see[v] == 1){
				start = u;
				_end = v;
				return true;
			}
			if(dfs(v, u)){
				parent[v] = u;
				return true;
			}
		}
	}
	return false;
}
 
vector <int> rec(int u){
	vector <int> ans;
	while(u != _end and u != -1)
		ans.push_back(u), u = parent[u];
	ans.push_back(_end);
	reverse(all(ans));
	return ans;
}
 
vector <int> get(int n){
	see.assign(n+1, 0);
	parent.assign(n+1, -1);
	for(int i = 1; i <= n; i++){
		start = -1;
		if(dfs(i, i)){
			vector <int> ans = rec(start);
			if(sz(ans) > 2)
				return ans;
		}
	}
	return vector <int>();
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
	vector <int> ans = get(n);
	if(ans.empty() or ans.size() == 2)
		cout << "IMPOSSIBLE" << endl;
	else{
		ans.push_back(ans[0]);
		cout << sz(ans) << endl;
		for(auto i : ans)
			cout << i << " ";
		cout << endl;
	}
	return 0;
}
