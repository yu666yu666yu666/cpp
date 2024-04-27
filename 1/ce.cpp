#include <iostream>
#include <string>
#include <array>
#include <memory>
#include <utility>

class ced{
    static int x,y;
public:
    ced(){
        for(int i = 0;i < another.size();i++){
            
        }
    }
    ~ced(){

    }
private:

public:
    int a,b;
    std::array <int,5> another;
    virtual int mk(){

    }
protected:

};

class ma : public ced{
    int mk() override {
        
    }
};

struct ce
{
    static int x,y;
};

int ce::x;
int ce::y;

void PrintString(const std::string& string);

//std::pair
static std::tuple<std::string,std::string,int> ParseShfader();//返回多个数据,(太繁琐),用结构体返回更好

//模板，随用随创，即调用了才会创建
template<typename T>//class和typename一样
void Print(T value){
    //
}

int main()
{
    std::string name = std::string("Cherno") + "hello";
    std::string name = "Cherno";
    name += "hello";
    bool contains = name.find("no") != std::string::npos;

    {
        std::shared_ptr<ced> p;
        {
            //unique低开销
            std::unique_ptr<ced> m_ced(new ced());
            std::unique_ptr<ced> n_ced = std::make_unique<ced>();//更安全
            //std::unique_ptr<ced> n_ced1 = n_ced;  error,只能有一个

            std::shared_ptr<ced> q = std::make_shared<ced>();//有引用计数系统的开销。不要用new
            std::weak_ptr<ced> weake = q;//不增加计数
            p = q;
        }
    }
    ce::x = 3;
    ce::y = 4;
    std::cout<< ce::x << ce::y;
    ce::x = 5;
    ce::y = 6;
    std::cout<< ce::x << ce::y;
}
