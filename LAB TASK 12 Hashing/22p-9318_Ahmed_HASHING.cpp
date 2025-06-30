#include<iostream>
using namespace std;

class book
{
	private:
		string isbn;
		string title;
	public:
		book()
		{
			isbn="";
			title="";
		}
		book(string isbn, string title)
		{
			this->isbn=isbn;
			this->title=title;
		}
		friend class hash_table;
		friend int main();
};

class node
{
	public:
		book data;
		node *next;
		
	    node()
		{
			next=nullptr;
		}
		node(book data)
		{
			this->data=data;
			this->next=nullptr;
		}
};

class hash_table
{
	private:
		node *table;
		int table_size;
	public:
		hash_table(int size)
		{
			table_size=size;
			table=new node[table_size];
			for(int i=0; i<table_size; ++i)
			{
				table[i].next=nullptr;
			}
		}
		
		int hash_function(string isbn)
		{
			int hash=0;
			for(int i=0; i<isbn.length(); ++i)
			{
				hash=(hash*31+isbn[i])%table_size;
			}
			return hash;
		}
		
		void insert(book copy)
		{
			if(isbn_exists(copy.isbn))
			{
				cout<<"same isbn book "<<copy.isbn<<" already exists"<<endl;
	            return;
			}
	        int i=hash_function(copy.isbn);
	        node *new_node=new node(copy);
	        new_node->next=table[i].next;
	        table[i].next=new_node;
	    }
		
		void delete_book(string isbn)
		{
			int i=hash_function(isbn);
			node *curr=table[i].next;
			node *prev=&table[i];
			
			while(curr)
			{
				if(curr->data.isbn==isbn)
				{
					prev->next=curr->next;
					delete curr;
					cout<<isbn<<" deleted"<<endl;
					return;
				}
				prev=curr;
				curr=curr->next;
			}
			cout<<isbn<<"not present"<<endl;
		}
		
		book *search(string isbn)
		{
			int i=hash_function(isbn);
			node *curr=table[i].next;
			while(curr)
			{
				if(curr->data.isbn==isbn)
				{
					return &curr->data;
				}
				curr=curr->next;
			}
			cout<<isbn<<" not present"<<endl;
			return nullptr;
		}
		
		void display()
		{
			for(int i=0; i<table_size; ++i)
			{
				node *curr=table[i].next;
				cout<<"index "<<i<<": ";
				while(curr)
				{
					cout<<"isbn: "<<curr->data.isbn<<", title: "<<curr->data.title;
					curr=curr->next;
				}
				cout<<endl;
			}
		}
		
		bool isbn_exists(string isbn)
		{
			int i=hash_function(isbn);
			node *curr=table[i].next;
			while(curr)
			{
				if(curr->data.isbn==isbn)
				{
					return true;
				}
				curr=curr->next;
			}
			return false;
		}
};

int main()
{
	hash_table ht(5);
	int ch;
	string isbn, title;
	
	do
	{
		cout<<"1. insert"<<endl;
		cout<<"2. search"<<endl;
		cout<<"3. delete"<<endl;
		cout<<"4. display"<< endl;
		cout<<"5. exit"<<endl;
		cout<<"enter choice: ";
		cin>>ch;
		
		switch(ch)
		{
			case 1:
				cout<<"enter isbn: ";
				cin>>isbn;
				cout<<"enter title: ";
				cin>>title;
				ht.insert(book(isbn, title));
				break;
			
			case 2:
                cout<<"enter isbn: ";
				cin>>isbn;
				{
					book *found=ht.search(isbn);
					if(found)
					{
						cout<<"book founded: isbn: "<<found->isbn<<", title: "<<found->title<<endl;
					}
				}
				break;
            
			case 3:
				cout<<"enter isbn: ";
				cin>>isbn;
				ht.delete_book(isbn);
				break;
        
			case 4:
				ht.display();
				break;
				
			case 5:
				cout<<"exiting........."<<endl;
				break;
            
			default:
				cout<<"incorrect option selected, try again"<<endl;
				break;
		}
	}
	while(ch!=5);
	return 0;
}