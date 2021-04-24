#include <bits/stdc++.h>
 
using namespace std;
 
#define all(x) x.begin(), x.end()
#define sz(x) i(int) x.size()
#define endl "\n"
 
typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> ii;
typedef pair <ll, ll> pll;
 
int main(){
	string s;
	cin >> s;
	
	int ans = 0, cnt = 0;
	char last = '$';
 
	for(auto c : s){
		if(c != last){
			last = c;
			ans = max(ans, cnt);
			cnt = 1;
		}
		else
			cnt++;
	}
	
	cout << max(ans, cnt) << endl;
	return 0;
}
