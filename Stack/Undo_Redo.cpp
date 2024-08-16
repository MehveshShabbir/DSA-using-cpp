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

void menu()
{
    cout<<"0. Exit\n1. push\n2. Undo\n3. Redo\n";
}

void display(Stack temp)
{
    while(!temp.IsEmpty())
    {
        cout<<temp.pop()<<" | ";
    }
    cout<<endl;
}

int main()
{
    Stack s, undo;
    string element;
    int choice;

    menu();

//-----------------User driven menu Label----------
    MENU:
    cout<<"Your Choice: ";
    cin>>choice;
    switch(choice)
    {
//----------------Clear previous screen------------
        case 0:
        {
          system("CLS");  
          menu();
          goto MENU;
        }

//---------------Take element from user and push it in s stack
        case 1:
        {   
            cout<<"Element: ";
            cin>>element;
            s.push(element);
            display(s);
            goto MENU;
        }

//---if s stack is not empty --> pop s element --> push it in undo stack
        case 2:
        {   
            if(!s.IsEmpty())        undo.push(s.pop());
            display(s);
            goto MENU;
        }

//---if undo stack is not empty --> pop undo element --> push it in s stack
        case 3:
        {   
            if(!undo.IsEmpty())     s.push(undo.pop());
            display(s);
            goto MENU;
        }

//--- Reinput user choice
        default:
        {
            cout<<"Invalid Choice\n";
            goto MENU;
        }
    }

}

/*
--------------------------------------------------
0. Exit
1. push
2. Undo
3. Redo
Your Choice: 1
Element: one
one |
Your Choice: 1
Element: two
two | one |
Your Choice: 1
Element: three
three | two | one |
Your Choice: 1
Element: four
four | three | two | one |
Your Choice: 2
three | two | one |
Your Choice: 2
two | one |
Your Choice: 1
Element: extra
extra | two | one |
Your Choice: 3
three | extra | two | one |
Your Choice: 3
four | three | extra | two | one |
Your Choice: 3
four | three | extra | two | one |
Your Choice: 3
four | three | extra | two | one |
Your Choice:
--------------------------------------------------
*/