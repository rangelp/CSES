#include <bits/stdc++.h>
 
using namespace std;
 
#define all(x) x.begin(), x.end()
#define sz(x) i(int) x.size()
#define endl "\n"
 
typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> ii;
typedef pair <ll, ll> pll;
 
#define maxn 210101
 
vector <int> g[maxn];
vector <int> dp[2];
int n;
 
ii bfs(int s, int fg){
	vector <int> dist(maxn, 1<<30);
	queue <int> q;
	dist[s] = 0;
	q.push(s);
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(auto v : g[u])
			if(dist[v] == 1<<30)
				dist[v] = 1+dist[u], q.push(v);
	}
	ii ans = {-1, -1};
	for(int i = 1; i <= n; i++)
		if(dist[i] > ans.second)
			ans = {i, dist[i]};
	dp[fg] = dist;
	return ans;
}
 
int main(){
	cin >> n;
	for(int i = 0; i < n-1; i++){
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	int l = bfs(1, 0).first;
	int r = bfs(l, 0).first;
	bfs(r, 1);
	for(int i = 1; i <= n; i++)
		cout << max(dp[0][i], dp[1][i]) << " ";
	cout << endl;
	return 0;
}
