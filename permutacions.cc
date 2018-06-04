#include <iostream>
#include <vector>
#include <string>

using namespace std;

void write_vector(const vector<string>& v){
	
	cout << "(" << v[0];
	for (int i=1; i<v.size(); ++i) cout << "," << v[i];
	cout << ")" << endl;
	
}

void permutacions(vector<string>& v, int i, vector<bool>& utilitzats){
	
	int s = v.size();
	
	if (i == s) write_vector(v);
	
	else{
		for (int j=i; j<s; ++j){
			string aux = v[i];
			v[i] = v[j];
			v[j] = aux;
			permutacions(v,i+1,utilitzats);
			aux = v[i];
			v[i] = v[j];
			v[j] = aux;
		}
	}
}

int main(){
	
	int n;
	cin >> n;
	vector<string> frase(n);
	vector<bool> b(n,false);
	for (int i=0; i<n; ++i) cin >> frase[i];
	permutacions(frase,0,b);
}
