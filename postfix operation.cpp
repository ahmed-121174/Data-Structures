#include<iostream>
#include<string>
using namespace std;

class node
{
	public:
		int info;
		node *next;
		node(int info)
		{
			this->info=info;
			next=nullptr;
		}
};

class stack
{
	private:
		node *top;
	public:
		stack()
		{
			top=nullptr;
		}
		
		bool empty()
		{
			if(top==nullptr)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		
		void push(int info)
		{
			node *newnode=new node(info);
			if(empty())
			{
				top=newnode;	
			}
			else
			{
				newnode->next=top;
				top=newnode;
			}
		}
		
		int pop()
		{
			if(empty())
			{
				cout<<"stack is empty: stack underflow"<<endl;
				return -1;
			}
			node *temp=top;
			top=top->next;
			int val=temp->info;
			delete temp;
			return val;
		}
		
		int peek()
		{
			if(empty())
			{
				cout<<"empty!"<<endl;
				return -1;
			}
			return top->info;
		}
};

int postfix(string x)
{
    stack stak;
    for(int i=0; i<x.length(); i++)
	{
        if(x[i]>='0'&&x[i]<='9')
        {
        	stak.push(x[i]-'0');
		}
        else
		{
            int second_no=stak.pop();
            int first_no=stak.pop();
            switch (x[i])
			{
                case '+':
                    stak.push(first_no+second_no);
                    break;
                case '-':
                    stak.push(first_no-second_no);
                    break;
                case '*':
                    stak.push(first_no*second_no);
                    break;
                case '/':
                    stak.push(first_no/second_no);
                    break;
                case '%':
                    stak.push(first_no%second_no);
                    break;
            }
        }
    }
    return stak.peek();
}

int main()
{
    string val;
    cout<<"Enter values to be calculated in postfix order: ";
    cin>>val;
    cout<<"Result " << val << " is " << postfix(val);
    return 0;
}