#include<iostream>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;

bool comp(pair<int,int> p1 , pair<int,int> p2){
    if(p1.second<p2.second) return true;
    if(p1.second>p2.second) return false;
    if(p1.first>p2.first) return true;
    return false;
}

void algos(){
    // sort(start, index till where u want to sort)
    // sort(start,end,greater<int>)  -> decreasing order
    vector<pair<int,int> > vecPair;
    // sort it according to second element
    // if second element same then sort it according to first and that too in decreasing order
    sort(vecPair.begin(),vecPair.end(),comp); // comp is a self written comparator(boolean function)


    int num = 7;
    int cnt = __builtin_popcount(num); //  in case of 7 ans is 3 returns the number of 1's in the binary form of the number like 7 binary form is 111

    long long num2 = 123445678909876543;
    int cnt2 =  __builtin_popcount(num2);

    string s = "123";
    do{
        cout<<s<<endl;
    }while(next_permutation(s.begin(),s.end()));

    // like if the string is 231 then it would have printed 231 312 321 so it is advised to sort first 
    // int maxi = *max_element(a,a+n); {1,2,6,3,10} -> gives 10 as answer


}