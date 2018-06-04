#include <iostream>
#include <vector>

using namespace std;

void write_vector(const vector<int>& v){
	
	cout << "(" << v[0];
	
	for(int i=1; i<v.size(); ++i){
		cout << "," << v[i];
	}
	cout << ")" << endl;
}

void dunaena(vector<int>& v, int i){
	
	int n = v.size();
	int sm = 2*n;
	
	if (i == n) write_vector(v);
	
	else{
		
		for (int j=i; j<n; ++j){
			
			int aux = v[i];
			v[i] = v[j];
			v[j] = aux;
			dunaena(v,i+1);
			aux = v[i];
			v[i] = v[j];
			v[j] = aux;
			
		}
	}
}

int main(){

	int n;
	cin >> n;
	vector<int> v(n);
	dunaena(v,0);

}
