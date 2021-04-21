#include <bits/stdc++.h>
 
using namespace std;
 
#define all(x) x.begin(), x.end()
#define sz(x) (int) x.size()
#define endl '\n'
 
typedef long long ll;
typedef tuple <int, int, int> tp;
typedef pair <int, int> ii;

int main(){
	int n;
	cin >> n;
	set <int> st;
	while(n--){
		int x;
		cin >> x;
		st.insert(x);
	}
	cout << sz(st) << endl;
	return 0;
}
