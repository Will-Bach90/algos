#include <iostream>

using namespace std;

class Node{
    private:
        int value;
        Node* left;
        Node* right;

    public:
        Node() {
            this->value = 0;
            this->left = nullptr;
            this->right = nullptr;
        }

        Node(int val) {
            this->value = val;
            this->left = nullptr;
            this->right = nullptr;
        }

        int getValue() {
            return this->value;
        }

        Node* getLeft() {
            return this->left;
        }

        Node* getRight() {
            return this->right;
        }

        void setValue(int val) {
            this->value = val;
        }

        void setLeft(Node* l) {
            this->left = l;
        }

        void setRight(Node* r) {
            this->right = r;
        }
};

class BinarySearchTree {
    private:
        Node* root;
        void deleteHelper(Node* temp) {
            if(temp == nullptr) return;
            deleteHelper(temp->getLeft());
            deleteHelper(temp->getRight());
            delete temp;
        }

        void printHelper(Node* temp) {
            if(temp == nullptr) return;
            printHelper(temp->getLeft());
            cout << temp->getValue() << endl;
            printHelper(temp->getRight());
        }

        void floatHelper(Node* temp) {
            if(temp == nullptr) return;
        }

    public:
        BinarySearchTree() {
            root = nullptr;
        }

        BinarySearchTree(int val) {
            Node* newNode = new Node(val);
            root = newNode;
        }

        ~BinarySearchTree() {
            deleteHelper(root);
        }

        void insertNode(int val) {
            if(root == nullptr) {
                Node* newNode = new Node(val);
                root = newNode;
            } else {
                Node* temp = root;
                Node* parent = root;
                while(temp) {
                    if(val == temp->getValue()) return;
                    parent = temp;
                    if(val < temp->getValue()) {
                        temp = temp->getLeft();
                    } else {
                        temp = temp->getRight();
                    }
                }
                Node* newNode = new Node(val);
                if(val < parent->getValue()) {
                    parent->setLeft(newNode);
                } else {
                    parent->setRight(newNode);
                }
            }
        }

        Node* findNode(int val) {
            Node* temp = root;
            while(temp){
                if(temp->getValue() == val) return temp;
                if(val < temp->getValue()) {
                    temp = temp->getLeft();
                } else {
                    temp = temp->getRight();
                }
            }
            return nullptr;
        }

        Node* findParent(int val) {
            if(val == root->getValue()) return nullptr;
            Node* temp = root;
            Node* parent = root;
            while(temp) {
                if(temp->getValue() == val) return parent;
                parent = temp;
                if(val < temp->getValue()) {
                    temp = temp->getLeft();
                } else {
                    temp = temp->getRight();
                }
            }
            return nullptr;
        }

        bool deleteNode(int val) {
            Node* target = findNode(val);
            Node* parent = findParent(val);

            if (!target) {
                return false; // Node not found
            }

            // Node with two children
            if (target->getLeft() != nullptr && target->getRight() != nullptr) {
                Node* succ = target->getRight();
                while (succ->getLeft() != nullptr) {
                    succ = succ->getLeft();
                }
                int succValue = succ->getValue();
                deleteNode(succ->getValue()); 
                target->setValue(succValue); 
                return true;
            }

            // Node with one child or no child
            Node* child = (target->getLeft() != nullptr) ? target->getLeft() : target->getRight();

            // If the target is the root
            if (!parent) {
                if (child != nullptr) {
                    // If the root has one child, make it the new root
                    root = child; 
                } else {
                    root = nullptr; // Assume 'root' is accessible globally
                }
            } else {
                if (parent->getLeft() == target) {
                    parent->setLeft(child);
                } else {
                    parent->setRight(child);
                }
            }

            delete target; // Delete the target node
            return true;
        }


        void floatNodeUp(Node* temp) {
            floatHelper(temp);
        }

        void printAll() {
            printHelper(root);
        }

        void deleteAll() {
            deleteHelper(root);
        }


};


int main() {
    BinarySearchTree* bst = new BinarySearchTree(10);
    bst->insertNode(3);
    bst->insertNode(15);
    bst->insertNode(1);
    bst->insertNode(5);
    bst->insertNode(12);
    bst->insertNode(17);
    bst->printAll();

    cout << "=================" << endl;
    Node* t1 = bst->findNode(5);
    Node* t2 = bst->findParent(10);
    if(t1) {
        cout << "The val is: " << t1->getValue() << endl;
    }

    // Node* t2 = bst->findNode(9);
    if(t2) {
        cout << "The parent val is: " << t2->getValue() << endl;
    }
}