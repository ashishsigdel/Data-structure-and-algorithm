#include<iostream>

using namespace std;

class Queue {
  private:
    int front;
    int rear;
    int arr[5];

  public:
    Queue() {
      front = -1;
      rear = -1;
      for (int i = 0; i < 5; i++) {
        arr[i] = 0;
      }
    }
  bool isEmpty() {
    if (front == -1 && rear == -1)
      return true;
    else
      return false;
  }
  bool isFull() {
    if (rear == 4)
      return true;
    else
      return false;
  }
  void enqueue(int val) {
    if (isFull()) {
      cout << "Queue is full" << endl;
      return;
    } else if (isEmpty()) {
      rear = 0;
      front = 0;
      arr[rear] = val;
    } else {
      rear++;
      arr[rear] = val;
    }

  }

  int dequeue() {
    int x = 0;
    if (isEmpty()) {
      cout << "Queue is Empty" << endl;
      return x;
    } else if (rear == front) {
      x = arr[rear];
      rear = -1;
      front = -1;
      return x;
    } else {
      x = arr[front];
      arr[front] = 0;
      front++;
      return x;
    }
  }

  int count() {
    if(isEmpty())
    return 0;

    else 
    return (rear - front + 1);
  }

  void display() {
    cout << "All values in the Queue are - " << endl;
    for (int i = 0; i < 5; i++) {
      cout << arr[i] << "  ";
    }
  }

};

int main() {
  Queue q1;
  int value, option;

  do {
    cout << "Select option to perform the operation" << endl;
    cout << "1. Enqueue()" << endl;
    cout << "2. Dequeue()" << endl;
    cout << "3. isEmpty()" << endl;
    cout << "4. isFull()" << endl;
    cout << "5. Count()" << endl;
    cout << "6. Display()" << endl;

    cin >> option;

    switch (option) {
    case 0:
      break;
    case 1:
      cout <<endl<< "Enter an value to Enqueue in the Queue" << endl;
      cin >> value;
      q1.enqueue(value);
      break;
    case 2:
      cout << "Dequeued Value : " << q1.dequeue() << endl;
      break;
    case 3:
      if (q1.isEmpty())
        cout << "Queue is Empty" << endl;
      else
        cout << "Queue is not Empty" << endl;
      break;
    case 4:
      if (q1.isFull())
        cout << "Queue is Full" << endl;
      else
        cout << "Queue is not Full" << endl;
      break;
    case 5:
      cout << "Total values in Queue : " << q1.count() << endl;
      break;
    case 6:
      q1.display();
      break;
    default:
      cout << "Enter Proper Option number " << endl;
    }

  } while (option != 0);

  return 0;
}