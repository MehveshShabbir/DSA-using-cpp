#include<iostream>

using namespace std;

class List
{
    private:
        string array[100];      //pointer indicates that it holds 
                                //address & can hold array address also
        int head, end, current;
        int size;

    public:
        List()
        {
            head = end = current = 0;
            size = 0;
        }

        void add(string value)          //add value at end
        {   
            if(IsFull())            cout<<"List underflow\n";
            else
            {
                array[current] = value;
                current++;
                end++;
                size++;
                display();  
            }
           
        }

        void add(string value, int index)       //add value at a specific index
        {   
            if(IsFull())                cout<<"List underflow\n";
            else
            {
                current = index;
                for(int j=++end; j>index; j--)
                {
                    array[j] = array [j-1];
                }

                array[current] = value;
                size++;
                display();
            }
            
        }

        bool IsEmpty()              // if List is empty
        {
            return size == 0;
        }

        bool IsFull()               // if List is full(i.e, array is full)
        {
            return size == 100;
        }
        void display()          
        {   
            if(IsEmpty())           cout<<"List underflow\n";
            else
            {
                cout<<"Array: ";
                for( int i=0; i<end; i++)       
                {
                    cout<<array[i]<<" -> ";     
                }
                cout<<endl;
            }
            
        }

        void Next()             // move current to next index
        {
            current++;
        }

        void Back()
        {
            current--;          // move current to previous index
        }

        string getHead()
        {
            return array[head];
        }

        string getEnd()
        {
            return array[end];
        }

        void Remove(int index)
        {
            for(int current=index; current<end; current++)
            {
                array[current] = array[current+1];          // move each index back
            }
            end--;
            size--;
            display();
        }

        void search(string value)
        {   
            bool flag = true;                           // to check if the value is found
            for(int current=0; current<end; current++)
            {   
                if(value == array[current])
                {
                    cout<<value<<" is found on index "<<current<<endl;
                    flag=false;
                    break;
                }
            }

            if(flag)            cout<<"Item not found\n";
        }

        void Delete(string value)
        {
            for(int current=0; current<end; current++)
            {
                if(value == array[current])
                {
                    Remove(current);
                    break;
                }
            }
        }

        void update(string value, int index)
        {   
            current=index;              // move current ot index
            array[current] = value;     // overwrite value at cuurent index
            display();
        }
};

int main()
{
   List example;
   example.add("One");            
   example.add("Two");
   example.add("Half", 1);

   example.search("three");
   example.Delete("One");
   example.Remove(0);

}

/*
---------------------< O U T P U T >-----------------------
Array: One ->
Array: One -> Two ->
Array: One -> Half -> Two ->
Item not found
Array: Half -> Two ->
Array: Two ->
-----------------------------------------------------------
*/