#include<iostream>
using namespace std;

class abc{
    public:
    int x;
    int * y;

    // copy constructor -> here we are doing shallow copy
    // abc(abc& obj){
    //     this->x = obj.x; 
    //     this->y = obj.y;
    //     cout<<"copy constructor called"<<endl;
    // }

    // deep copy constructor
    abc(abc& obj){
        this->x = obj.x; 
        this->y = new int(*obj.y); // yha a ka y aur b ka y different location ko point kar rha
    }

    // initialization list
    abc(int _x, int _y):x(_x),y(new int(_y)){}
    void print() const{
        cout<<"X:"<<x<<endl<<"address to which y is pointing: "<<y<<endl<<"Y:"<<*y<<endl;
    }

    ~abc(){
        delete y;
    }
};


int main(){
    // abc a(1,2);
    // a.print();

    // abc b(a);  // copy constructor is called
    // b.print();

    // *(b.y)=20;
    // b.print();
    // a.print();

    abc * a = new abc(1,2);
    abc b = *a;
    delete a;
    b.print();
    return 0;

}