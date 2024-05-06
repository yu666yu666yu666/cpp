#include <iostream>
#include <string>
#include <tuple>

//结构化绑定
std::tuple<std::string,int> CreatePerson(){
    return {"Cherno",24};
}

int main(){
/*
    auto person = CreatePerson();
    std::string& name = std::get<0>(person);
    int age = std::get<1>(person);

    std::string name;
    int age;
    std::tie(name,age) = CreatePerson();
*/
    auto[name,age] = CreatePerson();
    std::cout << name;
}