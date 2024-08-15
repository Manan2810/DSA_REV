#include<iostream>
using namespace std;

// inline used in that case where there is a small function
inline void numberShow(int num){
    cout<<num<<endl;
}

int main(){
    numberShow(10); // after we make function inline that means ki function ke andar ka code yha uth ke aajayga jha function call hogi
    // numberShow(10); -> this will be replaced by cout<<10<<endl;
    numberShow(10);
    numberShow(10);
    numberShow(10);
    numberShow(10);
    numberShow(10);
    numberShow(10);
    numberShow(10);
    numberShow(10);
}