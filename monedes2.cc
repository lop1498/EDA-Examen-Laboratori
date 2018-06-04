#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> v;
vector<bool> vist;
int cont = 0;

void escriu(int x){
	
	cout << x << " = ";
    bool primer = true;
    for (int i = 0; i < 2*n; i++) {
        if (vist[i]) {
            if(primer) {
                primer = false;
            }
            else  cout << " + ";
             
            if(i%2 == 0) {
                cout << v[i];
            }
            else cout << v[i] << "p";
        }
    }
    cout << endl;
}


void monedes(int x, int sum, int i){
	
	if (sum == x) ++cont;
	else{
		for (int j=i; j<n; ++j){
			if ((sum + v[j]) <= x){
				
				if (not v[j]){	
					vist[j] = true;
					monedes(x,sum+v[j],i);
					++i;
				}
				if (v[j]){
					monedes(x,sum+v[j],i++);
					++i;
				}
			}
		}
	}
}

int main(){
	
	int x,p;
	
	while (cin >> x >> p){
		
		n = p;
		v = vector<int>(p);
		vist = vector<bool>(p,false);
		for (int i=0; i<p; i++){
			 cin >> v[i];
			 v[i+1] = v[i];
		 }
		sort(v.begin(),v.end());
		monedes(x,0,0);
		if (cont >= 3) cout << cont -1 << endl;
		else cout << cont << endl;
		cont = 0;
		
	}
}
