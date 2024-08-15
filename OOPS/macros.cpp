#include<iostream>
using namespace std;
#define PI 3.14159465 // macros keyword (not a variable , donot take a memory and needs to be pre-processed before compiling)
#define MAXX(x,y) (x>y?x:y)

float circleArea(float r){
    return PI*r*r;
}

float circlePerieter(float r){
    return 2*PI*r;
}

void fun(){
    int x = 6;
    int y = 17;
    int c = MAXX(x,y);
}

int main(){
    cout<<circleArea(65.4)<<endl;
    return 0;
}