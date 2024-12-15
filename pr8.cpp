
#include <iostream>
using namespace std;

struct SLLNode {
    char data;
    SLLNode* next;
};

SLLNode* createSLL(int cnt);
void displaySLL(SLLNode* head);
SLLNode *headU = nullptr, *headA = nullptr, *headB = nullptr;

void calculateSets();

int main() {
    cout << "\n\tEnter Students (All, Vanilla, Butterscotch):\n";
    headU = createSLL(10);
    headA = createSLL(3);
    headB = createSLL(3);

    cout << "\nSet 'U': ";
    displaySLL(headU);
    cout << "Set 'A': ";
    displaySLL(headA);
    cout << "Set 'B': ";
    displaySLL(headB);

    calculateSets();
    return 0;
}

SLLNode* createSLL(int cnt) {
    SLLNode *head = nullptr, *tail = nullptr;
    for (int i = 0; i < cnt; i++) {
        SLLNode* newNode = new SLLNode;
        cout << "\tEnter Student Initial: ";
        cin >> newNode->data;
        newNode->next = nullptr;
        if (!head) head = tail = newNode;
        else tail = tail->next = newNode;
    }
    return head;
}

void displaySLL(SLLNode* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void addUnique(SLLNode* head, char* arr, int& idx) {
    while (head) {
        bool found = false;
        for (int j = 0; j < idx; j++) if (arr[j] == head->data) found = true;
        if (!found) arr[idx++] = head->data;
        head = head->next;
    }
}

void calculateSets() {
    char arr[10];
    int idx = 0;

    cout << "\nSet A U B: ";
    addUnique(headA, arr, idx);
    addUnique(headB, arr, idx);
    for (int i = 0; i < idx; i++) cout << arr[i] << " ";

    idx = 0;
    cout << "\nSet A ^ B: ";
    for (SLLNode *p = headA; p; p = p->next)
        for (SLLNode *q = headB; q; q = q->next)
            if (p->data == q->data) arr[idx++] = p->data;
    for (int i = 0; i < idx; i++) cout << arr[i] << " ";

    idx = 0;
    cout << "\nSet A - B: ";
    for (SLLNode *p = headA; p; p = p->next) {
        bool found = false;
        for (SLLNode *q = headB; q; q = q->next) if (p->data == q->data) found = true;
        if (!found) arr[idx++] = p->data;
    }
    for (int i = 0; i < idx; i++) cout << arr[i] << " ";

    idx = 0;
    cout << "\nSet B - A: ";
    for (SLLNode *q = headB; q; q = q->next) {
        bool found = false;
        for (SLLNode *p = headA; p; p = p->next) if (q->data == p->data) found = true;
        if (!found) arr[idx++] = q->data;
    }
    for (int i = 0; i < idx; i++) cout << arr[i] << " ";

    idx = 0;
    cout << "\nSet U - (A U B): ";
    for (SLLNode *p = headU; p; p = p->next) {
        bool found = false;
        for (SLLNode *q = headA; q; q = q->next) if (p->data == q->data) found = true;
        for (SLLNode *r = headB; r; r = r->next) if (p->data == r->data) found = true;
        if (!found) arr[idx++] = p->data;
    }
    for (int i = 0; i < idx; i++) cout << arr[i] << " ";
    cout << endl;
}
