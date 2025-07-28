#include <iostream>
using namespace std;

// Node structure for Doubly Linked List
struct Node {
    int data;
    Node* prev;
    Node* next;
};

Node* head = nullptr;

// Function to traverse the list
void traverse() {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return;
    }
    Node* temp = head;
    cout << "Doubly Linked List (forward): ";
    while (temp != nullptr) {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

// Insert at beginning
void insertAtBeginning(int value) {
    Node* newNode = new Node{value, nullptr, head};
    if (head != nullptr) {
        // purono head node er prev natun nod hoy
        head->prev = newNode;
    }
    head = newNode;
    cout << value << " inserted at beginning.\n";
}

// Insert at end
void insertAtEnd(int value) {
    Node* newNode = new Node{value, nullptr, nullptr};
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
    cout << value << " inserted at end.\n";
}

// Insert at specific position
void insertAtPosition(int value, int pos) {
    if (pos < 1) {
        cout << "Invalid position.\n";
        return;
    }
    if (pos == 1) {
        insertAtBeginning(value);
        return;
    }

    Node* temp = head;
    for (int i = 1; i < pos - 1 && temp != nullptr; i++) {
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Position out of range.\n";
        return;
    }

    Node* newNode = new Node{value, temp, temp->next};
    if (temp->next != nullptr) {
        // jodi temp er pore kono node thake tahole tar prev
        //pointer notun node ke dekhay
        temp->next->prev = newNode;
    }
    // ager node er next pointer natun node ke dekhay
    temp->next = newNode;
    cout << value << " inserted at position " << pos << ".\n";
}

// Delete from beginning
void deleteFromBeginning() {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return;
    }
    Node* temp = head;
    head = head->next;
    if (head != nullptr) {
        head->prev = nullptr;
    }
    cout << temp->data << " deleted from beginning.\n";
    delete temp;
}

// Delete from end
void deleteFromEnd() {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return;
    }
    //jodi list e 1 ti node thake
    if (head->next == nullptr) {
        cout << head->data << " deleted from end.\n";
        delete head;
        head = nullptr;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    cout << temp->data << " deleted from end.\n";
    //shes node er ager node er next pointer
    temp->prev->next = nullptr;
    delete temp;
}

// Delete from specific position
void deleteFromPosition(int pos) {
    if (pos < 1 || head == nullptr) {
        cout << "Invalid position or list is empty.\n";
        return;
    }
    if (pos == 1) {
        deleteFromBeginning();
        return;
    }

    Node* temp = head;
    for (int i = 1; i < pos && temp != nullptr; i++) {
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Position out of range.\n";
        return;
    }

    if (temp->prev != nullptr) {
        temp->prev->next = temp->next;
    }
    if (temp->next != nullptr) {
        temp->next->prev = temp->prev;
    }

    cout << temp->data << " deleted from position " << pos << ".\n";
    delete temp;
}

// Search for a value
void search(int value) {
    Node* temp = head;
    int pos = 1;
    while (temp != nullptr) {
        if (temp->data == value) {
            cout << value << " found at position " << pos << ".\n";
            return;
        }
        temp = temp->next;
        pos++;
    }
    cout << value << " not found in the list.\n";
}

// Main function with menu
int main() {
    int choice, subChoice, value, pos;

    while (true) {
        cout << "\nMain Menu:\n";
        cout << "1. Traverse\n";
        cout << "2. Insert\n";
        cout << "3. Delete\n";
        cout << "4. Search\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                traverse();
                break;

            case 2:
                cout << "\nInsert Menu:\n";
                cout << "1. Insert at Beginning\n";
                cout << "2. Insert at End\n";
                cout << "3. Insert at Specific Position\n";
                cout << "Enter your choice: ";
                cin >> subChoice;
                cout << "Enter value to insert: ";
                cin >> value;
                if (subChoice == 1) {
                    insertAtBeginning(value);
                } else if (subChoice == 2) {
                    insertAtEnd(value);
                } else if (subChoice == 3) {
                    cout << "Enter position: ";
                    cin >> pos;
                    insertAtPosition(value, pos);
                } else {
                    cout << "Invalid insert choice.\n";
                }
                break;

            case 3:
                cout << "\nDelete Menu:\n";
                cout << "1. Delete from Beginning\n";
                cout << "2. Delete from End\n";
                cout << "3. Delete from Specific Position\n";
                cout << "Enter your choice: ";
                cin >> subChoice;
                if (subChoice == 1) {
                    deleteFromBeginning();
                } else if (subChoice == 2) {
                    deleteFromEnd();
                } else if (subChoice == 3) {
                    cout << "Enter position: ";
                    cin >> pos;
                    deleteFromPosition(pos);
                } else {
                    cout << "Invalid delete choice.\n";
                }
                break;

            case 4:
                cout << "Enter value to search: ";
                cin >> value;
                search(value);
                break;

            case 5:
                cout << "Exiting program.\n";
                return 0;

            default:
                cout << "Invalid choice! Try again.\n";
        }
    }

    return 0;
}
