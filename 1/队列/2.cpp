#include <iostream>
#include <string>

int main(){
    std::string s;
    std::cin >> s;
    int tag = 0;
    int i = 0;
    int j = s.length() - 1;
    while(j > i){
        if(s[i] != s[j]){
            tag = 1;
            break;
        }
        i++;j--;
    }
    if(tag)
        std::cout << "不是回文";
    else
        std::cout << "回文";
}