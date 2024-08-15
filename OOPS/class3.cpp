// const keyword -> is used to declare that a variable function or obejct is immutable ie its value cannot be changed after initialization

#include<iostream>
using namespace std;

class ABC {
private:
    mutable int x; // here by writing mutable we can change the value of x in the member functions that are marked as constant
    int* y;
    int z;

public:
    // Default constructor
    // ABC() {
    //     x = 0;
    //     y = new int(0);
    // }

    // Parameterized constructor : old way of writing constructor
    // ABC(int _x, int _y, int _z = 0) {
    //     x = _x;
    //     y = new int(_y); // Properly initialize y
    //     z = _z;
    // }

    // Initialization list : new way of writitng constructor
    ABC(int _x , int _y ,int _z = 0) : x(_x),y(new int (_y)),z(_z){}
    // like if i make my z a const value so we can initialize a value to it in case of initialization list but not in case of old style of writing constructor

    // Getter for x
    int getX() const {
        x=10;
        return x;
    }

    // Setter for x
    void setX(int x) {
        this->x = x;
    }

    // Getter for y
    int getY() const {
        return *y;
    }

    // Setter for y
    void setY(int y) {
        *(this->y) = y;
    }

    // Getter for z
    int getZ() const {
        return z;
    }

    // Setter for z
    void setZ(int z) {
        this->z = z;
    }

    // Destructor to avoid memory leak
    // ~ABC() {
    //     delete y;
    // }
};

void PrintABC(const ABC& obj){
    // const ABC& obj -> here we have an constant object and we make 
    // sure that we donot make a function call that is not constant
    cout<<obj.getX()<<" "<<obj.getY()<<" "<<obj.getZ()<<endl;

    // obj.setX(3) -> will give an error as its not a constant member function
}

int main() {
    ABC a2(1, 2, 3);
    PrintABC(a2);
}

int main2(){
    const int x = 10;
    cout<<x<<endl;
    // x=11;
    // cout<<x<<endl;

    // const with pointers

    // 1. constant data but non constant pointer
    const int * a = new int(2); // const data and non const pointer
    // int const * a = new int(2); //same as above line
    // *a=2; cant change the value of the pointer
    cout<< *a<<endl;
    int b = 5;
    a=&b; // but the pointer can be reassigned
    cout<<*a<<endl;

    // 2. constant pointer but non constant data
    int *const w = new int(20);
    cout<<*w<<endl;
    *w = 30;
    cout<<*w<<endl;
    int c = 20;
    // w=&c; //not possible 
    return 0;

    // 3. const and data both pointer
    int const * const d = new int(2);
    // *d = 30; //error
    // cout<<*w<<endl;
    // int l = 20;
    // d=&l; // error
}