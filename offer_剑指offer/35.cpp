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
*   Created Time: 2019年04月21日 星期日 22时51分34秒
*	Modifed Time: 2019年04月21日 星期日 23时11分38秒
*   Blog: http://www.cnblogs.com/yinheyi
*   Github: https://github.com/yinheyi
*   
***********************************************************************/


// 题目：copy一个复杂的链表
struct ComplexListNode
{
	int m_nValue;
	ComplexListNode* m_pNext;
	ComplexListNode* m_pSibling;
};

void Copy(ComplexListNode* pRoot_)
{
	if (pRoot_ == nullptr)
		return;

	ComplexListNode* _pCurrentNode = pRoot_;
	while (_pCurrentNode != nullptr)
	{
		ComplexListNode* _pNew = new ComplexListNode;
		_pNew->m_nValue = _pCurrentNode->m_nValue;
		_pNew->m_pNext = _pCurrentNode->m_pNext;

		_pCurrentNode->m_pNext = _pNew;
		_pCurrentNode = _pNew->m_pNext;
	}
}

void SetSibling(ComplexListNode* pRoot_)
{
	if (pRoot_ == nullptr)
		return;

	ComplexListNode* _pCurrentNode = pRoot_;
	while (_pCurrentNode != nullptr)
	{
		ComplexListNode* _pNew = _pCurrentNode->m_pNext;
		if (_pCurrentNode->m_pSibling != nullptr)
		{
			_pNew->m_pSibling = _pCurrentNode->m_pSibling->m_pNext;
		}

		_pCurrentNode = _pNew->m_pNext;
	}
}

ComplexListNode* ReconnectNode(ComplexListNode* pHead_)
{
	if (pHead_ == nullptr)
		return nullptr;

	ComplexListNode* _pResult = pHead_->m_pNext;
	pHead_->m_pNext = _pResult->m_pNext;

	ComplexListNode* _pCurrentNode = pHead_->m_pNext;
	ComplexListNode* _pNewCurrentNode = _pResult;
	while (_pCurrentNode != nullptr)
	{
		_pNewCurrentNode->m_pNext = _pCurrentNode->m_pNext;
		_pNewCurrentNode = _pNewCurrentNode->m_pNext;

		_pCurrentNode->m_pNext = _pNewCurrentNode->m_pNext;
		_pCurrentNode = _pCurrentNode->m_pNext;
	}

	return _pResult;

}

ComplexListNode* Clone(ComplexListNode* pHead_)
{
	Copy(pHead_);
	SetSibling(pHead_);
	return ReconnectNode(pHead_);
}

/***************    main.c     *********************/
int main(int argc, char* argv[])
{
	return 0;
}

