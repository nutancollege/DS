
#include <iostream>
#include <string>
#define MAX 10
using namespace std;

class Stack {
private:
    int top = -1;
    string str = "rar rar";
    char revStr[MAX] = "";

public:
    // Function to display original and reversed strings
    void getData() {
        cout << "\nOriginal String: " << str << endl;
        cout << "Reversed String: " << revStr << endl;
    }

    // Function to check if stack is empty
    int isEmpty() {
        return (top == -1);
    }

    // Function to check if stack is full
    int isFull() {
        return (top == MAX - 1);
    }

    // Function to push a character onto the stack
    void push(char ch) {
        if (isFull()) {
            cout << "Stack Overflow!" << endl;
        } else {
            top++;
            revStr[top] = ch;
        }
    }

    // Function to check if the string is a palindrome
    void isPalindrome() {
        if (str == revStr) {
            cout << "String is a Palindrome" << endl;
        } else {
            cout << "String is not a Palindrome" << endl;
        }
    }

    // Function to reverse the string using the stack
    void reverse() {
        for (int i = str.length() - 1; i >= 0; i--) {
            push(str[i]);
        }
    }
};

int main() {
    Stack stk;
    stk.getData();
    stk.reverse();
    stk.getData();
    stk.isPalindrome();
    return 0;
}
