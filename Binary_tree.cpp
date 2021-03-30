#include<iostream>
#include<stack>

#define ll long long int
#define fo(i,a,n) for(ll i=a;i<=(n-1);i++)
using namespace std;

#define sp 3
class node
{
public:
	int data;
	node* left, * right;
	node()
	{
		data = 0;
		left = NULL;
		right = NULL;
	}
	node(int v)
	{
		data = v;
		left = NULL;
		right = NULL;
	}
};
class bt
{
public:
	node* root;
	bt()
	{
		root = NULL;
	}
	bool isempty();
	node* insert(node*, node*);
	void Preorder(node*);
	void Inorder(node*);
	void Postorder(node*);
	void nrecPreorder();
	void nrecInorder();
	void nrecPostorder();
};
bool bt::isempty()
{
	return(root == NULL);
}
node* bt::insert(node* r, node* n)
{
	node* ptr = r;
	if (isempty())
	{
		root = n;
		cout << "Node Inserted as ROOT NODE\n";
		return(root);
	}
	if (ptr->data == n->data)
	{
		cout << "Value already exist, same values are not allowed\n";
		return(ptr);
	}
	cout << "We are at node whose value is : " << ptr->data << "\n\nWhere would you like to insert Data , left or right of current node ? enter 'l' for left and 'r' for right\n";
	char opt;
	cin >> opt;
	if (opt == 'l')
	{
		if (ptr->left == NULL)
		{
			ptr->left = n;
			cout << "Node inserted successfully\n";
			return(ptr);
		}
		else
		{
			ptr->left = insert(ptr->left, n);
		}

	}
	else
	{
		if (ptr->right == NULL)
		{
			ptr->right = n;
			cout << "Node inserted successfully\n";
			return(ptr);
		}
		else
		{
			ptr->right = insert(ptr->right, n);
		}
	}
}
void bt::Preorder(node* n)
{
	if (isempty())
	{
		cout << "Tree is Empty\n";
		return;
	}

	else if (n == NULL)
		return;
	else
	{
		cout << n->data << " ";
		Preorder(n->left);
		Preorder(n->right);
	}
}
void bt::Inorder(node* n)
{
	if (isempty())
	{
		cout << "Tree is Empty\n";
		return;
	}

	else if (n == NULL)
		return;
	else
	{
		Inorder(n->left);
		cout << n->data << " ";
		Inorder(n->right);
	}
}
void bt::Postorder(node* n)
{
	if (isempty())
	{
		cout << "Tree is Empty\n";
		return;
	}

	else if (n == NULL)
		return;
	else
	{
		Postorder(n->left);
		Postorder(n->right);
		cout << n->data << " ";

	}
}
void bt::nrecPreorder()
{
	
	if (root == NULL)
	{
		cout << "Tree is Empty\n";
		return;
	}
	stack<node *> s;
	s.push(root);
	while (!s.empty())
	{
		node* ptr = s.top();
		s.pop();
		cout << ptr->data << " ";
		if (ptr->right != NULL)
			s.push(ptr->right);
		if (ptr->left != NULL)
			s.push(ptr->left);
	}
	cout << "\n";
	return;
}
void bt::nrecInorder()
{

	if (root == NULL)
	{
		cout << "Tree is Empty\n";
		return;
	}
	stack<node*> s;
	node* ptr = root;
	
	while (ptr != NULL || s.empty() == false)
	{
		
		while (ptr != NULL)
		{
			s.push(ptr);
			ptr = ptr->left;
		}


		ptr = s.top();
		s.pop();

		cout << ptr->data << " ";
		ptr = ptr->right;

	}
	cout << "\n";
	return;
}
void bt::nrecPostorder()
{

	if (root == NULL)
	{
		cout << "Tree is Empty\n";
		return;
	}
	stack<node*> s;
	stack<int> out;
	s.push(root);
	while (!s.empty())
	{
		node * ptr = s.top();
		s.pop();

		out.push(ptr->data);
		if (ptr->left!=NULL) 
			s.push(ptr->left);
		
		if (ptr->right!=NULL) 
			s.push(ptr->right);
		
	}
	while (!out.empty())
	{
		cout << out.top() << " ";
		out.pop();
	}
	cout << "\n";
	return;
}
int main()
{
	bt b, cp, mi;
	int c, val, ans = 0;

	do {
		cout << "ENTER : \n" << "1. Insert Node\n" << "2. Print/Traversal BST values\n";
		node* n = new node;
		int a;
		cin >> c;
		node* k;
		switch (c)
		{
		case 1:
			cout << "Enter the Value\n";
			cin >> a;
			n->data = a;
			k = b.insert(b.root, n);
			break;
		case 2:
			cout << "Traversals :-\n";
			cout << "--------------------------------------------------DFS---------------------------------------" << "\n";
			cout << "PREORDER : \n";
			cout << "Recursive : ";
			b.Preorder(b.root);
			cout << "\nNon Recursive: ";
			b.nrecPreorder();
			cout << "\nINORDER : \n";
			cout << "Recursive : ";
			b.Inorder(b.root);
			cout << "\nNon Recursive: ";
			b.nrecInorder();
			cout << "\nPOSTORDER : \n";
			cout << "Recursive : ";
			b.Postorder(b.root);
			cout << "\nNon Recursive: ";
			b.nrecPostorder();
			break;
		default:
			cout << "Invalid choice\n";
		}
		cout << "\nWould u like to continue ?\nEnter '0' to exit : ";
		cin >> ans;
	} while (ans != 0);

}
