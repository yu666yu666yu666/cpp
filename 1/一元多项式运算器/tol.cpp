#include <iostream>
#include <cmath>
struct L{
    int a;
    int b;
    L* next;
};
class one{
private:
    L* head;
public:
    one(){head = new(L);}
    void set(int);
    void cal(int);
};
void one::set(int num){
    char c;
    L* pre = head;
    while(num){
        num--;
        L* p = new(L);
        std::cin >> c >> p->a;
        std::cin.ignore();
        std::cin >> p->b >> c;
        pre->next = p;
        pre = p;
    }
}
void one::cal(int num){
    int totol = 0;
    L* pre = head->next;
    while(pre){
        totol += pre->a * std::pow(num,pre->b);
        //totol += pre->a * static_cast<int>(std::pow(num, pre->b));
        pre = pre->next;
    }
    std::cout << totol;
}
int main(){
    one ones;
    int num;
    std::cin >> num;
    ones.set(num);
    std::cin >> num;
    ones.cal(num);
}