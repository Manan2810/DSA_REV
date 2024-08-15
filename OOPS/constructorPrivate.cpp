#include<iostream>
using namespace std;


class Box{
    private:
    int width;

    Box(int _width){
        width = _width;
    }
    public:
    
    int getWidth() const{
        return width;
    }

    void setWidth(int _val){
        width=_val;
    }

    friend class BoxFactory;
};

class BoxFactory{
    int count;
    public:
    Box getABox(int _w){
        ++count;
        return Box(_w);
    }
};

int main(){

    // requirement is that we cannot make an instance of the class box directly
    BoxFactory bfact;
    Box b = bfact.getABox(10);
    cout<<b.getWidth()<<endl;;

    // Box b(5);// not allowed as the constructor is pvt;
    // cout<<b.getWidth()<<endl;

}