#include<iostream>
#include"Node.cpp"

using namespace std;

class List{
    private: 
        Node *headNode, *endNode, *current; 
        int size;
    public:
//Deafualt Constructor
        List()
        {
            headNode=new Node();
            headNode=current=endNode=NULL;
            size=0;
        }
//-------------add
        void add(string object)
        {
            Node *newNode= new Node();
            
            newNode->setObject(object);
            newNode->setNext(NULL);

            if(headNode==NULL)
            {   
                newNode->setPrevious(NULL);
                headNode=newNode;
                endNode=newNode;
            }

            else
            {   
                endNode->setNext(newNode);
                newNode->setPrevious(endNode);
                endNode=newNode;
            }
            
            size++;
            current=endNode;
        }

        void MoveCurrent(int index)
        {
            
            current = headNode;
            for(int i=2; i<index; i ++)
            {
                current=current->getNext();
            }
        }

        void add(string object, int index)
        {
            if(index>size)
            {
                cout<<"This index does not exist\n";
            }
            else
            {   
                MoveCurrent(index);

                Node *newNode = new Node;

                newNode->setObject(object);
                newNode->setNext(current->getNext());
                newNode->setPrevious(current);
                current->setNext(newNode);
                current=newNode;
                size++;
            }
           
        }

        void TraveseList()
        {
            current = headNode;
            cout<<"List : | ";
            while(current!=NULL)
            {   
                cout<<current->getObject()<<" | ";
                current=current->getNext();
            }

            cout<<endl;
        }

        void showSize()
        {
            cout<<"\nLength: "<<size<<endl;
        }

        void showCurrent()
        {
            cout<<"Current -> Value: "<<current->getObject()<<endl;
        }

};

int main(){
    List one;
    one.add("a");
    one.add("b"); 
    one.add("c");
    one.add("d");
    one.TraveseList();

    one.add("three",2);
    one.showCurrent();
    one.TraveseList();
    one.showSize();
  
}

/*
----------------------------------------------------
List : | a | b | c | d |
Current -> Value: three
List : | a | three | b | c | d |

Length: 5
----------------------------------------------------
*/