#include "tree.h"
#include "stack.h"
#include "queue.h"

//
// Methods for a BST: 3 categories
//  [a] constructor
//  [b] insert
//  [c] traversal to print
//

BST::BST()
{
	root = NULL;	
}
// ------------------- INSERT DIVISION --------------------------
//
// Insert: public version of Insert takes a value only and
// 	   inserts in the tree at the root
//
void BST::unbalancedInsert(int v)
{
	root = unbalancedInsert(root, v);
}

//
// Insert: private version inserts a value at any subtree
//         given by the 'root' of that tree
//
//   rets: the current tree NOW WITH the value inserted
//   note: ALWAYS adds a leaf
//
BSTNode* BST::unbalancedInsert(BSTNode* r, int v)
{
        //Base Case for recursion:
        //We have reached the end of the
        //tree and we are at NULL. We
        //create a node with the correct
        //information and return a pointer
        //to the new data. This return sets
        //the value for the parent which made
        //the function call
        
        if(r == NULL)
        {
            r = new BSTNode;
            r->value = v;
            r->left = NULL;
            r->right = NULL;
            return r;
        }
        
        //notice we asked NULL first so that
        //r->left and r->right will not seg fault
        
        else if(v < r->value)
        {
            r->left = unbalancedInsert(r->left, v);
            return r;
            
        }
        
        else
        {
            r->right = unbalancedInsert(r->right, v);
            return r;
            
            
        }
}
//
// ------------------- PRINT DIVISION --------------------------
//   First two (inOrder, postOrder) are recursive
//
void BST::inOrder()
{
	inOrder(root);		// calls the next one
}


void BST::inOrder(BSTNode* root)
{

    if (root == NULL){
		return;
    }
    inOrder(root->left);
    cout << root->value << " ";
    inOrder(root->right);
    
    return;
}

void BST::postOrder()
{	
	postOrder(root);	// calls the next one
}

void BST::postOrder(BSTNode* root)
{
	if (root == NULL){
		return;
	}
	
	postOrder(root->left);
	postOrder(root->right);
	cout << root->value << " ";
}


// print the tree in preOrder using the next function
// Question to ponder: can we do this without a helper function?
void BST::preOrder()
{
	preOrder(root);		// calls the next one (really needed?) nope
}

//
// preOrder traversal using a stack of our own, not
// the one from the compiler

void BST::preOrder(BSTNode* root)
{
	//preorder with a stack
	//stack defined here:
	Stack stacey;
	BSTNode* temp;
	
	stacey.push(root);
	while (!stacey.isEmpty()){
		temp = stacey.pop();
		
		cout << temp->value << " ";
		
		if(temp->right != NULL){
			stacey.push(temp->right);
		}
		if (temp->left != NULL){
			stacey.push(temp->left);
		}
	}
}

//
//   Final one, (level Order) uses a Queue, not recursive
//

void BST::levelOrder()
{
	levelOrder(root);		// does it need a helper?  No
}

void BST::levelOrder(BSTNode* root)	// the helper
{

	//level order with a queue
	Queue quinn;
	BSTNode* temp;
	
	quinn.insert(root);
	
	while (!quinn.isEmpty()){
		temp = quinn.remove();
		cout << temp->value << " ";
		
		if (temp->left != NULL){
			quinn.insert(temp->left);
		}
		if (temp->right != NULL){
			quinn.insert(temp->right);
		}
	}
	
}

