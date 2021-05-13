#include<iostream>

template<typename T>
class Stack
{
private:
	T *m_Stack;
	int m_Size;
	int m_Count;

public:
	Stack( ) : m_Size ( 10 ), m_Count(0)
	{
		m_Stack = new T[m_Size];
	}

	~Stack()
	{
		delete[] m_Stack;
	}

	inline T Top()
	{
		return m_Stack[m_Count-1];
	}

	bool Push(const T &data);
	T Pop();

	template <typename C>
	friend std::ostream &operator<<(std::ostream &out, const Stack<C> &stack);
};

template<typename T>
bool Stack<T>::Push(const T& data)
{
	if (m_Count == m_Size)
		return false;

	m_Stack[m_Count++] = data;
	return true;
}

template<typename T>
T Stack<T>::Pop()
{
	if (m_Count == 0)
		return;

	return m_Stack[--m_Count];
}

template <typename C>
std::ostream &operator<<(std::ostream &out, const Stack<C> &stack)
{
	out << std::endl;
	for(int i = 0; i < stack.m_Count; i ++)
		out << stack.m_Stack[i];
	out << std::endl;
}