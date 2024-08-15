#include<iostream>
#include"bird.h"
using namespace std;

void birdDoingSomething(BIRD *&bird){
    bird->eat();
    bird->fly();
    bird->eat();
}


int main(){
    // here BIRD is the interface
    BIRD * bird = new sparrow();
    birdDoingSomething(bird);
}