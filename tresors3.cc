#include <iostream>
#include <vector>
using namespace std;

int tresors = 0;

bool dfs (vector<vector<char> >& v, int f1, int f2, int f, int c){
	
	if (f1 < f and f1 >= 0 and f2 < c and f2 >= 0){
		if (v[f1][f2] == 't'){
			++tresors;
		}
		else if (v[f1][f2] == 'X'){
			return false;
		}
		v[f1][f2] = 'X';
		return dfs(v,f1+1,f2,f,c) or dfs(v,f1-1,f2,f,c) or dfs(v,f1,f2-1,f,c) or dfs(v,f1,f2+1,f,c);
	}
	else return false;
}
int main(){
	
	int f,c;
	cin >> f >> c;
	vector<vector<char> > v(f,vector<char>(c));
	
	for (int i=0; i<f;++i){
		for (int j=0;j<c;++j){
			cin >> v[i][j];
		}
	}
	
	int f1,f2;
	cin >> f1 >> f2;
	
	bool b = dfs(v,f1-1,f2-1,f,c); 
	
	cout << tresors << endl;
}
