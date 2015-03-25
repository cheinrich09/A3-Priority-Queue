/*--------------------------------------------------------------------------------------------------
Created by Alberto Bobadilla (labigm@rit.edu) in 2013

Modified by Christian Heinrich in 2014
--------------------------------------------------------------------------------------------------*/
#ifndef __MYVECTOR_H_
#define __MYVECTOR_H_
#include <iostream>

template <typename T>
class MyVector
{
public:
	T* m_Data;
	int m_nSize;
	int m_nIndex;
	MyVector()
	{
		m_Data = nullptr;
		m_nSize = 0;
		m_nIndex = 0;
	}
	MyVector(MyVector const& other)
	{
		m_Data = nullptr;
		//m_Data = other.m_Data;
		m_nIndex = 0;
		m_nSize = 0;
		//m_nSize = other.m_nSize;
		for(int i = 0; i<other.m_nSize; i++)
		{
			this->Push(other.m_Data[i]);
		}
	}
	MyVector& operator=(MyVector const& other)
	{
		MyVector(other);
		return *this;
	}
	~MyVector()
	{
		if(m_Data != nullptr)
		{
			delete[] m_Data;
			m_Data = nullptr;
		}
		m_nSize = 0;
		m_nIndex = 0;
	}
	void push(T a_Element)
	{
		if(m_nSize == m_nIndex)
		{
			Expand();
		}
		m_Data[m_nIndex] = a_Element;
		m_nIndex++;
	}
	T pop(void)
	{
		if(m_nIndex > 0)
		{
			m_nIndex --;
			return m_Data[m_nIndex];
		}
		else
		{
			return 0;
		}
	}
	T operator[](int index)
	{
		if (index <= m_nindex)
		{
			return m_Data[m_nIndex];
		}
		else
		{
			return 0;
		}
	}
	T front()
	{
		if(m_nIndex >0)
		{
			return m_data[0];
		}
		else
		{
			return 0;
		}
	}
	T back()
	{
		if(m_nSize>0)
		{
			return m_Data[m_nIndex];
		}
		else
		{
			return 0;
		}
	}
	int size()
	{
		return m_nSize;
	}
private:
	
	void Expand()
	{
		if(m_Data == nullptr)
		{
			m_Data = new T[1];
			m_nSize = 1;
		}
		else
		{
			T* tempData = new T[m_nSize * 2];
			for(int i = 0; i < m_nSize; i++)
			{
				tempData[i] = m_Data[i];
			}
			delete[] m_Data;
			m_Data = tempData;

			if(m_nSize == 0)
				m_nSize = 1;
			else
			 m_nSize *= 2;
		}
	}
};


#endif //_MYVECTOR_H
