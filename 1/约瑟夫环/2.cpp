#include <iostream>

struct L{
    int a;
    L* next;
};

int main(){
    int a,b,c;
    std::cin >> a >> b;
    c = a;
    L* head = new L;
    head->next = nullptr;
    L* pre = head;
    while(c){
        c--;
        L* p = new L;
        p->a = (a - c);
        if(!c){
            p->next = head->next;
            pre->next = p;
            break;
        }
        p->next = nullptr;
        pre->next = p;
        pre = pre->next;
    }
    pre = head;
    for(int i = 0;i < a;i++){
        L* ppre = pre;
        for(int j = 0;j < b;j++){
            ppre = pre;
            pre = pre->next;
        }
        ppre->next = pre->next;
        std::cout << pre->a << ' ';
        pre = ppre;
    }
}