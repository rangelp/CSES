#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
 
#define all(x) x.begin(), x.end()
#define sz(x) (int) x.size()
#define endl '\n'

typedef pair <int, int> ii;

using namespace __gnu_pbds;

template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;


int main(){
	int n, q;
	cin >> n >> q;
	int v[202020];
	Tree <ii> indexSet;
	for(int i = 1; i <= n; i++){
		cin >> v[i];
		indexSet.insert({v[i], i});
	}
	while(q--){
		char c;
		int l, r;
		cin >> c >> l >> r;
		if(c == '!'){
			indexSet.erase({v[l], l});
			v[l] = r;
			indexSet.insert({v[l], l});
		}
		else{
			cout << (indexSet.order_of_key({r, 1e9+7})-indexSet.order_of_key({l-1, 1e9+7})) << endl;
		}
	}
	return 0;
}
