#include "node.h"


class BST

{
	public:
	
        BST();
    
        void unbalancedInsert(int v);
	
        void inOrder();
        void preOrder();
        void levelOrder();
        void postOrder();
	  
	
    private:
	
        BSTNode* unbalancedInsert(BSTNode* r, int v);
	
        void inOrder(BSTNode* r);
        void preOrder(BSTNode* r);
        void levelOrder(BSTNode* r);
        void postOrder(BSTNode* r);
    
        BSTNode* root;
};
	


