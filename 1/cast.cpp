#include <iostream>
#include <string.h>

class base{
public:
    base(){

    }
    virtual ~base(){

    }
};

class a :public base{
public:
    a(){

    }
    ~a(){

    }
};

int main (){
    double value = 4.43;
    double a = (int)value + 4.4;
    double s = static_cast<int>(value) + 4.4;

    std::cout << s <<'\n';
}