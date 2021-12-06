#ifndef AVLTREEH
#define AVLTREEH
#include <string>
using namespace std;

class Node {
public:
    // Declare necessary variables for user's Bank Account 
    int pin; // PIN Number
    int num; // Bank Account No.
    string name; // User's Full Name
    string nik; // ID Number or Nomor Induk Kependudukan
    string gender; // Either Male or Female
    float bal; // User's Current Balance

    // Left and right pointer for branches and height for Balance Factor
    Node *right, *left;
    int height;

    // Node constructor of a parameterized Bank Account
    Node(int pin, int num, string name, string nik, string gender, float bal) {
        this->pin = pin;
        this->num = num;
        this->name = name;
        this->nik = nik;
        this->gender = gender;
        this->bal = bal;
    }

    // Declare necessary function prototype
    int getHeight(Node* node);
    Node* leftRotation(Node* node2);
    Node* rightRotation(Node* node2);
    Node* leftRightRotation(Node* node);
    Node* rightLeftRotation(Node* node);
    Node* getLastNode(Node* node);
    Node* balanceTree(Node* node);

    Node* createAccount(Node* node, int pin, int num, string name, string nik, string gender, float bal);
    Node* deleteAccount(Node* node, int num);
    bool findAccount(Node* node, int num);
    bool pinValidator(Node* node, int num, int pin);
    int getLastNum(Node* node);
    int showAccountInfo(Node* node, int num);
    void displayAllAccounts(Node* node);
    void depositFunds(Node* node, int num, float bal);
    bool withdrawFunds(Node* node, int num, float bal);
    void modifyInfo(Node* node, int pin, int num, string name, string nik, string gender, float bal);
};

#endif
