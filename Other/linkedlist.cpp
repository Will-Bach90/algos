#include <iostream>

class Node{
    private:
        int value;
        Node* next;
    public:
        Node(int val){
            value = val;
            next = nullptr;
        }
        int getValue(){
            return this->value;
        }
        void setValue(int val){
            this->value = val;
        }

        Node* getNext(){
            return this->next;
        }
        void setNext(Node* temp){
            this->next = temp;
        }
};

class LinkedList{
    public:
        LinkedList(int value){
            Node* newNode = new Node(value);
            head = newNode;
            tail = newNode;
            length = 1;
        }
        ~LinkedList(){
            Node* curr = head;
            while(curr){
                head = head->getNext();
                delete curr;
                curr = head;
            }
        }
        void prependNode(int value){
            Node* newNode = new Node(value);
            if(length == 0){
                head = newNode;
                tail = newNode;
            } else {
                newNode->setNext(head);
                head = newNode;
            }
            length++;
        }
        void appendNode(int value){
            Node* newNode = new Node(value);
            if(length == 0){
                head = newNode;
                tail = newNode;
            } else {
                tail->setNext(newNode);
                tail = tail->getNext();
            }
            length++;
        }
        void deleteLast() {
            if(length == 0) return;
            Node* curr = head;
            if(length == 1) {
                head = nullptr;
                tail = nullptr;
            } else {
                Node* pre = head;
                while(curr->getNext()){
                    pre = curr;
                    curr = curr->getNext();
                }
                tail = pre;
                tail->setNext(nullptr);
            }
            delete curr;
            length--;
        }

        void deleteFirst() {
            if(length == 0) return;
            Node* curr = head;
            if(length == 1) {
                head = nullptr;
                tail = nullptr;
            } else {
                head = head->getNext();
            }
            delete curr;
            length--;
        }

        Node* get(int index) {
            if(index >= length || index < 0) return nullptr;
            Node* curr = head;
            for(int i = 0; i < index; i++) {
                curr = curr->getNext();
            }
            return curr;
        }

        bool set(int index, int value){
            Node* temp = get(index);
            if(temp){
                temp->setValue(value);
                return true;
            } 
            return false;
        }

        bool insert(int index, int value){
            if(index == 0) {
                prependNode(value);
                return true;
            }
            if(length >= 1 && index == length){
                 appendNode(value);
                 return true;
            }
            Node* temp = get(index-1);
            if(temp){
                Node* newNode = new Node(value);
                newNode->setNext(temp->getNext());
                temp->setNext(newNode);
                length++;
                return true;
            }
            return false;
        }

        bool deleteNode(int index){
            if(index == 0){
                deleteFirst();
                return true;
            }
            if(length >= 1 && index == length-1){
                deleteLast();
                return true;
            }
            Node* temp = get(index-1);
            if(temp){
                Node* tempNext = temp->getNext();
                temp->setNext(tempNext->getNext());
                delete tempNext;
                length--;
                return true;
            }
            return false;
        }

        void reverse() {
            Node* temp = head;
            head = tail;
            tail = temp;

            Node* after = temp->getNext();
            Node* before = nullptr;
            for(int i = 0; i < length; i++){
                after = temp->getNext();
                temp->setNext(before);
                before = temp;
                temp = after;
            }
        }

        Node* findMiddleNode(){
            if(head == nullptr || head == tail) return head;
            if(head->getNext() == tail) return tail;
            Node* slow = head;
            Node* fast = head;
            while(fast != nullptr && fast->getNext() != nullptr){
                fast = fast->getNext()->getNext();
                slow = slow->getNext();
            }
            return slow;
        }

        void partitionList(int x){
            if(head == nullptr) return;
            Node* trav = head;
            Node* high = nullptr;
            Node* highHead = nullptr;
            Node* low = nullptr;
            Node* lowHead = nullptr;

            while(trav){
                Node* next = trav->getNext();
                trav->setNext(nullptr);
                if(trav->getValue() < x){
                    if(lowHead == nullptr){
                        lowHead = trav;
                        low = lowHead;
                    } else {
                        low->setNext(trav);
                        low = low->getNext();
                    }
                } else {
                    if(highHead == nullptr){
                        highHead = trav;
                        high = highHead;
                    } else {
                        high->setNext(trav);
                        high = high->getNext();
                    }
                }
                trav = next;
            }

            if(low){
                low->setNext(highHead);
                head = lowHead;
            } else {
                head = highHead;
            }
        }

        void printLL(){
            Node* curr = head;
            while(curr){
                std::cout << curr->getValue() << std::endl;
                curr = curr->getNext();
            }
            if(head && tail){
                std::cout << "The head is: " << head->getValue() << std::endl;
                std::cout << "The tail is: " << tail->getValue() << std::endl;
                std::cout << "The length is: " << length << std::endl;
            } else {
                std::cout << "Null list!!!" << std::endl;
            }

        }
    private:
        Node* head;
        Node* tail;
        int length;
};

int main() {
    LinkedList* ll = new LinkedList(1);
    // ll->prependNode(1);
    // ll->prependNode(2);
    ll->appendNode(4);
    ll->appendNode(3);
    ll->appendNode(2);
    ll->appendNode(5);
    ll->appendNode(2);
    ll->printLL();
    std::cout << "============================== " << std::endl;
    ll->partitionList(4);
    ll->printLL();
    // std::cout << "The middle node is: " << ll->findMiddleNode()->getValue() << std::endl;

    // ll->printLL();
    // ll->insert(1, 1);
    // ll->printLL();
    // ll->insert(0, 8);
    // ll->printLL();
    // ll->deleteNode(1);
    // ll->printLL();
    // ll->reverse();
    // ll->printLL();
    // std::cout << "====================" << std::endl;
    // ll->deleteFirst();
    // ll->printLL();
    // std::cout << "====================" << std::endl;
    // ll->deleteLast();
    // ll->printLL();
    // std::cout << "====================" << std::endl;
    // ll->deleteFirst();
    // ll->printLL();
    // std::cout << "====================" << std::endl;
    // ll->deleteFirst();
    // ll->printLL();
}