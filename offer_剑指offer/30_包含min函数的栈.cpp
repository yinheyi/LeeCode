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
*   Created Time: 2019年04月19日 星期五 23时08分31秒
*	Modifed Time: 2019年04月21日 星期日 18时22分54秒
*   Blog: http://www.cnblogs.com/yinheyi
*   Github: https://github.com/yinheyi
*   
***********************************************************************/

#include <stack>
// 题目：定义一个都o(1)时间内完成push()/pop()/min()/的栈
template <typename T>
class StackWithMin
{
public:
	void Pop();
	void Push(const T& value_);
	void Top() const;
	const T& Min() const;

private:
	std::stack<T> m_DataStack;
	std::stack<T> m_MinStack;
};

template <typename T>
void StackWithMin<T>::Pop()
{
	m_DataStack.pop();
	m_MinStack.pop();
}

template <typename T>
void StackWithMin<T>::Push(const T& value_)
{
	m_DataStack.push(value_);

	if (value_ < m_MinStack.top())
		m_MinStack.push(value_);
	else
		m_MinStack.push(m_MinStack.top());
}

template <typename T>
const T& StackWithMin<T>::Min() const
{
	return m_MinStack.top();
}

/***************    main.c     *********************/
int main(int argc, char* argv[])
{
	return 0;
}
