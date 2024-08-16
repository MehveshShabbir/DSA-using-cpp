#include<iostream>
#include<conio.h>
#include<string>

//add(), head(), pop() is done at first(headNode)
//Introduce template before a class
//Replace build-in type to xyz 

using namespace std;
template <class xyz> 
class Node{
    private:
        xyz object;
        Node<xyz> *next;
    public:
        //getters
        xyz getObject()
        {
            return object;
        }

        Node<xyz> *getNext()
        {
            return next;
        }

         //setters

         void setObject(xyz object)
         {
           this->object=object;
         }

         void setNext(Node<xyz> *next)
         {
            this->next=next;
         }
};

template <class xyz>
class Stack
{
    private:
        Node<xyz> *head;        //headNode

    public:
//------------Default constructor
        Stack()
        {
            head=NULL;
        }

        bool IsEmpty()
        {
            return head == NULL;
        }

        void push(xyz object)
        {   
            Node<xyz> *newNode=new Node<xyz>();
            newNode->setObject(object);
            newNode->setNext(head);
            head = newNode;
        }

        xyz pop()
        {   
            if(IsEmpty())           cout<<"\nStack underflow";
            else
            {
                xyz temp;
                temp = head->getObject();
                head = head->getNext();
                return temp;
            }
        }

        xyz top()
        {   
            if(IsEmpty())           cout<<"\nStack underflow";
            else                    return head->getObject();
        }

};

int main()
{
    Stack <string> ex_string;           //Defining string Stack 
    ex_string.push("First");
    ex_string.push("Second");
    cout<<"Pop string: "<<ex_string.pop()<<endl;

    Stack <int> ex_int;                 // Defining int Stack
    ex_int.push(1);
    ex_int.push(2);
    cout<<"Pop int: "<<ex_int.pop()<<endl;

    Stack <float> ex_float;             // Defining float Stack
    ex_float.push(1.1);
    ex_float.push(2.2);
    cout<<"Pop float: "<<ex_float.pop()<<endl;

}

/*
---------------------------------------------
Pop string: Second
Pop int: 2
Pop float: 2.2
-----------------------------------------------
*/