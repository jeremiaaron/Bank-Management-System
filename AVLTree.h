#ifndef AVLTREEH
#define AVLTREEH
#include <string>
using namespace std;

class Node {
public:
    int pin;
    int num;
    string name;
    string nik;
    string gender;
    int bal;

    Node *right, *left;
    int height;

    Node(int pin, int num, string name, string nik, string gender, int bal) {
        this->pin = pin;
        this->num = num;
        this->name = name;
        this->nik = nik;
        this->gender = gender;
        this->bal = bal;
    }

    int getHeight(Node* node);
    Node* leftRotation(Node* node2);
    Node* rightRotation(Node* node2);
    Node* leftRightRotation(Node* node);
    Node* rightLeftRotation(Node* node);
    Node* getLastNode(Node* node);
    Node* balanceTree(Node* node);

    Node* createAccount(Node* node, int pin, int num, string name, string nik, string gender, int bal);
    Node* deleteAccount(Node* node, int num);
    bool findAccount(Node* node, int num);
    int getLastNum(Node* node);
    void showAccountInfo(Node* node, int num);
    void displayAllAccounts(Node* node);
    int depositFunds(Node* node, int pin, int num, int bal);
    int withdrawFunds(Node* node, int pin, int num, int bal);
    void modifyInfo(Node* node, int pin, int num, string name, string nik, string gender, int bal);
};

#endif