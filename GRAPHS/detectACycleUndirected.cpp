#include<iostream>
#include<vector>
#include<queue>
using namespace std;
bool DetectCycleUndirectedBFS(vector<vector<int> >& adjMat,vector<int>& visited,int start){
    visited[start]=1;
    queue<pair<int,int> > q;
    q.push(make_pair(0,-1));
    while(!q.empty()){
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();
        for(int i=0;i<adjMat.size();i++){
            if(i==node){
                continue;
            }
            if(!visited[i] && adjMat[node][i]==1){
                visited[i]=1;
                q.push(make_pair(i,node));
            }
            else if(visited[i] && i!=parent && adjMat[node][i]==1){
                return true;
            }
        }
    }
    return false;
}

bool DetectCycleUndirectedDFS(vector<vector<int> >& adjMat,vector<int>& visited,int start,int parent){
    visited[start]=1;
    for(int i=0;i<adjMat.size();i++){
        if(i==start){
            continue;
        }
        if(adjMat[start][i]==1){
            if(!visited[i]){
                if(DetectCycleUndirectedDFS(adjMat,visited,i,start)==true){
                    return true;
                }
            }
            else if(i!=parent){
                return true;
            }
        }
    }
    return false;
}

int main(){
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
    bool ans = DetectCycleUndirectedDFS(adjMat,visited,0,-1);
    if(ans){
        cout<<"Cycle is present"<<endl;
    }
    else{
        cout<<"Cycle is not present"<<endl;
    }
}