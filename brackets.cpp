#include<iostream>
using namespace std;

class node
{
	public:
    	char info;
    	node *next;

    	node(char info)
		{
        	this->info=info;
        	next=nullptr;
    	}
};

class Stack
{
	private:
	    node *top;

	public:
	    Stack()
		{
        	top=nullptr;
    	}	

    	void push(char val)
		{
        	node *new_node=new node(val);
        	new_node->next=top;
        	top=new_node;
    	}

    	char pop()
		{
        	if(empty())
			{
				cout<<"stack is empty: stack underflow"<<endl;
				return -1;
        	}
        	
			node* temp=top;
        	char value=temp->info;
        	top=top->next;
        	delete temp;
        	return value;
    	}

    	char peek()
		{
       		if(empty())
			{
            	cout<<"stack is empty: stack underflow"<<endl;
				return -1;
        	}
        	return top->info;
    	}

    	bool empty()
		{
        	return top==nullptr;
    	}
};

bool valid(string s)
{
    Stack stack;

    for(int i=0; i<s.length(); i++)
	{
        char c=s[i];
        if(c=='('||c=='['||c=='{')
		{
            stack.push(c);
        }
		else
		{
            if(stack.empty())
			{
                return false;
            }
            
            char top=stack.peek();
            if((c==')'&& top=='(')||(c==']'&&top=='[')||(c=='}'&&top=='{'))
			{
                stack.pop();
            }
			else
			{
                return false;
            }
        }
    }
    return stack.empty();
}

int main()
{
    string s;
    cout<<"Enter a string containing only '(', ')', '{', '}', '[' and ']': ";
    cin>>s;

    if(valid(s))
	{
        cout<<endl<<"Output: true"<<endl;
    }
	else
	{
        cout<<endl<<"Output: false"<<endl;
    }
    return 0;
}