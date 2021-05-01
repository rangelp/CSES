#include <bits/stdc++.h>
 
using namespace std;
 
#define all(x) x.begin(), x.end()
#define sz(x) (int) x.size()
#define endl '\n'
 
typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> ii;
typedef pair <ll, ll> pll;
 
#define maxn 1010
 
int v[maxn][maxn], dp[maxn][maxn];
 
void build(int n, int m){
	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= m; j++){
			if(i == 0 or j == 0){
				dp[i][j] = 0;
				continue;
			}
			dp[i][j] = v[i][j]+dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];
		}
	}
}
 
int query(int x1, int y1, int x2, int y2){
	return dp[x2][y2]-dp[x1-1][y2]-dp[x2][y1-1]+dp[x1-1][y1-1];
}
 
int main(){
	int n, q;
	cin >> n >> q;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			char c;
			cin >> c;
			v[i][j] = (c == '*');
		}
	}
	build(n, n);
	while(q--){
		int x1, x2, y1, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		cout << query(x1, y1, x2, y2) << endl;
	}
	return 0;
