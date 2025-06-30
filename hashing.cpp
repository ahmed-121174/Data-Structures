	#include<iostream>
	using namespace std;
	
	class Node
	{
		public:
			int data;
		    Node *next;
		    Node(int val)
			{
		        data=val;
		        next=nullptr;
		    }
	};
	
	class HashTable
	{
		private:
		    int cell_count; //no. of cells
		    int size;       //no. of elements stored in the hash table
		    float load_factor_threshold; //threshold for load factor to trigger rehashing
		    int range_start;
		    int range_end;
		    Node **table;    // Array of head nodes for each cell
	
		public:
		    
		    HashTable(int v, int start, int end, float threshold)
			{
		        cell_count=v;
		        range_start=start;
		        range_end=end;
		        load_factor_threshold=threshold;
		        size=0;
		        table=new Node*[cell_count];
		        for(int i=0; i<cell_count; i++)
				{
		            table[i]=nullptr;
		        }
		    }
		
		    int hash_function(int x)	//hash function to map values to key
			{
		        return (x%cell_count);
		    }
		
		    
			void insert_item(int x) //insert function with linear probing
	        {
	            if(x<range_start || x>range_end)
	            {
	                cout<<"Number "<<x<<" is outside the allowed range!"<<endl;
	                return;
	            }
	
	            if((float)(size+1)/cell_count>load_factor_threshold) //checking load factor and rehash if necessary
	            {
	                rehash();
	            }
	
	            int index=hash_function(x);
	
	            // Handling collision by linear probing
	            while (table[index]!=nullptr)
				{
	                index=(index + 1) % cell_count; //incrementing index and wrap around if necessary
	            }
	
	            //inserting at the beginning of the linked list at the found index
	            Node *new_node=new Node(x);
	            new_node->next=table[index];
	            table[index]=new_node;
	            size++;
	        }
		
		    
		    void rehash()	//rehashing the function to double the size of the hash table
			{
		        int new_cell_count=cell_count*2;
		        Node **new_table= new Node*[new_cell_count];
		        for(int i=0; i<new_cell_count; i++)
				{
		            new_table[i]=nullptr;
		        }
		        
		        for(int i=0; i<cell_count; i++)	//copying elements from the old table to new one
				{
		            Node *current=table[i];
		            while(current!=nullptr)
					{
		                int index=hash_function(current->data);
		                Node *temp=current->next;
		                current->next=new_table[index];
		                new_table[index]=current;
		                current=temp;
		            }
		        }
		
		        //deleting the old table and updating member variables with new values
		        delete[] table;
		        table=new_table;
		        cell_count=new_cell_count;
		    }
		
		    bool search(int key)	//searching function to find value in the hash table
			{
		        int index=hash_function(key);
		        Node *current=table[index];
		
		        while(current!=nullptr)	 //traversing linked list at the found index
				{
		            if(current->data==key)
					{
		                return true;
		            }
		            current=current->next;
		        }
		        return false;
		    }
		
		    void display()	//display function to print the hash table
			{
		        for(int i=0; i<cell_count; i++)
				{
		            cout<<i<<": ";
		            Node *current=table[i];
		            while(current!=nullptr)
					{
		                cout<<current->data<< " ";
		                current=current->next;
		            }
		            cout<<endl;
		        }
		    }
	};
	
int main()
{
    int a[]={1, 13, 22, 7, 12};
    int n=sizeof(a)/sizeof(a[0]);

    HashTable hash_table(7, 0, 99, 0.7);	//creating hash table with size 7 and range 0 to 99

    
    for (int i=0; i<n; i++)	//inserting values into the hash table
    {   
		hash_table.insert_item(a[i]);
	}
	
    cout<<"Hash Table:"<<endl;
    hash_table.display();

    //searching for elements
    cout<<"Searching for 8: "<<(hash_table.search(8)?"Found":"Not Found")<<endl;
    cout<<"Searching for 12: "<<(hash_table.search(12)?"Found":"Not Found")<<endl;
    cout<<"Searching for 20: "<<(hash_table.search(20)?"Found":"Not Found")<<endl;

    return 0;
}