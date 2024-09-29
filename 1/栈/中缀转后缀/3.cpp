#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <cctype>

bool isok(char a, char b) {
    if (b == '(') return false; // '(' 一律入栈
    if (a == '*' || a == '/') {
        return (b == '*' || b == '/'); // *, / 优先级高于 +, -
    } else if (a == '+' || a == '-') {
        return (b == '+' || b == '-' || b == '*' || b == '/'); // +, - 优先级低于 *, /
    }
    return false;
}


double jisuan(const std::string &string2) {
    std::stack<double> a;
    std::istringstream iss(string2);
    std::string token;

    while (iss >> token) {
        if (isdigit(token[0])) {
            // 将数字作为 double 入栈
            
            a.push(std::stod(token)); // 使用 std::stod 转换为 double
        } else {
            double x = a.top(); a.pop();
            double y = a.top(); a.pop();
            switch (token[0]) {
                case '+': a.push(y + x); break;
                case '-': a.push(y - x); break;
                case '*': a.push(y * x); break;
                case '/': a.push(y / x); break;
                default:break;
            }
        }
    }

    return a.top();
}

void ztoz(const std::string &string1, std::string &string2) {
    std::stack<char> a;
    string2.clear();

    for (int i = 0; i < string1.length(); ++i) {
        char ch = string1[i];

        if (isdigit(ch)) {
            // 处理多位数
            while (isdigit(ch)) {
                string2 += ch;
                ch = string1[++i]; // 继续读取
            }
            string2 += ' '; // 操作数后加空格
            --i; // 回退一个字符
        } else {
            switch (ch) {
                case '+':
                case '-':
                case '*':
                case '/':
                    while (!a.empty() && isok(ch, a.top())) {
                        string2 += a.top();
                        string2 += ' '; // 运算符后加空格
                        a.pop();
                    }
                    a.push(ch);
                    break;
                case '(':
                    a.push('(');
                    break;
                case ')':
                    while (!a.empty() && a.top() != '(') {
                        string2 += a.top();
                        string2 += ' '; // 运算符后加空格
                        a.pop();
                    }
                    a.pop(); // 去掉 '('
                    break;
                default:
                    break;
            }
        }
    }

    while (!a.empty()) {
        string2 += a.top();
        string2 += ' '; // 运算符后加空格
        a.pop();
    }
}

int main() {
    std::string string1, string2;
    std::getline(std::cin, string1, '#');
    ztoz(string1, string2);
    std::cout << jisuan(string2) << std::endl;
    return 0;
}