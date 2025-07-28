#include <iostream>
using namespace std;

class CircularQueue {
private:
    int *queue;
    int size, front, rear;

public:
    CircularQueue(int s) {
        size = s;
        queue = new int[size];
        front = rear = -1;
    }

    ~CircularQueue() {
        delete[] queue;
    }

    void enqueue(int item) {
        if ((rear + 1) % size == front) {
            cout << "Queue is full!" << endl;
            return;
        } else if (front == -1) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % size;
        }
        queue[rear] = item;
        cout << "Inserted " << item << endl;
    }

    void dequeue() {
        if (front == -1) {
            cout << "Queue is empty!" << endl;
            return;
        }
        int removed = queue[front];
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % size;
        }
        cout << "Removed " << removed << endl;
    }

    void display() {
        if (front == -1) {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Queue elements: ";
        int i = front;
        while (true) {
            cout << queue[i] << " ";
            if (i == rear)
                break;
            i = (i + 1) % size;
        }
        cout << endl;
    }
};

int main() {
    int size;
    cout << "Enter the size of the circular queue: ";
    cin >> size;
    CircularQueue cq(size);

    while (true) {
        cout << "\nOptions:" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Display" << endl;
        cout << "4. Exit" << endl;

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            int item;
            cout << "Enter the element to enqueue: ";
            cin >> item;
            cq.enqueue(item);
        } else if (choice == 2) {
            cq.dequeue();
        } else if (choice == 3) {
            cq.display();
        } else if (choice == 4) {
            cout << "Exiting..." << endl;
            break;
        } else {
            cout << "Invalid choice! Please try again." << endl;
        }
    }
    return 0;
}

