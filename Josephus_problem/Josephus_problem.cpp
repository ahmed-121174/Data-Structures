#include<iostream>
#include<string>
using namespace std;
class Node{
	private:
    string name;
    Node *next;
    Node *prev;
    public:
    Node(string name){
    	this->name=name;
    	next=NULL;
    	prev=NULL;
	}
	friend class JosephusProblem;
};
class JosephusProblem{
	private:
	    Node* head;
	public:
	    JosephusProblem(){
	    	head=NULL;
		}
	    void addPerson(string name){
	        Node *newNode=new Node(name);
	        if(head==NULL){
	            head=newNode;
	            head->next=head;
	            head->prev=head;
	        }
			else{
	            newNode->next=head;
	            newNode->prev=head->prev;
	            head->prev->next=newNode;
	            head->prev=newNode;
	        }
	        cout<<"Person "<<name<<" added to the circle."<<endl;
	        display();
	    }
	    void eliminate(string startPerson,int jump,int direction)
		{
	        Node* temp=head;
	        if(head==NULL||head->next==NULL)
		    {
		        cout<<"No persons to eliminate."<<endl;
		        return;
		    }
	        while(temp->name!=startPerson)
			{
	            temp=temp->next;
	        }
	        cout<<"Elimination sequence:"<<endl;
	        while(temp->next!=temp)
			{
	            for(int i=0;i<jump;i++)
				{
	                if(direction==1)
					{
	                    temp=temp->next;
	                } 
					else{
	                    temp=temp->prev;
	                }
	            }
	            Node* eliminatedPerson=temp;
	            temp->prev->next=temp->next;
	            temp->next->prev=temp->prev;
	            temp=(direction==1)?temp->next:temp->prev;
	            cout<<"Eliminate person "<<eliminatedPerson->name<<endl;
	            delete eliminatedPerson;
	        }
	        cout<<"The survivor is: "<<temp->name<<endl;
	        delete temp;
	    }
	    void display(){
	        if(head==NULL){
	            cout<<"List is Empty"<<endl;
	        } 
			else
			{
	            cout<<"Current persons in the circle: ";
	            Node* temp=head;
	            do {
	                cout<<temp->name<<", ";
	                temp=temp->next;
	            } while(temp!=head);
	            cout<<endl;
	        }
	    }
	    void menu(){
	    	
		}
};
int main() {
    JosephusProblem jp;
    cout<<"--- Josephus Problem Simulator ---" << endl;
    int choice;
    do{
        cout<<"1. Add Person\n2. Start Elimination Process\n3. Exit\nEnter your choice: ";
        cin>>choice;
        switch(choice){
            case 1:{
                string name;
                cout<<"Enter the name for the person: ";
                cin>> name;
                jp.addPerson(name);
                break;
            }
            case 2: {
            	string startingPoint;
                int jump, direction;
                cout<<"Enter the starting point: ";
                cin>>startingPoint;
                cout<<"Enter the jump value: ";
                cin>>jump;
                cout<<"Choose the direction (1. Clockwise / 2. Anticlockwise): ";
                cin>>direction;
                jp.eliminate(startingPoint,jump,direction);
                break;
            }
            case 3:
                cout<<"Exit......"<<endl;
                break;
            default:
                cout<<"Invalid choice. Please try again." << endl;
        }
    } while (choice!=3);
    return 0;
}

