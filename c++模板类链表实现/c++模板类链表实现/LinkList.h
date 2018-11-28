#ifndef LinkList_h
#define LinkList_h
#include<iostream>

template<class T>
struct node
{
	T data;
	node *pNext;
};

template<typename T>
class LinkList {
public:
	LinkList();
	LinkList(const LinkList<T> &list);
	LinkList<T>&operator =(const LinkList<T>&rhs);
	~LinkList();
public:
	void headAdd(const T&data);
	void rearAdd(const T&data);
	int size() const;
	bool isEmpty() const;
	void print() const;
	T getNElement(int n) const;
	void insertNElement(int n, const T&data);
	void deleteNElement(int n);
	void modifyElement(int n, const T&data);
	int find(const T&data);
	void sort();//≈≈–Ú
	void destory();//œ˙ªŸ¡¥±Ì

private:
	node<T> *header;
	int length;
};
#endif