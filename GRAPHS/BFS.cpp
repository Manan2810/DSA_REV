#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void BFS(vector<vector<int> >&adjMat , vector<int>& visited,int start){
    visited[start]=1;
    queue<int> q;
    q.push(start);
    while(!q.empty()){
        int node = q.front();
        cout<<node<<endl;
        q.pop();
        for(int i=0;i<adjMat.size();i++){
            if(node == i){
                continue;
            }
            if(!visited[i] && adjMat[node][i]==1){
                visited[i]=1;
                q.push(i);
            }
        }
    }

}


int main(){
    int n;
    cout<<"enter the number of nodes: "<<endl;
    cin>>n;
    int e;
    cout<<"enter the number of edges: "<<endl;
    cin>>e;
    vector<vector<int> > adjMat(n,vector<int>(n,0));
    for(int i=0;i<e;i++){
        int f,s;
        cin>>f>>s;
        adjMat[f][s]=1;
        adjMat[s][f]=1;
    }
    vector<int> visited(n,0);
    for(int i=0;i<n;i++){
        if(!visited[i]){
            BFS(adjMat,visited,i);
        }
    }

}