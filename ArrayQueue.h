#include<iostream>

template<typename T>
class ArrayQueue
{
private:
	int m_head = 0;
	int m_tail = 0;
	int m_size = 0;
	T *m_queue = nullptr;

public:
	ArrayQueue( ) : m_size(10), m_head(0), m_tail(0)
	{
		m_queue = new T[m_size];
	}

	ArrayQueue(int size) : m_size(size), m_head(0), m_tail(0)
	{
		m_queue = new T[m_size];
	}

	~ArrayQueue()
	{
		delete[] m_queue;
		m_queue = nullptr;
		m_size = 0;
		m_tail = 0;
		m_head = 0;
	}

	void enqueue(const T &data);
	bool dequeue(T& data);
};

template<typename T>
void ArrayQueue<T>::enqueue(const T& data)
{
	if (m_tail == m_size)
	{
		if (m_head == 0)
			return;

		for (int i = m_head; i < m_tail; i ++)
			m_queue[i - m_head] = m_queue[i];

		m_tail -= m_head;
		m_head = 0;
	}

	m_queue[m_tail++] = data;
}

template<typename T>
bool ArrayQueue<T>::dequeue(T& data)
{
	if (m_head==m_tail)
		return false;

	data = m_queue[m_head++];

	return true;
}

template<typename T>
class CircleQueue
{
private:
	int m_size = 0;
	int m_head = 0;
	int m_tail = 0;
	T *m_queue;

public:
	CircleQueue():m_size(10), m_head(0), m_tail(0)
	{
		m_queue = new T[m_size];
	}

	CircleQueue(int size):m_size(size), m_head(0), m_tail(0)
	{
		m_queue = new T[m_size];
	}

	~CircleQueue()
	{
		delete[] m_queue;
		m_queue = nullptr;
	}

	void enqueue(const T &data);
	bool dequeue(T &data);
};

template<typename T>
bool CircleQueue<T>::dequeue(T& data)
{
	if (m_head == m_tail)
		return false;

	data = m_queue[m_head];
	m_head = (m_head + 1) % m_size;
}

template<typename T>
void CircleQueue<T>::enqueue(const T& data)
{
	if( (m_tail+1) % m_size == m_head)
		return;

	m_queue[m_tail] = data;
	m_tail = (m_tail + 1) % m_size;
}
