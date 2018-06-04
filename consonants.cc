#include <iostream>
#include <vector>
 
using namespace std;
 
 
void escribir(vector<char> &solucion) {
    for (int i = 0; i < solucion.size(); i++) {
        cout << solucion[i];
    }
    cout << endl;
}
 
void permutacions(int i, vector<bool> &consonantes_usadas, vector<bool> &vocales_usadas,vector<char> &consonantes, vector<char> &vocales, vector<char> &solucion) {
    int n = consonantes.size();
    if (i == n) escribir(solucion);
    else {
        for (int j = 0; j < n; j++) {
            if (not consonantes_usadas[j]) {
                solucion[2*i] = consonantes[j];
                consonantes_usadas[j] = true;
                for (int k = 0; k < n; k++) {
                    if (not vocales_usadas[k]) {
 
                        vocales_usadas[k] = true;
                        solucion[2*i + 1] = vocales[k];
                        permutacions(i + 1, consonantes_usadas, vocales_usadas,consonantes, vocales, solucion);
                        vocales_usadas[k] = false;
                    }
 
                }
                consonantes_usadas[j] = false;
            }
 
        }
    }
 
}
 
int main() {
    int n;
    cin >> n;
    vector<char> consonantes(n);
    for (int i = 0; i < n; i++) cin >> consonantes[i];
    vector<char> vocales(n);
    for (int i = 0; i < n; i++) cin >> vocales[i];
    vector<char> solucion(2*n);
    vector<bool> consonantes_usadas(n, false);
    vector<bool> vocales_usadas(n, false);
    permutacions(0, consonantes_usadas, vocales_usadas, consonantes, vocales, solucion);
}
