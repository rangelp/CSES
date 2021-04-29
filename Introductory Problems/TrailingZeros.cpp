#include <bits/stdc++.h>
 
using namespace std;
 
#define all(x) x.begin(), x.end()
#define sz(x) (int) x.size()
#define endl '\n'
 
typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> ii;
typedef pair <ll, ll> pll;
 
int solve(int n){
	int cnt = 0;
	for(int i = 5; n/i >= 1; i *= 5)
		cnt += n/i;
	return cnt;
}
 
int main(){
	int n;
	cin >> n;
	cout << solve(n) << endl;
	return 0;
}
