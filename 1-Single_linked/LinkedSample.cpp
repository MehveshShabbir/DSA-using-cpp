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
            Node *nextNode=new Node();

            nextNode->setObject(object);
            nextNode->setNext(NULL);

            if(headNode==NULL)
            {
                headNode=nextNode;
                endNode = nextNode;
            }

            else
            {
                endNode->setNext(nextNode->getNext());
                endNode=nextNode;
            }

        }

        void TraveseList()
        {
            current = headNode;
            while(current!=NULL)
            {
                cout<<"Node data is "<<current->getObject();
                current=current->getNext();
            }
        }
};

int main(){
    List one;
    one.add("ss");
    one.add("pp");
    one.add("tt");
    one.TraveseList();
}