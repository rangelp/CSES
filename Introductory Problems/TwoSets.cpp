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
	ll n;
	cin >> n;
	ll sum = 0;
	for(int i = 1; i <= n; i++)
		sum += i;
	if(sum&1)
		cout << "NO" << endl;
	else{
		ll get = sum/2;
		set <ll> s1, s2;
		for(int i = n; i >= 1; i--){
			if(get-i >= 0){
				s1.insert(i);
				get -= i;
			}
			else
				s2.insert(i);
		}
		cout << "YES" << endl;
		cout << s1.size() << endl;
		for(auto i : s1)
			cout << i << " ";
		cout << endl;
		cout << s2.size() << endl;
		for(auto i : s2)
			cout << i << " ";
		cout << endl;
	}
	return 0;
}
