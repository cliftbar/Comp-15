#include "tree.h"
//
// main for QRST lab -- build and explore a Binary Search Tree
// Do not modify this program. Instead, fill in code for the
// tree.cpp
//

int main() {
	
	//create the tree
	BST testTree;
	testTree.unbalancedInsert(54);
	testTree.unbalancedInsert(22);
	testTree.unbalancedInsert(17);
	testTree.unbalancedInsert(41);
	testTree.unbalancedInsert(36);
	testTree.unbalancedInsert(30);
	testTree.unbalancedInsert(74);
	testTree.unbalancedInsert(76);
	testTree.unbalancedInsert(26);
	testTree.unbalancedInsert(27);
	testTree.unbalancedInsert(45);
	testTree.unbalancedInsert(82);
	
	cout << endl;
	cout << "Ricky to the rescue:" << endl;
	cout << "printing inorder: ";
	testTree.inOrder();
	cout << endl;
	cout<< "Answer:           17 22 26 27 30 36 41 45 54 74 76 82";
	cout << endl;
	cout << endl;
	cout << "Stacey saves the day" << endl;
	cout << "printing preorder: ";
	testTree.preOrder();
	cout << endl;
	cout <<"Answer:            54 22 17 41 36 30 26 27 45 74 76 82";
	cout << endl;
	cout << endl;
	cout << "Quiet down, Quinn's in Town" << endl;
	cout << "printing levelorder: ";
	testTree.levelOrder();
	cout << endl;
	cout <<"Answer:              54 22 74 17 41 76 36 45 82 30 26 27";
	cout << endl;
	cout << endl;
    
    /////////////////////////////////////////////////
    
	cout << "printing postorder: ";
	testTree.postOrder();
	cout << endl;
	cout <<"Answer:             17 27 26 30 36 45 41 22 82 76 74 54  ";
	cout << endl;
	
	//////////////////////////////////////////////////
	
	
	return 0;
}
