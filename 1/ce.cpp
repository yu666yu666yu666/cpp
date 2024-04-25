#include <iostream>
#include <string>
#include <array>
#include <memory>

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

int main()
{
    std::string name = std::string("Cherno") + "hello";
    std::string name = "Cherno";
    name += "hello";
    bool contains = name.find("no") != std::string::npos;

    {
        std::unique_ptr<ced> m_ced(new ced());
        std::unique_ptr<ced> n_ced = std::make_unique<ced>();//更安全
         std::unique_ptr<ced> n_ced1 = n_ced;
    }

    ce::x = 3;
    ce::y = 4;
    std::cout<< ce::x << ce::y;
    ce::x = 5;
    ce::y = 6;
    std::cout<< ce::x << ce::y;
}
