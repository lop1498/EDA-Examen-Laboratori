#include <iostream>
#include <vector>
#include <stack>
using namespace std;

typedef vector<vector<char> > Graf;

bool dfs(Graf& G,int n, int m, int f, int c){
	if (n >= 0 and n<f and m>=0 and m<c){
		if(G[n][m] == 't') return true;
		if(G[n][m] == 'X') return false;
		G[n][m] = 'X';
		return dfs(G,n+1,m,f,c) or dfs(G,n-1,m,f,c) or dfs(G,n,m+1,f,c) or dfs(G,n,m-1,f,c);
	}
	else return false;
	
}

int main(){
	
	int f,c;
	cin >> f >> c;
	Graf mapa(f,vector<char>(c));
	vector<bool> vist(f,false);

	for (int i=0; i<f; ++i){
		for (int j=0; j<c; ++j){
			cin >> mapa[i][j];
		}
	}
	
	int f1,f2;
	cin >> f1 >> f2;
	
	bool b = dfs(mapa,f1-1,f2-1,f,c);
	
	if (b) cout << "yes" << endl;
	else cout << "no" << endl;
	
}
