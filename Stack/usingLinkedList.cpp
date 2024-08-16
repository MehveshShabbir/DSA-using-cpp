#include<iostream>
#include"Node.cpp"

//add(), head(), pop() is done at first(headNode)

using namespace std;

class Stack
{
    private:
        Node *head;        //headNode

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

        void push(string object)
        {   
            Node *newNode=new Node();
            newNode->setObject(object);
            newNode->setNext(head);
            head = newNode;
        }

        string pop()
        {   
            if(IsEmpty())           cout<<"\nStack underflow";
            else
            {
                string temp;
                temp = head->getObject();
                head = head->getNext();
                return temp;
            }
        }

        string top()
        {   
            if(IsEmpty())           cout<<"\nStack underflow";
            else                    return head->getObject();
        }

};

int main()
{
    Stack s;
    
    s.push("First");
    s.push("Second");
    s.push("Third");
    s.pop();                                // removing & returning third
    cout<<"Top: "<<s.top()<<endl;           // returning two
    s.push("Fourth");

    while(!s.IsEmpty())
    {
        cout<<" | "<<s.pop();
    }

}

/*
--------------------------------------------------
Top: Second
 | Fourth | Second | First
--------------------------------------------------
*/