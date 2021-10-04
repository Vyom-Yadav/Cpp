#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define n INT_MAX

class myQueue {
    int* arr;
    int front;
    int back;

    public:
    myQueue() {
        arr = new int[n];
        front = -1;
        back = -1;
    }

    void enqueue(int x) { 
        if(back == n-1) {
            cout<<"Overflow"<<endl;
            return;
        }
        back++;
        arr[back] = x;

        if(front == -1) {
            front++;
        }
    }

    void dequeue() {
        if(front == -1 || front > back) {
            cout<<"Underflow"<<endl;
            return;
        }
        front++;
    }

    void display() {
        if(front == -1 || front > back) {
            cout<<"Empty Queue"<<endl;
            return;
        } 
        for(int i=front; i<=back; i++) {
            cout<<*(arr + i)<<" ";
        }
        cout<<endl;
    }

};


int main() {
    myQueue q;
    q.enqueue(12);
    q.enqueue(122);
    q.enqueue(1);
    q.enqueue(32);

    q.display();

    q.dequeue();
    q.dequeue();

    q.display();
    
    return 0;
}