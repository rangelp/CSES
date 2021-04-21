#include <bits/stdc++.h>
 
using namespace std;
 
#define all(x) x.begin(), x.end()
#define sz(x) (int) x.size()
#define endl '\n'
 
typedef long long ll;
typedef tuple <int, int, int> tp;
typedef pair <int, int> ii;

int main(){
	int n, q;
	cin >> n >> q;
	ll prefix[n+1];
	prefix[0] = 0;
	for(int i = 1; i <= n; i++){
		int x;
		cin >> x;
		prefix[i] = x+prefix[i-1];
	}
	while(q--){
		int l, r;
		cin >> l >> r;
		cout << prefix[r]-prefix[l-1] << endl;
	}
	return 0;
}
