#include <iostream>

using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int val) :val(val), next(nullptr) {}//构造函数
};
ADT: advanced datatype
data： value next
operations: insert delete traverse

int main()
{
//insert after node 'p'
	ListNode* p;
	ListNode* t = new ListNode(0);//a temp node
	t->next = p->next;//先指向同一个，再把前面的指向当前的
	p->next = t;
//delete the node after 'p'
	p->next = p->next->next;
//traverse
	while (p) {
		cout << p->val << endl;
//search
//if(p->val== )
		p = p->next;
	}
	
}

//可执行版本

#include <iostream>
using namespace std;
struct node{
	int val;
	node* next;
	node(int val) : val(val), next(nullptr){}
};
void printList(node* prnode){
	while (prnode != nullptr){
		cout << prnode->val << " ";
		prnode = prnode->next;
	}
	cout << endl;
}
int main(){

	// create a linkedlist with 3 nodes

	node* head = new node(3);
	head->next = new node(7);
	node* tail = head->next;
	node* tmp = new node(5);
	tail->next = tmp;
	tail = tmp;

	node* prnode = head;
	printList(prnode);

	//insert 
	node* inode = new node(4);
	node* pnode = head->next;
	inode->next = pnode->next;
	pnode->next = inode->next;

	node* prnode2 = head;
	printList(prnode2);

	//remove
	node* prenode = head->next;
	node* rnode = prenode->next;
	prenode->next = rnode->next;
	delete rnode;

	node* prnode3 = head;
	printList(prnode3);

	//traverse 
	node* tnode = head;
	while (tnode != nullptr){
		cout << tnode->val << " ";
		tnode = tnode->next;
	}
	cout << endl;

	return 0;
}

