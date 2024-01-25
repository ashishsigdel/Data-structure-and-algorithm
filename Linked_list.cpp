#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int main() {
    Node *Ptr, *CPT, *First, *Avail;

    // Assume Avail is a function that returns a new node
    Avail = new Node;
    
    // Assume link is a function that returns the next available node
    Avail->next = nullptr;

    // Read data into the first node
    cout << "Enter data for the first node: ";
    cin >> Avail->data;

    Ptr = Avail;
    First = Ptr;

    char CH = 'Y';

    while (CH == 'Y' || CH == 'y') {
        // Create a new node
        CPT = new Node;
        CPT->next = nullptr;

        // Read data into the new node
        cout << "Enter data for the next node: ";
        cin >> CPT->data;

        // Link the new node to the current node
        Ptr->next = CPT;

        // Move the pointer to the new node
        Ptr = CPT;

        // Ask user if they want to add more nodes
        cout << "Do you want to add more nodes? (Y/N): ";
        cin >> CH;
    }

    // Set the last node's link to NULL
    Ptr->next = nullptr;

    // Display the linked list
    Ptr = First;
    cout << "Linked List: ";
    while (Ptr != nullptr) {
        cout << Ptr->data << " ";
        Ptr = Ptr->next;
    }

    // Clean up memory by deleting the allocated nodes
    Ptr = First;
    while (Ptr != nullptr) {
        CPT = Ptr;
        Ptr = Ptr->next;
        delete CPT;
    }

    return 0;
}
