#include<iostream>
#include "Node.cpp"

using namespace std;

class List{
    private:
        Node *headNode, *current, *endNode;
        int size;

    public:

//Default Constructor
        List()
        {   
            headNode=new Node();
            headNode=current=endNode=NULL;
            size=0;
        }

//Add new node at the end of list
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
                endNode->setNext(nextNode);
                endNode=nextNode;
            }

            size++;
            current=endNode;

        }

        void addFirst(string object)
        {
            Node *nextNode=new Node();

            nextNode->setObject(object);
            nextNode->setNext(headNode);

            headNode=nextNode;

            size++;
        }

// Add new node at a specific location
        void add(string object, int index)
        {
            if(index>size)
            {
                cout<<"This index does not exist\n";
            }

            else if(index==1)       addFirst(object);
            else
            {
                current=headNode;
              
                for(int i=2 ; i<index ; i++)
                {
                    current=current->getNext();
                }

                 Node *nextNode=new Node();

                 nextNode->setObject(object);
                 nextNode->setNext(current->getNext());

                 current->setNext(nextNode);
                 current=nextNode;
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
            current=endNode;
        }

        void showLength()
        {
            cout<<"Length of List is: "<<size<<" Nodes.\n";
        }

        void printIndex(int index)
        {   
            if(index>size)
            {
                cout<<"This index does not exist\n";
            }
            else{
                current=headNode;
                
                for(int i=1 ; i<index ; i++)
                {
                    current=current->getNext();
                }

                cout<<"Node object: "<<current->getObject()<<endl;
            }
        }

        void find(string object)
        {   bool flag=true;
            current=headNode;
            for(int i=1 ; i<=size ; i++)
            {
               if(current->getObject()==object)
               {
                    cout<<"Node index: "<<i<<endl;
                    flag=false;
                    break;
               }    
               else  
               {
                    current=current->getNext();
               }   
            }
            if(flag)             cout<<"Object does not exist\n";            

        }

        void removeFirst()
        {
            headNode=headNode->getNext();
            size--;
        }

        void removeLast()
        {   
            current=headNode;
            for(int i=2  ;  i<size ; i++)
            {
                current=current->getNext();
            }

            current->setNext(NULL);
            endNode=current;
            size--;
        }
        
        void remove(string object)
        {   
            bool flag=true;
            int i=1;
            if(headNode->getObject()==object)
            {
                headNode=headNode->getNext();
                flag=false;
            }
            else
            {
                Node *preNode=new Node();
                preNode=headNode;
                current=headNode->getNext();

                while(current!=NULL)                              
                {   
                    if(current->getObject()==object)
                    {
                        preNode->setNext(current->getNext());
                        size--;
                        flag=false;
                        break;
                    }
                    i++;
                    preNode=current;
                    current=current->getNext();
                }  
             if(i==size)
                {
                    endNode=preNode;
                }

            }

            if(flag)             cout<<"Object does not exist\n";            
        }

        void remove(int index)
        {   
            if(index>size)
            {
                cout<<"This index does not exist\n";
            }
            else if(index==1)
            {
                removeFirst();
            }

            else if(index==size)
            {
                removeLast();
            }
            else 
            {
                Node *preNode=new Node();
                preNode=headNode;
                current=headNode->getNext();
                for(int i=2 ; i<index ; i++)
                {
                    preNode=current;
                    current=current->getNext();
                }

                preNode->setNext(current->getNext());
                size--;     
            }
        }

        void update(string object, int index)
        {   
            if(index>size)
            {
                cout<<"This index does not exist\n";
            }
            else 
            {
                current=headNode;
                for(int i=2; i<=index; i++)
                {
                    current= current->getNext();
                }

                current->setObject(object);
            }
        }

        void start()
        {
            printIndex(1);
        }

        void end()
        {
            printIndex(size);
        }

        void showCurrent()
        {
            cout<<"Current -> Value: "<<current->getObject()<<endl;
        }

};

int main(){

   List one;
   int choice;
    
one.add("John");
one.add("Maria");
one.add("Henry");
cout<<"\n\n------------------------------------\n";
one.TraveseList();
one.showLength();
    cout<<"\n\t1. Add at the end\n\t2.Add at first\n\t3.Add in middle";
    cout<<"\n\t4.Remove first\n\t5.Remove last\n\t6.Remove object\n\t7.Remove Index";
    cout<<"\n\t8.Update Object\n\t9.Print List\n\t10.Search object\n\t11.Print Index\n\t";
    cout<<"12.Show start\n\t13.Show end\n\t14.Length\n\t15.Show current\n\n";
    

 Main:
    cout<<"\n\tYour choice: ";
    cin>>choice;
    switch(choice)
    {
        case 1:
        {
        one.add("William");
        one.TraveseList();
        break;
        }
        case 2:
        {
            one.addFirst("Tesla");
            one.TraveseList();
            break;
        }
        case 3:
        {
            one.add("Freddy", 5);
            one.TraveseList();
            break;
        }
        case 4:
        {
            one.removeFirst();
            one.TraveseList();
            break;
        }
        case 5:
        {
            one.removeLast();
            one.TraveseList();
            break;
        }
        case 6:
        {
            one.remove("John");
            one.TraveseList();
            break;
        }
        case 7:
        {
            one.remove(2);
            one.TraveseList();
            break;
        }
        case 8:
        {
            one.update("Newton", 8);
            one.TraveseList();
            break;
        }
        case 9:
        {
            one.TraveseList();
            break;
        }
        case 10:
        {
            one.find("Newton");
            break;
        }
        case 11:
        {
            one.printIndex(4);
        }
        case 12:
        {
            one.start();
            break;
        }
        case 13:
        {
            one.end();
            break;
        }
        case 14:
        {
            one.showLength();
            break;
        }
        case 15:
        {
            one.showCurrent();
            break;
        }

    }

    goto Main;
}