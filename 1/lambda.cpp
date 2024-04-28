#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

void ForEach (const std::vector<int>& values,const std::function<void(int)>& func){

/*范围for循环。遍历一个容器（在这里是values向量）中的元素。

int value：这是一个迭代变量，用于依次存储values中的每个元素的值。
: values：这表示要遍历的容器，即values向量。
func(value);：这是循环体。
因此，此循环将遍历values向量中的每个元素，并将每个元素的值传递给func函数进行处理。*/
    for(int value : values){
        func(value);
    }
}

int main (){
    std::vector<int> values = {1,3,5,6,2};

    auto it = std::find_if(values.begin(),values.end(),[](int value){return value > 3;});
    std::cout << *it << std::endl;

    int a = 5;
//[]中表明要传递的数据
    auto lambda = [](int value){std::cout << "Value:" << value << std::endl;};

    ForEach(values,lambda);

    std::cin.get();
}