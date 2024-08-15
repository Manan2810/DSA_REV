#include<iostream>
#include<bits/stdc++.h>
#include<map>
using namespace std;

void Map(){
    map<int,int> mp; //stores unique keys in sorted order O(log n )
    mp[1]=3; //key = 1 , value = 3
    mp.insert(make_pair(3,1)); // key = 3 value = 1

    map<pair<int,int>,int > mpp;
    mpp[make_pair(2,3)] = 5;

    for(auto it:mp){
        cout<<"first"<<endl;
        cout<<it.first<<" "<<it.second<<endl;
    }

    cout<<mp[1]<<endl;  //3
    cout<<mp[5]<<endl;  //0 since 5 doesnot exist; makes a new key as well
    cout<<mp.at(6)<<endl; // here it returns an error indicating that key doesnot existes

    for(auto it:mp){
        cout<<"second"<<endl;
        cout<<it.first<<" "<<it.second<<endl;
    }
    
    auto it = mp.find(3);
    cout<<(*it).second<<endl;

    auto it = mp.find(7); //like if 7 is not there it return address of mp.end()
    auto it = mp.lower_bound(3);
    auto it = mp.upper_bound(6);
}

void Multimap(){
    // can store duplicate values in sorted order
}

void Unorderedmap(){
    // can store unique values but not in sorted order O(1) but in worst case (O(n))
}