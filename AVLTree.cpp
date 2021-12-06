#include "AVLTree.h"
#include <iostream>
#include <stdlib.h>
#include <iomanip>
using namespace std;

// Obtain the height of a specific Node by calculating the left and right branch separately
int Node::getHeight(Node* node) {
    
    // Base case
    if(node == NULL)
        return 0;

    // Calculating the height is done recursively
    // Store the height to either Left or Right respectively to be compared later 
    int leftHeight = getHeight(node->left);
    int rightHeight = getHeight(node->right);

    // Return the biggest height from either Left or Right branch
    if(leftHeight > rightHeight)
        return leftHeight + 1;
    else
        return rightHeight + 1;
}

// Left rotation between two Nodes and two Nodes only
Node* Node::leftRotation(Node* node2) {
    Node* node1 = NULL;

    // Store the right Node of the root in temporary Node
    node1 = node2->right;
    node2->right = node1->left;
    node1->left = node2;

    // Assign the new height after rotation
    node1->height = max(getHeight(node1->left), getHeight(node1->right)) + 1;
    node2->height = max(getHeight(node2->left), getHeight(node2->right)) + 1;

    // Return to root Node
    return node1;
}

// Left rotation between two Node and two Nodes only
Node* Node::rightRotation(Node* node2) {
    // Create a temporary Node
    Node* node1 = NULL;

    // Store the left Node of the root in temporary Node
    node1 = node2->left;
    node2->left = node1->right;
    node1->right = node2;

    // Assign the new height after rotation
    node1->height = max(getHeight(node1->left), getHeight(node1->right)) + 1;
    node2->height = max(getHeight(node2->left), getHeight(node2->right)) + 1;

    // Return to root Node
    return node1;
}

// Left-right rotation between three Nodes and three Nodes only for imbalanced crooked Node on the left branch of the current Node
Node* Node::leftRightRotation(Node* node) {
    
    // Left rotation is done after the right rotation has been done
    node->left = leftRotation(node->left);
    
    // Right rotation is done first by entering the recursive function above
    return rightRotation(node->left);
}

// Right-left rotation between three Nodes and three Nodes only for imbalanced crooked Node on the right branch of the current Node 
Node* Node::rightLeftRotation(Node* node) {
    
    // Right rotation is done after the left rotation has been done
    node->left = rightRotation(node->left);
    
    // Left rotation is done first by entering the recursive function above
    return leftRotation(node->left);
}

// Obtain the leaf Node from left branch of a root Node
Node* Node::getLastNode(Node* node) {
    if(node == NULL)
        return 0;
    if(node->left == NULL)
        return node; // This returns the last Node
    else
        getLastNode(node->left);
}

// Self-balancing Tree to preserve the Balance Factor of each node in a Tree
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

// Function to create a Bank Account
Node* Node::createAccount(Node* node, int pin, int num, string name, string nik, string gender, float bal) {
    
    // If the first Node of a tree or even the Node (at leaf node) after doing a recursive is NULL, then create the new Node (Bank Account) there
    // This if statement will only be executed when the recursive function has reached the leaf Node of a root Node
    if(node == NULL) {
        node = new Node(pin, num, name, nik, gender, bal);
        node->left = NULL;
        node->right = NULL;
        node->height = 0;
    }

    // Check whether the inserted Bank Account No. is greater than or lesser than the root Node
    // If the No. is lesser than the root Node, then create an edge to the left branch of the root Node and store in a new Node there
    // Recursive is done if there are one or more child to the left branch
    if(num < node-> num) {
        node->left = createAccount(node->left, pin, num, name, nik, gender, bal);

        // Check the Balance Factor of the left and right branch height if the left height is heavier by 2
        // Balance Factor can only be -1, 0, +1
        if(getHeight(node->left) - getHeight(node->right) == 2) {
            if(num < node->left->num)
                node = rightRotation(node);
            else
                node = leftRightRotation(node);
        }
    }
    // If the No. is greater than the root Node, then create an edge to the right branch of the root Node and store in a new Node there
    // Recursive is done if there are one or more child to the right branch
    else if(num > node->num) {
        node->right = createAccount(node->right, pin, num, name, nik, gender, bal);

        // Check the Balance Factor of the left and right branch height if the right height is heavier by 2
        // Balance Factor can only be -1, 0, +1
        // Do a left rotation if the Bank Account No. is greater than the right
        if(getHeight(node->right) - getHeight(node->left) == 2) {
            if(num > node->right->num)
                node = leftRotation(node);
            else
                node = rightLeftRotation(node);
        }
    }

    // Store the maximum height (largest amount of node from root to leaf) of a current Node either from the left or right branch
    node->height = max(getHeight(node->left), getHeight(node->right)) + 1;

    // Return to root Node
    return node;
}

// Function to delete a Bank Account
Node* Node::deleteAccount(Node* node, int num) {
    // Create a temporary Node
    Node* tempNode = NULL;

    // Base case
    if(node == NULL)
        return node;

    // Check if the Bank Account No. is smaller or larger than the Bank Account No. on the current Node
    // Recursive either to the left or right branch of the root Node until the Node to be deleted is found
    else if(num < node->num)
        node->left = deleteAccount(node->left, num);

    else if(num > node->num)
        node->right = deleteAccount(node->right, num);
    
    else if(node->left && node->right) {
        tempNode = getLastNode(node->right);
        node->num = tempNode->num;
        node->right = deleteAccount(node->right, node->num);
    }

    // Node to be deleted has been found
    else {
        // Store the Node to be deleted into a temporary Node
        tempNode = node;

        // If the left child is NUll, then replace the Node to be deleted with Node from the right child
        if(node->left == NULL) {
            node = node->right;
            delete tempNode;	
		}
        // If the right child is NUll, then replace the Node to be deleted with Node from the left child
        else if(node->right == NULL) {
            node = node->left;
            delete tempNode;
        }

        // The replaced Node needs to be balanced again since Balance Factors (at the replace Node) may have been affected by the Node replacement
        // Check also that the Node is not NULL to make sure
        if(node != NULL) {
            node = balanceTree(node);
        }
    }

    // Return to root Node
    return node;
}

