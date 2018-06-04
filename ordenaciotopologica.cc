#include <iostream>
#include <vector>
#include <queue>

using namespace std;


void topological (vector<vector<int> >& G, vector<int>& v){
	
	int n = G.size();
	vector<int> final;
	priority_queue <int,vector<int>,greater<int> > pQ;
	
	for (int i=0; i<G.size();++i) if(v[i] == 0) pQ.push(i);
	
	while (not pQ.empty()){
		
		int new_node = pQ.top();
		pQ.pop();
		final.push(new_node);
		for (int i=0; i<G[new_node].size();++i){
			if (--v[G[new_node][i]] == 0) pQ.push(G[new_node][i]);
			
}

int main(){
	
	int n,m;
	while (cin >> n >> m){
		
		int x,y;
		for (int i=0; i<m; ++i){
			cin >> x >> y;
			G[x].push_back(y);
			v[y]++;
		}
		
		vector<vector<int> > G(n);
		vector<int> v(n);
		topological(G,v);
	}
	
}
