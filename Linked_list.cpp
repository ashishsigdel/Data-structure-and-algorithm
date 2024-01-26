#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};

class LinkedList {
private:
    Node* first;

public:
   LinkedList() {
        first = NULL;
    }

    void addNode(int value) {
        Node* newNode = new Node(value);

        if (first == NULL) {
            first = newNode;
        } else {
            Node* current = first;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    void displayList() {
        Node* current = first;
        while (current != NULL) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList myList;

    char choice = 'Y';
    do {
        int value;
        Node* Ptr = new Node(0);
        Node* CPT;

        cout << "Enter data for the node: ";
        cin >> value;

        // Update the first pointer if it's the first node
        if (Ptr->data == 0) {
            Ptr->data = value;
            myList.addNode(Ptr->data);
        } else {
            CPT = new Node(value); 
            myList.addNode(CPT->data);

            // Link the previous node to the new node
            Ptr->next = CPT;
            Ptr = CPT;
        }
        cout << "Do you want to add more nodes? (Y/N): ";
        cin >> choice;

    } while (choice == 'Y' || choice == 'y');

    myList.displayList(); 
    return 0;
}
