#include<iostream>

using namespace std;

string Stack[100];
int head = -1, Size = 100;

bool IsFull()
{
    return head == Size-1;
}

bool IsEmpty()
{
    return head == -1;
}

void push( string value)
{
    if( IsFull())           cout<<"Stack overflow\n";
    else                    Stack[++head] = value;
}

string pop()
{
    if(IsEmpty())           cout<<"Stack underflow\n";
    else                    return Stack[head--];
}

string top()
{
    if(IsEmpty())           cout<<"Stack underflow\n";
    else                    return Stack[head];
}

int main()
{
    push("1st");
    push("2nd");
    push("3rd");
    pop();
    push("fourth");

    while(!IsEmpty())
    {
        cout<<" | "<<pop();
    }

}

/*
--------------------------------------------------
 | fourth | 2nd | 1st
--------------------------------------------------
*/