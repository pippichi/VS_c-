#ifndef _QUEUE_H_
#define _QUEUE_H_
#include<cassert>

template<class T,int SIZE=50>
class Queue {
private:
	int front, rear, count;
	T list[SIZE];
public:
	Queue();
	void insert(const T&item);
	void clear();
	T remove();//Ԫ�س���
	const T &getFront() const;//��ȡ����Ԫ��
	//���Զ���״̬
	int getLength() const;
	bool isEmpty() const;
	bool isFull() const;

};

template<class T,int SIZE>
Queue<T,SIZE>::Queue():front(0),rear(0),count(0) {}

template<class T,int SIZE>
void Queue<T, SIZE>::insert(const T &item) {
	assert(count != SIZE);
	count++;
	list[rear] = item;
	rear = (rear + 1) % SIZE;//ѭ������
}

template<class T,int SIZE>
T Queue<T, SIZE>::remove() {
	assert(count != 0);
	int temp = front;//����ԭ�ȶ���Ԫ��ָ��
	count--;
	front = (front + 1) % SIZE;
	return list[temp];
}

template<class T,int SIZE>
const T &Queue<T, SIZE>::getFront() const {
	return list[front];
}

template<class T,int SIZE>
int Queue<T, SIZE>::getLength() const {
	return count;
}

template<class T,int SIZE>
bool Queue<T, SIZE>::isEmpty() const {
	return count == 0;
}

template<class T,int SIZE>
bool Queue<T, SIZE>::isFull() const {
	return count == SIZE;
}

template<class T,int SIZE>
void Queue<T, SIZE>::clear() {
	count = 0;
	front = 0;
	rear = 0;
}

#endif