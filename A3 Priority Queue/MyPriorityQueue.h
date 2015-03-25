//
//Christian Heirnich
//3/9/14
//The priority Queue Class, as well as the comparison Functor
//
#include <iostream>
#include <queue>
#include <vector>
#include "Functors.h"
#include "MyVector.h"


//functor to be used to compare the two inputs
#ifndef __MYFUNCTOR_H_
#define __MYFUNCTOR_H_

template<typename T = int, class DoCompare = greaterThan<T>>
class MyFunctor
{
	DoCompare compare;
public:
	T operator()(const T& left, const T& right)
	{
		return compare(left, right);//performs the comparison between left and right
	}
};
#endif

//priority queue template
#ifndef __MYPRIORITYQUEUE_H_
#define __MYPRIORITYQUEUE_H_

template <typename T = int, class Container = MyVector<T>, class Compare = lessThan<T>>
class MyPriorityQueue
{
public:
	Container* m_pqData; //container structure that the queue is wrapped around
	MyFunctor<T, Compare> m_pqFunctor; //comparison functor
	//constructor
	MyPriorityQueue()
	{
		m_pqData = new Container();
	}
	//copy constructor
	MyPriorityQueue(MyPriorityQueue const& other)
	{
		m_pqData = other.m_pqData;
		m_pqFunctor = other.m_pqFunctor;
	}
	//copy assignment operator
	MyPriorityQueue& operator=(MyPriorityQueue const& other)
	{
		MyPriorityQueue(other);
		return *this;
	}
	//destructor
	~MyPriorityQueue()
	{
		delete m_pqData;
		m_pqData = nullptr;
	}
	//returns whether it is empty
	bool isEmpty()
	{
		if(m_pqData.size() == 0)
		{
			return true;
		}
		return false;
	}
	//returns size of internal container
	unsigned int Size()
	{
		return m_pqData.size();
	}
	//top value
	T top()
	{
		T temp = m_pqData->pop();
		m_pqData->push(temp);
		return temp;
	}
	//push operation (not currently working correctly, should sort the container with the insert, but doesn't)
	void Push(T value)
	{
		Container* temp = new Container();
		for(int i = 0; i < m_pqData->size(); i++)
		{
			if(m_pqFunctor(value, m_pqData->back()))
			{
				temp->push(m_pqData->pop());
			}
			else
			{
				break;
			}
		}
		temp->push(value);
		for(int b = 0; b < temp->size(); b++)
		{
			m_pqData->push(temp->pop());
		}
	}
	//pops the last value from the container
	T Pop()
	{
		T temp = m_pqData->pop();
		return temp;
	}


};
#endif