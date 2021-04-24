#include <bits/stdc++.h>
 
using namespace std;
 
#define all(x) x.begin(), x.end()
#define sz(x) (int) x.size()
#define endl "\n"
 
typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, ll> ii;
typedef pair <ll, ll> pll;
 
#define maxn 101010
 
vector <pll> g[maxn];
const ll mod = 1e9+7;
 
void dijkstra(int s, int t){
	vector <ll> dist(t+1, 1LL<<50), cntPath(t+1, 0), minPath(t+1, 0), maxPath(t+1, 0);
	priority_queue <pll, vector <pll>, greater <pll>> pq;
 
	dist[s] = 0;
	pq.push({0, s});
	cntPath[s] = 1;
 
	while(!pq.empty()){
		auto [w, u] = pq.top();
		pq.pop();
 
		if(w > dist[u])
			continue;
 
		for(auto [v, c] : g[u]){
			if(dist[v] > dist[u]+c){
				dist[v] = dist[u]+c;
				pq.push({dist[v], v});
				maxPath[v] = 1+maxPath[u];
				minPath[v] = 1+minPath[u];
				cntPath[v] = cntPath[u];
			}
			else if(dist[v] == dist[u]+c){
				cntPath[v] += cntPath[u], cntPath[v] %= mod;
				maxPath[v] = max(maxPath[v], 1+maxPath[u]);
				minPath[v] = min(minPath[v], 1+minPath[u]);
			}
		}
	}
 
	cout << dist[t] << " " << cntPath[t] << " " << minPath[t] << " " << maxPath[t] << endl;
}
 
int main(){
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int u, v, w;
		cin >> u >> v >> w;
		g[u].push_back({v, w});
	}
	dijkstra(1, n);
	return 0;
}
