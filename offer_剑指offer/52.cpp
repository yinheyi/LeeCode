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
*   Created Time: 2019年05月03日 星期五 12时36分09秒
*   Modifed Time: 2019年05月03日 星期五 13时05分16秒
*   Blog: http://www.cnblogs.com/yinheyi
*   Github: https://github.com/yinheyi
*   
***********************************************************************/


// 题目：输入两个链表， 找出它们的第一个公共节点。 链表的定义如下：
struct ListNode
{
	int m_nKey;
	ListNode* m_pNext;
};

// 想法：我本人的想法是：遍历三次链表，第一次把链表中赋值为1, 第二次把链表赋值为2, 第三 
// 次再遍历第一个链表，找到为2的节点，就是第一个公共节点了。
//
// 看了答案之后，感觉我的方法很笨，并且很局限，它改变了链表的值。所以这个方法不好。 
// 看完答案之后，学习到:
// 1. 如果想反向遍历单向链表，可以使用栈的数据结构。
// 2. 看到单向链表的相关题目时，记得使用两个指针来遍历链表，一个走的快，一个走的慢。
//
// 本题的解决方法：
// 1. 先分别遍历两个链表，可以得到它们的长度之差为n。
// 2. 在链表较长上的指针，先行走n步，然后两个指针再同时行走。
//
// 代码如下：
#define ABS(x) ((x) >= 0 ? (x) : -(x))
ListNode* GetFirstCommonNode(ListNode* pHeadFirst_, ListNode* pHeadSecond_)
{
	if (pHeadFirst_ == nullptr || pHeadSecond_ == nullptr)
		return nullptr;

	// 求链表1的长度
	int nCountFirst_ = 0;
	while (pHeadFirst_ != nullptr)
	{
		++nCountFirst_;
		pHeadFirst_ = pHeadFirst_->m_pNext;
	}

	// 求链表2的长度
	int nCountSecond_ = 0;
	while (pHeadSecond_ != nullptr)
	{
		++nCountSecond_;
		pHeadSecond_ = pHeadSecond_->m_pNext;
	}

	// 较长的链表先走n步。
	ListNode* _pLongger = nCountFirst_ >= nCountSecond_ ? pHeadFirst_ : pHeadSecond_;
	ListNode* _pShoter = nCountFirst_ <= nCountSecond_ ? pHeadFirst_ : pHeadSecond_;
	for (int i = 0; i < ABS(nCountFirst_ - nCountSecond_); ++i)
	{
		_pLongger = _pLongger->m_pNext;
	}

	// 两个链表同步向前行进，直到相同为止。
	while (_pShoter != nullptr && _pLongger != nullptr && _pShoter != _pLongger)
	{
		_pShoter = _pShoter->m_pNext;
		_pLongger = _pLongger->m_pNext;
	}

	// 如果不为空时，返回公共的指针。
	if (_pShoter == nullptr || _pLongger == nullptr)
		return nullptr;
	else
		return _pShoter;
}

/***************    main.c     *********************/
int main(int argc, char* argv[])
{
	return 0;
}

