#include<iostream>
#include<stdlib.h>
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

void preorder(TreeNode<int>* Current)               // root -> left -> right
{
    if( Current != NULL ) 
    {
        cout << *(Current->getObject())<<" -> ";
        preorder(Current->getLeft());
        preorder(Current->getRight());
    }
}

void inorder(TreeNode<int>* Current)                // left -> root -> right
{
    if( Current != NULL ) 
    {
        inorder(Current->getLeft());
        cout << *(Current->getObject())<<" -> ";
        inorder(Current->getRight());
    }
}

void postorder(TreeNode<int>* Current)               // left -> right -> root
{
    if( Current != NULL ) 
    {
        postorder(Current->getLeft());
        postorder(Current->getRight());

        cout << *Current->getObject()<<" -> ";
    }
}

TreeNode<int>* Del_Root(TreeNode<int>* current)
{   
        TreeNode<int> *next, *pre_current ;
        next = current->getLeft();
        while(next->getRight() != NULL)
        {   
            pre_current = next;
            next = next->getRight();
        }
        //cout<<"-----"<<*next->getObject();
        current->setObject(next->getObject());
        if(next->getLeft() != NULL)        pre_current->setRight(next->getLeft());
        delete next;
        return current;
}
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
void Deletion(TreeNode<int>* root, int* key)
{   
    bool flag = true;
    TreeNode<int> *current, *pre_current, *next;    // current will store key Node
                                                    // pre will store key Parent Node
    if (*root->getObject() == *key)
    {
        current = Del_Root(root);
    }               
    else
    {                                            // next will store key child Node
        current = root;
        while(*current->getObject() != *key && current != NULL)
        {
            pre_current =  current;       
            if (*key > *current->getObject())      current = current->getRight();  
            else     
                current = current->getLeft();  
            // //cout<<endl<<*current->getObject()<<endl;
        }
        if (current->getLeft() == NULL && current->getRight()== NULL)
        {
            if(*current->getObject() < *pre_current->getObject())   pre_current->setLeft(NULL);
            else if(*current->getObject() > *pre_current->getObject())   pre_current->setRight(NULL);
            delete current;
        }     
        else if(*current->getObject() < *pre_current->getObject())
        {
            if (current->getRight() != NULL) 
            {   
                next = current->getRight();
                pre_current->setLeft(next);
                while(next->getLeft() != NULL)
                {
                    next=next->getLeft();
                }
                next->setLeft(current->getLeft());
            }   
            else if(current->getLeft() != NULL)
            {
                pre_current->setLeft(current->getLeft());
            } 
            delete current;
        }

        else if(*current->getObject() > *pre_current->getObject())
        {
            if (current->getLeft() != NULL) 
            {   
                next = current->getLeft();
                pre_current->setRight(next);
                while(next->getRight() != NULL)
                {
                    next=next->getRight();
                }
                next->setRight(current->getRight());
            }   
            else if(current->getRight() != NULL)
            {
                pre_current->setRight(current->getRight());
            } 
            delete current;
        }
    }
}

int main()
{
    int x[] = {14, 15, 4, 2, 9, 7, 18, 3, 5, 16,4, 20, 17, 9, 14, 5, -1};

	TreeNode<int>* root = new TreeNode<int>();      //creating root Node
	root->setObject( &x[0] );                       //first element in array will be root
	
    for(int i=1; x[i] > 0; i++ )
	{
		Insert(root, &x[i] );                  //Insert all elements into a binary tree
	}                                          // to catch the duplicates  

    int y=4;
    cout<<"\nPre Order: ";              preorder(root);
    cout<<"\nPost Order: ";             postorder(root);
    cout<<"\nLevel Order: ";            levelOrderTraverse(root);
    cout<<"\nIn Order: ";               inorder(root);
    Deletion(root, &x[3]);
    //cout<<"root: "<<*root->getObject();
    cout<<"\nIn Order: ";               inorder(root);
       
}

/*
---------------------------------------------
Duplicate: 4
Duplicate: 9
Duplicate: 14
Duplicate: 5

Pre Order: 14 -> 4 -> 3 -> 9 -> 7 -> 5 -> 15 -> 18 -> 16 -> 17 -> 20 ->
In Order: 3 -> 4 -> 5 -> 7 -> 9 -> 14 -> 15 -> 16 -> 17 -> 18 -> 20 ->
Post Order: 3 -> 5 -> 7 -> 9 -> 4 -> 17 -> 16 -> 20 -> 18 -> 15 -> 14 ->
----------------------------------------------
*/