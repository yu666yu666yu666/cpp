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
    one(){head = new L;}
    void set(int);
    void put();
    void add(one&,one&);
};
void one::set(int num){
    char c;
    L* pre = head;
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
    if(p == nullptr){
        c.head = b.head;
        return;
    }
    if(q == nullptr){
        c.head = head;
        return;
    }
    L* ppre = c.head;
    while(p&&q){
        L* pp = new L;
        if(p->b == q->b){
            pp->b = p->b;
            pp->a = p->a + q->a;
            if(!pp->a){
                delete pp;
                p = p->next;
                q = q->next;
                continue;
            }
            ppre->next = pp;
            ppre = pp;
            p = p->next;
            q = q->next;
            continue;
        }
        if(p->b > q->b){
            pp->a = q->a;
            pp->b = q->b;
            ppre->next = pp;
            ppre = pp;
            q = q->next;
            continue;
        }
        if(p->b < q->b){
            pp->a = p->a;
            pp->b = p->b;
            ppre->next = pp;
            ppre = pp;
            p = p->next;
            continue;
        }
    }
    if(!p){
        ppre->next = q;
    }
    if(!q){
        ppre->next = p;
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