// if we include bird.h more than one time then also it gets included only for a single time
# if !defined(BIRD_H) 
#define BIRD_H
#include<iostream>
using namespace std;

// interface
class BIRD{
    public:
    virtual void eat() = 0; //pure virtual function
    //jab bhi class me hum pure virtual function likhdete hai to vo ek interface ban jaata hai
    virtual void fly() = 0;
    // classes that inherits this class has to implement pure virtual functions
};

// implementation
class sparrow:public BIRD{
    public:
    void eat(){
        cout<<"sparrow is eating"<<endl;
    }
    void fly(){
        cout<<"sparrow is flying"<<endl;
    }
};
class eagle:public BIRD{
    public:
    void eat(){
        cout<<"eagle is eating"<<endl;
    }
    void fly(){
        cout<<"eagle is flying"<<endl;
    }
};
class pigeon:public BIRD{
    public:
    void eat(){
        cout<<"pigeon is eating"<<endl;
    }
    void fly(){
        cout<<"pigeon is flying"<<endl;
    }
};

#endif