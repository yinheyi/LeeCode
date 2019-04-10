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
*   Created Time: 2019年04月10日 星期三 23时01分56秒
*	Modifed Time: 2019年04月10日 星期三 23时42分17秒
*   Blog: http://www.cnblogs.com/yinheyi
*   Github: https://github.com/yinheyi
*   
***********************************************************************/

// 题目：给定一个单向链表的头指针和一个节点指针， 定义一个函数在O(1)的时间内删除该节点。
// 链表的定义如下：
struct ListNode
{
	int nValue;
	ListNode* pNext;
};

// 好吧，想了半天也没有想出方法来。直到看了书中的答案，直的让人拍案惊奇！
// 这个方法绝了！！！
// 如何突破传统的思维模式的枷锁呢？？太难了。
// 直接看代码
bool DeleteNode(ListNode*& pHead_, ListNode* pToBeDeleted_)
{
	// 参数的合法性检测
	if (!pHead_ || !pToBeDeleted_)
		return false;

	// 大致方法：
	// 当删除头节点时, 直接删除就好了, 记得要修改头指针;
	// 当删除链表的中间节点时，把下一个节点的内容复制到当前节点，去删除下一个节点
	// 当删除尾部节点时，只能从头遍历到链表尾部
	if (pToBeDeleted_ == pHead_)
	{
		pHead_ = pToBeDeleted_->pNext;
		delete pToBeDeleted_;
		pToBeDeleted_ = nullptr;
		return true;
	}

	if (pToBeDeleted_->pNext)
	{
		ListNode* _pNextNode = pToBeDeleted_->pNext;
		pToBeDeleted_->nValue = _pNextNode->nValue;
		pToBeDeleted_->pNext = _pNextNode->pNext;
		delete _pNextNode;
		_pNextNode = nullptr;
	}

	if (!pToBeDeleted_->pNext)
	{
		ListNode* _pCurrentNode = pHead_;
		while (_pCurrentNode->pNext != pToBeDeleted_)
			_pCurrentNode = _pCurrentNode->pNext;

		_pCurrentNode->pNext = nullptr;
		delete pToBeDeleted_;
		pToBeDeleted_ = nullptr;
	}
}

/***********  测试使用  *********/
int main()
{
	return 0;
}
