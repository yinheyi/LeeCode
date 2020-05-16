/***********************************************************************
*   Copyright (C) 2019  Yinheyi. <chinayinheyi@163.com>
*   
* This program is free software; you can redistribute it and/or modify it under the terms
* of the GNU General Public License as published by the Free Software Foundation; either 
* version 2 of the License, or (at your option) any later version.

*   Brief:    
*   Author: yinheyi
*   Email: chinayinheyi@163.com
*   Version: 1.0
*   Created Time: 2019年04月27日 星期六 07时47分38秒
*   Modifed Time: 2019年04月27日 星期六 10时12分15秒
*   Blog: http://www.cnblogs.com/yinheyi
*   Github: https://github.com/yinheyi
*   
***********************************************************************/


#include <vector>
#include <algorithm>
#include <functional>
#include <stdexcept>
#include <iostream>
typedef unsigned long size_t;

// 题目：如何得到一个数据流的中位数？
// 借助最大堆与最小堆来实现。
// 在std中，可以使用一些标准的函数进行建堆/加入元素/删除元素操作， make_heap/push_heap/
// pop_heap.


// 最大堆的定义
template <typename T>
class Max_Heap
{
public:
	size_t size() const;
	bool empty() const;
	void Push(const T& value);
	void Pop();
	const T& GetMax() const;

private:
	std::vector<T> m_container;
};

template <typename T>
size_t Max_Heap<T>::size() const
{
	return m_container.size();
}

template <typename T>
bool Max_Heap<T>::empty() const
{
	return m_container.empty();
}

template <typename T>

void Max_Heap<T>::Push(const T& value)
{
	m_container.push_back(value);
	std::push_heap(m_container.begin(), m_container.end());		// 默认为最大堆
}

template <typename T>
void Max_Heap<T>::Pop()
{
	std::pop_heap(m_container.begin(), m_container.end());
	m_container.pop_back();
}

template <typename T>
const T& Max_Heap<T>::GetMax() const
{
	if (empty())
	{
		throw std::out_of_range("对不起，最大堆为空");
	}
	else
	{
		return m_container.front();
	}
}


// 最小堆的定义
template <typename T>
class Min_Heap
{
public:
	size_t size() const;
	bool empty() const;
	void Push(const T& value);
	void Pop();
	const T& GetMin() const;
private:
	std::vector<T> m_container;
};

template <typename T>
size_t Min_Heap<T>::size() const
{
	return m_container.size();
}

template <typename T>
bool Min_Heap<T>::empty() const
{
	return m_container.empty();
}

template <typename T>
void Min_Heap<T>::Push(const T& value)
{
	m_container.push_back(value);
	std::push_heap(m_container.begin(), m_container.end(), std::greater<T>());		//使用最小堆
}

template <typename T>
void Min_Heap<T>::Pop()
{
	std::pop_heap(m_container.begin(), m_container.end(), std::greater<T>());
	m_container.pop_back();
}

template <typename T>
const T& Min_Heap<T>::GetMin() const
{
	if (m_container.empty())
	{
		throw std::out_of_range("对不起，最小堆为空");
	}
	else
	{
		return m_container.front();
	}
}


// 功能函数的实现
template <typename T>
class DynamicArray
{
public:
	size_t size() const;
	bool empty() const;
	void Push(const T& value);
	T GetMedian() const;
private:
	Max_Heap<T> m_MaxHeap;
	Min_Heap<T> m_MinHeap;
};


template <typename T>
size_t DynamicArray<T>::size() const
{
	return m_MaxHeap.size() + m_MinHeap.size();
}

template <typename T>
bool DynamicArray<T>::empty() const
{
	return m_MaxHeap.empty() && m_MinHeap.empty();
}

// 1. 当动态数组内的个数为偶数时把当前数字放到最大堆中, 当为奇数时放到最小堆中。
// 2. 向最大堆中存放元素时，如果待存放的元素大于最大堆中最大的元素，则把最小堆中最小的元
// 	  放到最大堆中，把待存放的元素放到最小堆中。
// 3. 向最小堆中存放元素时，如果待存放的元素小于最小堆中最小的元素，则把最大堆中最小的元
//    放到最小堆中， 把待存放的元素放到最大堆中。
template <typename T>
void DynamicArray<T>::Push(const T& value)
{
	if (size() & 1)		// 为奇数时, 向最小堆中存放元素
	{
		if (!m_MinHeap.empty() && value < m_MinHeap.GetMin())
		{
			m_MinHeap.Push(m_MaxHeap.GetMax());
			m_MaxHeap.Pop();
			m_MaxHeap.Push(value);
		}
		else
		{
			m_MinHeap.Push(value);
		}
	}
	else		// 为偶数时，向最大堆中存放元素
	{
		if (!m_MaxHeap.empty() && value > m_MaxHeap.GetMax())
		{
			m_MaxHeap.Push(m_MinHeap.GetMin());
			m_MinHeap.Pop();
			m_MinHeap.Push(value);
		}
		else
		{
			m_MaxHeap.Push(value);
		}
	}
}

// 1. 当动态数组为空时，抛出异常。
// 2. 当动态数组中的元素个数为偶数时，返回最大堆的最大元素和最小堆的最小元素的平均值。
// 3. 当动态数组听元素个数为奇数时，返回最大堆的最大值。
template <typename T>
T DynamicArray<T>::GetMedian() const
{
	if (empty())
	{
		throw std::out_of_range("对不起，元素为空，不最大中位数");
	}

	if (size() & 1)
	{
		return m_MaxHeap.GetMax();
	}
	else
	{
		return (m_MaxHeap.GetMax() + m_MinHeap.GetMin()) / 2;
	}
}

/***************    main.c     *********************/
int main(int argc, char* argv[])
{
	int nCount = 0;
	std::cout << "请输入你想输入的个数:" << std::endl;
	std::cin >> nCount;
	
	DynamicArray<double> _contianer;
	for (int i = 0; i < nCount; ++i)
	{
		double nTemp;
		std::cin >> nTemp;
		_contianer.Push(nTemp);
	}

	std::cout << "中位数为：" << _contianer.GetMedian() << std::endl;
	return 0;
}
