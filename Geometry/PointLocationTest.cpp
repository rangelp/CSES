#include <bits/stdc++.h>
 
using namespace std;
 
#define all(x) x.begin(), x.end()
#define sz(x) (int) x.size()
#define endl '\n'
 
typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> ii;
typedef pair <ll, ll> pll;
 
typedef double T;
 
struct pt{
	T x, y;
	pt operator + (pt p){ return {x+p.x, y+p.y};}
	pt operator - (pt p){ return {x-p.x, y-p.y};}
	pt operator * (T d) { return {x*d, y*d};}
	pt operator / (T d) {return {x/d, y/d};}
};
 
T cross(pt v, pt w){
	return v.x*w.y-v.y*w.x;
}
 
T orient(pt a, pt b, pt c){
	return cross(b-a, c-a);
}
 
int main(){
	int n;
	pt a, b, c;
	cin >> n;
	while(n--){
		cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;
		T clock = orient(a, b, c);
		if(clock == 0)
			cout << "TOUCH" << endl;
		else if(clock < 0)
			cout << "RIGHT" << endl;
		else
			cout << "LEFT" << endl;
	}
	return 0;
}
