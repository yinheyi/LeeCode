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
*   Created Time: 2019年04月15日 星期一 22时25分33秒
*	Modifed Time: 2019年04月15日 星期一 23时08分22秒
*   Blog: http://www.cnblogs.com/yinheyi
*   Github: https://github.com/yinheyi
*   
***********************************************************************/


// Merge two incremental singly linked list, and guarantee the merged singly linked list 
// is also incremental.
// The singly linked list node is defiend as follows:
struct ListNode
{
	int m_nValue;
	ListNode* m_pNext;
	ListNode();
};
// The constructor of ListNode
ListNode::ListNode()
{
	m_nValue = 0;
	m_pNext = nullptr;
}

// The idea: Build a new singly linked list, and compare two lists, insert the node of 
// little value in the tail of the new list.
// return the root point the new list. the roots of first list and second list will be 
// seted as nullptr after merge.
ListNode* MergeList_Version1(ListNode*& pRoot1_, ListNode*& pRoot2_)
{
	// It will return nullptr when both lists are empty.
	if (pRoot1_ == nullptr && pRoot2_ == nullptr)
		return nullptr;

	// It will return the second list when the first list is empty.
	if (pRoot1_ == nullptr)
	{
		ListNode* _pTemp = pRoot2_;
		pRoot2_ = nullptr;
		return _pTemp;
	}

	// it will return the first list when the second list is empty.
	if (pRoot2_ == nullptr)
	{
		ListNode* _pTemp = pRoot1_;
		pRoot1_ = nullptr;
		return pRoot1_;
	}

	// build a new pointer for new new list.
	ListNode* _pNewRoot = nullptr;
	if (pRoot1_->m_nValue <= pRoot2_->m_nValue)
	{
		_pNewRoot = pRoot1_;
		pRoot1_ = pRoot1_->m_pNext;
	}
	else
	{
		_pNewRoot = pRoot2_;
		pRoot2_ = pRoot2_->m_pNext;
	}

	// insert node into new list continuously from original lists;
	while (pRoot1_ != nullptr || pRoot2_ != nullptr)
	{
		// when the first list is empty, we just insert the second list into the tail of
		// the new list.
		if (pRoot1_ == nullptr)
		{
			_pNewRoot = pRoot2_;
			break;
		}

		// when the second list is empty, we just insert the first list into the tail of
		// the new list.
		if (pRoot2_ == nullptr)
		{
			_pNewRoot = pRoot1_;
			break;
		}

		// when two list both aren't empty, we need the compare them and deside insert
		// which node into the new list.
		if (pRoot1_->m_nValue <= pRoot2_->m_nValue)
		{
			_pNewRoot = pRoot1_;
			pRoot1_ = pRoot1_->m_pNext;
		}
		else
		{
			_pNewRoot = pRoot2_;
			pRoot2_ = pRoot2_->m_pNext;
		}
	}

	return _pNewRoot;
}

// the recursive version of merge lists.
ListNode* MergeList_Recursion(ListNode*& pRoot1_, ListNode*& pRoot2_)
{
	// It will return nullptr when both lists are empty.
	if (pRoot1_ == nullptr && pRoot2_ == nullptr)
		return nullptr;

	// It will return the second list when the first list is empty.
	if (pRoot1_ == nullptr)
	{
		ListNode* _pTemp = pRoot2_;
		pRoot2_ = nullptr;
		return _pTemp;
	}

	// it will return the first list when the second list is empty.
	if (pRoot2_ == nullptr)
	{
		ListNode* _pTemp = pRoot1_;
		pRoot1_ = nullptr;
		return pRoot1_;
	}

	ListNode* _pNewRoot = nullptr;
	if (pRoot1_->m_nValue <= pRoot2_->m_nValue)
	{
		_pNewRoot = pRoot1_;
		pRoot1_ = pRoot1_->m_pNext;
	}
	else
	{
		_pNewRoot = pRoot2_;
		pRoot2_ = pRoot2_->m_pNext;
	}

	// recursive call.
	_pNewRoot->m_pNext = MergeList_Recursion(pRoot1_, pRoot2_);
	return _pNewRoot;
}


/***********   int main() **************/
int main()
{
	return 0;
}
