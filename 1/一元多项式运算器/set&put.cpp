#include <iostream>

struct L{
    int a;
    int b;
    L* next;
};
class one{
private:
    L* head;
public:
    void set(int);
    void put();
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
void one::put(){
    L* q = head->next;
    int flag = 1;
    if(!q) {
        std::cout << '0' << '\n';
        return;
    }
    while(q) {
        if(q->a > 0 && flag != 1) {
            std::cout << '+';
        }
        if(q->a != 1 && q->a != -1) {
            std::cout << q->a;
            if(q->b == 1) {
                std::cout << 'X';
            } else if (q->b) {
                std::cout << "X^" << q->b;
            }
        } else {
            if(q->a == 1) {
                if(!q->b) {
                    std::cout << '1';
                } else if (q->b == 1) {
                    std::cout << 'X';
                } else {
                    std::cout << "X^" << q->b;
                }
            }
            if(q->a == -1) {
                if(!q->b) {
                    std::cout << "-1";
                } else if(q->b == 1) {;
                    std::cout << "-X";
                } else {
                    std::cout << "-X^" << q->b;
                }
            }
        }
        q = q->next;
        flag++;
    }
}
int main(){
    one ones;
    int num;
    std::cin >> num;
    ones.set(num);
    ones.put();
}