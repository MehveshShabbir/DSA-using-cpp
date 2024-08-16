#include<iostream>
#include "TreeNode.cpp"
#include "Queue.cpp"       // must include Queue template file and comment its main()

using namespace std;

template <class xyz>
//Insert will start checking from root and place the object where it sets 
void Insert(TreeNode<xyz>* root, xyz* object)       
{   
    //----------Creating 
    TreeNode<xyz>* newNode = new TreeNode<xyz>();
    newNode->setObject(object);
    newNode->setLeft(NULL);
    newNode->setRight(NULL);

    //--The above four steps can be done in a single step using argument constructor
    //--TreeNode<xyz>* newNode = new TreeNode<xyz>(object);

    TreeNode<xyz> *pre_current, *current;
    pre_current = current = root;           //Initializing with root

    // object != pre_current's object && in case during current reaches to Left/ Right of leaf
    while( *object != *(pre_current->getObject()) && current != NULL )
    {
        pre_current = current;                           // move pre_current to current
        
        if( *object < *(pre_current->getObject()) )      // if object < pre_current's object
            current = pre_current->getLeft();            // current = Left of pre_current
        
        else                                             // if object > pre_current's object
            current = pre_current->getRight();           // current = Right of pre_current
    }

    if( *object == *(pre_current->getObject()))          // if object = pre_current's object
    {
        cout << "Duplicate: "<< *object << endl;        
        delete newNode;                                  // delete newNode as it is useless
    }

    else if( *object < *(pre_current->getObject()))      // if object < pre_current's object
        pre_current->setLeft( newNode );                 // Left of pre_current (current) = newNode
    
    else                                                 // if object > pre_current's object
        pre_current->setRight( newNode );                // Right of pre_current (current) = newNode
} 

// Every time the loop executes it will move the queue front in current
// Enqueue its left and right if not NULL

void levelOrderTraverse(TreeNode<int>* Current)
{   
    Queue <TreeNode<int>* > q;          // Queue of TreeNode type
    q.Enqueue(Current);

    while(!q.IsEmpty())              
    {
        Current = q.Dequeue();               // dequeue front element and print   
        cout<<*Current->getObject()<<" || ";

        // Enqueue current's left to rear if not empty
        if(Current->getLeft() != NULL)      q.Enqueue(Current->getLeft());

        //Enqueue current's right to rear if not empty
        if(Current->getRight() != NULL)     q.Enqueue(Current->getRight());
    }
}

int main()
{
    int x[] = {14, 15, 4, 9, 7, 18, 3, 5, 16,4, 20, 17, 9, 14, 5, -1};

	TreeNode<int>* root = new TreeNode<int>();      //creating root Node
	root->setObject( &x[0] );                       //first element in array will be root
	
    for(int i=1; x[i] > 0; i++ )
	{
		Insert(root, &x[i] );                  //Insert all elements into a binary tree
	}                                          // to catch the duplicates  
    
    cout<<"Level Order: ";               levelOrderTraverse(root);         
}

/*
------------------------------------------------------------
Level Order: 14 || 4 || 15 || 3 || 9 || 18 || 7 || 16 || 20 || 5 || 17 ||
------------------------------------------------------------
*/