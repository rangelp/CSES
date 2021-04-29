#include <bits/stdc++.h>
 
using namespace std;
 
#define all(x) x.begin(), x.end()
#define sz(x) (int) x.size()
#define endl '\n'
 
typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> ii;
typedef pair <ll, ll> pll;
 
int solve(int x){
	set <int> ans;
	for(int i = 1; i <= sqrt(x); i++){
		if(x%i == 0){
			ans.insert(i);
			ans.insert(x/i);
		}
	}
	return sz(ans);
}
 
int main(){
	int n;
	cin >> n;
	while(n--){
		int x;
		cin >> x;
		cout << solve(x) << endl;
	}
	return 0;
}
