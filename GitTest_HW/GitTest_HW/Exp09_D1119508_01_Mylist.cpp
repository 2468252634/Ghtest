#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<ctime>
#include"Exp09_D1119508_01_Mylist.h"
using namespace std;


/**************结点类定义****************/
template<typename T>Node<T>::Node()
{
	this->var = 0;
	this->next = NULL;
}
template<typename T>Node<T>::Node(const T& data)
{
	this->var = data;
	this->next = NULL;
}
template<typename T>void Node<T>::InsertAfter(Node<T>* p)
{
	p->next = this->next;		//p的指针域指向当前结点的后继结点
	this->next = p;				//当前结点的指针域指向p
}
template<typename T>void Node<T>::deleteAfter()
{
	Node<T>* tempPtr = this->next;
	if (next == 0)return;
	else this->next = tempPtr->next;
	delete tempPtr;
}
template<typename T>Node<T>* Node<T>::nextNode()
{
	return this->next;
}
/**************链表类定义****************/
template<typename T>void myList<T>::newNode(const T& data, Node<T>* ptrNext)
{
	currPtr = new Node<T>(data);
	currPtr->next = ptrNext;
}
template<typename T>void myList<T>::freeNode(Node<T>* p)
{
	prevPtr = head;
	while (prevPtr->next->next != NULL && prevPtr->next != p)prevPtr = prevPtr->next;
	if (prevPtr->next == tail)tail = prevPtr;
	prevPtr->deleteAfter();
}
template<typename T>myList<T>::myList()
{
	this->head = new Node<T>;
	this->tail = new Node<T>;
}
template<typename T>myList<T>::~myList()
{
	MakeEmpty();
	delete this->head;
}
template<typename T>void myList<T>::MakeEmpty()
{
	Node<T>* tempP;
	while (head->next)
	{
		tempP = head->next;
		head->next = tempP->next;
		delete tempP;
	}
	tail = head;
}
template<typename T>void myList<T>::InsertFront(const T & data)
{
	newNode(data);		//插入到表头后一个元素
	head->InsertAfter(currPtr);
	if (tail == head)tail = currPtr;
}
template<typename T>void myList<T>::InsertRear(const T& data)
{
	this->prevPtr = head->next;
	while (prevPtr->next)prevPtr = prevPtr->next;
	//Node<T>* tempP = new Node<T>(data);		//插入到表尾后一个元素
	newNode(data);
	tail->InsertAfter(currPtr);
	tail = currPtr;								//插入的那个元素变成了表尾
	prevPtr->next = tail;
}
template<typename T>void myList<T>::PrintList()const
{
	Node<T>* tempP = head->next;
	while (tempP)
	{
		cout << tempP->var << '\t';
		tempP = tempP->next;
	}
	cout << endl;
}
template<typename T>void myList<T>::InsertOrder(const T& data)
{
	this->prevPtr = head;
	while (prevPtr)
	{
		currPtr = prevPtr->next;
		if (currPtr->var > data)break;
		prevPtr = prevPtr->next;
		currPtr = currPtr->next;
	}
	Node<T>* tempP = new Node<T>(data);
	prevPtr->InsertAfter(tempP);
	if (tail == head)tail = prevPtr->next;
}
template<typename T>int myList<T>::Length()const
{
	Node<T>* tempP = head->next;
	int count = 0;
	while (tempP)
	{
		count++;
		tempP = tempP->next;
	}
	return count;
}
template<typename T>bool myList<T>::isEmpty()const
{
	if (head->next == NULL)return 1;
	else return 0;
}
template<typename T>void myList<T>::reset(int pos)
{
	this->position = pos;
}
template<typename T>bool myList<T>::endOfList()const
{
	if (position == size)return true;
	else return false;
}
template<typename T>void myList<T>::next()
{
	if (position < size)
		this->position++;
	else cout << "链表已满,游标已到末尾" << endl;
}
template<typename T>int myList<T>::currentPosition()const
{
	return this->position;
}
template<typename T>Node<T>* myList<T>::Find(const T& data)
{
	reset(0);
	prevPtr = head->next;
	while (prevPtr->var != data)
	{
		position++;
		prevPtr = prevPtr->next;
	}
	if (endOfList())
	{
		cout << "未找到该元素" << endl;
		return NULL;
	}
	return prevPtr;
}
template<typename T>void myList<T>::copy(const myList<T>& L1)
{
	head = tail = new Node<T>;
	prevPtr = head;
	Node<T>* tempP = L1.head->next;
	while (tempP)
	{
		newNode(tempP->var);
		prevPtr->next = currPtr;
		prevPtr = prevPtr->next;
		tempP = tempP->next;
	}
}
template<typename T>myList<T>& myList<T>::operator=(const myList<T>& L1)
{
	this->copy(L1);
	return *this;
}
template<typename T>myList<T>::myList(const myList<T>& L1)
{
	this->copy(L1);
}
template<typename T>void myList<T>::DeleteNodeWithVar(const T& data)
{
	Node<T>* tempP = head->next;
	Node<T>* tempQ = NULL;
	while (tempP != NULL)
	{
		tempQ = tempP->next;
		if (tempP->var == data)freeNode(tempP);
		tempP = tempQ;
	}
}
template<typename T>T myList<T>::FindVar(int k)
{
	reset(0);
	currPtr = head->next;
	position++;
	for (; position < k; position++)
	{
		currPtr = currPtr->next;
	}
	return currPtr->var;
}
template<typename T>void myList<T>::Reverse()
{
	size = Length();
	reset(0);
	prevPtr = head->next;
	currPtr = prevPtr->next;
	Node<T>* P=NULL;
	Node<T>* Q=NULL;
	while (currPtr->next != NULL)
	{
		P = currPtr->next;
		currPtr->next = prevPtr;
		prevPtr = currPtr;
		currPtr = P;
	}
	head->next = currPtr;
	currPtr->next = prevPtr;
	Q = head->next;
	Q->next = currPtr->next;
	position++;
	for (; position < size; position++)
	{
		Q = Q->next;
	}
	tail = NULL;
	Q->next = tail;
}
template<typename T>void myList<T>::BubbleSort()
{
	for(prevPtr=head->next;prevPtr!=NULL;prevPtr=prevPtr->next)
		for (currPtr = prevPtr->next; currPtr != NULL; currPtr = currPtr->next)
		{
			if (prevPtr->var > currPtr->var)
			{
				T s = currPtr->var;
				currPtr->var = prevPtr->var;
				prevPtr->var = s;
			}
		}
}
template<typename T>void myList<T>::RemoveRepeat()
{
	Node<T>* P;
	P = head->next;
	while (P&&P->next)
	{
		if (P->var == P->next->var)
		{
			Node<T>* temp = P->next;
			
			P->next = temp->next;
			delete temp;
			
		}
		P = P->next;
	}
}
template<typename T>myList<T> operator+(const myList<T>& L1,const myList<T>& L2)
{
	myList<T> tempList;
	Node<T>* M = tempList.head;
	Node<T>* temp;
	Node<T>* P, * Q;
	P = L1.head->next;
	Q = L2.head->next;
	while (P || Q)
	{
		M->next = new Node<T>;
		if (P == NULL)
		{
			M->var = Q->var;
			Q = Q->next;
		}
		else if (Q == NULL)
		{
			M->var = P->var;
			P = P->next;
		}
		else if (P->var <= Q->var)
		{
			M->var = P->var;
			P = P->next;
		}
		else
		{
			M->var = Q->var;
			Q = Q->next;
		}
		M = M->next;
		
	}
	M->next = NULL;
	tempList.BubbleSort();
	tempList.RemoveRepeat();
	return tempList;
}
int main()
{
	myList<int>L1;
	Node<int>*N1;
	srand(0);

	int a[3] = { 1,3,2 };
	int i;
	for (i = 0; i < 5; i++)
	{
		L1.InsertFront(rand() % 11);
	}
	for (i = 0; i < 3; i++)
	{
		L1.InsertOrder(a[i]);
	}
	L1.PrintList();
	cout << "链表的长度是" << L1.Length() << endl;
	myList<int> L2;
	L2 = L1;
	N1 = L2.Find(2);
	L2.freeNode(N1);
	L2.PrintList();
	cout << "输入你想删除的元素" << endl;
	int num;
	cin >> num;
	L2.DeleteNodeWithVar(num);
	L2.PrintList();
	cout << "第2个元素是" << L2.FindVar(2) << endl;
	L2.Reverse();
	cout << "链表反转后" << endl;
	L2.PrintList();
	cout << "排序后" << endl;
	L2.BubbleSort();
	L2.PrintList();
	cout << "去重后" << endl;
	L2.RemoveRepeat();
	L2.PrintList();
	myList<int> L3;
	L3 = L1 + L2;
	
	cout << "L1是" << endl;
	L1.PrintList();
	cout << "L2是" << endl;
	L2.PrintList();
	cout << "L1和L2链接后" << endl;
	L3.PrintList();
	return 0;
}


