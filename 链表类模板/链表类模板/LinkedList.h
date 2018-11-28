#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_
#include"Node.h"

template<class T>
class LinkedList {
private:
	Node<T> *head, *rear;
	Node<T> *prevPtr, *currPtr;
	int size;
	int position;//当前元素在表中的位置序号，由函数reset调用
	Node<T>(const T &item, Node<T> *ptrNext = NULL);
	void freeNode(Node<T>*p);
	void copy(LinkedList<T> &L);//将链表复制到当前表，假设当前表为空，被复制构造函数、operator = 调用
public:
	LinkedList();
	LinkedList(const LinkedList<T> &L);
	~LinkedList();
	LinkedList<T> & operator =(const LinkedList<T> &L);

	int getSize() const();//返回表中元素个数
	bool isEmpty()const;
	void reset(int pos = 0);//设置浮标初始位置为0
	void next;
	bool endOfList() const;//浮标是否到了结尾
	int curruentPosition()const;//返回附表当前位置

	void insertFront(const T&item);//在表头插入结点
	void insertRear(const T&item);
	void insertAt(const T&item);//在当前位置插入结点
	void insertAfter(const T&item);//在当前结点之后插入结点

	T deleteFront();//删除头结点
	void deleteCurrent();//删除当前结点

	T &data();//返回对当前结点成员数据的引用
	const T &data() const;//返回对当前结点成员数据的引用

	void clear();//清空链表：释放所有结点的内存空间，被析构函数、operator = 调用
};

template<class T>
LinkedList<T>::Node<T>(const T&item, Node<T>*ptrNext = NULL) :data(item),next(ptrNext){}
template<class T>
void LinkedList<T>::freeNode(Node<T>*p) {
	Node<T> *tempPtr;

}
#endif