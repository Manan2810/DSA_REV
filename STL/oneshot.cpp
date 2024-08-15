#include<bits/stdc++.h>
#include<iostream>
#include<list>
#include<deque>
#include<stack>
#include<queue>
#include<set>
#include<unordered_set>
#include<map>
#include<unordered_map>
using namespace std;

// 4 parts of STL
// 1. Algorithm
// 2. Containers
// 3. Functions
// 4. Iterators

// pairs
void Pair(){
    pair<int,int> p = {1,2};
    cout<<p.first<<" "<<p.second<<endl;

    // nested property of pair
    pair<int,pair<int,int> > p2 = {1,{2,3}};
    cout<<p2.first<<" "<<p2.second.first<<" "<<p2.second.second<<endl;

    pair<int,int> arr[] = {{1,2},{3,5},{4,6}};
    cout<<arr[1].second<<endl;
}

void Vector(){
    // vector is a container dynamic in nature that increases its size;
    vector<int> v(5); //{}
    v.push_back(1); // will enter 1 at the end of the vector {1}
    v.emplace_back(2); // {1,2}

    vector<pair<int,int> >vec;
    vec.push_back({1,2});
    vec.emplace_back(1,2); // isme isne assume hi karlia ki 1,2 par hi honge

    vector<int> v2(5,100); // here we are making a vector of size 5 initialised with 100 {100,100,100,100,100}<- this is how our vector looks

    vector<int> v3(5); //here we are making a vector of size 5 initialised with 0 or garbage value

    // copying a vector to another vector
    vector<int> v4(v2); //v4={100,100,100,100,100}

    // iterator
    vector<int>::iterator it = v.begin(); // it points directly to the memory
    it++; // moves to next address
    cout<<*(it)<<" ";

    vector<int>::iterator it = v.end(); // end points to the memory location that is right after the last element of the vector
    // vector<int>::iterator it = v.rbegin(); // rbegin will point to the last element of the vector
    // vector<int>::iterator it = v.rend(); // points to the memory location just before the first element

    cout<<v[0]<<" "<<v.at(0);
    cout<<v.back()<<endl; // back points to the last eleemnt and return the value of last element

    // printing
    // method 1
    for(vector<int>::iterator it = v.begin();it!=v.end();it++){
        cout<<*(it)<<" ";
    }
    cout<<endl;
    // method2
    for(auto it=v.begin();it!=v.end();it++){
        cout<<*(it)<<" ";
    }
    cout<<endl;
    // method 3
    for(auto x:v){
        cout<<x<<" ";
    }
    cout<<endl;

    //erase
    // v.erase(address u want to delete)
    // v = {10,20,30,40,50,60,70}
    v.erase(v.begin()+1); //{10,30,40,50,60,70}
    v.erase(v.begin()+1,v.begin()+3);//{10,50,60,70}

    // insert function
    vector<int> v1(2,100); //{100,100}
    v1.insert(v1.begin(),300); //{300,100,100}
    v1.insert(v1.begin()+1,2,10); //{300,10,10,100,100} v1.insert(position,number of elements,element)

    vector<int> copy = {1,2};
    v1.insert(v1.begin()+2,copy.begin(),copy.end()); //v1.insert(position,(another array to copy)) {300,10,1,2,10,100,100}

    v1.pop_back(); //removes an element from end of the vector

    // before swap
    // v1->{10,20}
    // v2->{30,40}
    v1.swap(v2);
    // after swap
    // v1->{30,40}
    // v2->{10,20}

    v.clear(); //erases the entire vector
    cout<<v.empty(); // return a bool value indicating whether vector has element or not

}

void List(){
    list<int> l1;
    l1.push_back(5);
    l1.emplace_back(5);
    l1.push_front(10);
    l1.emplace_front(10);
    // begin, end, rbegin, rend, clear, insert, size, swap -> same as vector 
}

void Deque(){
    deque<int> dq;
    // all operations are same as list
}

void Stack(){
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.emplace(4);
    st.pop();
    st.top();
    st.empty();
    stack<int> st2;
    st.swap(st2);
}

void Queue(){
    queue<int> q;
    q.push(1);
    q.push(2);
    q.emplace(4);
    q.back()+=5;
    q.front();
    q.pop();

}

void PriorityQueue(){
    priority_queue<int> pq;
    // default -> Maximum Heap
    // element with the maximum value stays at the top

    pq.push(5); //{5}
    pq.push(2); //{5,2}
    pq.push(8); //{8,5,2}
    pq.emplace(10); //{10,8,5,2}
    pq.push(6); //{10,8,6,5,2}
    pq.top();//10
    pq.pop(); //{8,6,5,2}

    // Minimum heap
    priority_queue<int,vector<int> , greater<int> > pq2;
    pq2.push(5); //{5}
    pq2.push(2); //{2,5}
    pq2.push(8); //{2,5,8}
    pq2.emplace(10); //{2,5,8,10}
    pq2.push(6); // {2,5,6,8,10}
    cout<< pq2.top(); //2
    // push() and pop() -> O(log(n)) and top() -> O(1);
}

// void Set(){ -> every thing happens in (log) time complexity
       // sets everything in sorted order and store unique elements
//     set<int> s;
//     s.insert(1);  {1}
//     s.emplace(2); {1,2}
//     s.insert(2);  {1,2}
//     s.insert(4);  {1,2,4}
//     s.insert(3);  {1,2,3,4}
//     s.insert(3);  {1,2,3,4}

//     {1,2,3,4,5}
//     auto it = s.find(3);  s.find(ele)  returns an iterator that points on that ele
//     {1,2,3,4,5}
//     auto it = s.find(6);  since 6 not in set it will return s.end();
//     st.erase(5);  remove 5 from set {1,2,3,4}

//     st.count(ele); return either 1 or 0

//     {1,2,3,4,5}
//     auto it1 = s.find(2);
//     auto it2 = s.find(4);
//     s.erase(it1,it2);    {1,4,5}

//     lower_bound(ele) and upper_bound(ele) -> these are the functions that works same with vector
//     auto it3 = s.lower_bound(2);
//     auto it4 = s.upper_bound(2);
// }

void Multiset(){ //-> stores data in sorted manner but dont save unique values can save repeated values
    // multiset<int> ms;
    // ms.insert(1) {1}
    // ms.insert(1) {1,1}
    // ms.insert(1) {1,1,1}
    
    // int cnt = ms.count(1); -> ans = 3
    // ms.erase(1) -> here all the 1's will get deleted 

    // inorder to erase a single 1
    // ms.erase(ms.find(1));  // ms.find() -> returns the address of thr first 1
    // ms.erase(ms.find(1),ms.find(1)+2); -> removes the first 2 ones
}

void Unordered_set(){ //-> store unique values but not in a sorted order
    // unordered_set<int> st;
    // here upper_bound and lower_bound function do not work
}




int main(){
}

