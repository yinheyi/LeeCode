/***********************************************************************
*   Copyright (C) 2018  Yinheyi. <chinayinheyi@163.com>
*   
* This program is free software; you can redistribute it and/or
* modify it under the terms of the GNU General Public License
* as published by the Free Software Foundation; either version
* 2 of the License, or (at your option) any later version.

*   Brief:    
*   Author: yinheyi
*   Email: chinayinheyi@163.com
*   Version: 1.0
*   Created Time: 2019年04月04日 星期四 13时29分32秒
*	Modifed Time: 2019年04月04日 星期四 14时50分10秒
*   Blog: http://www.cnblogs.com/yinheyi
*   Github: https://github.com/yinheyi
*   
***********************************************************************/

#include <iostream>
#include <stack>	// 把链表的元素反向打印时使用

// 题目：从尾到头反向打印单向链表内的值;
// 链表节点的定义
struct Node
{
	Node(int nValue_); 		// Node的构造函数

	int nValue;
	Node* pNext;
};
Node::Node(int nValue_) : nValue(nValue_), pNext(nullptr)
{
}


// 方案一:
// 从头到尾遍历链表，把结果压入栈中。然后再出栈。
void PrintListReversely_ByStack(const Node* const pHead_)
{
	// 当为空链表时， 直接返回.
	if (pHead_ == nullptr)
		return;

	// 定义一个栈,用于存放链表的结点
	std::stack<const Node*> _StackNodes;
	const Node* _pNode = pHead_;

	// 遍历整个链表，把node压入到栈中
	while (_pNode != nullptr)
	{
		_StackNodes.push(_pNode);
		_pNode = _pNode->pNext;
	}

	// 出栈,反向打印链表的值
	while (!_StackNodes.empty())
	{
		std::cout << _StackNodes.top()->nValue << " ";
		_StackNodes.pop();
	}
}


// 方案二：
// 基于递归，隐式使用栈来完成
void PrintListReversely_ByRecursion(const Node* const pHead_)
{
	if (pHead_ == nullptr)
		return;

	// 递归调用自己, 打印当前节点之后的链表部分，再打印当前节点的值
	PrintListReversely_ByRecursion(pHead_->pNext);
	std::cout << pHead_->nValue << " ";
}


/***********************   测试使用  ************************/
// 新建一个链表，包含100个元素
Node* NewList()
{
	Node* _pHead = new Node(-1);
	Node* _pCurrent = _pHead;
	for (int i = 0; i < 99; ++i)
	{
		_pCurrent->pNext  = new Node(i);
		_pCurrent = _pCurrent->pNext;
	}
	return _pHead;
}

// 顺序遍历一个链表中的值
void TraverseList(const Node* const pHead_)
{
	// 为空时，返回
	if (pHead_ == nullptr)
		return;

	const Node* _pCurrentNode = pHead_;
	while (_pCurrentNode != nullptr)
	{
		std::cout << _pCurrentNode->nValue << " ";
		_pCurrentNode = _pCurrentNode->pNext;
	}
}

/************************  主函数  ***********************/
int main()
{
	Node* _pNewList = NewList();

	// 顺序遍历链表中的值
	std::cout << "顺序遍历链表中的值：" << std::endl;
	TraverseList(_pNewList);
	std:: cout << std::endl;

	// 使用方案一逆序遍历链表中的值
	std::cout << "使用方案一逆序遍历链表中的值：" << std::endl;
	PrintListReversely_ByStack(_pNewList);
	std:: cout << std::endl;

	// 使用方案二逆序遍历链表中的值
	std::cout << "使用方案二逆序遍历链表中的值：" << std::endl;
	PrintListReversely_ByRecursion(_pNewList);
	std:: cout << std::endl;

	return 0;
}
