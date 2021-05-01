#include <bits/stdc++.h>
 
using namespace std;
 
#define all(x) x.begin(), x.end()
#define sz(x) (int) x.size()
#define endl '\n'
 
typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> ii;
typedef pair <ll, ll> pll;
 
#define maxn 101010
 
vector <int> g[maxn], part;
 
bool bfs(int s){
	queue <int> q;
	part[s] = 0;
	q.push(s);
	bool ok = true;
	while(!q.empty() and ok){
		s = q.front();
		q.pop();
		for(auto v : g[s]){
			if(part[v] == -1){
				part[v] = 1-part[s];
				q.push(v);
			}
			if(part[s] == part[v])
				ok = false;
		}
	}
	return ok;
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
	bool ans = true;
	part.assign(n+1, -1);
	for(int i = 1; i <= n; i++)
		if(part[i] == -1)
			ans &= bfs(i);
	if(ans){
		for(int i = 1; i <= n; i++)
			cout << part[i]+1 << " ";
		cout << endl;
	}
	else{
		cout << "IMPOSSIBLE" << endl;
	}
	return 0;
}
