#include <iostream>
#include <fstream>
#include <optional>

std::optional<std::string> ReadFileAsString(const std::string& filepath){
    //允许有一些不存在的可选数据
    std::ifstream stream(filepath);
    if(stream){
        std::string result;

        stream.close();
        return result;
    }

    return {};
}
int main(){
    auto data = ReadFileAsString("data.txt");

    std::string value = data.value_or("Not present");//存在提取，不存在用（）中自己给定

    if(data.has_value()){
        std::cout << "File read successfully\n";
    }
    else{
        
    }
}