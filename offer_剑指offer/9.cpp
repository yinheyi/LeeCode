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
*   Created Time: 2019年04月05日 星期五 13时33分03秒
*	Modifed Time: 2019年04月05日 星期五 21时14分55秒
*   Blog: http://www.cnblogs.com/yinheyi
*   Github: https://github.com/yinheyi
*   
***********************************************************************/

#include <stack>
#include <queue>
#include <stdexcept>	// 用于当队列为空时，抛出异常

// 题目： 使用两个格实现一个队列, 实现appendTail和deleteHead分别在尾部插入和在头部删除.
//
//
///****************    下面是一个错误的思考过程      ******************/
// 思考：如何使用两个栈实现队列呢？栈是先进后出，队列是先进先出, 怎么由两个先由后出来实现
// 一个先进先出呢？
// 一个栈本质上就是把一个序列进行了反向， 而队列没有进行反向。所以呢，使用两个栈把一个序列
// 反向之后再反向，就相当于没有反向。。如此想下去，就有了思路：
// 栈A只添加元素，对应在队列尾部添加元素，栈B只删除元系， 对应在队列头部删除元素。
// 在栈A作添加元素和栈B作删除元素动作之前，应该保持两个栈的元素一致, 因此:
// 当栈A添加元素时，需要先看看栈B是否删除了元素，如果删除了的话，则需要把栈b先压入到栈A中
// 再进行添加元素。
// 同样地，当栈B删除元素时，需要先看看栈A是否添加了元素，如果是，则需要先把栈a先压入到栈
// B中，栈B再进行删除元素。
template <typename T>
class Queue
{
public:
	Queue();
	void appendTail(const T& value_);	// 入队
	void DeleteHead();					// 出队
	const T& GetHeadValue() const;		// 获取队首的元素

private:
	stack<T> m_stackA;					// 使用两个栈来实现队列
	stack<T> m_stackB;
	bool m_bStackAChanged;				// 跟踪栈A是否变化
	bool m_bStackBChanged;				// 跟踪栈B是否变化
};

// 构造函数 
template <typename T>
Queue<T>::Queue() 
{
	m_bStackAChanged = false;
	m_bStackBChanged = false;
}

template <typename T>
Queue<T>::appendTail(const T& value_)
{
	// 栈A在执行添加元素动作之前, 先检测栈B是否变化，如果变化，则先同步栈B的元素
	if (m_bStackBChanged)
	{
		// 清空栈A
		while (!m_stackA.empty())
			m_stackA.pop();

		// 同步栈B的元素 
		while (!m_stackB.empty())
		{
			m_stackA.push(m_stackB.top());
			m_stackB.pop();
		}
		// 同步完成之后，把栈B是否变化置为false;
		m_bStackBChanged = false;
	}

	m_stackA.push(value_);
	m_bStackAChanged = true;
}

template <typename T>
Queue<T>::DeleteHead()
{
	// 栈B在执行删除元素动作之前, 先检测栈A是否变化，如果变化，则先同步栈A的元素
	if (m_bStackAChanged)
	{
		// 清空栈B
		while (!m_stackB.empty())
			m_stackB.pop();

		// 同步栈A的元素 
		while (!m_stackA.empty())
		{
			m_stackB.push(m_stackA.top());
			m_stackA.pop();
		}
		// 同步完成之后，把栈A是否变化置为false;
		m_bStackAChanged = false;
	}

	if (!m_stackB.empty())
	{
		m_stackB.pop();
		m_bStackBChanged = true;
	}
	else
		throw out_of_range("队列为空，无法删除");
}

// 对于获取队列首部元素值这一动作, 不到万不得已时，不需要同步栈A的元素。
// 那什么是万不得已的时候呢？ 就是栈B为空而栈A又添加了新元素时, 就需要同步栈A的元素了。
template <typename T>
const T& Queue<T>::GetHeadValue() const
{
	// 当栈B不为空时，不需要同步栈A的元素
	if (!m_stackB.empty())
		return m_stackB.top();

	if (m_bStackAChanged)
	{
		// 同步栈A的元素 
		while (!m_stackA.empty())
		{
			m_stackB.push(m_stackA.top());
			m_stackA.pop();
		}
		// 同步完成之后，把栈A是否变化置为false;
		m_bStackAChanged = false;
		return m_stackB.top();
	}
	else
		throw out_of_range("队列为空，无法删除");
}



/**********************   正确的解决方案       ***********************/
//
// 上面的答案是错误的，错在哪了呢？
// 把问题想复杂了！两个栈之间没有办法同步数据, 把一个栈的数据放到另一个栈时，当前栈就会变
// 成空的, 所有数据只能在两个栈之间进行转移，不能同时拥有！
// 正解的解决方案很简单, 如下所示：
template <typename T>
class Queue
{
public:
	Queue();
	void appendTail(const T& value_);	// 入队
	void DeleteHead();					// 出队
	const T& GetHeadValue() const;		// 获取队首的元素

private:
	stack<T> m_stackA;					// 使用两个栈来实现队列
	stack<T> m_stackB;
};

template <typename T>
void Queue<T>::appendTail(const T& value_)
{
	m_stackA.push(value_);
}

template <typename T>
void Queue<T>::DeleteHead()
{
	// 当栈B为空时，把栈A内的元素转移到栈B中
	if (m_stackB.empty())
	{
		while (!m_stackA.empty())
		{
			m_stackB.push(m_stackA.top());
			m_stackA.pop();
		}
	}

	// 如果栈B为空，则抛出错误
	if (m_stackB.empty())
		throw out_of_range("队列为空");
	else
		m_stackB.pop();
}

template <typename T>
const T& Queue<T>::GetHeadValue() const
{
	// 当栈B为空时，把栈A内的元素转移到栈B中
	if (m_stackB.empty())
	{
		while (!m_stackA.empty())
		{
			m_stackB.push(m_stackA.top());
			m_stackA.pop();
		}
	}

	// 如果栈B为空，则抛出错误
	if (m_stackB.empty())
		throw out_of_range("队列为空");
	else
		return m_stackB.top();
}
