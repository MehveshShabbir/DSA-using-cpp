#include<iostream>

using namespace std;

int Queue[5];
int front=0, rear=-1, elements=0, Size=5;

//--------------Checks if (number of elements in array) = (size of array)
bool IsFull()
{
    return elements == Size;
}

//-------------Checks if (number of elements in array) = 0
bool IsEmpty()
{
    return elements == 0;
}

//--------------Inserting element in the next index of rear if avaialble
void Enqueue(int value)
{   
    if(IsFull())                       cout<<"\nQueue overflow\n";
    else
    {
        //-------- Increment rear to next index
        //--------- Getting remainder to to move to the available index 
        rear = (rear+1) % Size;
        Queue[rear] = value;
        elements++;
    }
}

//-------------Removing element from front without shifting(leaving that index blaank)
//-------------Works like pop() but in FIFO order
int Dequeue()
{   
    if(IsEmpty())                       cout<<"\nQueue underflow\n";
    else
    {
        int temp =  Queue[front];        //copy element into temp variable to return it
        front = (front+1) % Size;        //moving front to next, getting remainder in case the front is at last of Queue
        elements--;                      //decrementing number of elements in array
        return temp;    
    }
}

int Front()
{   
    if(IsEmpty())           cout<<"\nQueue underflow";
    else                    return Queue[front];
}

int Rear()
{   
    if(IsEmpty())          cout<<"\nQueue ounderflow\n";
    else                   return Queue[rear];
}

void display()
{   
    cout<<"Queue: ";
    if(IsEmpty())                       cout<<"\nQueue underflow\n";
    
    else if(front<=rear)        // if front index is less than rear index
    {   
        for(int i=front; i<=rear ; i++)
        {   
            cout<<" || "<<Queue[i];
        }
        cout<<endl;  
    }
                                // if front index is greater than rear index
    else                        // if front index = 3,  rear index = 1
    {                       
        for(int i=front; i<Size; i++)   // print from front to end (index 3 to 5)
        {
            cout<<" || "<<Queue[i];
        }
        for(int i=0; i<=rear; i++)      // then print from start to rear (index 0 to 2)
        {
            cout<<" || "<<Queue[i];
        }
        cout<<endl;
    }
    
}
int showSize()
{
    return elements;
}

int main()
{   
    //display();                  //will display--> "Queue underflow"

    for(int i=0; i<Size; i++)
    {
        Enqueue(i);
    }
    display();
    Enqueue(22);                //will display --> "Queue overflow"
    display();
    cout<<"Dequeue: "<<Dequeue()<<endl;
    display();
    cout<<"Dequeue: "<<Dequeue()<<endl;
    display();
    cout<<"Length: "<<showSize()<<endl;
    Enqueue(33);
    Enqueue(44);
    display();
    Enqueue(55);
    cout<<"Length: "<<showSize()<<endl;
   
}

/*
-------------------------------------------------
Queue:  || 0 || 1 || 2 || 3 || 4

Queue overflow
Queue:  || 0 || 1 || 2 || 3 || 4
Dequeue: 0
Queue:  || 1 || 2 || 3 || 4
Dequeue: 1
Queue:  || 2 || 3 || 4
Length: 3
Queue:  || 2 || 3 || 4 || 33 || 44

Queue overflow
Length: 5
-------------------------------------------------
*/