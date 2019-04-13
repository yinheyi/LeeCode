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
*   Created Time: 2019年04月13日 星期六 23时32分30秒
*	Modifed Time: 2019年04月14日 星期日 00时23分37秒
*   Blog: http://www.cnblogs.com/yinheyi
*   Github: https://github.com/yinheyi
*   
***********************************************************************/

#include <iostream>
#include <stdexcept>
#include <vector>

// 题目： 输出一个单向链表的倒数第k个结点的值, 单向链表的节点结构如下所示：
struct ListNode
{
	int m_nValue;
	ListNode* m_pNext;
	ListNode();
};

// 构造函数
ListNode::ListNode()
{
	m_nValue = 0;
	m_pNext = nullptr;
}

// 版本1
ListNode* FindKthToTailVersion1(ListNode* pRoot_, int k_)
{
	if (pRoot_ == nullptr)
		throw std::domain_error("参数对应的结果值不存在，该单向链表的长度不足k个");

	// 初始化一个vector, 用于存放链表中的node的指针
	std::vector<ListNode*> _vecNodeContainer;

	// 把链表中的node放到vector中
	ListNode* _pCurrentNode = pRoot_;
	while (_pCurrentNode != nullptr)
	{
		_vecNodeContainer.push_back(_pCurrentNode);
		_pCurrentNode = _pCurrentNode->m_pNext;
	}

	// 判断是否多于k个元素的个数
	if (_vecNodeContainer.size()  < k_)
		throw std::domain_error("参数对应的结果值不存在，该单向链表的长度不足k个");
	else
		return *(_vecNodeContainer.end() - k_);
}

// 版本2
ListNode* FindKthToTailVersion2(ListNode* pRoot_, int k_)
{
	if (pRoot_ == nullptr)
	{
		throw std::domain_error("参数对应的结果值不存在，该单向链表的长度不足k个");
	}

	ListNode* _pFront = pRoot_;
	ListNode* _pLater = pRoot_;
	for (int i = 1; i < k_; ++i)
	{
		if (_pLater != nullptr)
			_pLater = _pLater->m_pNext;
		else
			throw std::domain_error("参数对应的结果值不存在，该单向链表的长度不足k个");
	}

	// 此时， pLater与pFront中间正好间隔了4个数, 要判断_pLater是否为空
	if (_pLater == nullptr)
		throw std::domain_error("参数对应的结果值不存在，该单向链表的长度不足k个");

	// 继续移动, 一直把_pLater移动到最后一个节点
	while (_pLater->m_pNext != nullptr)
	{
		_pFront = _pFront->m_pNext;
		_pLater =_pLater->m_pNext;
	}

	return _pFront;
}


/***************   测试使用   *****************/
int main()
{
	return 0;
}
