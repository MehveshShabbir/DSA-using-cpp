#include<iostream>

using namespace std;

class Stack{
    private:
        string* objArray;
        int head;
        int size;
    public:
//--------- Deafault Constructor
        Stack(int length)
        {   
            size=length;                    //storing length as fixed size of array
            objArray=new string[length];    //creating array of length size
            //objArray = {0};  		       //NULL array
            head=-1;                        //no index is -1
        }

//------------- return TRUE if head reaches total size
        bool IsFull()
        {
            return head == size-1;
        }

//------------ return TRUE if head is -1(no value is pushed into array)       
        bool IsEmpty()
        {
            return head == -1;
        }

        void push(string object)
        {   
            if(IsFull())             cout<<"\nStack overflow";

            //-------increment head by 1 --> add value to the head index
            else                    objArray[++head] = object;    
        }

        string pop()
        {   
            if(IsEmpty())             cout<<"\nStack underflow";
            //-------return head value --> decrement head by 1
            //-------decrementing head will move head to previous index
            else                      return objArray[head--];  
        }

        string top()
        {   
            if(IsEmpty())             cout<<"\nStack underflow";
            //------return the value without deleting index
            else                      return objArray[head]; 
        }

};

int main()
{
    Stack s(5);
    
    s.push("one");
    s.push("two");
    s.push("three");
    s.push("four");
    s.push("five");
    // while(!s.IsEmpty())
    // {
         cout<<" | "<<s.pop();
                  cout<<" | "<<s.pop();

         cout<<" | "<<s.pop();

         cout<<" | "<<s.pop();

    // }
    s.push("six");
    cout<<s.pop();
}

/*
--------------------------------------------------
 | three | two | one
--------------------------------------------------
*/
