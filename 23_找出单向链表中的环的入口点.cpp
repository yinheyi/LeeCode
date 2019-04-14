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
*	Modifed Time: 2019年04月14日 星期日 11时25分37秒
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
//


/*******************   主函数    *********************/
int main()
{
	return 0;
}
