#include <iostream>
#include <queue>
using namespace std;
 
struct posicio{
    int f;
    int c;
    int d;
};
 
int distancia(int f, int c, vector< vector<char> > mapa) {
    int min_dist = 0;
    bool trobat = false;
    queue<posicio> pending;
    vector< vector<bool> > visitats ((int)mapa.size(), vector<bool>((int)mapa[0].size(),false));
    posicio act;
    act.f = f;
    act.c = c;
    act.d = 0;
    pending.push(act);
    while (not trobat and not pending.empty()){
        posicio aux = pending.front();
        pending.pop();
        if (not visitats[aux.f][aux.c]) {
            visitats[aux.f][aux.c] = true;
            if (mapa[aux.f][aux.c] == 't')
            {
                trobat = true;
                min_dist = aux.d;
            }
            else if (mapa[aux.f][aux.c] != 'X') {
                if (aux.f > 0 and not visitats[aux.f-1][aux.c]) {
                    posicio amunt;
                    amunt.f = aux.f-1;
                    amunt.c = aux.c;
                    amunt.d = aux.d+1;
                    pending.push(amunt);
                }
                if (aux.f < (int)mapa.size()-1 and not visitats[aux.f+1][aux.c]) {
                    posicio avall;
                    avall.f = aux.f+1;
                    avall.c = aux.c;
                    avall.d = aux.d+1;
                    pending.push(avall);
                }
                if (aux.c > 0 and not visitats[aux.f][aux.c-1]) {
                    posicio esquerre;
                    esquerre.f = aux.f;
                    esquerre.c = aux.c-1;
                    esquerre.d = aux.d+1;
                    pending.push(esquerre);
                }
                if (aux.c < (int)mapa[0].size()-1 and not visitats[aux.f][aux.c+1]) {
                    posicio dreta;
                    dreta.f = aux.f;
                    dreta.c = aux.c+1;
                    dreta.d = aux.d+1;
                    pending.push(dreta);
                }
            }
        }
    }
    return min_dist;
}
 
int main() {
    int n, m;
    cin >> n >> m;
    vector< vector<char> > mapa (n, vector<char>(m));
    for (int i = 0; i < (int)mapa.size(); ++i) {
        for (int j = 0; j < (int)mapa[0].size(); ++j) cin >> mapa[i][j];
    }
    int f, c;
    cin >> f >> c;
    int dis_min = distancia(f-1,c-1,mapa);
    if (dis_min > 0) cout << "distancia minima: " << dis_min << endl;
    else cout << "no es pot arribar a cap tresor" << endl;
}
