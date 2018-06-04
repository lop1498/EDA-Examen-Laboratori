#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

void dijkstra(const vector<vector<pair<int,int> > >& v, int a, int b){
	
	vector<bool> visitat(v.size(),false);
	vector<int> distancia(v.size(),-1);
	distancia[a] = 0;
	vector<int> cami(v.size(),-1);
	bool trobat = false;
	priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > pq;
	pq.push({0,a});
	
	while (not pq.empty() and pq.top().second != b){
		
		int node = pq.top().second;
		pq.pop();
		
		if (not visitat[node]){
		
			visitat[node] = true;
			
			for (int i=0; i<v[node].size(); ++i){
				
				pair<int,int> p = v[node][i];
				
				if (distancia[p.second] == -1 or distancia[p.second] > distancia[node] + p.first){
					distancia[p.second] = distancia[node] + p.first;
					cami[p.second] = node;
					pq.push({distancia[p.second],p.second});
				}
			}
		}
	}
	
	if (pq.empty()) cout << "no path from " << a << " to " << b << endl;
	
	else{
		
		stack<int> s;
		while (cami[b] != -1){
			s.push(b);
			b = cami[b];
		}
		
		s.push(b);
		cout << s.top(); s.pop();
		
		while (!s.empty()) {
			cout << " " << s.top();
			s.pop();
		}
		cout << endl;
	}
	
}

int main(){
	
	int n,m;
	
	while (cin >> n >> m){
		
		vector<vector<pair<int,int> > > v(n);
		int x,y,z;
		
		for (int i=0; i<m; ++i){
			cin >> x >> y >> z;
			v[x].push_back(make_pair(z,y));
		}
		
		int a,b;
		cin >> a >> b;
		dijkstra(v,a,b);

	}
	
}
