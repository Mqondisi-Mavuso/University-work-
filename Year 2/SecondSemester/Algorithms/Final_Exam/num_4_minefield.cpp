#include<bits/stdc++.h> 
#include <vector>

using namespace std;

int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
int numMinefield(vector<vector<int>> &Map) {
        int n=Map.size(),m=Map[0].size(); 
        vector <vector<int>> vis(n,vector<int>(m,0));
        int res=0; 
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(Map[i][j]==1 && vis[i][j]==0){
                int count=0;	
                stack<pair<int,int>> s;
                s.push({i,j});	
                vis[i][j]=1;
                while(s.size()>0){
                    count++;
                    int x=s.top().first;
                    int y=s.top().second;	
                    s.pop();
                    for(int i=0;i<4;i++){
                        int u=x+dx[i];	
                        int v=y+dy[i];
                        if(u>=0 && u<n && v>=0 && v<m && Map[u] [v]==1 && vis[u][v]==0){
                            vis[u][v]=1;
                            s.push({u,v});
                        }
                    }
                }	              
            res = count;
            }
        }
    }
    return res;	
} 

int main() { 
    int n,m;
    cout << "Enter the size of Map(row,column): "; 
    cin >> n >> m;
    vector <vector<int>> Map (n,vector<int>(m,0));
    cout << "Enter the map" << endl;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) {
            cin >> Map[i][j]; 
        }
    } 
    cout <<"Number of minefields: " << numMinefield(Map) << endl; 
    return 0;
}

// test cases 
/* 
4 
5
0 1 1 0 0
1 1 0 1 1
0 0 1 0 0
0 0 1 1 0

output : 3
*/