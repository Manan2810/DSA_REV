#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// identification ke lia humne minimum possible memory ya space dedi
class Animal{
    // state or property -> data members

    private:
    int weight;

    public:
    int age;
    string name;

    // Constructor

    // default constructor
    Animal(){
        this->weight = 0;
        this->age=0;
        this->name="";
        cout<<"Constructor Called"<<endl;
    }

    // Paramaterised Constructor
    Animal(int age){
        this->age=age;
        cout<<"Paramaterised Constructor called"<<endl;
    }

    Animal(int age,int weight){
        this->age=age;
        this->weight=weight;
        cout<<"Paramaterised Constructor2 called"<<endl;
    }

    // Copy Constructor
    Animal(Animal& obj){
        this->age = obj.age; 
        this->weight = obj.weight;
        this->name =obj.name;
        cout<<"copy constructor called"<<endl;
    }

    // destructor
    ~Animal(){
        cout<<"Destructor here"<<endl;
    }

    // behaviour -> member functions
    void eat(){
        cout<<"eating"<<endl;
    }
    void sleep(){
        cout<<"sleeping"<<endl;
    }

    void print(){
        cout<<this->age<<" "<<this->weight<<" "<<this->name<<endl;
    }

    // getter 
    int getWeight(){
        return weight;
    }
    // setter
    void setWeight(int weight){
        this->weight=weight;
        // (*this).weight = weight;
    }


};

// when we want to access private members outside the class then we use getter and setter
// getter -> to fetch a particular property
// setter -> to set a particular property



int main(){
    // cout<<"size "<<sizeof(Animal)<<endl;
    // Object creation


    //! static
    // Animal ramesh; // hamare pass yha animal type ka object hai(ramesh object hai)
    // // ramesh.age=12;
    // // ramesh.name="lion";
    // cout<< "Age of ramesh is: " <<ramesh.age<<endl;
    // cout<< "Name of ramesh is: " <<ramesh.name<<endl;
    // ramesh.sleep();
    // ramesh.eat();


    //! to access private members
    // ramesh.setWeight(101); //<--setter
    // cout<<"Weight:-"<<ramesh.getWeight()<<endl; //<-- getter


    //! dynamic memory allocation
    // Animal * suresh = new Animal;

    // method -1
    // suresh->age=15;
    // suresh->name="tiger";
    // cout<< "Age of suresh is: " <<suresh->age<<endl;
    // cout<< "Name of suresh is: " <<suresh->name<<endl;
    // suresh->eat();
    // suresh->sleep();

    // method 2
    // (*suresh).age = 15;
    // (*suresh).name = "tiger";

    
    //! Constructors
    // Animal sherr(12);
    // cout<<sherr.age<<endl;
    // cout<<sherr.getWeight()<<endl;
    // cout<<sherr.name<<endl;


    //! Object copy
    // method 1
    // Animal a;
    // Animal b=a; //->copy constructor called
    // method 2
    // Animal c(b); //copy constructor called


    //! Destructor
    //static
    Animal a; 
    a.age = 5;

    // dynamic
    Animal * b = new Animal;
    b->age=10;
    // manually call instructor
    delete b; //this calls the destructor


    
    return 0;
}