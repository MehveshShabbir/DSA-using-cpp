#include<iostream>
#include "Stack.cpp"   // must include Queue template file and comment its main()
#include "TreeNode.cpp"

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

void traverse(TreeNode<int>* root)          
{   
    Stack < TreeNode<int>* > s;            // Stack of TreeNode type
    TreeNode<int>* Current = root;         // starting from root  

    while( !s.IsEmpty() || Current != NULL)  // loop until Stack is empty OR Current becomes NULL
    {
        while(Current!=NULL)                // loop until reach left leaf
        {
            s.push(Current);                // Push every current to Stack               
            Current = Current->getLeft();   // move Current to left
        }

        if(!s.IsEmpty())                     
        {
            Current = s.pop();              // Move top of Stack to Current and delete it
            cout<< *(Current->getObject())<<" -> ";     // A pointer value is printed with *
            Current = Current->getRight();              // Move Current to right Node
        }
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
    
    cout<<"Non Recursive: ";             traverse(root);
}

/*
------------------------------------------------------------------------
Non Recursive: 3 -> 4 -> 5 -> 7 -> 9 -> 14 -> 15 -> 16 -> 17 -> 18 -> 20 ->
------------------------------------------------------------------------
*/