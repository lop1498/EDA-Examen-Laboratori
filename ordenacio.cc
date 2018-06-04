#include <iostream>
#include <vector>
using namespace std;
 
typedef vector<vector<int> > Graf;
 
void escriu(vector<int>& solucion, int n){
    for(int i = 0; i < n; ++i){
        if (i == 0) cout << solucion[i];
        else cout << " " << solucion[i];
    }
    cout << endl;
}
 
void ordtopo (const Graf& graf, vector<int>&solucion, vector<int>& pred, int n, int i) {
    if (i == n) escriu(solucion,n);
    else {
        for (int j = 0; j < n; ++j) {
            if (pred[j] == 0) {
                solucion[i] = j;
                --pred[j]; // pondrá pred[j] = -1 => así no lo volverán a coger
                for(int k = 0; k < graf[j].size(); ++k) --pred[graf[j][k]];
                ordtopo(graf,solucion,pred,n,i+1);
                ++pred[j]; // pondrá pred[j] = 0;
                for(int k = 0; k < graf[j].size(); ++k) ++pred[graf[j][k]];
            }
        }
    }
}
 
int main(){
    int n, p;
    cin >> n >> p;
    Graf graf(n);
    vector<int> pred(n,0);
    for (int i = 0; i < p; ++i){
        int a, b;
        cin >> a >> b;
        graf[a].push_back(b);
        ++pred[b];
    }
    vector<int> solucion(n);
    ordtopo(graf,solucion,pred,n,0);
}
