#include<iostream>

using namespace std;

class node {
    public:
    int data;
    node* next;

    node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

class Queue {
    public:
    node* front;
    node* rear;

    void Insert(int data);    
    void Delete();
    void printQueue();
    Queue(int data) {
        node* nodeToInsert = new node(data);
        front = rear = nodeToInsert;
    }
};

void Queue::Insert(int data) {
    node* nodeToInsert = new node(data);
    if(rear == NULL) {
        rear = front = nodeToInsert;
        return;
    }
    rear->next = nodeToInsert;
    rear = rear->next;
}

void Queue::Delete() {
    if(front == rear) {
        front == NULL;
        rear == NULL;
        return;
    }
    front = front->next;
}

void Queue::printQueue() {
    cout<<"Printing from front to rear"<<endl;
    node* temp = front;
    while(temp != NULL) {
        cout<<temp->data<<endl;
        temp = temp->next;
    }
}

int main() {
    Queue obj = Queue(12);
    obj.Insert(45);
    obj.Insert(47);
    obj.Delete();

    obj.printQueue();



    return 0;
}