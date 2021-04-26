#include <bits/stdc++.h>
 
using namespace std;
 
#define all(x) x.begin(), x.end()
#define sz(x) (int) x.size()
#define endl '\n'
 
typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> ii;
typedef pair <ll, ll> pll;

/* Divide the string into sets where each part contains ACTG and take the last letter of the set */

int main(){
	string s, ans, dna = "ACGT";
	cin >> s;
	set <char> sq;
	int cnt = 0;
	for(auto i : s){
		sq.insert(i);
		if(sz(sq) == 4){
			sq.clear();
			cnt++;
			ans += i;
		}
	}
	for(auto c : dna){
		if(sq.find(c) == sq.end()){
			ans += c;
			break;
		}
	}
	cout << ans << endl;
	return 0;
