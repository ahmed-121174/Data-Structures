#include<iostream>
#include<string>
using namespace std;

class list
{
    private:
        int *arr;
        int capacity;
        int size;
        int *curr;
    
    public:
        list(int size)
        {
            arr=new int[size];
            capacity=size;
            this->size=0;
            curr=NULL;
        }
        ~list()
        {
            delete []arr;
        }
        
        void start()
        {
            curr=arr;
        }
        void next()
        {
            if(curr<arr+size-1)
                curr++;
        }
        void back()
        {
            if(curr>arr) 
                curr--;
        }
        void tail()
        {
            curr= arr+size-1;
        }
        
        void insert(int val, int pos)
        {
            if(size==capacity)
            {
                cout<<"List is full, cannot insert...."<<endl;
                return;
            }
            
            if(pos<1 || pos > size+1)
            {
                cout<<"Invalid position...."<<endl;
                return;
            }
            
            for(int *i=arr+size; i>=arr+pos; i--)
            {
                *(i)= *(i-1);
            }
            *(arr+pos-1)=val;
            size++;
        }
        
        void remove(int pos)
        {
            if(size==0)
            {
                cout<<"List is empty...."<<endl;
                return;
            }
            if(pos<1 || pos>size)
            {
                cout<<"Invalid position..."<<endl;
                return;
            }
            
            for(int *i=arr+pos-1; i<arr+size-1; i++)
            {
                *i= *(i+1);
            }
            size--;
        }
        
        int get(int pos)
        {
            if(size==0)
            {
                cout<<"Array is empty..."<<endl;
                return 0;
            }
            if(pos<1 || pos>size)
            {
                cout<<"Invalid Index..."<<endl;
                return 0;
            }
            return *(arr+pos-1);
        }
        
        void update(int val, int pos)
        {
            if(size==0)
            {
                cout<<"List is empty." << endl;
                return;
            }
            if(pos<1 || pos>size)
            {
                cout<<"Invalid position...."<<endl;
                return;
            }
            *(arr+pos-1)=val;
        }
        
        void copy(list &List)
        {
            for(int i=0; i<List.size && i<capacity; i++)
            {
                *(arr+i)= *(List.arr+i);
            }
            size=List.size;
            cout<<"List is copied"<<endl;
        }
		
		void clear()
		{
			size = 0;
			curr=NULL;
			cout<<"List cleared!"<<endl;
		}
        
        bool find(int val)
        {
            for(int *i=arr; i<arr+size; i++)
            {
                if(*i==val)
                {
                    cout<<"Element Found!"<<endl;
                    return true;
                }
            }
            cout<<"Element Not Found!"<<endl;
            return false;
        }
        
        int length()
        {
            return size;
        }
        
        void display()
        {
            cout<<"Array: "<<endl;
            for(int *i=arr; i<arr+size; i++)
            {
                cout<< *i <<" ";
            }
            cout<<endl;
        }
};

int main()
{
    int size;
    cout<<"Enter the size of the list: ";
    cin>>size;

    list List(size);
    
    int choice;
    do
	{
        cout<<"\nMenu:\n";
        cout<<"1. Insert element\n";
        cout<<"2. Remove element\n";
        cout<<"3. Get element\n";
        cout<<"4. Update element\n";
        cout<<"5. Copy list\n";
        cout<<"6. Clear list\n";
        cout<<"7. Find element\n";
        cout<<"8. Length of list\n";
        cout<<"0. Exit\n";
        cout<<"Enter your choice: ";
        cin>>choice;

        switch(choice)
		{
            case 1:
			{
                int val, pos;
                cout<<"Enter value to insert: ";
                cin>>val;
                cout<<"Enter position to insert: ";
                cin>>pos;
                
                List.insert(val, pos);
                List.display();
                break;
            }
            case 2:
			{
                int pos;
                cout<<"Enter position to remove: ";
                cin>>pos;
                
                List.remove(pos);
                List.display();
                break;
            }
            case 3:
			{
                int pos;
                cout<<"Enter position to get element from: ";
                cin>>pos;
                cout<<"Element at position "<<pos<<" is: "<<List.get(pos)<<endl;
                List.display();
                break;
            }
            case 4:
			{
                int val, pos;
                cout<<"Enter value to update: ";
                cin>>val;
                cout<<"Enter position to update: ";
                cin>>pos;
                List.update(val, pos);
                List.display();
                break;
            }
            case 5:
			{
                list CopyList(size);
                CopyList.copy(List);
                CopyList.display();
                break;
            }
            case 6:
			{
                List.clear();
                List.display();
                break;
            }
            case 7:
			{
                int val;
                cout<<"Enter value to find: ";
                cin>>val;
                List.find(val);
                List.display();
                break;
            }
            case 8:
			{
                cout<<"Length of list is: "<<List.length()<<endl;
                List.display();
                break;
            }
            case 0:
                cout<<"Exiting...";
                break;
            default:
                cout<<"Invalid choice. Please enter again."<<endl;
        }
    }
	while(choice!=0);
    return 0;
}