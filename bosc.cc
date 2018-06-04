#include <iostream>
#include <vector>
using namespace std;
 
typedef vector<int> VE;
typedef vector< VE > VVE;
 
VVE llegir_graf(int n, int m) {
    VVE g = VVE(n);
    int x, y;
    for (int j = 0; j < m; j++) {
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    return g;
}

void cerca_cicles(const VVE& g, vector<bool>& vis, int i, int pare, bool& b) {
    if (!vis[i]) {
        vis[i] = true;
        for (int j = 0; j < g[i].size(); j++) {
            if (g[i][j] != pare) //no s'ha d'operar si el vèrtex és el seu pare ja que detectariem un cicle fals
                cerca_cicles(g, vis, g[i][j], i, b);
                if (b) return;
        }
    }
    else b = true;
}
 
void dfs(const VVE& g) {
    vector<bool> vis(g.size(), false);
    int na = 0; //#arbres
    for (int i = 0; i < g.size(); i++) {
        if (!vis[i]) {
            bool b = false;
            cerca_cicles(g, vis, i, i, b);
            if (b) {
                cout << "no" << endl;
                return; //si es troba algun cicle no cal operar més
            }
            else na++;
        }
    }
    cout << na << endl;
}
 
int main() {
    int n, m;
    while (cin >> n >> m) {
        VVE g;
        g = llegir_graf(n, m); //representació amb una llista d'adjacència
        dfs(g);
    }
}
