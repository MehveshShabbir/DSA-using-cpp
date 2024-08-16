#include<iostream>

using namespace std;

class Node{
    private:
        string object;
        Node *next;
        Node *previous;
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

        Node *getPrevious()
        {
            return previous;
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

         void setPrevious(Node *previous)
         {
            this->previous=previous;
         }


};
