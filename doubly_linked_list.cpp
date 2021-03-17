#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;

class node
{
	public:
		int data;
		node *next, *prev;
};

class list : public node
{
	public:
		node *head,*temp; 
		list()
		{
			head=NULL;
			temp=NULL;
		}
		void cre();
		void ins();
		void del();
		void disp();
		void con();
		void rev();
};

void list::cre()
{
	int x,n;
	cout<<"\nENTER NUMBER OF NODES:";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		node *newnode=new node;
		cout<<"\nENTER DATA FOR "<<i+1<<" NODE:";
		cin>>x;
		newnode->data=x;
		newnode->next=NULL;
		newnode->prev=NULL;
		if(head==NULL)
		{
			head=newnode;
			temp=newnode;
		} 
		else
		{
			temp->next=newnode;
			newnode->prev=temp;
			temp=temp->next;
		}
	}
}

void list::disp() //done
{
	temp=head;
	cout<<"\n\nLINKED LIST:\n";
	cout<<"NULL -> ";
	while(temp!=NULL)
	{
		cout<<temp->data;
		cout<<" -> ";
		temp=temp->next;
	}
	cout<<"NULL";
}

void list::ins() //done
{
	int opt;
	cout<<"\nINSERT:\n1.AT BEGINNING\n2.AT END\n3.AT INTERMEDIATE POSITION\n";
	cin>>opt;
	switch(opt)
	{
		case 1: 
		{
			int x;
	        node *newnode=new node;
	        cout<<"\nENTER DATA:";
	        cin>>x;
	        cout<<"\nDATA INSERTED AT BEGINNING.";
			newnode->data=x;
			newnode->prev=NULL;
			newnode->next=NULL;
			newnode->next=head;
			head->prev=newnode;
			head=newnode;
			disp();
			
			break;	
		}
		case 2: 
		{
			int x;
	        node *newnode=new node;
	        cout<<"\nENTER DATA:";
	        cin>>x;
	        cout<<"\nDATA INSERTED AT END.";
			newnode->data=x;
			newnode->next=NULL;
			temp=head;
			while(temp->next!=NULL)
			{
				temp=temp->next;
			}
			temp->next=newnode;	
			newnode->prev=temp;	
			disp();
			
			break;
		
		}
		case 3: 
		{
			int x,pos,i;
			temp=head;
	        node *newnode=new node;
	        cout<<"\nENTER DATA:";
	        cin>>x;
			newnode->data=x;
			newnode->prev=NULL;
			newnode->next=NULL;
			cout<<"\nWHERE TO INSERT DATA? (nodes starting from 0):";
			cin>>pos;
			i=0;
			while(i!=pos-1)
			{
				temp=temp->next;
				i++;				
			}
			newnode->next=temp->next;
			temp->next=newnode;
			newnode->prev=temp;
			newnode->next->prev=newnode;
			cout<<"\nDATA INSERTED AT POSITION:"<<pos;
			
			disp();
			break;
		}
		default:
		{
			cout<<"\nWRONG CHOICE!";
		}	
	}
}

void list::del() //done
{
	int opt;
	cout<<"\nDELETE:\n1.FROM BEGINNING\n2.FROM END\n3.FROM INTERMEDIATE POSITION\n";
	cin>>opt;
	switch(opt)
	{
		case 1: 
		{
		    temp=head;
			head=temp->next;
			head->prev=NULL;
	        delete(temp);
	        cout<<"\nDATA DELETED FROM BEGINNING.";
	        
	        disp();
	        break;
	        
		}
		case 2:
		{
			temp=head;
			while(temp->next->next!=NULL)
			{
				temp=temp->next;
			}
			delete(temp->next); 
			temp->next=NULL;
			cout<<"\nDATA DELETED FROM END.";
			
	        disp();
			break;
		}
		case 3:
		{
			int pos,i=0;
			temp=head; //temp traverses and stands on one position before the user entered position
			cout<<"\nWHERE TO DELETE DATA FROM? (nodes starting from 0):";
			cin>>pos; 
			for(i=0;i<pos;i++) 
			{
				temp=temp->next;
			}
			temp->prev->next=temp->next;
			temp->next->prev=temp->prev;
			delete(temp);
			cout<<"\nDATA DELETED FROM POSITION:"<<pos;
			
			disp();
			break;
			
		}	
    }
}

void list::rev() 
{
	temp=head;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	cout<<"\nDATA REVERSED.";
	cout<<"\nNULL -> ";
	cout<<temp->data<<" -> ";
	while(temp->prev!=NULL)
	{
		temp=temp->prev;
		cout<<temp->data;
		cout<<"->";
    }
    cout<<"NULL";
    
    disp();
}

void list::con()
{
	int x,n;
	cout<<"\nENTER NUMBER OF NODES:";
	cin>>n;
	node *head2,*temp2;
	head2=NULL;
	temp2=NULL;
	for(int i=0;i<n;i++)
	{
		node *newnode=new node;
		cout<<"\nENTER DATA FOR "<<i+1<<" NODE:";
		cin>>x;
		newnode->data=x;
		newnode->next=NULL;
		newnode->prev=NULL;
		if(head2==NULL)
		{
			head2=newnode;
			temp2=newnode;
		} 
		else
		{
			temp2->next=newnode;
			newnode->prev=temp2;
			temp2=temp2->next;
		}
	}
	temp2=head2;
	cout<<"\n\nSECOND LINKED LIST:\n";
	cout<<"NULL -> ";
	while(temp2!=NULL)
	{
		cout<<temp2->data;
		cout<<" -> ";
		temp2=temp2->next;
	}
	cout<<"NULL";
	temp=head;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->next=head2;
	cout<<"\n\nCONCATENATED.";
	disp();	
}

int main()
{
	int d,option;
	list l;
	do
	{
		cout<<"\n____________________________________DOUBLY LINKED LIST OPERATIONS____________________________________\n\n";
		cout<<"\nCHOOSE YOUR DESIRED OPERATION:\n1.CREATE\n2.INSERT\n3.DELETE\n4.REVERSE\n5.CONCATENATION\n6.DISPLAY\n";
		cin>>option;
		switch(option)
		{
			case 1:
				l.cre();
				break;
			case 2:
				l.ins();
				break;
			case 3:
				l.del();
				break;
			case 4:
				l.rev();
				break;
			case 5:
				l.con();
				break;
			case 6:
				l.disp();
				break;
			default:
				cout<<"\nWRONG CHOICE!";	
		}
		cout<<"\n\nWOULD YOU LIKE TO:\n1.CHOOSE ANOTHER OPERATION\n2.LEAVE\n";
		cin>>d;
	}
	while(d==1);
	return 0;
}
