#include <iostream>
#include <any>

//存储任意类型数据，用void*

int main(){
    std::any data;
    data = 2;
    data = std::string("Cherno");
    std::string& string = std::any_cast<std::string&>(data);
    while(1){
    std::string o;
    std::cout << "1" << '\n';
    std::cin >> o;
    std::cout << o << '\n';
    }
}
