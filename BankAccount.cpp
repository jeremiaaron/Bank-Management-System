// Bank Account Binary Tree.
#include <bits/stdc++.h>

using namespace std;

class BankAccount
{	
	int key;
	BankAccount *left, *right;
	
	private:
		string Name;
		int NIK;
		string Gender;
		int age;
		float Balance = 0.0;

	public:
		
		// Default constructor
		BankAccount();
		
		// Parameterized constructor
		BankAccount(int, string, int, string, int , float);
		
		// Insert function.
	    BankAccount* Insert(BankAccount*, int);
	    
	    // Delete function
	    BankAccount* Delete(BankAccount*, int);
	    
	    // Search function
	    BankAccount* Search(BankAccount*, int);
	 
	    // Inorder traversal.
	    void Inorder(BankAccount*);
};

// Default constructor definition
BankAccount :: BankAccount() : key(0), left(NULL), right(NULL){};

// Parameterized constructor definition
BankAccount :: BankAccount(int k, string n, int nik, string g, int a, float b)
{
	key = k;
	
	Name = n;
	NIK = nik;
	Gender = g
	age = a;
	Balance = b;
	
	left = right = NULL;
}

/* A utility function to insert a new node with given key in
 * BST */
BankAccount* BankAccount :: Insert(BankAccount* root, int k, string n, int nik, int g, int a, float b)
{
    /* If the tree is empty, return a new node */
    if (root == NULL)
        return new BankAccount(k);
 
    /* Otherwise, recur down the tree */
    if (k < root->key)
        root->left = Insert(root->left, k);
    else
        root->right = Insert(root->right, k);
 
    /* return the (unchanged) node pointer */
    // This will return the main root
    return root;
}
 
/* Given a binary search tree and a key, this function
   deletes the key and returns the new root */
BankAccount* BankAccount :: Delete(BankAccount* root, int k)
{
    // Base case
    if (root == NULL)
        return root;
 
    // Recursive calls for ancestors of
    // node to be deleted
    
    // If the key to be deleted is
    // smaller than the root's
    // key, then it lies in left subtree
	if (k < root->key) {
        root->left = Delete(root->left, k);
        return root;
    }
	// If the key to be deleted is
    // greater than the root's
    // key, then it lies in right subtree
    else if (k > root->key) {
        root->right = Delete(root->right, k);
        return root;
    }
 
    // We reach here when root is the node
    // to be deleted.
 
    // If one of the children is empty
    if (root->left == NULL) {
        BankAccount* temp = root->right;
        delete root;
        return temp;
    }
    else if (root->right == NULL) {
        BankAccount* temp = root->left;
        delete root;
        return temp;
    }
 
    // If both children exist
    else {
 
        BankAccount* succParent = root; //succParent == successor parent
 
        // Find successor
        BankAccount* succ = root->right;
        while (succ->left != NULL) {
            succParent = succ;
            succ = succ->left;
        }
 
        // Delete successor.  Since successor
        // is always left child of its parent
        // we can safely make successor's
        // right child as left of its parent.
        // If there is no succ, then assign
        // succ->right to succParent->right
        if (succParent != root)
            succParent->left = succ->right;
        else
            succParent->right = succ->right;
 
        // Copy Successor Data to root
        root->key = succ->key;

        // Delete Successor and return root
        delete succ;
        return root;
    }
}

// C function to search a given key in a given BST
BankAccount* BankAccount :: Search(BankAccount* root, int k)
{
    // Base Cases: root is null or key is present at root
    if (root == NULL || root->key == k)
       return root;
    
    // Key is greater than root's key
    if (root->key < k)
       return Search(root->right, k);
 
    // Key is smaller than root's key
    return Search(root->left, k);
}

// A utility function to do inorder traversal of BST
void BankAccount :: Inorder(BankAccount* root)
{
    if (root != NULL) {
        Inorder(root->left);
        cout << "\t" << root->key;
        Inorder(root->right);
    }
}

// Driver Code
int main()
{
    /* Let us create following BST
              50
           /     \
          30      70
         /  \    /  \
       20   40  60   80 */
    
    BankAccount b, *root = NULL;
    
    root = b.Insert(root, 12450, "James", 13456, 'M', 23, 5000.0);
    b.Insert(root, 12467, "Mac", 12386, 'M', 28, 7000.0);
    b.Insert(root, 12488, "Earl", 14876, 'M', 21, 2500.0);
    b.Insert(root, 12431, "May", 13984, 'F', 31, 15000.0);
    b.Insert(root, 12442, "Brad", 10987, 'M', 28, 50000.0);
    b.Insert(root, 12479, "Jodi", 17456, 'F', 20, 16000.0);
    b.Insert(root, 12426, "Tilly", 18945, 'F', 25, 27000.0);
 
    cout << "Inorder traversal of the given tree \n";
    b.Inorder(root);
 
    cout << "\nDelete 20\n";
    b.Delete(root, 20);
    cout << "Inorder traversal of the modified tree \n";
    b.Inorder(root);
 
    cout << "\nDelete 30\n";
    b.Delete(root, 30);
    cout << "Inorder traversal of the modified tree \n";
    b.Inorder(root);
 
    cout << "\nDelete 50\n";
    b.Delete(root, 50);
    cout << "Inorder traversal of the modified tree \n";
    b.Inorder(root);
    
    return 0;
}
