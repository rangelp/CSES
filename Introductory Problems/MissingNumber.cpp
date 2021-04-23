#include <bits/stdc++.h>
 
using namespace std;
 
#define all(x) x.begin(), x.end()
#define sz(x) (int) x.size()
#define endl '\n'
 
typedef long long ll;
typedef tuple <int, int, int> tp;
typedef pair <int, int> ii;
 
int main(){
	int n;
	cin >> n;
	ll ans = 0;
    for(int i = 1; i <= n; i++)
        ans ^= i;
	for(int i = 0; i < n-1; i++){
		int x;
		cin >> x;
		ans ^= x;
	}
	cout << ans << endl;
	return 0;
}
