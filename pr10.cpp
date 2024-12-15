
#include <iostream>
#include <stack>
#include <string>
using namespace std;
// Function to check if the given expression is well parenthesized
bool isWellParenthesized(string expression) {
stack<char> s;
for (char ch : expression) {
// Push opening brackets onto the stack
if (ch == '(' || ch == '{' || ch == '[') {
s.push(ch);
}
// Check for closing brackets
else if (ch == ')' || ch == '}' || ch == ']') {
// If stack is empty or top of stack doesn't match
if (s.empty()) return false;
char top = s.top();
s.pop();
// Check if the brackets match
if ((ch == ')' && top != '(') ||
(ch == '}' && top != '{') ||
(ch == ']' && top != '[')) {
return false;
}
}
}
// If stack is empty, all opening brackets matched
return s.empty();
}
bool hasParentheses(string expression) {
// Check if the expression contains any parentheses
for (char ch : expression) {
if (ch == '(' || ch == ')' || ch == '{' || ch == '}' || ch == '[' || ch == ']') {
return true;
}
}
return false;
}
int main() {
string expression;
cout << "Enter an expression: ";
getline(cin, expression);
if (hasParentheses(expression)) {
if (isWellParenthesized(expression)) {
cout << "The expression is well parenthesized.\n";
} else {
cout << "The expression is not well parenthesized.\n";
}
} else {
cout << "The expression does not contain any parentheses.\n";
}
return 0;
}

