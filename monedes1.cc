#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int n;
vector<int> m;
vector<bool> vists;
int cont = 0;
 
void escriu(int x) {
    cout << x << " = ";
    bool primer = true;
    for (int i = 0; i < 2*n; i++) {
        if (vists[i]) {
            if(primer) {
                primer = false;
            }
            else  cout << " + ";
             
            if(i%2 == 0) {
                cout << m[i];
            }
            else cout << m[i] << "p";
        }
    }
    cout << endl;
}
 
void monedes(int x, int sum, int i) {
    if(sum == x) {
		++cont;
        escriu(x);
    }
    else {
        for(int j = i; j < n*2; j++) {
            if ((sum + m[j]) <= x) {
                    vists[j] = true;
                    monedes(x, sum+m[j], i+1);
                    i++;
                    vists[j] = false;
            }
        }
    }
}
 
int main() {
    int x;
    while (cin >> x) {
        cin >> n;
        m = vector<int>(n*2);
        vists = vector<bool>(n*2, false);
        for (int i = 0; i < n*2; i+=2) {
            cin >> m[i];
            m[i+1] = m[i];
        }
        sort(m.begin(), m.end());
        monedes(x, 0, 0);
        cout << "----------" << endl;
        cout << "EL CONTADOR ES " << cont << endl;
        cont = 0;
    }
}
