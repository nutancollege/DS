
#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isOperand(char ch) {
    return isalnum(ch);
}

int precedence(char op) {
    return (op == '+' || op == '-') ? 1 : (op == '*' || op == '/') ? 2 : 0;
}

string infixToPostfix(string infix) {
    stack<char> s;
    string postfix;

    for (char ch : infix) {
        if (isOperand(ch)) {
            postfix += ch;
            postfix += ' ';
        } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            while (!s.empty() && precedence(s.top()) >= precedence(ch)) {
                postfix += s.top();
                postfix += ' ';
                s.pop();
            }
            s.push(ch);
        } else {
            cout << "Invalid character or parentheses not allowed: " << ch << "\n";
            return "";
        }
    }

    while (!s.empty()) {
        postfix += s.top();
        postfix += ' ';
        s.pop();
    }

    return postfix;
}

int evaluatePostfix(string postfix) {
    stack<int> s;

    for (char ch : postfix) {
        if (ch == ' ') continue;
        if (isdigit(ch)) {
            s.push(ch - '0');
        } else {
            int b = s.top(); s.pop();
            int a = s.top(); s.pop();
            s.push(ch == '+' ? a + b : ch == '-' ? a - b : ch == '*' ? a * b : a / b);
        }
    }

    return s.top();
}

int main() {
    string infix;
    cout << "Enter an infix expression (single-character operands and operators): ";
    cin >> infix;

    string postfix = infixToPostfix(infix);
    if (postfix.empty()) return 0;

    cout << "Postfix expression: " << postfix << endl;

    if (postfix.find_first_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ") != string::npos) {
        cout << "Alphabetic characters found, evaluation skipped.\n";
    } else {
        cout << "Result of evaluation: " << evaluatePostfix(postfix) << endl;
    }

    return 0;
}

