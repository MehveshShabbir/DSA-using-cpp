#include<iostream>

using namespace std;

class Node{
    private:
        string object;
        Node *next;
    public:
        //getters
        string getObject()
        {
            return object;
        }

        Node *getNext()
        {
            return next;
        }

         //setters

         void setObject(string object)
         {
           this->object=object;
         }

         void setNext(Node *next)
         {
            this->next=next;
         }


};