// Find if user's Bank Account exist or not in the Binary Tree
bool Node::findAccount(Node* node, int num) {
    
    // Loop until leaf Node
    while(node != NULL) {
        // If Bank Account No. is smaller than the Bank Account No. on the current Node, traverse to the left branch
        if(num < node->num)
            node = node->left;
        // If Bank Account No. is larger than the Bank Account No. on the current Node, traverse to the right branch
        else if(num > node->num)
            node = node->right;
        // If Bank Account No. matches the Bank Account No. on the current Node, return "true"
        else if(num == node->num)
            return true;
    }
    // Return false if the Node traversal has reached the leaf Node
    return false;
}

// Find if user's Bank Account exist or not in the Binary Tree
bool Node::pinValidator(Node* node, int num, int pin) {
    
    // Loop until leaf Node
    while(node != NULL) {
        // If Bank Account No. is smaller than the Bank Account No. on the current Node, traverse to the left branch
        if(num < node->num)
            node = node->left;
        // If Bank Account No. is larger than the Bank Account No. on the current Node, traverse to the right branch
        else if(num > node->num)
            node = node->right;
        // If Bank Account No. matches the Bank Account No. on the current Node, return "true"
        else if(num == node->num && pin == node->pin)
            return true;
    }
    cout << "PIN Invalid" << endl;
    // Return false if the Node traversal has reached the leaf Node
    return false;
}

// Obtain the last Bank Account No. at the leaf Node
int Node::getLastNum(Node* node) {
    
    // Base case
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

// Display a user's Bank Account info
void Node::showAccountInfo(Node* node, int num) {
    // Traverse through the Binary Tree
    while(node != NULL) {
        // If Bank Account No. is smaller than the Bank Account No. on the current Node, traverse to the left branch
        if(num < node->num)
            node = node->left;
        // If Bank Account No. is larger than the Bank Account No. on the current Node, traverse to the right branch
        else if(num > node->num)
            node = node->right;
        // If Bank Account No. matches the Bank Account No. on the current Node, display the user's necessary account info
        else {
            cout << "Account No. : " << node->num << endl;
            cout << "Name        : " << node->name << endl;
            cout << "NIK         : " << node->nik << endl;
            cout << "Gender      : " << node->gender << endl;
            cout << "Balance     : " << node->bal << endl << endl;
        }
    }
}

// Display all the user's Bank Account in the whole Binary Tree
void Node::displayAllAccounts(Node* node) {
    
    // Base case
    if(node == NULL)
        cout << "List of accounts is empty!!" << endl;

    else {
        // Both if statements below will traverse through left and right branch of the whole tree
        // Traverse to the left branch recursively
        if(node->left != NULL) 
            displayAllAccounts(node->left);

        cout << "Account No. : " << node->num << endl;
        cout << "Name        : " << node->name << endl;
        cout << "NIK         : " << node->nik << endl;
        cout << "Gender      : " << node->gender << endl;
        cout << "Balance     : " << node->bal << endl << endl;

        // Traverse to the right branch recrusively
        if(node->right != NULL)
            displayAllAccounts(node->right);
    }
}

// Function to deposit
void Node::depositFunds(Node* node, int num, float bal) {
    // Traverse the whole Binary Tree
    while(node != NULL) {
        // If Bank Account No. is smaller than the Bank Account No. on the current Node, traverse to the left branch
        if(num < node->num)
            node = node->left;

        // If Bank Account No. is larger than the Bank Account No. on the current Node, traverse to the right branch
        else if(num > node->num)
            node = node->right;

        // Check if Bank Account No. matches the Bank Account No. on the current Node
        else if(num == node->num) {
                // Add the deposit to the user's account current balance
                node->bal += bal;
        }
    }
    // Base return
    return 0;
}

// Funciton to withdraw
bool Node::withdrawFunds(Node* node, int pin, int num, float bal) {
    // Traverse the whole Binary Tree
    while(node != NULL) {
        // If Bank Account No. is smaller than the Bank Account No. on the current Node, traverse to the left branch
        if(num < node->num)
            node = node->left;
        
        // If Bank Account No. is larger than the Bank Account No. on the current Node, traverse to the right branch
        else if(num > node->num)
            node = node->right;
        
        // Check if Bank Account No. matches the Bank Account No. on the current Node
        else if(num == node->num) {
                // If the withdrawal fund is larger than the amount of current balance, return -2 
                if(node->bal < bal)
                	cout << "Not enough balance" << endl;
                    return false;
                else
                    // Else withdraw the fund of the user's account current balance
                    node->bal -= bal;
                    return true;
            }
        }
    }
    // Base return
    return false;
}

// Function to modify a user's Bank Account
void Node::modifyInfo(Node* node, int pin, int num, string name, string nik, string gender, int bal) {
    // Traverse the whole Binary Tree
    while(node != NULL) {
        // If Bank Account No. is smaller than the Bank Account No. on the current Node, traverse to the left branch
        if(num < node->num)
            node = node->left;

        // If Bank Account No. is larger than the Bank Account No. on the current Node, traverse to the right branch
        else if(num > node->num)
            node = node->right;

        // If Bank Account No. matches the Bank Account No. on the current Node, assign the modified account info
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
