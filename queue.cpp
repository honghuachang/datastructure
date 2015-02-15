//基于固定数组的queue，当反复大量enqueue，dequeue时，会占用大量内存，
//dequeu并不会释放所占的空间：//加入队列时，head固定不动，tail往后挪；
//出队时，tail固定不动，head往后挪。
//因此链表是更好的数据存储形式

#include <iostream>

using namespace std;
#define MAX_QUEUE_SIZE 3
struct queue {
	int data[MAX_QUEUE_SIZE];
	//head 和 tail 的下标
	int head;
	int tail;
	queue() :head(0), tail(0){}
};
//加入队列时，head固定不动，tail往后挪；出队时，tail固定不动，head往后挪。
void EnQueue(queue* q, int val){
	if (q->tail == MAX_QUEUE_SIZE - 1)
		cout << "Queue's underlying storage is overflow" << endl;
	else{
		q->tail++;
		q->data[q->tail] = val;
	}
};
int DeQueue(queue* q){
	int tmp;
	if (q->head == q->tail)
		cout << "Queue is empty" << endl;
	else{
		tmp = q->data[q->head];
		q->head = q->head + 1;
	}
	return tmp;
}

int main(){
	//create a queue with 3 values
	queue* q = new queue();
	EnQueue(q, 5);
	DeQueue(q);
	cout << q->data[q->head] << endl;
	return 0;
}

//基于链表的形式