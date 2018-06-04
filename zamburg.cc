#include <iostream>
#include <vector>
#include <queue>

struct roca{
	
	double x,y,r;
};
int zamburguesas(vector<roca>& v,int d){
	queue<int> q;
	vector<bool> visto(v.size(),-1);
	int dmin = -1;
	visto[0] = 0;
	q.push(0);
	bool trobat = false;
	while(not q.empty() and not trobat){
		int pos = q.front();
		roca r = v[pos];
		q.pop();
		if (pos == v.size()-1){
			trobat = true;
			dmin = dist[pos];
		}
		else{
			for(int i=0; i<v.size(); ++i){
				if(dist[i]){
				}
			}
		}	
	}
	return dmin;
}

int main(){

	int nroques;
	double d;
	while(cin >> roques>> d){
		roca roc;
		vector<roca> v(nroques);
		for(int i=0; i<nroques;++i){
			cin >> roc.x >> roc.y >> roc.r;
			v[i] = r;
		}
		int dmin = zamburguesas(v,d);
		if (dmin == -1) cout << "Xof!!!" << endl;
		else cout << dmin << endl;
	
	
	}


}
