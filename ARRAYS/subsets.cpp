#include<iostream>
#include<vector>
using namespace std;

void Recursive(vector<int>& nums,vector<int> temp,int index,vector<vector<int> >& ans){
    if(index>=nums.size()){
        ans.push_back(temp);
        return;
    }

    // exclude
    Recursive(nums,temp,index+1,ans);

    // include
    temp.push_back(nums[index]);
    Recursive(nums,temp,index+1,ans);
}

vector<vector<int> > subsets(vector<int>& nums) {
    vector<vector<int> > ans;
    vector<int> temp;
    int index = 0;
    Recursive(nums,temp,index,ans);
    return ans;
}

int main(){
    int n ;
    cin>>n;
    vector<int> nums;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        nums.push_back(a);
    }
    vector<vector<int> > ans = subsets(nums);

    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}