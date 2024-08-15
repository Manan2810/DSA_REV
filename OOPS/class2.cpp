// 4 pillars of OOPS
// 1. Abstraction
// 2. Polymorphism
// 3. Inheritance
// 4. Encapsulation

// Encapsulation-> wrapping your Data members and member functions in bigger entity
//              ->Data Hiding
//              -> Perfect Encapsulation -> all data members are private
//              -> getter and setter are used to get/set data


// Inheritance-> is the process of one class inheriting properties and methods from another class
// Types of Inheritance -> Single (one parent class one child class)
//                      -> Multilevel(parent class <-child class <-grand-child class) similarly the levels can continue
//                      -> Multiple(A child inheriting form multiple parent)
//                      -> Hierarchical(Multiple children inheriting from the same parent)
//                      -> Hybrid(Mixture of all the inheritance)
//  reusability ke lia we need inheritance
// multiple inheritance possible in cpp and not in java

// Polymorphism-> Existing in multiple form
// Types of polymorphism -> Compile Time Polymorphism
//                          Types:-
//                               -> Operator Overloading
//                               -> Function Overloading
//                       -> Run Time Polymorphism->Function over-riding

// Abstraction -> implementation hiding
//             -> 



#include<iostream>
using namespace std;

// encapsulation
// class Animal{
//     private:
//         int age;
//         int weight;

//     public:
//         void eat(){
//             cout<<"Eating"<<endl;
//         }
//         int getAge(){
//             return this->age;
//         }
//         void setAge(int age){
//             this->age = age;
//         }

// };

// Inheritance
class Animal{
    public:
        int age;
        int weight;
        void eat(){
            cout<<"Eating"<<endl;
        }
        int getAge(){
            return this->age;
        }
        void setAge(int age){
            this->age = age;
        }
};

class Dog:protected Animal{
    public:

    void print(){
        cout<<age<<endl;
    }
};


// Types of Inheritance

// 1. single level inheritance
class Car{
    public:
        string name;
        int weight;
        int age;

        void speedUp(){
            cout<<"Speeding Up"<<endl;
        }

        void applyBreaks(){
            cout<<"applying breaks"<<endl;
        }
};

class Scorpipo : public Car{

};


// 2. Multi-level inheritance
class Fruit{
    public:
    string name;
};
class Mango:public Fruit{
    public:
    int weight;
};
class Alphanso:public Mango{
    public:
    int sugarLevel;
};

// 3. Multiple Inheritance
class A{
    public:
    int pyhsics;
    int chemistry;
    A(){
        pyhsics=100;
        chemistry=200;
    }
};
class B{
    public:
    int chemistry;
    B(){
        chemistry=300;
    }
};
class C:public A, public B{
    public:
    int maths;
    C(){
        maths=400;
    }
};

// 4. Hierarchical
class Car2{
    public:
    string name;
    int age;
    int weight;

    void speedUp(){
        cout<<"Speeding Up"<<endl;
    }
};
class Scorpio:public Car2{

};
class Fortuner:public Car2{

};


// Polymorphism
// 1. Compile-Time Polymorphism

class Maths{
    public:

    // here function overloading is happening as sum function is existing in multiple forms
    // functions should have different number of parameters or if have same number of parameters then should have different data types
    int sum(int a,int b){
        return a+b;
    }
    int sum(int a,int b, int c){
        return a+b+c;
    }
    int sum(float a,float b){
        return a+b+10;
    }

};

class Parameter{
    public:
    int value;
    int age;
    int weight;

    void operator + (Parameter& obj2){ //parameter type ke object ke beech me + kaise act kargea yeh btata hai
        int value1 = this->value;
        int value2 = obj2.value;
        cout<<value1-value2<<endl;
        ;
    } 

    void operator << (Parameter& obj3){
        cout<<"the value is :-"<<this->value<<endl;
        cout<<"the age is :-"<<this->age<<endl;
        cout<<"the weight is :-"<<this->weight<<endl;
    }
};

// Runtime polymorphism -> Function overriding
class Animal3{
    public:
    Animal3(){
        cout<<"i am in animal3 constructor"<<endl;
    }
    void speak(){
        cout<<"speaking"<<endl;
    }
};

class Dog2 : public Animal3{
    // in this class we over rided the speak function which is being inherited from Animal2 
    public:
    Dog2(){
        cout<<"i am in dog2 constructor"<<endl;
    }
    void speak(){
        cout<<"barking"<<endl;
    }
};



int main(){
    Dog d1;
    d1.print();

    // single inheritance
    Scorpipo babbarvali;
    babbarvali.speedUp();

    // multi-level inheritance
    Alphanso a;
    cout<<a.name<<endl;
    cout<<a.weight<<endl;
    cout<<a.sugarLevel<<endl;

    // multiple inheritance
    C obj;
    cout<<obj.B::chemistry<<" "<<obj.maths<<" "<<obj.pyhsics<<endl;
    // :: scope resolution operator

    // Hierarchical
    Fortuner f11;
    f11.speedUp();

    // Polymorphism

    // Compile time polymorphism
    // function overloading
    Maths calc;
    cout<<calc.sum(1,2)<<endl;
    cout<<calc.sum(1,2,3)<<endl;
    cout<<calc.sum(1.0f,2.2f)<<endl;

    // operator overloading
    Parameter obj1,obj2,obj3;
    obj1.value=7;
    obj2.value=2;
    // this should print the diffrenece between them;
    obj1+obj2;
    obj3.value = 12;
    obj3.age = 10;
    obj3.weight = 60;
    // cout<<obj3;

    // Run-time polymorphism
    // Dog2 d2;
    // d2.speak();

    // more in function over-riding()
    // case 1 
    // Animal3 * t = new Animal3;
    // t->speak(); //speaking

    // case 2
    // Dog2* t2 = new Dog2;
    // t2->speak(); //barking

    // case 3 (Upcasting)-> yha agar parent ke function ko virtual na bnate toh parent ka function hi call hota but jaise hi virtual bna dete then child ie Dog2 ka function call hota)
    // Animal3 * t3 = new Dog2;
    // t3->speak(); //speaking
    // as soon as we convert the member function ie speak in parent class ie Animal3 to a virtual function then it will print barking

    // case 4 (Downcasting) 
    // Dog2 * t4 = (Dog2*)new Animal3;
    // t3->speak();

    // note-> in both upcasting and downcasting if we dont make the member function virtual then your member function of those class will get executed same as that of the pointer type

    // playing with constructors
    // Animal3 * a1 = new Animal3; -> yha sirf parent ka constructor call hora
    // Dog2 * a2 = new Dog2; -> yha pehle parent ka constructor chalega and then child vala because of inheritance
    // Animal3 * a1 = new Dog2; -> yha pehle parent ka constructor chalega and then child vala
    // Dog2 * a1 =(Dog2*) new Animal3; -> yha sirf parent ka call hoga
}


// important things to keep in mind:-
// 1. Inheritance -> Diamond problem -> hierarchecal + multiple
// 2. polymorphism-> Runtime polymorphysm and compile-time polymorphism
// 3. difference between encap and abstraction