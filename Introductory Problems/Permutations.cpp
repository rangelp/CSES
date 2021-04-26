#include <bits/stdc++.h>
 
using namespace std;
 
#define all(x) x.begin(), x.end()
#define sz(x) (int) x.size()
#define endl '\n'
 
typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> ii;
typedef pair <ll, ll> pll;
 
int main(){
	int n;
	cin >> n;
	vector <int> ans, odd;
	for(int i = 1; i <= n; i++){
		if(!(i&1))
			ans.push_back(i);
		else
			odd.push_back(i);
	}
	for(auto i : odd)
		ans.push_back(i);
	bool ok = true;
	for(int i = 1; i < n and ok; i++){
		//cout << ans[i] << " " << ans[i-1] << " " <<  abs(ans[i]-ans[i-1]) << endl;
		ok &= abs(ans[i]-ans[i-1]) > 1;
	}
	if(ok){
		for(auto i : ans)
			cout << i << " ";
		cout << endl;
	}
	else
		cout << "NO SOLUTION" << endl;
	return 0;
}
