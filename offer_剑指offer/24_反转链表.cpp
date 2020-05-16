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
*   Created Time: 2019年04月14日 星期日 23时40分38秒
*	Modifed Time: 2019年04月15日 星期一 00时55分40秒
*   Blog: http://www.cnblogs.com/yinheyi
*   Github: https://github.com/yinheyi
*   
***********************************************************************/

#include <stack>
// 题目:输入一个链表的头节点，反转该链表并输出反转后链表的头节点。
struct ListNode
{
	int m_nKey;
	ListNode* m_pNext;
	ListNode();
};

// 节点的构造函数
ListNode::ListNode()
{
	m_nKey = 0;
	m_pNext = nullptr;
}


// 版本一：最直接的办法就是使用一个栈结构，把链表的节点指针加入到栈中，再出栈重新连接起来
// 下面为代码实现：
void ReverseList(ListNode** ppRoot_)
{
	// 非法值
	if (ppRoot_ == nullptr)
		return;

	// 空链表时，直接返回
	if (*ppRoot_ == nullptr)
		return;

	ListNode* _pCurrentNode = *ppRoot_;
	std::stack<ListNode*> _NodeContainer;
	while (_pCurrentNode)
	{
		_NodeContainer.push(_pCurrentNode);
		_pCurrentNode = _pCurrentNode->m_pNext;
	}

	// 重新组合, 栈内节点肯定不会为空
	_pCurrentNode = _NodeContainer.top();
	*ppRoot_ = _pCurrentNode;
	_NodeContainer.pop();
	while (!_NodeContainer.empty())
	{
		ListNode* _pTemp = _NodeContainer.top();
		_pCurrentNode->m_pNext = _pTemp;
		_pCurrentNode = _pTemp;
		_NodeContainer.pop();
	}
	_pCurrentNode->m_pNext = nullptr;
}


// 版本二：借助两个指针来完成反转
// 第一个指针指向前一个节点，后一个指针指向当前节点,修改当前节点的m_pNext值。修改之前要
// 先使用一个局部变量记住下一个节点的指针.
void ReverseListVersion2(ListNode*& pRoot_)		// 这里参数使用了引用
{
	// 如果链表为空或者只有一个节点，不需要反向，直接返回
	if(pRoot_ == nullptr && pRoot_->m_pNext)
		return;

	// 定义两个指针，执行反向动作
	ListNode* _pFirstNode = pRoot_;
	ListNode* _pSecondNode = _pFirstNode->m_pNext;
	_pFirstNode->m_pNext = nullptr;
	while (_pSecondNode != nullptr)
	{
		ListNode* _pTemp = _pSecondNode->m_pNext;
		_pSecondNode->m_pNext = _pFirstNode;
		_pFirstNode = _pSecondNode;
		_pSecondNode = _pTemp;
	}

	pRoot_ = _pFirstNode;
}



/**************  主函数    *****************/
int main()
{
	return 0;
}
