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

class Queue{
    private:
        Node *front, *rear;
        int size;

    public:

        Queue()
        {
            front=rear=NULL;
            size=0;
        }

        bool IsEmpty()
        {
            return front==NULL;
        }

        void Enqueue(string object)
        {   
            Node *newNode=new Node();
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
        }   

        string Dequeue()
        {  
            if(IsEmpty())           return "Queue underflow\n";
            else
            {
                string temp;                // to copy content of front object
                temp=front->getObject();
                front=front->getNext();     //move front to next Node
                size--;                     
                return temp;
            } 
        }

        string Front()
        {
            return front->getObject();
        }

        string Rear()
        {
            return rear->getObject();
        }

        int showSize()
        {
            return size;
        }

        void display()
        {
            Node *current;
            current=front;

            cout<<"Queue: ";
            while(!current==NULL)
            {
                cout<<" -> "<<current->getObject();
                current=current->getNext();
            }
        }

};

int main()
{
    Queue example;

    cout<<"Dequeue: "<<example.Dequeue();              //Queue underflow

    example.Enqueue("one");      
    example.Enqueue("two");
    example.Enqueue("three");

    cout<<"Dequeue: "<<example.Dequeue()<<endl;   
    example.Enqueue("four");
    example.display();
    cout<<"\nSize: "<<example.showSize()<<endl;

}

/*
-------------------------------------------------
Dequeue: Queue underflow
Dequeue: one
Queue:  -> two -> three -> four
Size: 3
-------------------------------------------------
*/