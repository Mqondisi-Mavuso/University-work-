#include <bits/stdc++.h> 

using namespace std;
const int MAX_E=2005;

const int MAX_V=1005; struct edge{
	int from,to,cost;
};



edge es[MAX_E];
int d[MAX_V];
int V,E;                // the vertices represent the stars
                        // the edges represent the wormholes

bool find_negative_loop(){
	memset(d,0,sizeof(d));
	for(int i=0;i<V;i++){
		for(int j=0;j<E;j++){
			edge e=es[j];
          	if(d[e.to]>d[e.from]+e.cost){
				d[e.to]=d[e.from]+e.cost;
				if(i==V-1) return true;
			}
		}
	}
return false;
}
int main(){
	ios::sync_with_stdio(false);
	int t; 
    cin>>t; 
  	while(t--){
		cin>>V>>E;
		for(int i=0;i<E;i++)
        	cin>>es[i].from>>es[i].to>>es[i].cost;
      	if(find_negative_loop()) cout<<"possible"<<endl;
		else
			cout<<"not possible"<<endl;
	}
	return 0;
}