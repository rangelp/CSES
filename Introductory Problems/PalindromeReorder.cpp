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
	string s;
	cin >> s;
	map <char, int> mp;
	for(auto c : s)
		mp[c]++;
	if(sz(s)&1){
		string p[2];
		vector <char> temp;
		for(auto &[c, t] : mp){
			if(t&1){
				temp.push_back(c);
				t--;
			}
			for(int i = 1; i <= t; i++)
					p[i&1] += c;
		}
		if(sz(temp) > 1)
			cout << "NO SOLUTION" << endl;
		else{
			string ans;
			ans += p[0];
			ans += temp[0];
			reverse(all(p[1]));
			ans += p[1];
			cout << ans << endl;
		}
	}
	else{
		string p[2];
		for(auto [c, t] : mp){
			if(t&1){
				cout << "NO SOLUTION" << endl;
				return 0;
			}
			else
				for(int i = 1; i <= t; i++)
					p[i&1] += c;
		}
		string ans;
		ans += p[0];
		reverse(all(p[1]));
		ans += p[1];
		cout << ans << endl;
	}
	return 0;
}
