#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    vector<int> v = {3,4,1,2};
    sort(v.begin(),v.end()); // here sort function ki implementation is hidden in the header file.-> abstraction
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    return 0;
}