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
 
vector <int> g[maxn], d;
vector <int> see;
 
vector <int> toposort(int n){
	priority_queue <int> q;
	for(int i = 1; i <= n; i++)
		if(d[i] == 0)
			q.push(i);
	vector <int> tops;
	while(!q.empty()){
		int	s = q.top();
		q.pop();
		tops.push_back(s);
		for(auto v : g[s])
			if(--d[v] == 0)
				q.push(v);
	}
	reverse(all(tops));
	return tops;
}
 
int main(){
	int n, m;
	cin >> n >> m;
	d.assign(n+1, 0);
	for(int i = 0; i < m; i++){
		int u, v;
		cin >> u >> v;
		g[v].push_back(u);
		d[u]++;
	}
	vector <int> ans = toposort(n);
	for(auto i : ans)
		cout << i << " ";
	cout << endl;
	return 0;
}
