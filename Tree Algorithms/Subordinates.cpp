#include <bits/stdc++.h>
 
using namespace std;
 
#define all(x) x.begin(), x.end()
#define sz(x) (int) x.size()
#define endl '\n'
 
typedef long long ll;
typedef tuple <int, int, int> tp;
typedef pair <int, int> ii;

#define maxn 212345

vector <int> g[maxn];
vector <int> ans;

int dfs(int u){
	ans[u] = 1;
	for(auto v : g[u])
		ans[u] += dfs(v);
	return ans[u];
}

int main(){
	int n;
	cin >> n;
	for(int i = 2; i <= n; i++){
		int u;
		cin >> u;
		g[u].push_back(i);
	}
	ans.assign(n+1, -1);
	dfs(1);
	for(int i = 1; i <= n; i++)
		cout << ans[i]-1 << " ";
	cout << endl;
	return 0;
}
