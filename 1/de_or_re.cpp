#include <iostream>
#include <string>

/*用宏替代new可以更好追踪*/

#define PR_DEBUG 0 //可以随时更改为0或1

#if PR_DEBUG == 1//优于ifdef
#define LOG(x) std::cout << x << std::endl
#else
#define LOG(x)
#endif

int main(){
    LOG("Hello");
    std::cin.get();
}