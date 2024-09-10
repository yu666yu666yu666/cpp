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
    one(){head = new L;head->next = nullptr;}
    void set(int);
    void put();
    void add(one&,one&);
};
void one::set(int num){
    char c;
    L* pre = new L;
    pre = head;
    while(num){
        num--;
        L* p = new L;
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
void one::add(one& b,one& c){
    L* p = head->next;
    L* q = b.head->next;
    L* pre = c.head->next;
    if(!q){
        c.head->next = p;
        return;
    }
    if(!p){
        c.head->next = q;
        return;
    }
    while(p){
        q = b.head->next;
        while(q){
            pre = c.head->next;
            int a = p->a * q->a;
            int b = p->b + q->b;
            L* m = new L;
            if(!c.head->next){
                m->a = a;
                m->b = b;
                c.head->next = m;
                q = q->next;
                continue;
            }
            L* ppre;
            while(pre){
                if(b > pre->b){
                    ppre = pre;
                    pre = pre->next;
                    if(!pre){
                        m->a = a;
                        m->b = b;
                        ppre->next = m;
                        break;
                    }
                    continue;
                }
                if(b < pre->b){
                    m->a = a;
                    m->b = b;
                    m->next = nullptr;
                    ppre->next = m;
                    m->next = pre;
                    break;
                }
                if(b == pre->b){
                    pre->a += a;
                    if(!pre->a){
                        ppre->next = pre->next;
                    }
                    break;
                }
            }
            q = q->next;
        }
        p =p->next;
    }
}

int main(){
    one a,b,c;
    int num;
    std::cin >> num;
    a.set(num);
    std::cin >> num;
    b.set(num);
    a.add(b,c);
    c.put();
}