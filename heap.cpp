//Heap property for min heap//priority queue

//For every node in a heap, node's value is lesser or equal, than values of the children.

#include <iostream>
using namespace std;

//#define 后面没有分号
#define MAX_HEAP_SIZE 100

struct heap{
	int data[MAX_HEAP_SIZE];
	int size;
	heap() : size(0){}
};

int getMinimum(heap* h){
	if (h->size == 0)
		cout << "heap is empty" << endl;
	return h->data[0];
}
void SiftUp(heap* h, int nIndex){
	int tmp, pIndex;
	if (nIndex != 0){
		pIndex = (nIndex - 1) / 2;
		if (h->data[pIndex]>h->data[nIndex])
			tmp = h->data[pIndex];
		h->data[pIndex] = h->data[nIndex];
		h->data[nIndex] = tmp;
		SiftUp(h, pIndex);
	}

}
void insert(heap* h, int ival){
	if (h->size == MAX_HEAP_SIZE)
		cout << "heap's underlying storage is overflow" << endl;
	else{
		h->size++;
		h->data[h->size - 1] = ival;
		SiftUp(h, h->size - 1);
	}

}
void SiftDown(heap* h, int nIndex){
	int tmp, lcIndex, rcIndex, minIndex;
	lcIndex = 2 * nIndex + 1;
	rcIndex = 2 * nIndex + 2;
	if (rcIndex >= h->size){
		if (lcIndex >= h->size)
			return;
		else minIndex = rcIndex;
	}
	else{
		if (h->data[lcIndex]>h->data[rcIndex])
			minIndex = rcIndex;
		else minIndex = lcIndex;
	}
	if (h->data[nIndex]>h->data[minIndex]){
		tmp = h->data[nIndex];
		h->data[nIndex] = h->data[minIndex];
		h->data[minIndex] = tmp;
	}

}
void removeMin(heap* h){
	if (h->size == 0)
		cout << "Heap is empty" << endl;

	else{
		h->data[0] = h->data[h->size - 1];
		h->size--;
		SiftDown(h, 0);

	}
}

int main(){
	heap* h = new heap();
	insert(h, 5);
	cout << getMinimum(h) << endl;
	removeMin(h);
	cout << h->size << endl;
}

