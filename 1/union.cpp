#include <iostream>

struct vector{
    float x,y;
};

struct vector2{
    union {
        struct {
            float x,y,z,w;
        };
        struct {
            vector a,b;
        };
    };
};

void PrintString(const vector& vec){
    std::cout << vec.x  << ',' << vec.y << '\n';
}

int main(){

    vector2 m = {1.3f,3.3f,4.3f,6.5f};
    PrintString(m.a);
    PrintString(m.b);
    m.z = 8.3f;
    PrintString(m.a);
    PrintString(m.b);

    std::cin.get();
}