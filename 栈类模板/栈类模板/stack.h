#ifndef _STACK_H_
#define _STACK_H_
#include<cassert>
template<class T,int SIZE=50>
class Stack {
private:
	T list[SIZE];
	int top;
public:
	Stack();
	void push(const T&item);
	T pop();
	void clear();
	const T&peek() const;
	bool isEmpty() const;
	bool isFull() const;
};
template<class T,int SIZE>
Stack<T, SIZE>::Stack() :top(-1) {}
template<class T,int SIZE>
void Stack<T, SIZE>::push(const T&item) {
	assert(!isEmpty());
	list[++top] = item;
}
template<typename T,int SIZE>
T Stack<T, SIZE>::pop() {
	assert(!isEmpty());
	return list[top--];
}

template<class T,int SIZE>
const T& Stack<T, SIZE>::peek()const {
	assert(!isEmpty());
	return list[top];
}

template<class T,int SIZE>
bool Stack<T, SIZE>::isEmpty() const {
	return top == -1;
}
template<class T,int SIZE>
bool Stack<T, SIZE>::isFull() const {
	return top == SIZE - 1;
}
template<class T,int SIZE>
void Stack<T, SIZE>::clear() {
	top = -1;
}
#endif