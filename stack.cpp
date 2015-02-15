#include <iostream>

using namespace std;

int stack[100];
int top = -1;

// LIFO last in, first out;
// Data: array and top index
// Operations: push pop top

int main()
{
	// push
	stack[++top] = 3;

	// top
	cout << stack[top] << endl;

	// pop
	top--;
}

//可执行代码
//array based implementation
#include <iostream>

using namespace std;

int stack[100];
int top = -1;

// LIFO last in, first out;
// Data: array and top index
// Operations: push pop top

int main()
{
	// push
	stack[++top] = 3;
	stack[++top] = 5;
	stack[++top] = 7;
	int t = top;
	for (int i = 0; i < 3; i++){
		cout << stack[t--] << " ";
	}
	cout << endl;

	// top
	if (top == -1)
		cout<<"Stack is empty"<<endl;
	else 
	cout << stack[top] << endl;

	// pop
	if (top == -1)
		cout << "Stack is empty" << endl;
	else{
		top--;
		cout << stack[top] << endl;
	}

}

//linked list based stack implementation
#include <iostream>

using namespace std;

struct node{
	int val;
	node* next;
	node(int val) :val(val), next(nullptr){}
};
// LIFO last in, first out;
// Data: array and top index
// Operations: push pop top

int main()
{
	// push 相当于linkedlist的insert at first 
	node* head = new node(3);
	node* inode1 = new node(5);
	inode1->next = head;
	head = inode1;
	node* inode2=new node(7);
	inode2->next = head;
	head=inode2;

	node* prnode = head;
	while(prnode!=nullptr){
		cout << prnode->val << " ";
		prnode=prnode->next;
	}
	cout << endl;

	// top
	if (head == nullptr)
		cout<<"Stack is empty"<<endl;
	else 
	cout << head->val << endl;

	// pop
	if (head == nullptr)
		cout << "Stack is empty" << endl;
	else{
		node* popednode = head;
		head = popednode->next;
		delete popednode;
		//ouput current topmost value
		cout << head->val << endl;
	}

}
