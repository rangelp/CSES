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
	while(n--){
		int x, y;
		cin >> x >> y;
		if(x < y)
			swap(x, y);
		if(x > 2*y)
			cout << "NO" << endl;
		else if((x+y)%3 == 0)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}
