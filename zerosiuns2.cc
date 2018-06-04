#include <iostream>
#include <vector>

using namespace std;


void write_vector(const vector<int> &v)
{
    if (v.size() != 0) {
        cout << v[0];
        for (int i = 1; i < v.size(); ++i)
            cout << " " << v[i];
    }
    cout << endl;
}
 
void zerosiuns(vector<int>& v, int i, int num){
	
	int n = v.size();
	if (i == n){
		 if (num == 0) write_vector(v);
	}
	else if ((n-i) >= num){
		v[i] = 0;
		zerosiuns(v,i+1,num);
		if (num>0){
			v[i] = 1;
			zerosiuns(v,i+1,num-1);
		}
	}
}

int main(){
	
	int a,b;
	cin >> a >> b;
	
	vector<int> v1(a);
	zerosiuns(v1,0,b);
	
}
