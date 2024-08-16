#include<iostream>
#include<conio.h>
#include<string>

using namespace std;

template <class xyz>                //template
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

        Node<xyz>* getNext()
        {
            return next;
        }

         //setters

         void setObject(xyz object)
         {
           this->object=object;
         }

         void setNext(Node *next)
         {
            this->next=next;
         }

};
                             
template        <class xyz>             //template
class Queue
{
    private:
        Node <xyz> *front;
        Node <xyz> *rear;
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

        void Enqueue(xyz object)
        { 
            Node<xyz> *newNode=new  Node<xyz>();
            newNode->setObject(object);
            newNode->setNext(NULL);
            
            if(IsEmpty())
            {
                front=rear=newNode;
            }
            else
            {
                rear->setNext(newNode);     //copy address of newNode in rear->Next
                rear=newNode;               //move rear to newNode making it last nmode  
            }
            
            size++;                      

            if(showSize()==1)
            {
                front=rear;
            }
        }   

        xyz Dequeue()
        {
            if(IsEmpty())           cout<<"Queue underflow"<<endl;
            else
            {
                xyz temp;                // to copy content of front object
                temp=front->getObject();
                front=front->getNext();     //move front to next Node
                size--;                  
                return temp;
            }       
        }
        xyz Front()
        {
            return front->getObject();
        }

        xyz Rear()
        {
            return rear->getObject();
        }

        int showSize()
        {
            return size;
        }

        
        void display()
        {
            Node<xyz> *current;
            current=front;

            while(current!=NULL)          //until current reaches end
            {
                cout<<" -> "<<current->getObject();
                current=current->getNext();
            }  
        }

};

//int main()
// {
//     Queue <string> ex_string;           //String Queue
//     ex_string.Enqueue("one"); 
//     ex_string.Enqueue("two");
//     cout<<"Dequeue string: "<<ex_string.Dequeue()<<endl;
    
//     Queue <int> ex_int;                 // int Queue
//     ex_int.Enqueue(1);
//     ex_int.Enqueue(2);
//     cout<<"Dequeue int: "<<ex_int.Dequeue()<<endl;

// }

/*
-------------------------------------------------
Dequeue string: one
Dequeue int: 1
-------------------------------------------------
*/