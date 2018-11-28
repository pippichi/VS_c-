#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_
#include"Node.h"

template<class T>
class LinkedList {
private:
	Node<T> *head, *rear;
	Node<T> *prevPtr, *currPtr;
	int size;
	int position;//��ǰԪ���ڱ��е�λ����ţ��ɺ���reset����
	Node<T>(const T &item, Node<T> *ptrNext = NULL);
	void freeNode(Node<T>*p);
	void copy(LinkedList<T> &L);//�������Ƶ���ǰ�����赱ǰ��Ϊ�գ������ƹ��캯����operator = ����
public:
	LinkedList();
	LinkedList(const LinkedList<T> &L);
	~LinkedList();
	LinkedList<T> & operator =(const LinkedList<T> &L);

	int getSize() const();//���ر���Ԫ�ظ���
	bool isEmpty()const;
	void reset(int pos = 0);//���ø����ʼλ��Ϊ0
	void next;
	bool endOfList() const;//�����Ƿ��˽�β
	int curruentPosition()const;//���ظ���ǰλ��

	void insertFront(const T&item);//�ڱ�ͷ������
	void insertRear(const T&item);
	void insertAt(const T&item);//�ڵ�ǰλ�ò�����
	void insertAfter(const T&item);//�ڵ�ǰ���֮�������

	T deleteFront();//ɾ��ͷ���
	void deleteCurrent();//ɾ����ǰ���

	T &data();//���ضԵ�ǰ����Ա���ݵ�����
	const T &data() const;//���ضԵ�ǰ����Ա���ݵ�����

	void clear();//��������ͷ����н����ڴ�ռ䣬������������operator = ����
};

template<class T>
LinkedList<T>::Node<T>(const T&item, Node<T>*ptrNext = NULL) :data(item),next(ptrNext){}
template<class T>
void LinkedList<T>::freeNode(Node<T>*p) {
	Node<T> *tempPtr;

}
#endif