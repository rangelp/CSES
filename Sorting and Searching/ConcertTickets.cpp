#include <bits/stdc++.h>
 
using namespace std;
 
#define all(x) x.begin(), x.end()
#define sz(x) (int) x.size()
#define endl '\n'
 
typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> ii;
typedef pair <ll, ll> pll;
 
const ll mod = 1e9+7;
 
int main(){
	int n, m;
	cin >> n >> m;
	map <int, int> mp;
	vector <int> v(n);
	set <int> st;
	for(auto &i : v){
		cin >> i;
		mp[i]++;
		st.insert(i);
	}
	while(m--){
		int u;
		cin >> u;		
		if(sz(st) == 0){
			cout << -1 << endl;
			continue;
		}
		auto ptr = st.upper_bound(u);
		if(ptr == st.end())
			ptr--;
		if(*ptr <= u){
			if(mp[*ptr] == 0)
				cout << -1 << endl;
			else{
				cout << *ptr << endl;
				mp[*ptr]--;
				if(mp[*ptr] == 0)
					st.erase(*ptr);
			}
		}
		else{
			ptr--;
			if(mp[*ptr] == 0)
				cout << -1 << endl;
			else if(*ptr <= u){
				cout << *ptr << endl;
				mp[*ptr]--;
				if(mp[*ptr] == 0)
					st.erase(*ptr);
			}
			else
				cout << -1 << endl;
		}
	}
	return 0;
}
