#include <iostream>
#include <stack>
#include <string>

bool isok(char a, char b) { // 1 为出栈，0 为入栈；a 为中缀表达式中的运算符
    if (b == '(') return false; // '(' 一律入栈
    if (a == '*' || a == '/') {
        return (b == '*' || b == '/'); // *, / 优先级高于 +, -
    } else if (a == '+' || a == '-') {
        return (b == '+' || b == '-' || b == '*' || b == '/'); // +, - 优先级低于 *, /
    }
    return false;
}

int main() {
    std::string string1, string2;
    std::stack<char> a;
    std::cin >> string1;

    string2.resize(string1.length());
    int i = 0, j = 0;

    while (string1[i] != '#') {
        switch (string1[i]) {
            case '+':
            case '-':
            case '*':
            case '/':
                while (!a.empty() && isok(string1[i], a.top())) {
                    string2[j++] = a.top(); 
                    a.pop();
                }
                a.push(string1[i]); 
                break;
            case '(':
                a.push('(');
                break;
            case ')':
                while (!a.empty() && a.top() != '(') {
                    string2[j++] = a.top();
                    a.pop();
                }
                a.pop(); 
                break;
            default:
                string2[j++] = string1[i];
                break;
        }
        i++;
    }

    while (!a.empty()) {
        string2[j++] = a.top();
        a.pop();
    }

    string2.resize(j);
    std::cout << string2;
}