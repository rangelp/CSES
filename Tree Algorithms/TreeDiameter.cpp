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
 
vector <int> g[maxn];
int n;
 
ii bfs(int s){
	vector <int> dist(maxn, 1<<30);
	queue <int> q;
	dist[s] = 0;
	q.push(s);
	while(!q.empty()){
		s = q.front();
		q.pop();
		for(auto v : g[s]){
			if(dist[v] == 1<<30){
				dist[v] = 1+dist[s];
				q.push(v);
			}
		}
	}
	ii ans = {-1, -1};
	for(int i = 1; i <= n; i++)
		if(dist[i] > ans.second)
			ans = {i, dist[i]};
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
	cout << bfs(bfs(1).first).second << endl;
	return 0;
}
