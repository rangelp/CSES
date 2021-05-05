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
	vector <int> freq(1010101, 0);
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		freq[x]++;
	}
	int ans = 0;
	for(int i = 1000000; i; i--){
		int div = 0;
		for(int j = i; j <= 1000000; j += i){
			div += freq[j];
			if(div > 1){
				ans = i;
				goto resposta;
			}
		}
	}
	resposta: 
		cout << ans << endl;
	return 0;
}
