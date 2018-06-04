#include <iostream>
#include <vector>
#include <queue>
 
using namespace std;
 
typedef vector<vector<int>> Graph;
 
bool twoColorable(Graph& G) {
    vector<int> colors(G.size(), -1);
    queue<int> Q;
    for (int i = 0; i < G.size(); ++i) {
        if (colors[i] < 0) {
            Q.push(i);
            colors[i] = 1;
            while (not Q.empty()) {
                int n = Q.front();
                Q.pop();
                for (int j = 0; j < G[n].size(); ++j) {
                    if (colors[G[n][j]] < 0) {
                        Q.push(G[n][j]);
                        colors[G[n][j]] = 1 - colors[n];
                    }
                    else if (colors[G[n][j]] == colors[n])
                        return false;
                }
            }
        }
    }
    return true;
}
 
int main() {
    int n, m;
    while (cin >> n >> m) {
        Graph G(n);
        for (int i = 0; i < m; ++i) {
            int n1, n2;
            cin >> n1 >> n2;
            G[n1].push_back(n2);
            G[n2].push_back(n1);
        }
        if (twoColorable(G))
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }
}
