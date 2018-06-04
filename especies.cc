#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

int main(){
	
	char n,m,x,y;
	vector<char> especies(n);
	for (int i=0; i<n; ++i) cin >> especies[i];
	map<char,vector<char> > incomp;
	cin >> m;
	map<char,set>::iterator it;
	
	for (int i=0; i<m; ++i){
		
		cin >> x >> y;
		it = incomp.find(x);
		if (it == incomp.end()){
			vector<char> v;
			v.push_back(y);	
			incomp.insert(make_pair(x,v));
		}
		else it->second.push_back(y);
		
	}
}
