#include <bits/stdc++.h>
 
using namespace std;
 
#define all(x) x.begin(), x.end()
#define sz(x) (int) x.size()
#define endl '\n'
 
typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> ii;
typedef pair <ll, ll> pll;
 
vector <string> get(int n){
	vector <string> ans;
	ans.push_back("");
	for(int i = 1; i <= n; i++){
		vector <string> cpy;
		cpy = ans;
		reverse(all(cpy));
		for(int j = 0; j < sz(ans); j++)
			ans[j].insert(ans[j].begin(), '0');
		for(int j = 0; j < sz(cpy); j++)
			cpy[j].insert(cpy[j].begin(), '1');
		for(auto j : cpy)
			ans.push_back(j);
	}
	return ans;
}
 
int main(){
	int n;
	cin >> n;
	vector <string> ans = get(n);
	for(auto v : ans)
		cout << v << endl;
	return 0;
}
