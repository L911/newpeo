#pragma once

#include<iostream>
template<typename T>
struct ListNode
{
	ListNode *m_next;
	T m_data;

	ListNode() : m_next(nullptr) {}
	ListNode(const T& data) : m_next(nullptr), m_data(data) { }
};

template<typename T>
class LinkedList
{
private:
	int m_length = 0;
	ListNode<T> *m_head = nullptr;

public:
	LinkedList() : m_length(0)
	{
		m_head = new ListNode<T>();
	}

	~LinkedList()
	{
		ListNode<T> *node = m_head;
		while(node!=nullptr)
		{
			ListNode<T> *tmp = node;
			node = node->m_next;

			delete tmp;
			m_head = nullptr;
			m_length = 0;
		}
	}

	int GetLength() { return m_length; }

	void Insert(const T& data, int index);
	void InsertAtFront(const T& data);
	void InsertAtEnd(const T& data);
	void DeleteData(const T &data);
	void DeletaData(int index);
	ListNode<T>* FindData(const T &data);

	ListNode<T>* FindMiddleNode();
	void Reverse();
	void DelteFromEnd(int n);
	bool TestCircle();
	void Merge(const LinkedList<T> &inlist);

	template<typename C>
	friend std::ostream &operator<<(std::ostream &ostream, const LinkedList<C> &list);
};

template<typename T>
void LinkedList<T>::Insert(const T& data, int index)
{
	if (index > m_length)
		index = m_length;

	ListNode<T> *node = m_head->m_next;
	ListNode<T> *p = m_head;
	int k = 0;
	while(node != nullptr && k < index)
	{
		p = node;
		node = node->m_next;
		k ++;
	}

	ListNode<T> *newnode = new ListNode<T>(data);
	p->m_next = newnode;
	newnode->m_next = node;

	m_length++;
}

template<typename T>
void LinkedList<T>::InsertAtEnd(const T& data)
{
	ListNode<T> *newnode = new ListNode<T>(data);
	ListNode<T> *node;
	for (node = m_head; node->m_next != nullptr;node = node->m_next);
	node->m_next = newnode;
	m_length ++;
}

template<typename T>
void LinkedList<T>::InsertAtFront(const T& data)
{
	ListNode<T> *node = new ListNode<T>(data);
	node->m_next = m_head->m_next;
	m_head->m_next = node;
	m_length ++;
}

template<typename T>
void LinkedList<T>::DeleteData(const T& data)
{
	ListNode<T> *node = m_head->m_next;
	ListNode<T> *p = m_head;

	while(node!=nullptr && node->m_data == data)
	{
		p = node;
		node = node->m_next;
	}

	if (node == nullptr)
		return;

	p->m_next = node->m_next;
	delete node;

	m_length--;
}

template<typename T>
void LinkedList<T>::DeletaData(int index)
{
	int k = 1;
	ListNode<T> *node = m_head->m_next;
	ListNode<T> *p = m_head;
	while(k != index && node != nullptr)
	{
		p = node;
		node = node->m_next;
		k ++;
	}


	if (node==nullptr)
		return;

	p->m_next = node->m_next;
	delete node;

	m_length--;
}

template<typename T>
ListNode<T>* LinkedList<T>::FindData(const T& data)
{
	ListNode<T> *node = m_head->m_next;
	while(node!=nullptr&&node->m_data!=data)
		node = node->m_next;

	return node;
}

template<typename T>
ListNode<T>* LinkedList<T>::FindMiddleNode()
{
	if (m_length == 0)
		return nullptr;

	ListNode<T> *p = m_head->m_next, *q = m_head->m_next;
	while(q != nullptr && q->m_next != nullptr)
	{
		p = p->m_next;
		q = q->m_next->m_next;
	}

	return p;
}

template<typename T>
void LinkedList<T>::Reverse()
{
	if (m_length == 0)
		return;

	ListNode<T> *p = m_head->m_next, *q = p->m_next;
	p->m_next = nullptr;

	while(q != nullptr)
	{
		ListNode<T> *tmp = q->m_next;
		q->m_next = p;
		p = q;
		q = tmp;
	}

	m_head->m_next = p;
}

template<typename T>
void LinkedList<T>::DelteFromEnd(int n)
{
	if (m_length == 0)
		return;

	ListNode<T> *p = m_head->m_next, *q = m_head->m_next, *parent = m_head;
	int i = 0;
	n--;
	while(i < n && p != nullptr)
	{
		i ++;
		p = p->m_next;
	}

	if (p == nullptr)
		return;

	while(p->m_next != nullptr)
	{
		p = p->m_next;
		parent = q;
		q = q->m_next;
	}

	parent->m_next = q->m_next;

	delete q;

	m_length--;
}

template<typename T>
bool LinkedList<T>::TestCircle()
{
	if (m_length == 0)
		return false;

	ListNode<T> *p = m_head->m_next, *q = m_head->m_next;
	while (q != nullptr && q->m_next != nullptr )
	{
		p = p->m_next;
		q = q->m_next->m_next;

		if (p == q)
			return true;
	}

	return false;
}

template<typename T>
void LinkedList<T>::Merge(const LinkedList& list)
{
	if (m_length == 0)
	{
		m_head->m_next = list.m_head->m_next;

		return;
	}

	if (list.m_length == 0)
		return;

	ListNode<T> *l = m_head->m_next;
	ListNode<T> *r = list.m_head->m_next;

	ListNode<T> *head, *work;
	if (l->m_data <= r->m_data)
	{
		head = l;
		l = l->m_next;
	}
	else
	{
		head = r;
		r = r->m_next;
	}

	work = head;

	while(l != nullptr && r != nullptr)
	{
		if (l->m_data<=r->m_data)
		{
			work->m_next = l;
			l = l->m_next;
		}
		else
		{
			work->m_next = r;
			r = r->m_next;
		}

		work = work->m_next;
	}

	if ( l != nullptr )
		work->m_next = l;
	else
		work->m_next = r;

	m_head->m_next = head;
}

template<typename C>
std::ostream &operator<<(std::ostream &out, const LinkedList<C> &list)
{
	out << std::endl;

	ListNode<C> *node = list.m_head->m_next;
	while(node!=nullptr)
	{
		out << node->m_data <<" ";
		node = node->m_next;
	}

	out << std::endl;

	return out;
}