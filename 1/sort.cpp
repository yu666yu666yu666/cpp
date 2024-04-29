#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

int main(){
    std::vector<int> vec = {4,3,2,1,5,6};
    std::sort(vec.begin(),vec.end(),[](int a,int b)
    {
        if(a == 1)
            return false;
        if(b == 1)
            return true;
        return a < b;
    });
    for(int value : vec)
        std::cout << value << '\n';
}