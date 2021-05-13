#pragma once
#include<iostream>

template<typename T>
class Array
{
private:
	T* m_elements;
	int m_size;
	int m_length;

public:
	Array() : m_size(20), m_length(0)
	{
		m_elements = new T[m_size];
	}

	Array(int size) : m_size(size), m_length(0)
	{
		m_elements = new T[m_size];
	}

	~Array()
	{
		delete[] m_elements;
		m_size = 0;
		m_length = 0;
	}

	T& operator[](int index)
	{
		return m_elements[index];
	}

	const T& operator[](int index) const
	{
		return m_elements[index];
	}


	void Resize(int size)
	{
		m_size = size;
		T* elements = new T[size];
		for (int i = 0; i < m_length; i ++)
			elements[i] = m_elements[i];

		delete[] m_elements;

		m_elements = elements;
	}

	void Add(const T& data)
	{
		if (m_length >= m_size)
			Resize(m_size*2);

		m_elements[m_length++] = data;
	}

	void Insert(const T& data, int k)
	{
		k--;
		if (k >= m_length)
		{
			Add(data);

			return;
		}

		m_length++;
		if (m_length >= m_size)
			Resize(m_size * 2);

		for (int i = m_length; i > k; i --)
			m_elements[i] = m_elements[i - 1];

/*
		for (int i = m_length - 1; i > k; i --)
			m_elements[i + 1] = m_elements[i];
*/

		m_elements[k] = data;
	}

	T RemoveLast()
	{
		const T &data = m_elements[m_length --];

		return data;
	}

	void RemoveFromTo(int from, int to)
	{
		to = to > m_length ? m_length : to;
		int range = to - from + 1;
		from--;
		to--;
		for (int i = from; i < to; i ++)
			m_elements[i] = m_elements[i + range];

		m_length -= range;
	}

	void Delete(const T& data)
	{
		int k = 0;
		for (; k < m_length; k ++)
		{
			if (data == m_elements[k])
				break;
		}

		if (k == m_length)
			return;

		for (int i = k; i < m_length - 1; i ++)
			m_elements[i] = m_elements[i + 1];

		m_length--;
	}

	template<typename C>
	friend std::ostream &operator<<(std::ostream &out, const Array<C> &array);
};

template<typename T>
std::ostream &operator<<(std::ostream &out, const Array<T> &array)
{
	out << std::endl;
	for (int i = 0; i < array.m_length; i++)
		out << array[i] << " ";
	out << std::endl;

	return out;
}