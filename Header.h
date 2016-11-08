#include<iostream>
#include<Windows.h>
#include<string>
using namespace std;

void postfix_count(string, float*, string);
string postfix(string, int&);
int priority(char);


template <class T> struct Stack
{
	T key;
	Stack *next;
	Stack();
	~Stack();
	Stack* Pop(Stack*&);
	void Push(Stack *&, T);
};
template <class T> void Print(Stack<T> *stack);