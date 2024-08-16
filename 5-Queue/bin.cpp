#include<iostream>
#include<conio.h>
//#include<userdefined>

using namespace std;

//macros
#define queue_capacity 10       //10 --> identidies that 10 different
                                // type of values can be used
template <class userdefined>
class Node{
    private:
        userdefined object;
        Node<userdefined> *next;
    public:
        Node();
        //getters
        userdefined getObject()
        {
            return object;
        }

        Node<userdefined>* getNext()
        {
            return next;
        }

         //setters

         void setObject(userdefined object)
         {
           this->object=object;
         }

         void setNext(Node<userdefined> *next)
         {
            this->next=next;
         }
};

//build-in      //specific type of data                              
template        <class userdefined> 
class Queue
{
    private:
        Node <userdefined>* front;
        Node<userdefined>* rear;
        int size;

    public:

        Queue()
        {
            front=NULL;
            rear=NULL;
            size=0;
        }


        bool IsEmpty()
        {
            return front==NULL;
        }

        void Enqueue(userdefined object)
        {   
            Node<userdefined> *newNode=new  Node<userdefined>;
            newNode->setObject(object);
            newNode->setNext(NULL);
            
            rear->setNext(newNode);     //copy address of newNode in rear->Next
            rear=newNode;               //move rear to newNode making it last nmode  
            size++;                     //optional

            if(IsEmpty())
            {
                front=rear;
            }
        }   

        userdefined Dequeue()
        {
            if(IsEmpty())           cout<<"\nQueue underflow\n";
            else
            {
                userdefined temp;                // to copy content of front object
                temp=front->getObject();
                front=front->getNext();     //move front to next Node
                size--;                     //optional
                return temp;
            }       
        }
        userdefined Front()
        {
            return front->getObject();
        }

        userdefined Rear()
        {
            return rear->getObject();
        }

        int showSize()
        {
            return size;
        }

};

int main()
{
    Queue <string> ex_string;
    ex_string.Enqueue("one"); 
     
    ex_string.Enqueue("two");
    cout<<"Dequeue: "<<ex_string.Dequeue();
    
    Queue <int> ex_int;
    ex_int.Enqueue(1);
    ex_int.Enqueue(2);
    cout<<"Dequeue int: "<<ex_int.Dequeue();


}
