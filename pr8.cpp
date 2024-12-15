#include <iostream>
#include <string>
using namespace std;

struct Node {
    char bit;
    Node* next;
    Node* prev;
};

class BinaryNumber {
private:
    Node* head;
    Node* tail;

public:
    BinaryNumber() : head(nullptr), tail(nullptr) {}

    void addBit(char bit) {
        Node* newNode = new Node{bit, nullptr, tail};
        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void display() {
        Node* current = head;
        while (current) {
            cout << current->bit;
            current = current->next;
        }
        cout << endl;
    }

    void onesComplement() {
        Node* current = head;
        while (current) {
            current->bit = (current->bit == '0') ? '1' : '0';
            current = current->next;
        }
    }

    void twosComplement() {
        onesComplement();
        Node* current = tail;
        bool carry = true;

        while (current && carry) {
            if (current->bit == '1') {
                current->bit = '0';
            } else {
                current->bit = '1';
                carry = false;
            }
            current = current->prev;
        }

        if (carry) {
            addBit('1');
        }
    }

    static BinaryNumber add(BinaryNumber& num1, BinaryNumber& num2) {
        BinaryNumber result;
        Node* ptr1 = num1.tail;
        Node* ptr2 = num2.tail;
        bool carry = false;

        while (ptr1 || ptr2 || carry) {
            int sum = carry;
            if (ptr1) {
                sum += (ptr1->bit - '0');
                ptr1 = ptr1->prev;
            }
            if (ptr2) {
                sum += (ptr2->bit - '0');
                ptr2 = ptr2->prev;
            }

            carry = sum > 1;
            result.addBit((sum % 2) + '0');
        }

        reverse(result);
        return result;
    }

    static void reverse(BinaryNumber& binary) {
        Node* current = binary.head;
        Node* temp = nullptr;

        while (current) {
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;
            current = temp;
        }

        if (temp) {
            binary.tail = binary.head;
            binary.head = temp->prev;
        }
    }

    ~BinaryNumber() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

BinaryNumber inputBinaryNumber() {
    BinaryNumber binary;
    string binaryStr;
    cout << "Enter a binary number: ";
    cin >> binaryStr;
    for (char bit : binaryStr) {
        binary.addBit(bit);
    }
    return binary;
}

int main() {
    cout << "Binary Number Operations using Doubly Linked List\n";
    BinaryNumber num1 = inputBinaryNumber();
    BinaryNumber num2 = inputBinaryNumber();
    cout << "\nBinary Number 1: ";
    num1.display();
    cout << "1's Complement: ";
    num1.onesComplement();
    num1.display();
    cout << "2's Complement: ";
    num1.twosComplement();
    num1.display();
    cout << "\nBinary Number 2: ";
    num2.display();
    cout << "1's Complement: ";
    num2.onesComplement();
    num2.display();
    cout << "2's Complement: ";
    num2.twosComplement();
    num2.display();
    BinaryNumber sum = BinaryNumber::add(num1, num2);
    cout << "\nSum of the two binary numbers: ";
    sum.display();
    return 0;
}
