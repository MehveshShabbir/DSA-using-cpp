#include<iostream>
#include<stack>

using namespace std;

bool prcd(char op1, char op2)
{   

    if      ((op1=='(' || op1==')') &&  (op2=='(' || op2==')'))			 return false;
    else if	(op1==op2)				  return true;
    else if (op1=='(' || op2=='(')	  return false;
    else if (op1==')')				  return false;
    else if (op2==')')				  return true;
    else if (op2=='^')				  return false;
    else if ((op1=='+' || op1=='-') && (op2=='-' || op2=='+'))		return true;
    else if ((op1=='/' || op1=='*') && (op2=='/' || op2=='*'))		return true;
    else if ((op1=='*' || op1=='/') && (op2=='+' || op2 == '-'))	return true;
    else if ((op1=='+' || op1=='-') && (op2=='*' || op2 == '/'))	return false;
    else if (op1=='^')				  return true;
}

int main()
{	
    stack <char> s;				//predefined stack
    string infix, postfix=" "; char temp;
    int i=0;

    //infix="(A/(B-C)*D)";
    //infix="(a+b)*c";
    infix="((A-(B/C))*((A/K)-D))";
    
    
    while(infix[i]!='\0')			
    {	
    //------------  checks infix element is a variable -------------------------
        if ((infix[i]>='a' && infix[i]<='z') || (infix[i]>='A' && infix[i]<='Z'))
        {
            postfix+=infix[i];
            i++;
        }
	//-----------  if not ------------------------------
        else  
            {
	//-----------  until stack is not empty --> add top element to postfix string	
            	while (!s.empty() && prcd(s.top(), infix[i]))
            	{
                	postfix+=s.top();
                	s.pop();
            	}
            	
    //----------  when stack is empty OR infix element is ')' -->  add infix element to stack
            	 if(s.empty() || infix[i] != ')' )
                 {
                     s.push(infix[i]);
                 }
                 
    //----------  if not -->  remove top stack element
                 else 
                 {
                 	s.pop();
                 }
    //----------  move tpo next infix element
                 i++;
            }
	}
	
	//----------  to add remaining stack elements to postfix string
    while(!s.empty())
    {	temp=s.top();
        postfix+=temp;
        s.pop();
    }
    cout<<"Infix:\t"<<infix<<endl;
    cout<<"Postfix:"<<postfix<<endl;

}
