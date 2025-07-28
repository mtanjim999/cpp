#include <iostream>
using namespace std;

#define MAX 100

class Stack {
private:
    int top;
    int arr[MAX]; // Stack array

public:
    Stack() { top = -1; } // Constructor initializes top to -1


    void push(int value) {
        if (top >= MAX - 1) {
            cout << "Stack Overflow! Cannot push " << value << endl;
            return;
        }
        arr[++top] = value;
        cout << value << " pushed into the stack." << endl;
    }


    void pop() {
        if (top == -1) {
            cout << "Stack Underflow! No elements to pop." << endl;
            return;
        }
        cout << arr[top] << " popped from the stack." << endl;
        top--;
    }


    void peek() {
        if (top < 0) {
            cout << "Stack is empty!" << endl;
            return;
        }
        cout << "Top element: " << arr[top] << endl;
    }


    void display() {
        if (top < 0) {
            cout << "Stack is empty!" << endl;
            return;
        }
        cout << "Stack elements: ";
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};


int main() {
    Stack s;
    int choice, value;

    do {
        cout << "\nStack Operations Menu:\n";
        cout << "1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                s.push(value);
                break;
            case 2:
                s.pop();
                break;
            case 3:
                s.peek();
                break;
            case 4:
                s.display();
                break;
            case 5:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice! Try again." << endl;
        }
    } while (choice != 5);

    return 0;
}

