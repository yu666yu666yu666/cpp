#include <iostream>
#include <stack>
#include <string>

bool isok(char a,char b){//1为出栈，0为入栈;a为中缀表达式中运算符
    if(b == '('){
        if(a == '(')
            return 1;
        return 0;
    }
    switch (a)
    {
    case '+':
        return 1;
    case '-':
        return 1;
    case '*':
        switch (b)
        {
        case '+':
            return 0;
        case '-':
            return 0;
        case '*':
            return 1;
        case '/':
            return 1;
        }
    case '/':
        switch (b)
        {
        case '+':
            return 0;
        case '-':
            return 0;
        case '*':
            return 1;
        case '/':
            return 1;
        }
    }
}

int main(){
    std::string string1,string2;
    std::stack<char> a;
    std::cin >> string1;
    int i = 0,j = 0;
    while(string1[i] != '#'){
        switch (string1[i])
        {
        case '+':
        case '-':
        case '*':
        case '/':
            if(a.empty()){
                a.push(string1[i]);
                i++;
            }
            else{
                while(isok(string1[i],a.top())){
                    string2[j] = a.top();
                    a.pop();
                    j++;
                    if(a.empty())
                        break;
                }
                a.push(string1[i]);
                i++;
            }
            break;
        case '(':
            a.push('(');
            i++;
            break;
        case ')':
            while(a.top() != '('){
                string2[j] = a.top();
                a.pop();
                j++;
            }
            a.pop();
            j++;i++;
            break;
        default:
            string2[j] = string1[i];
            i++;j++;
            break;
        }
    }
    std::cout << string2;
}