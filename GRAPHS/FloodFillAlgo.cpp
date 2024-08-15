#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<vector<int> > floodFill(vector<vector<int> >& grid,vector<vector<int> >& visited,int sr,int sc,int newColor){
    vector<vector<int> > ans=grid; 
    queue<pair<int,int> > q;
    vector<int> delRow = {-1,0,1,0};
    vector<int> delCol = {0,1,0,-1};
    visited[sr][sc]=1;
    ans[sr][sc]=newColor;
    q.push(make_pair(sr,sc));
    while(!q.empty()){
        int currRow = q.front().first;
        int currCol = q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int nrow = currRow+delRow[i];
            int ncol = currCol+delCol[i];
            if(nrow>=0 && nrow<grid.size() && ncol>=0 && ncol<grid[0].size() && !visited[nrow][ncol] && grid[nrow][ncol]==1){
                q.push(make_pair(nrow,ncol));
                visited[nrow][ncol]=1;
                ans[nrow][ncol]=newColor;
            }
        }
    }
    return ans;
}


int main(){
    int n;
    cin>>n;
    int m;
    cin>>m;
    vector<vector<int> > grid(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int a;
            cin>>a;
            grid[i][j]=a;
        }
    }
    vector<vector<int> > visited(n,vector<int>(m,0));
    int sr;
    int sc;
    cin>>sr>>sc;
    int newCol;
    cin>>newCol;
    vector<vector<int> > ans;
    ans=floodFill(grid,visited,sr,sc,newCol);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[0].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }

}