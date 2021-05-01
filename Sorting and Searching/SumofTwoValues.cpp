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
	int n, x;
	cin >> n >> x;
	vector <ii> v(n);
	for(int i = 0; i < n; i++){
		cin >> v[i].first;
		v[i].second = i+1;
	}
	sort(all(v));
	int l = 0, r = n-1;
	while(l < r){
		if(v[l].first+v[r].first == x){
			cout << v[l].second << " " << v[r].second << endl;
			return 0;
		}
		else if(v[l].first+v[r].first > x)
			r--;
		else
			l++;
	}
	cout << "IMPOSSIBLE" << endl;
	return 0;
}
