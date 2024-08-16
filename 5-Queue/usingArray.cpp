#include<iostream>

using namespace std;

class Queue{
    private:
        string* objArray;
        int front;
        int rear;
        int size;
        int elements;
    public:
//--------- Deafault Constructor
        Queue(int length)
        {   
            size=length;                    //storing length as fixed size of array
            objArray=new string[length];    //creating array of length size
            front=0;                        
            rear=-1;                        //if user insert a value then rear moves forwward
            size=5;
            elements=0;
        }

//------------- return TRUE if elements reaches total size
        bool IsFull()
        {
            return elements == size;
        }

//------------ return TRUE if no value is Enqueueed into array       
        bool IsEmpty()
        {
            return elements == 0;
        }

        void Enqueue(string object)
        {   
            if(IsFull())                       cout<<"\nQueue overflow\n";
            else
            {
                //-------- Increment rear to next index
                //--------- Getting remainder to to move to the available index 
                rear = (rear+1) % size;
                objArray[rear] = object;
                elements++;   
            }
        }

        string Dequeue()
        {   
            if(IsEmpty())                       cout<<"\nQueue underflow\n";
            else
            {
                string temp =  objArray[front];        //copy element into temp variable to return it
                front = (front+1) % size;        //moving front to next, getting remainder in case the front is at last of Queue
                elements--;                      //decrementing number of elements in array
                return temp;   
            }
        }
        
        string Front()
        {   
            if(IsEmpty())           cout<<"\nQueue underflow";
            else                    return objArray[front];
        }

        string Rear()
        {   
            if(IsEmpty())          cout<<"\nQueue ounderflow\n";
            else                   return objArray[rear];
        }

        void display()
        {   
            cout<<"Dequeue: ";
            if(IsEmpty())                       cout<<"Queue underflow\n";
            
            else if(front<=rear)        // if front index is less than rear index
            {   
                for(int i=front; i<=rear ; i++)
                {   
                    cout<<" || "<<objArray[i];
                }
                cout<<endl;  
            }
                                        // if front index is greater than rear index
            else                        // if front index = 3,  rear index = 1
            {                       
                for(int i=front; i<size; i++)   // print from front to end (index 3 to 5)
                {
                    cout<<" || "<<objArray[i];
                }
                for(int i=0; i<=rear; i++)      // then print from start to rear (index 0 to 2)
                {
                    cout<<" || "<<objArray[i];
                }
                cout<<endl;
            } 
        }

        int showSize()
        {
            return elements;
        }

};

int main()
{
    Queue object(5);
    object.display();                  //will display--> "Queue underflow"
    
    object.Enqueue("one");
    object.display();

    object.Enqueue("two");                
    object.display();

    cout<<"Dequeue: "<<object.Dequeue()<<endl;
    object.display();

    cout<<"Dequeue: "<<object.Dequeue()<<endl;
    object.display();

    cout<<"Length: "<<object.showSize()<<endl;
    object.Enqueue("three");
    object.Enqueue("four");
    object.display();

    object.Enqueue("five");
    cout<<"Length: "<<object.showSize()<<endl;
    object.display();
    
}

/*
-------------------------------------------------
Dequeue: Queue underflow
Dequeue:  || one
Dequeue:  || one || two
Dequeue: one
Dequeue:  || two
Dequeue: two
Dequeue: Queue underflow
Length: 0
Dequeue:  || three || four
Length: 3
Dequeue:  || three || four || five
-------------------------------------------------
*/
