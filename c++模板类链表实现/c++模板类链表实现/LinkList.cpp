#include"stdafx.h"
#include<iostream>
#include"LinkList.h"
using namespace std;

template<typename T>
LinkList<T>::LinkList() :header(NULL), length(0) {}

template<typename T>
LinkList<T>::LinkList(const LinkList<T> &list) : header(NULL), length(0) {
	int i = 1;
	while (i <= list.size()) {
		rearAdd(list.getNElement(i));
		i++;
	}
}

template<class T>
LinkList<T>&LinkList<T>::operator=(const LinkList<T>&rhs) {
	if (this == &rhs) {
		return *this;
	}
	destory();
	for (int i = 1; i <= rhs.size(); i++) {
		rearAdd(rhs.getNElement(i));
	}
	return *this;
}

template<typename T>
LinkList<T>::~LinkList() {
	destory();
}

template<typename T>
void LinkList<T>::headAdd(const T&data) {
	node<T>*pnode = new node<T>;
	pnode->data = data;
	pnode->pNext = NULL;
	if (header == NULL) {
		header = pnode;
	}
	else {
		pnode->pNext = header;
		header = pnode;
	}
	length++;
}

template<typename T>
void LinkList<T>::rearAdd(const T&data) {
	node<T>*pnode = new node<T>;
	pnode->pNext = NULL;
	pnode->data = data;
	if (header == NULL) {
		header = pnode;
	}
	else {
		node<T>*rear = header;
		while (rear->pNext != NULL) {
			rear = rear->pNext;
		}
		rear->pNext = pnode;
	}
	length++;
}

template<class T>
int LinkList<T>::size() const{
	return length;
}

template<class T>
bool LinkList<T>::isEmpty() const{
	return header == NULL;
}

template<typename T>
void LinkList<T>::print() const{
	node<T>*ptemp = header;
	int count = 0;
	while (ptemp != 0) {
		cout << ptemp->data << "\t";
		ptemp = ptemp->pNext;
		count++;
		if (count % 5 == 0) {
			cout << endl;
		}
	}
	cout << endl;
}

template<typename T>
T LinkList<T>::getNElement(int n) const {
	if (n<1 || n>length) {
		throw"获取元素位置非法";
	}
	else {
		int i = 1;
		node<T>*ptemp = header;
		while (i++ < n) {
			ptemp = ptemp->pNext;
		}
		return ptemp->data;
	}
}

template<typename T>
void LinkList<T>::insertNElement(int n, const T&data) {
	if (n<1 || n>length) {
		cout << "插入元素位置非法!" << endl;
	}
	else {
		if (n == 1) {
			node<T>*ptemp = new node<T>;
			ptemp->data = data;
			ptemp->pNext = header;
			header = ptemp;
		}
		else {
			int i = 1;
			node<T>*ptemp = header;
			while (++i < n) {
				ptemp = ptemp->pNext;
			}
			node<T>*pinsert = new node<T>;
			pinsert->data = data;
			pinsert->pNext = ptemp->pNext;
			ptemp->pNext = pinsert;
		}
		length++;
	}
	return;
}

template<typename T>
void LinkList<T>::deleteNElement(int n) {
	if (n<1 || n>length) {
		cout << "Illegal delete" << endl;
	}
	else {
		node<T>*deleteElement;
		if (n == 1) {
			deleteElement = header;
			header = header->pNext;
		}
		else {
			int i = 1;
			node<T>*ptemp = header;
			while (++i < n) {
				ptemp = ptemp->pNext;
			}
			deleteElement = ptemp->pNext;
			ptemp->pNext = deleteElement->pNext;
		}
		delete deleteElement;
		length--;
	}
	return;
}

template<typename T>
void LinkList<T>::modifyElement(int n, const T&data) {
	if (n<1 || n>length) {
		cout << "wrong!" << endl;
	}
	else {
		if (n == 1) {
			header->data = data;
		}
		else {
			node<T>*ptemp = header;
			int i = 1;
			while (i++ < n) {
				ptemp = ptemp->pNext;
			}
			ptemp->data = data;

		}
	}
	return;
}

template<class T>
int LinkList<T>::find(const T&data) {
	int i = 1,re=-1;
	node<T>*ptemp = header;
	while (!ptemp) {
		if (ptemp->data == data) {
			re = i;
		}
		i++;
		ptemp = ptemp->pNext;
	}
	return re;
}

template<typename T>
void LinkList<T>::sort() {
	if (length > 1) {
		for (int i = length; i > 0; i--) {
			for (int j = 1; j < i; j++) {
				T right = getNElement(j + 1);
				T left = getNElement(j);
				if (left > right) {
					modifyElement(j, right);
					modifyElement(j + 1, left);
				}
			}
		}
	}
	return;
}

template<typename T>
void LinkList<T>::destory() {
	while (header != NULL) {
		node<T>*ptemp = header;
		header = header->pNext;
		delete ptemp;
	}
	length = 0;
}


