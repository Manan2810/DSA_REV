#include<iostream>
#include<vector>
using namespace std;

void DFS(vector<vector<int> >& adjMat, vector<int>& visited, int start){
    visited[start]=1;
    cout<<start<<endl;
    for(int i=0;i<adjMat.size();i++){
        if(start==i){
            continue;
        }
        if(!visited[i] && adjMat[start][i]==1){
            DFS(adjMat,visited,i);
        }
    }
}

int main(){
    // adjesancy list

    // adjesancy matrix
    int n;
    cout<<"enter number of nodes: "<<endl;
    cin>>n;
    int e;
    cout<<"enter number of edges: "<<endl;
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
        if(visited[i]==0){
            DFS(adjMat,visited,i);
        }
    }

}