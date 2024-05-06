#include <iostream>
#include <variant>

enum class ErrorCode{
    None = 0,NotFound = 1,NoAccess = 2
};

std::variant<std::string,ErrorCode> ReadFileAsString(const std::string& filepath){
    //可以使用错误码，相比optional,知道哪里出了问题，optional相当于只有bool值

}

int main(){
    std::variant<std::string,int> data;
    //单个变量存放多类型数据，方便，本质是创建了一个结构体或类,更加类型安全，应该使用
    data = "Cherno";
    std::cout << std::get<std::string>(data) << "\n";
    //data.index()确定索引
    if(auto value = std::get_if<std::string>(&data)){//优于index处理variant,有所期望
        
    }
    else{

    }
    data = 3;
    std::cout << std::get<int>(data) << "\n";

    std::cin.get();
}