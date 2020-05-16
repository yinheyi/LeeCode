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
*   Created Time: 2019年04月14日 星期日 11时02分33秒
*	Modifed Time: 2019年04月14日 星期日 23时27分19秒
*   Blog: http://www.cnblogs.com/yinheyi
*   Github: https://github.com/yinheyi
*   
***********************************************************************/

#include <set>
// 题目：找出单向链表中的环的入口点
struct ListNode
{
	int m_nValue;
	ListNode* m_pNext;
	ListNode();
};
// 节点的构造函数
ListNode::ListNode()
{
	m_nValue = 0;
	m_pNext = nullptr;
}

// 分析：带有环的单向链表的特点是其中一个节点被指向了二次。我们应该从这里入手解决吧。
// 版本一：可以使用一个set来处理, 但是感觉在这里使用这样重量级的容器, 有点浪费！ 
ListNode* FindEntryPoint(const ListNode* pRoot_)
{
	// 参数检测
	if (pRoot_ == nullptr)
		return nullptr;

	// 从头到尾遍历单向链表，把每一个node指针添加到set中
	std::set<ListNode*> _setContainer;
	ListNode* _pCurrentNode = const_cast<ListNode*>(pRoot_);
	while (_pCurrentNode != nullptr)
	{
		// 插入操作返回一个pair类型，第二个值表示是否插入成功。如果已经存在，则为false;
		if (!_setContainer.insert(_pCurrentNode).second)
			return _pCurrentNode;

		_pCurrentNode = _pCurrentNode->m_pNext;
	}

	// 如果没有在while循环中退出，则说明没有环状入口, 返回空
	return nullptr;
}


// 版本二：
// 书中的思路：
// 1. 判断一个链表中是否存在环？
//    使用两个指针，都同时从链表头出发，一个一次走一步，一个一次走两步。如果存在着环，它
//    们会相遇，如果不存在环，则走的快的指针会遇到nullptr
// 2. 如何求环中的结点个数？
// 	  在1中，两个指针相遇的地方一定在环内，在此处开始计数，一步步走直到再次直到这个位置,
// 	  此时，通过计数值就可以知道环的结点个数了。
// 3. 如何找到环的入口？
// 	  假设环内的节点个数为n, 再次使用两个指针，第一个指针先走n步，然后两个指针再一起走，
// 	  两个指针相遇时，第二个指针的位置就是环的入口结点。
//
ListNode* FindEntryPointVersion2(const ListNode* pRoot_)
{
	// 参数检测
	if (pRoot_ == nullptr)
		return nullptr;

	// 判断链表中是否存在着环
	ListNode* _pFirst = const_cast<ListNode*>(pRoot_);
	ListNode* _pSecond = _pFirst;
	while (_pFirst != _pSecond)
	{
		// 第一个指针走两步, 遇到空时直接返回空
		_pFirst = _pFirst->m_pNext;
		if (_pFirst == nullptr)
			return nullptr;
		_pFirst = _pFirst->m_pNext;
		if (_pFirst == nullptr)
			return nullptr;

		// 第二个指针走一步
		_pSecond = _pSecond->m_pNext;
	}

	// 求环中结点的个数
	unsigned int _nNumOfNodes = 0;
	_pFirst = _pFirst->m_pNext;
	++_nNumOfNodes;
	while (_pFirst != _pSecond)
	{
		_pFirst = _pFirst->m_pNext;
		++_nNumOfNodes;
	}

	// 求环的入口结点
	_pFirst = const_cast<ListNode*>(pRoot_);
	_pSecond = _pFirst;
	// 第一个指针先走n步
	for (int i = 0; i < _nNumOfNodes; ++i)
		_pFirst = _pFirst->m_pNext;
	while (_pFirst != _pSecond)
	{
		_pFirst = _pFirst->m_pNext;
		_pSecond = _pSecond->m_pNext;
	}

	return _pFirst;
}

/*******************   主函数    *********************/
int main()
{
	return 0;
}
