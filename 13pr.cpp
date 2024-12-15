
#include <iostream>
#define MAX 5
using namespace std;

class PizzaParlor {
private:
    int orders[MAX], front = -1, rear = -1;

    bool isFull() { return (front == 0 && rear == MAX - 1) || (front == rear + 1); }
    bool isEmpty() { return front == -1; }

public:
    void placeOrder(int orderID) {
        if (isFull()) {
            cout << "The parlor is at full capacity. Cannot accept more orders.\n";
            return;
        }
        rear = (rear + 1) % MAX;
        orders[rear] = orderID;
        if (front == -1) front = 0;
        cout << "Order " << orderID << " placed successfully.\n";
    }

    void serveOrder() {
        if (isEmpty()) {
            cout << "No orders to serve.\n";
            return;
        }
        cout << "Serving order " << orders[front] << ".\n";
        if (front == rear) front = rear = -1; // Reset queue
        else front = (front + 1) % MAX;
    }

    void displayOrders() {
        if (isEmpty()) {
            cout << "No orders in the queue.\n";
            return;
        }
        cout << "Current orders: ";
        for (int i = front; i != rear; i = (i + 1) % MAX)
            cout << orders[i] << " ";
        cout << orders[rear] << "\n";
    }
};

int main() {
    PizzaParlor parlor;
    int choice, orderID;

    while (true) {
        cout << "\n1. Place Order\n2. Serve Order\n3. Display Orders\n4. Exit\nEnter your choice: ";
        cin >> choice;

        if (choice == 4) break;

        switch (choice) {
            case 1:
                cout << "Enter order ID: ";
                cin >> orderID;
                parlor.placeOrder(orderID);
                break;
            case 2:
                parlor.serveOrder();
                break;
            case 3:
                parlor.displayOrders();
                break;
            default:
                cout << "Invalid choice.\n";
        }
    }

    return 0;
}

