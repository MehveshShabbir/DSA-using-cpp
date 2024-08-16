#include<iostream>
#include<stack>

using namespace std;

int main()
{   
    string postfix="ABC/-AK/D-*";
    stack <string> s;
    for(int i=0; i< postfix.length(); i++)
    {
        if ((postfix[i]>='a' && postfix[i]<='z') || (postfix[i]>='A' && postfix[i]<='Z'))
        {   
            string temp;                
            temp=postfix[i];            
            s.push(temp);           // push temp in stack
        }
        else
        {
            string temp1=s.top();
            s.pop();                // store top string in temp1 and pop it
            string temp2=s.top();
            s.pop();                // store next top string in temp2 and pop it
        
            s.push('(' + temp2 + postfix[i] + temp1 + ')');    // add both strings with operator enclosed in bracket    
        }
    }
        cout<<"Postfix: "<<postfix<<endl;
        cout<<"Infix: "<<s.top();           // print the result

}

/*
--------------------------------------------------
Postfix: ABC/-AK/D-*
Infix: ((A-(B/C))*((A/K)-D))
--------------------------------------------------
*/