#include <iostream>

using namespace std;

class Node {
    public:
        Node(int value) {
            this->value = value;
            this->next = nullptr;
            this->prev = nullptr;
        }

        ~Node() {}

        int getValue() {
            return this->value;
        }

        Node* getNext() {
            return this->next;
        }

        Node* getPrevious() {
            return this->prev;
        }

        void setValue(int val) {
            this->value = val;
        }

        void setNext(Node* n) {
            this->next = n;
        }

        void setPrevious(Node* p) {
            this->prev = p;
        }

    private:
        int value;
        Node* next;
        Node* prev;
};

class DoubleLinkedList {
    public:
        DoubleLinkedList(){
            head = nullptr;
            tail = nullptr;
            length = 0;
        }

        DoubleLinkedList(int val){
            Node* newNode = new Node(val);
            head = newNode;
            tail = newNode;
            length = 1;
        }

        ~DoubleLinkedList(){
            Node* temp = head;
            while(temp){
                head = head->getNext();
                delete temp;
                temp = head;
            }
        }

        void append(int val){
            Node* temp = new Node(val);
            if(length == 0) {
                head = temp;
                tail = temp;
            } else {
                tail->setNext(temp);
                temp->setPrevious(tail);
                tail = temp;
            }
            length++;
        }

        void deleteLast() {
            if(length == 0) return;
            Node* temp = tail;
            if(length == 1) {
                tail = nullptr;
                head = nullptr;
            } else {
                tail = tail->getPrevious();
                tail->setNext(nullptr);
            }
            delete temp;
            length--;
        }

        void prepend(int val){
            Node* temp = new Node(val);
            if(length == 0){
                head = temp;
                tail = temp;
            } else {
                head->setPrevious(temp);
                temp->setNext(head);
                head = temp;
            }
            length++;
        }

        void deleteFirst() {
            if(length == 0) return;
            Node* temp = head;
            if(length == 1) {
                head = nullptr;
                tail = nullptr;
            } else {
                head = head->getNext();
                head->setPrevious(nullptr);
            }
            delete temp;
            length--;
        }

        Node* get(int index) {
            if(index < 0 || index >= length) return nullptr;
            Node* temp = head;
            for(int i = 0; i < index; i++){
                temp = temp->getNext();
            }
            return temp;
        }

        bool set(int index, int val){
            Node* temp = get(index);
            if(temp){
                temp->setValue(val);
                return true;
            }
            return false;
        }

        bool insert(int index, int val) {
            if(index < 0 || index > length) return false;
            if(length == 0 || index == length){
                this->append(val);
                return true;
            }
            if(index == 0) {
                this->prepend(val);
                return true;
            }
            Node* temp = get(index-1);
            if(temp){
                Node* newNode = new Node(val);
                newNode->setNext(temp->getNext());
                newNode->setPrevious(temp);
                temp->getNext()->setPrevious(newNode);
                temp->setNext(newNode);
                length++;
                return true;
            }
            return false;
        }

        bool deleteNode(int index){
            if(index < 0 || index >= length) return false;
            if(index == length-1) {
                deleteLast();
                return true;
            }
            if(index == 0){
                deleteFirst();
                return true;
            }
            Node* temp = get(index-1);
            Node* goal = temp->getNext();
            if(temp && goal){
                temp->setNext(goal->getNext());
                goal->getNext()->setPrevious(temp);
                delete goal;
                length--;
                return true;
            }
            return false;
        }

        void swapPairs(){
            if(length < 2) return;
            Node* temp = head;
            int tempVal = head->getValue();
            while(temp && temp->getNext()){
                temp->setValue(temp->getNext()->getValue());
                temp->getNext()->setValue(tempVal);
                temp = temp->getNext()->getNext();
                if(temp) tempVal = temp->getValue();
            }
        }

        void printAll(){
            if(length == 0) return;
            Node* curr = head;
            while(curr) {
                cout << curr->getValue() << endl;
                curr = curr->getNext();
            }
        }

        void printBackwards() {
            if(length == 0) return;
            Node* curr = tail;
            while(curr){
                cout << curr->getValue() << endl;
                curr = curr->getPrevious();
            }
        }

        void getHead() {
            cout << "The head is: " << this->head->getValue() << endl; 
        }

        void getTail() {
            cout << "The tail is: " << this->tail->getValue() << endl; 
        }

        void getLength() {
            cout << "The length is: " << this->length << endl; 
        }

    private:
        Node* head;
        Node* tail;
        int length;
};

int main() {
    DoubleLinkedList* dll = new DoubleLinkedList(1);
    dll->append(2);
    dll->append(3);
    dll->append(4);
    dll->append(5);
    dll->append(6);
    dll->printAll();
    cout << "=================" << endl;
    dll->swapPairs();
    dll->printAll();

}