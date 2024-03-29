#include <iostream>

using namespace std;

class Node {
    public:
        Node() {
            value = 0;
            next = nullptr;
        }

        Node(int val){
            value = val;
            next = nullptr;
        }

        Node* getNext() const{
            return this->next;
        }

        int getValue() const{
            return this->value;
        }

        void setNext(Node* temp) {
            this->next = temp;
        }

        void setValue(int val){
            this->value = val;
        }
    private:
        int value;
        Node* next;
};

class Stack {
    public:
        Stack() {
            top = nullptr;
            height = 0;
        }

        Stack(int val) {
            Node* newNode = new Node(val);
            top = newNode;
            height = 1;
        }

        ~Stack() {
            Node* curr = top;
            while(curr) {
                top = top->getNext();
                delete curr;
                curr = top;
            }
        }

        void printAll(){
            if(height == 0) return;
            Node* curr = top;
            while(curr){
                cout << curr->getValue() << endl;
                curr = curr->getNext();
            }
        }

        int peek() {
            if(height > 0) {
                cout << top->getValue() << endl;
                return top->getValue();
            }
            return -1;
        }

        void push(int val) {
            Node* newNode = new Node(val);
            if(height == 0) {
                top = newNode;
            } else {
                newNode->setNext(top);
                top = newNode;
            }
            height++;
        }

        void pop() {
            if(height == 0) return;
            Node* temp = top;
            if(height == 1) {
                top = nullptr;
            } else {
                top = top->getNext();
            }
            delete temp;
            height--;
        }
    private:
        Node* top;
        int height;
};

class Queue {
    public:
        Queue(){
            front = nullptr;
            back = nullptr;
            length = 0;
        }

        Queue(int val) {
            Node* newNode = new Node(val);
            front = newNode;
            back = newNode;
            length = 1;
        }

        ~Queue() {
            Node* temp = front;
            while(temp) {
                front = front->getNext();
                delete temp;
                temp = front;
            }
        }

        int peek() {
            if(length > 0) {
                cout << front->getValue() << endl;
                return front->getValue();
            }
            return -1;
        }

        void pushBack(int val) {
            Node* newNode = new Node(val);
            if(length == 0){
                front = newNode;
                back = newNode;
            } else {
                back->setNext(newNode);
                back = newNode;
            }
            length++;
        }

        void pop() {
            if(length == 0) return;
            Node* temp = front;
            if(length == 1) {
                front = nullptr;
                back = nullptr;
            } else {
                front = front->getNext();
            }
            delete temp;
            length--;
        }

        void printAll() {
            Node* curr = front;
            while(curr) {
                cout << curr->getValue() << endl;
                curr = curr->getNext();
            }
        }
    
    private:
        Node* front;
        Node* back;
        int length;
};

int main() {
    Stack* st = new Stack(3);
    st->push(2);
    st->push(1);
    st->printAll();
    cout << "===================" << endl;
    Queue* q = new Queue(1);
    q->pushBack(2);
    q->pushBack(3);
    q->pushBack(4);
    q->printAll();
}