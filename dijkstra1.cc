#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dijkstra(const vector<vector<pair<int,int> > >& v, int x, int y){
	
	vector<bool> visitat(v.size(),false);
	vector<int> distancia(v.size(),-1); //-1 representa infinit
	priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > pq;
	pq.push({0,x});
	distancia[x] = 0;
	
	while (not pq.empty()){
		
		int node = pq.top().second;
		pq.pop();
		
		if (not visitat[node]){
			
			visitat[node] = true;
			
			for (int i=0; i<v[node].size();++i){
				
				pair<int,int> p = v[node][i];
				
				if (distancia[p.second] == -1 or distancia[p.second] > (distancia[node]+p.first)){
					distancia[p.second] = distancia[node]+p.first;
					pq.push({distancia[p.second],p.second});
				}
			}
		}
	}
	return distancia[y];
}

int main(){
	

    int n, m;
    while (cin >> n >> m) {
        vector<vector<pair<int,int> > > G(n);
        int u, v, c;
        for (int i = 0; i < m; ++i) {
            cin >> u >> v >> c;
            G[u].push_back({c, v});
        }
        int x, y;
        cin >> x >> y;
        int result = dijkstra(G, x, y);
        if (result == -1) cout << "no path from " << x << " to " << y << endl;
        else cout << result << endl;
    }
}
















