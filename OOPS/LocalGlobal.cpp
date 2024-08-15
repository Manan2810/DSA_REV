#include<iostream>
using namespace std;

int x = 100; //Global Variable

// most local ko zyada preference in that particular scope
int main(){
    x=20; //global x
    int x = 4; // local to main function
    
    cout<<x<<endl;
    cout<<::x<<endl; //access the global variable with :: if local name and global name same

    {
        int x = 50;
        cout<<x<<endl;
        cout<<::x<<endl;
    }
    return 0;
}