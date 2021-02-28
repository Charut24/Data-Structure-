#include<stdlib.h>
#include<iostream>
using namespace std;

class Node 
{
    public:
        int data,cnt;
        Node *next;
};


class List:public Node 
{
    Node *listptr, *listptr2, *temp;
    public:
    List() 
	{
        listptr = NULL;
        temp = NULL;
    }
    void create();
    void display();
    void Insert();
    void Delete();
    void Reverse();
    void Concatenate();
    
    void Insert_at_start();
    void Insert_at_intermediate();
    void Insert_at_end();
    
    void Delete_from_start();
    void Delete_from_intermediate();
    void Delete_from_end();
    void empty();
};
// to check whther the list is empty or not
void List :: empty()
{
	if(listptr==NULL)
	{
		cout<<"\n THE LIST IS EMPTY .. CREATING A LIST....";
		cout<<"Enter no. of nodes: ";
        cin>>cnt;
        cout<<"Enter the numbers: ";
        while(cnt !=0)
        {
        	create();
		}
	}
}
void List::create()
{
    	Node *nextNode = new Node();
		cin>>nextNode -> data;
		nextNode->next = NULL;
		
		if(listptr == NULL)
    	{
            listptr = nextNode;
            temp = nextNode;
        }
        else {
            temp->next=nextNode;
            temp = nextNode;
        }
    
}

void List::display() 
{
    cout<<"\n Result: "<<endl;
    if (listptr == NULL)
        cout<<"\n List empty. ";
    else 
	{
        temp = listptr;
        while (temp->next!= NULL)
		{
            cout<<temp->data<<" -> ";
            temp = temp->next;
        }
        cout<<temp->data;
    }
}

void List :: Insert()
{
	int ichoice;
	cout<<"\n Select from following. ";
	cout<<"\n 1. Insert at start. ";
	cout<<"\n 2. Insert at intermediate. ";
	cout<<"\n 3. Insert at end. ";
	cin>>ichoice;
	switch(ichoice)
	{
		case 1:
			Insert_at_start();
			break;
			
		case 2:
			Insert_at_intermediate();
			break;
			 
	    case 3:
	    	Insert_at_end();
	    	break;
	}
}

void List :: Insert_at_start()
{
	
	int x;
	Node *newnode = new Node;
	cout<<"\n Enter value: ";
	cin>>x;
	newnode->data=x;
	newnode->next=NULL;
	newnode->next=listptr;
	listptr=newnode;
	
	display();
}

void List :: Insert_at_intermediate()
{
	empty();
	int n,x,i=0;
	temp = listptr;
	Node *newnode = new Node;
	cout<<"\n\n  Enter value to insert: ";
	cin>>x;
	newnode->data=x;
	newnode->next=NULL;
	cout<<"\n Where to insert: ";
	cin>>n;
	while(i!=(n-1))     // traversing statement
	{
		temp = temp->next;
		i++;
	}
	newnode->next= temp->next;
	temp->next=newnode;
	
	display();
}

void List :: Insert_at_end()
{
	empty();
	int x;
	Node *newnode = new Node;
	cout<<"\n\n  Enter value to insert: ";
	cin>>x;
	newnode->data=x;
	newnode->next=NULL;
	temp = listptr;
	while(temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = newnode;
	
	display();
}


void List :: Delete()
{
	if(listptr==NULL)
	cout<<"\n The list is empty and cannot delete any element.";
	else
	{
		int dchoice;
	    cout<<"\n Select from following. ";
    	cout<<"\n 1. Delete from start. ";
	    cout<<"\n 2. Delete from intermediate. ";
    	cout<<"\n 3. Delete from end. ";
    	cin>>dchoice;
    	switch(dchoice)
    	{
	    	case 1:
	    		Delete_from_start();
		    	break;
			
	    	case 2:
	    		Delete_from_intermediate();
	    		break;
			 
	        case 3:
	        	Delete_from_end();
	        	break;
	    }
	}
	
}

void List :: Delete_from_start()
{
	temp = listptr;
	listptr = temp->next;
	delete(temp);
	display();
}

void List :: Delete_from_intermediate()
{
	Node *q;
	int n,check =0;
	temp = listptr;
	cout<<"\n enter the position to delete: ";
	cin>>n;
	for(int i=1;i<n-1;i++)
	{
		temp=temp->next;
		if(temp->next ==NULL)
		{
			cout<<"the element is not present there";
			break;
	    }
	    break;
	}
	q=temp->next;
	temp->next = q->next;
	delete(q);
	
	display();
}

void List :: Delete_from_end()
{
	Node *q;
	temp = listptr;
	if(temp->next==NULL)
	{
		delete(temp);
		listptr=NULL;
        temp=NULL;				
	}
    else
	{
    	while(temp->next->next!=NULL)
	    {
	    temp=temp->next;
	    }
    q=temp->next;
    temp->next=NULL;
	delete(q);
	}	
	display();	
}

void List :: Reverse()
{
	Node *forward , *current , *back;
	forward = listptr;
	current = NULL;
	while(forward != NULL)
	{
		back = current;
		current = forward;
		forward = forward->next;
		current->next=back;
	}
	listptr = current;
	
	display();
}

void List :: Concatenate()
{
	int n;
	listptr2=NULL;
    cout<<"Enter no. of nodes of second list : ";
    cin>>n;
    cout<<"Enter the numbers: ";
    for(int i=0;i<n;i++)
    {
    	Node *newNode=new Node();
        cin>>newNode->data;
        newNode->next=NULL;    
        if(listptr2==NULL)
	    {
        listptr2=newNode;
        temp=newNode;
        }
        else 
	    {
        temp->next=newNode;
        temp=newNode;
        }
	}
	temp=listptr;
	while(temp->next!=NULL)
		temp = temp->next;
	temp->next = listptr2;
	
	display();
}

int main () 
{
    int ch, cnt;
    char c;
    List l;
    do
	{
        cout<<"\n Select from following. ";
        cout<<"\n 1. Create.";
        cout<<"\n 2. Display.";
        cout<<"\n 3. Insert. ";
        cout<<"\n 4. Delete. ";
        cout<<"\n 5. Reverse. ";
        cout<<"\n 6. Concatenate. ";
        cout<<"\n \n Enter choice: ";
        cin>>ch;
        
        switch (ch) 
		{
            case 1:
            	cout<<"\n Enter no. of nodes: ";
                cin>>cnt;
                cout<<"\n Enter the numbers: ";
                while(cnt!=0)
				{
                    l.create();
                    cnt--;
                }
				break;
				
            case 2:
                l.display();
                break;
                
            case 3:
            	l.Insert();
            	break;
			
			case 4:
				l.Delete();
				break;
				
			case 5:
			    l.Reverse();
			    break;
			    
			case 6:
			    l.Concatenate();
				break;    
			    
            default:
			    cout<<"\n WRONG CHOICE. ";    
			
        }
        cout<<"\n \n Press Y Continue."<<endl;
        cin>>c;
    } while (c == 'Y');
    
    return 0;
}
