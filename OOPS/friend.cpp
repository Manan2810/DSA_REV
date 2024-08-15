#include<iostream>
using namespace std;

class A{
    private:
    int x;
    public:
    A(int _val):x(_val){};
    int getX() const{
        return x;
    }
    void setX(int _x){
        x=_x;
    }

    // friend class
    friend class B; // give access of all pvt members of A to B 
    
    // friend function
    friend void print(const A&);
};

class B{
    public:
    void print(const A& a){
        cout<<a.x<<endl;
    }
};

void print(const A& a){
    cout<<a.x<<endl;
}


int main(){
    A a(5);
    B b;
    b.print(a);
    print(a);
    return 0;
}