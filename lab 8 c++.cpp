#include <iostream>
using namespace std;

//node
struct Node {
    int data;    
    Node* next;     

    // Constructor
    Node(int value) {
        data = value;
        next = nullptr;
    }
};

// Queue class
class Queue {
private:
    Node* front;    // Pointer to the front of the queue
    Node* rear;     // Pointer to the rear of the queue

public:
    // Constructor to initialize the queue
    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    // Enqueue operation
    void enqueue(int value) {
        Node* newNode = new Node(value); // Create a new node
        if (rear == nullptr) {          // If the queue is empty
            front = rear = newNode;
        } else {
            rear->next = newNode;       // Link the new node at the end
            rear = newNode;             // Update the rear pointer
        }
        cout << value << " enqueued to the queue.\n";
    }

    // Dequeue operation
    void dequeue() {
        if (front == nullptr) {         // If the queue is empty
            cout << "Queue is empty. Cannot dequeue.\n";
            return;
        }
        Node* temp = front;             // Store the front node
        front = front->next;            // Move the front pointer to the next node

        if (front == nullptr)           // If the queue becomes empty
            rear = nullptr;

        cout << temp->data << " dequeued from the queue.\n";
        delete temp;                    // Free the memory of the dequeued node
    }

    // Peek operation to get the front element
    int peek() {
        if (front == nullptr) {
            cout << "Queue is empty.\n";
            return -1;                  // Return a dummy value
        }
        return front->data;
    }

    // Check if the queue is empty
    bool isEmpty() {
        return front == nullptr;
    }

    // Display the queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }
        Node* temp = front;
        cout << "Queue elements: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

// Main function
int main() {
    Queue q;

    // Enqueue elements
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    // Display the queue
    q.display();

    // Dequeue elements
    q.dequeue();
    q.display();

    // Peek at the front element
    cout << "Front element: " << q.peek() << endl;

    // Check if the queue is empty
    cout << (q.isEmpty() ? "Queue is empty.\n" : "Queue is not empty.\n");

    return 0;
}