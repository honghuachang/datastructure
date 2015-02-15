//���ڹ̶������queue������������enqueue��dequeueʱ����ռ�ô����ڴ棬
//dequeu�������ͷ���ռ�Ŀռ䣺//�������ʱ��head�̶�������tail����Ų��
//����ʱ��tail�̶�������head����Ų��
//��������Ǹ��õ����ݴ洢��ʽ

#include <iostream>

using namespace std;
#define MAX_QUEUE_SIZE 3
struct queue {
	int data[MAX_QUEUE_SIZE];
	//head �� tail ���±�
	int head;
	int tail;
	queue() :head(0), tail(0){}
};
//�������ʱ��head�̶�������tail����Ų������ʱ��tail�̶�������head����Ų��
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

//�����������ʽ