#include<iostream>
using namespace std;

template <class xyz> 
class TreeNode
{
    private:
        xyz*       object;
        TreeNode*  left;
        TreeNode*  right;

    public:
        //Constructors
        TreeNode()
        {
            this->object = NULL;
            this->left = this->right = NULL; //all NULL
        }
        TreeNode(xyz* object)
        {
            this->object = object;
            this->left = this->right = NULL;
        }

        //setters
        void setObject(xyz* object)
        {
            this->object = object;
        }
        void setLeft(TreeNode* left)
        {
            this->left = left;
        }
        void setRight(TreeNode* right)
        {
            this->right = right;
        }

        //Getters
        xyz* getObject()
        {
            return this->object;
        }
        TreeNode* getLeft()
        {
            return this->left;
        }
        TreeNode* getRight()
        {
            return this->right;
        }

        //---LEAF----
        bool IsLeaf()
        {
            return (this->left==NULL && this->right==NULL);
        }

};