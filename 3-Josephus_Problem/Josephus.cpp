#include<iostream>
#include "Node.cpp"

using namespace std;

class List{
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
            newNode->setNext(newNode);
            newNode->setPrevious(newNode);

            if(headNode==NULL)
            {
                headNode=newNode;
                endNode = newNode;
            }

            else
            {
                endNode->setNext(newNode->getNext());
                newNode->setNext(headNode);
                newNode->setPrevious(endNode);
                endNode=newNode;
            }

            size++;
        }

        void TraveseList()
        {
            current = headNode;
            
            cout<<"List: |";
            while(current!=NULL)
            {
                cout<<current->getObject()<<" | ";
                if(current->getNext()==headNode)    break;
                current=current->getNext();

            }
            cout<<endl;
        }

        int length()
        {
            return size;
        }

        void remove()           
        {
            Node *pre = new Node();
            
            pre=current->getPrevious();             // pre = current Previous
            pre->setNext(current->getNext());       // pre Next = current Next
            (current->getNext())->setPrevious(pre); // current Next -> Previous = pre
            next();                                 // move current to nect node
            size--;
        }

        void next()                                 // move current to next node
        {
            current=current->getNext();
        }

        void start()
        {
            current=headNode;
        }

        string get()
        {
            if(current!=NULL)   return current->getObject();
        }

};

int main(){
    List one;
    one.add("one");
    one.add("two");
    one.add("three");
    one.add("four");
    one.add("five");
    one.add("six");
    one.add("seven");
    one.add("eight");
    one.add("nine");
    one.add("ten");
    one.TraveseList();

    one.start();
    while(one.length()>1)           // until just one element is left
    {
        for(int i=1;i<=3;i++)       // Removing after count of 3
        {
            one.next();             // move current to next node 
        }
        cout<<"Removing "<<one.get()<<endl; 
        one.remove();
    }
    cout<<"Finalist: "<<one.get();
}

/*
-------------------------------------------------
List: |one | two | three | four | five | six | seven | eight | nine | ten |
Removing four
Removing eight
Removing two
Removing seven
Removing three
Removing ten
Removing nine
Removing one
Removing six
Finalist: five
-------------------------------------------------
*/