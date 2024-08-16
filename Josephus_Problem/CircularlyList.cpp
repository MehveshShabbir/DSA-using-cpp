#include<iostream>
#include "Node.cpp"

using namespace std;

class List
{
    private:
        Node *headNode, *current, *endNode;
        int size;

    public:

        List()
        {
            headNode=current=endNode=NULL;
            size=0;
        }

        void add(string object)
        {
            Node *newNode=new Node();

            newNode->setObject(object);
            newNode->setNext(newNode);         // we are not setting NULL as previous
            newNode->setPrevious(newNode);     // we are not setting NULL as previous

            if(headNode==NULL)
            {
                headNode=newNode;
                endNode = newNode;
            }

            else
            {   
                // this is where it becomes circular
                endNode->setNext(newNode->getNext());   // endNode's next = newNode
                newNode->setNext(headNode);             // newNode's next =headNode       
                newNode->setPrevious(endNode);          // newNode's previous= endNode
                endNode=newNode;
            }

        }

        void TraveseList()
        {
            current = headNode;
            
            cout<<"List: |";
            while(current!=NULL)
            {
                cout<<current->getObject()<<" | ";

                // checking if the next pinter of current = headNode
                // beacuse it means that we are again pointing at head
                if(current->getNext()==headNode)    break;

                current=current->getNext();

            }
            cout<<endl;
        }
};

int main(){
    List one;
    one.add("one");
    one.add("two");
    one.add("three");
    one.add("four");
    one.TraveseList();
}

/*
-------------------------------------------------
List: |one | two | three | four |
-------------------------------------------------
*/