#include "AVLTree.h"
#include <iostream>
#include <stdlib.h>
#include <iomanip>
using namespace std;

int Node::getHeight(Node* node) {
    if(node == NULL)
        return 0;

    int leftHeight = getHeight(node->left);
    int rightHeight = getHeight(node->right);

    if(leftHeight > rightHeight)
        return leftHeight + 1;
    else
        return rightHeight + 1;
}

Node* Node::leftRotation(Node* node2) {
    Node* node1 = NULL;

    node1 = node2->right;
    node2->right = node1->left;
    node1->left = node2;

    node1->height = max(getHeight(node1->left), getHeight(node1->right)) + 1;
    node2->height = max(getHeight(node2->left), getHeight(node2->right)) + 1;

    return node1;
}

Node* Node::rightRotation(Node* node2) {
    Node* node1 = NULL;

    node1 = node2->left;
    node2->left = node1->right;
    node1->right = node2;

    node1->height = max(getHeight(node1->left), getHeight(node1->right)) + 1;
    node2->height = max(getHeight(node2->left), getHeight(node2->right)) + 1;

    return node1;
}

Node* Node::leftRightRotation(Node* node) {
    node->left = leftRotation(node->left);
    return rightRotation(node->left);
}

Node* Node::rightLeftRotation(Node* node) {
    node->left = rightRotation(node->left);
    return leftRotation(node->left);
}

Node* Node::getLastNode(Node* node) {
    if(node == NULL)
        return 0;
    if(node->left == NULL)
        return node;
    else
        getLastNode(node->left);
}

Node* Node::balanceTree(Node* node) {
    if(getHeight(node->left) - getHeight(node->right) > 1) {
        if(getHeight(node->left->left) >= getHeight(node->left->right))
            node = rightRotation(node);
        else
            node = leftRotation(node);
    }

    else if(getHeight(node->right) - getHeight(node->left) > 1) {
        if(getHeight(node->right->right) >= getHeight(node->right->left))
            node = leftRotation(node);
        else
            node = rightLeftRotation(node);
    }

    node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
    
    return node;
}

//---------------------------------------------------------------------------------------------------------

Node* Node::createAccount(Node* node, int pin, int num, string name, string nik, string gender, int bal) {
    if(node == NULL) {
        node = new Node(pin, num, name, nik, gender, bal);
        node->left = NULL;
        node->right = NULL;
        node->height = 0;
    }

    if(num < node-> num) {
        node->left = createAccount(node->left, pin, num, name, nik, gender, bal);

        if(getHeight(node->left) - getHeight(node->right) == 2) {
            if(num < node->left->num)
                node = rightRotation(node);
            else
                node = leftRightRotation(node);
        }
    }

    else if(num > node->num) {
        node->right = createAccount(node->right, pin, num, name, nik, gender, bal);

        if(getHeight(node->right) - getHeight(node->left) == 2) {
            if(num > node->right->num)
                node = leftRotation(node);
            else
                node = rightLeftRotation(node);
        }
    }

    node->height = max(getHeight(node->left), getHeight(node->right)) + 1;

    return node;
}

Node* Node::deleteAccount(Node* node, int num) {
    Node* tempNode = NULL;

    if(node == NULL)
        return node;

    else if(num < node->num)
        node->left = deleteAccount(node->left, num);

    else if(num > node->num)
        node->right = deleteAccount(node->right, num);
    
    else if(node->left && node->right) {
        tempNode = getLastNode(node->right);
        node->num = tempNode->num;
        node->right = deleteAccount(node->right, node->num);
    }

    else {
        tempNode = node;

        if(node->left == NULL) 
            node = node->right;

        else if(node->right == NULL) {
            node = node->left;
            delete tempNode;
        }

        if(node != NULL) {
            node = balanceTree(node);
        }
    }

    return node;
}

bool Node::findAccount(Node* node, int num) {
    while(node != NULL) {
        if(num < node->num)
            node = node->left;

        else if(num > node->num)
            node = node->right;

        else if(num == node->num)
            return true;
    }

    return false;
}

int Node::getLastNum(Node* node) {
    if(node == NULL)
        return 0;

    int lastNum = node->num;

    int leftLastNum = getLastNum(node->left);
    int rightLastNum = getLastNum(node->right);

    if(leftLastNum > lastNum)
        lastNum = leftLastNum;
    else if(rightLastNum > lastNum)
        lastNum = rightLastNum;

    return lastNum;
}

void Node::showAccountInfo(Node* node, int num) {
    while(node != NULL) {
        if(num < node->num)
            node = node->left;

        else if(num > node->num)
            node = node->right;
        
        else {
            cout << "Account No. : " << node->num << endl;
            cout << "Name        : " << node->name << endl;
            cout << "NIK         : " << node->nik << endl;
            cout << "Gender      : " << node->gender << endl;
            cout << "Balance     : " << node->bal << endl << endl;
        }
    }
}

void Node::displayAllAccounts(Node* node) {
    if(node == NULL)
        cout << "List of accounts is empty!!" << endl;

    else {
        if(node->left != NULL) 
            displayAllAccounts(node->left);

        cout << "Account No. : " << node->num << endl;
        cout << "Name        : " << node->name << endl;
        cout << "NIK         : " << node->nik << endl;
        cout << "Gender      : " << node->gender << endl;
        cout << "Balance     : " << node->bal << endl << endl;

        if(node->right != NULL)
            displayAllAccounts(node->right);
    }
}

int Node::depositFunds(Node* node, int pin, int num, int bal) {
    while(node != NULL) {
        if(num < node->num)
            node = node->left;

        else if(num > node->num)
            node = node->right;

        else if(num == node->num) {
            if(node->pin == pin)
                node->bal = node->bal + bal;

            else
                return -1;

            return 1;
        }
    }

    return 0;
}

int Node::withdrawFunds(Node* node, int pin, int num, int bal) {
    while(node != NULL) {
        if(num < node->num)
            node = node->left;
        else if(num > node->num)
            node = node->right;
        else if(num == node->num) {
            if(node->pin == pin) {
                if(node->bal < bal)
                    return -2;
                else
                    node->bal = node->bal - bal;
            }

            else
                return -1;
            
            return 1;
        }
    }

    return 0;
}

void Node::modifyInfo(Node* node, int pin, int num, string name, string nik, string gender, int bal) {
    while(node != NULL) {
        if(num < node->num)
            node = node->left;

        else if(num > node->num)
            node = node->right;

        else if(num == node->num) {
            node->pin = pin;
            node->num = num;
            node->name = name;
            node->nik = nik;
            node->gender = gender;
            node->bal = bal;
        }
    }
}