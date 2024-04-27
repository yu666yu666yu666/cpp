#include <iostream>
#include <string>

#define PR_DEBUG 0 //可以随时更改为0或1

#if PR_DEBUG == 1
#define LOG(x) std::cout << x << std::endl
#else
#define LOG(x)
#endif

int main(){
    LOG("Hello");
    std::cin.get();
}