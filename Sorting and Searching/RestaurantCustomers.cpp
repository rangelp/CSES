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
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	set <int> events;
	map <int, int> IN, OUT;
	for(int i = 0; i < n; i++){
		int in, out;
		cin >> in >> out;
		events.insert(in);
		events.insert(out);
		IN[in]++;
		OUT[out]++;
	}
	int ans = 0;
	int rest = 0;
	for(auto i : events){
		if(IN.find(i) != IN.end())
			rest += IN[i];
		if(OUT.find(i) != OUT.end())
			rest -= OUT[i];
		ans = max(ans, rest);
	}
	cout << ans << endl;
	return 0;
}
