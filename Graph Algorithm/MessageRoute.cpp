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
 
vector <int> g[maxn];
vector <int> path;
 
int bfs(int s, int t){
	vector <int> dist(t+1, 1<<30);
	path.assign(t+1, -1);
	queue <int> q;
	dist[s] = 1;
	q.push(s);
	while(!q.empty()){
		s = q.front();
		q.pop();
		if(s == t)
			return dist[t];
		for(auto v : g[s]){
			if(dist[v] == 1<<30){
				dist[v] = 1+dist[s];
				q.push(v);
				path[v] = s;
			}
		}
	}
	return 1<<30; 
}
 
void get(int u){
	vector <int> ans;
	while(u != -1){
		ans.push_back(u);
		u = path[u];
	}
	reverse(all(ans));
	for(auto i : ans)
		cout << i << " ";
	cout << endl;
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
	int ans = bfs(1, n);
	if(ans == 1<<30)
		cout << "IMPOSSIBLE" << endl;
	else{
		cout << ans << endl;
		get(n);
	}
	return 0;
}
