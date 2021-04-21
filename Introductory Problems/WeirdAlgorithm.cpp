#include <bits/stdc++.h>
 
using namespace std;
 
#define all(x) x.begin(), x.end()
#define sz(x) (int) x.size()
#define endl '\n'
 
typedef long long ll;
typedef tuple <int, int, int> tp;
typedef pair <int, int> ii;

int main(){
	ll n;
	cin >> n;
	while(true){
		cout << n << " ";
		if(n == 1)
			break;
		if(n&1)
			n = 3*n+1;
		else
			n = n/2;
	}
	return 0;
}
