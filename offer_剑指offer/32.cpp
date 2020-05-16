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
*   Created Time: 2019年04月21日 星期日 19时40分55秒
*	Modifed Time: 2019年04月21日 星期日 20时02分52秒
*   Blog: http://www.cnblogs.com/yinheyi
*   Github: https://github.com/yinheyi
*   
***********************************************************************/
#include <queue>
#include <stack>
#include <iostream>
struct BinaryTreeNode
{
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
	BinaryTreeNode();
};
BinaryTreeNode::BinaryTreeNode()
{
	m_nValue = 0;
	m_pLeft = nullptr;
	m_pRight = nullptr;
}

void PrintHierarchically(const BinaryTreeNode* pRoot_)
{
	if (pRoot_ == nullptr)
		return;

	// define a deque for nodes.
	std::queue<const BinaryTreeNode*> _NodeDeque;
	_NodeDeque.push(pRoot_);
	while (!_NodeDeque.empty())
	{
		const BinaryTreeNode* _pCurrentNode = _NodeDeque.front();
		_NodeDeque.pop();
		std::cout << _pCurrentNode->m_nValue << std::endl;

		if (_pCurrentNode->m_pLeft != nullptr)
			_NodeDeque.push(_pCurrentNode->m_pLeft);
		if (_pCurrentNode->m_pRight != nullptr)
			_NodeDeque.push(_pCurrentNode->m_pRight);
	}
}

void PrintBidirectionally(const BinaryTreeNode* pRoot_)
{
	if (pRoot_ == nullptr)
		return;

	// define two stack;
	std::stack<const BinaryTreeNode*> _StackFirst;
	std::stack<const BinaryTreeNode*> _StackSecond;
	_StackFirst.push(pRoot_);
	while (!_StackFirst.empty() || !_StackSecond.empty())
	{
		while (!_StackFirst.empty())
		{
			const BinaryTreeNode* _pCurrentNode = _StackFirst.top();
			_StackFirst.pop();
			std::cout << _pCurrentNode->m_nValue << " ";

			if (_pCurrentNode->m_pLeft != nullptr)
			{
				_StackSecond.push(_pCurrentNode->m_pLeft);
			}
			if (_pCurrentNode->m_pRight != nullptr)
			{
				_StackSecond.push(_pCurrentNode->m_pRight);
			}
		}
		std::cout << std::endl;

		while (!_StackSecond.empty())
		{
			const BinaryTreeNode* _pCurrentNode = _StackSecond.top();
			_StackSecond.pop();
			std::cout << _pCurrentNode->m_nValue << " ";

			if (_pCurrentNode->m_pRight != nullptr)
			{
				_StackFirst.push(_pCurrentNode->m_pRight);
			}
			if (_pCurrentNode->m_pLeft != nullptr)
			{
				_StackFirst.push(_pCurrentNode->m_pLeft);
			}
		}
		std::cout << std::endl;
	}
}
/***************    main.c     *********************/
int main(int argc, char* argv[])
{
	return 0;
}

