#include<iostream>
using namespace std;

class abc {
public:
    static int x, y;
    static void print() { // yeh ab poore class ka member function hai that can be accessed by any instance 
        // iske andar sirf static varibales pass hote becuse its a static member function
        // no this pointer accessible
        cout << x << " " << y << endl;
    }
};

// Initialize static members outside the class definition
int abc::x; 
int abc::y; 

int main() {
    abc obj1;
    obj1.x = 2;
    obj1.y = 4;
    obj1.print();
    abc obj2;
    obj2.x = 5;
    obj2.y = 7;
    obj2.print();
    obj1.print();

    return 0;
}
