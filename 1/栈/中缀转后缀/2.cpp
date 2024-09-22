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

    string2.resize(string1.length()); // 为 string2 分配大小
    int i = 0, j = 0;

    while (string1[i] != '#') {
        switch (string1[i]) {
            case '+':
            case '-':
            case '*':
            case '/':
                while (!a.empty() && isok(string1[i], a.top())) {
                    string2[j++] = a.top(); // 将栈顶元素加入输出字符串
                    a.pop();
                }
                a.push(string1[i]); // 将当前运算符入栈
                break;
            case '(':
                a.push('(');
                break;
            case ')':
                while (!a.empty() && a.top() != '(') {
                    string2[j++] = a.top(); // 将栈顶元素加入输出字符串
                    a.pop();
                }
                a.pop(); // 弹出 '('
                break;
            default:
                string2[j++] = string1[i];
                break;
        }
        i++;
    }

    while (!a.empty()) { // 弹出所有剩余的运算符
        string2[j++] = a.top();
        a.pop();
    }

    string2.resize(j); // 调整 string2 的大小
    std::cout << string2;
}