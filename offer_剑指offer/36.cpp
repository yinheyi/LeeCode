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
*   Created Time: 2019年04月21日 星期日 23时15分39秒
*	Modifed Time: 2019年04月22日 星期一 00时54分56秒
*   Blog: http://www.cnblogs.com/yinheyi
*   Github: https://github.com/yinheyi
*   
***********************************************************************/


// 使用双向链表把二叉搜索树原来的节点连接起来。
struct BinaryTreeNode
{
	int m_nvalue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
	BinaryTreeNode();
};
BinaryTreeNode::BinaryTreeNode()
{
	m_nvalue = 0;
	m_pLeft = nullptr;
	m_pRight = nullptr;
}

// return the max node of a binary search tree.
BinaryTreeNode* GetMaxNode(BinaryTreeNode* pRoot_)
{
	if (pRoot_ == nullptr)
		return nullptr;

	if (pRoot_->m_pRight == nullptr)
		return pRoot_;
	else
		return GetMaxNode(pRoot_->m_pRight);
}

// return the max node of a binary search tree.
BinaryTreeNode* GetMinNode(BinaryTreeNode* pRoot_)
{
	if (pRoot_ == nullptr)
		return nullptr;

	if (pRoot_->m_pLeft == nullptr)
		return pRoot_;
	else
		return GetMaxNode(pRoot_->m_pLeft);
}

// Connect a node.
BinaryTreeNode* Convert(BinaryTreeNode* pRoot_)
{
	if (pRoot_ == nullptr)
		return nullptr;

	// the return value;
	BinaryTreeNode* _pResult = GetMinNode(pRoot_);

	// convert the left subtree and right subtree.
	BinaryTreeNode* _pLeftSubtree = pRoot_->m_pLeft;
	if (_pLeftSubtree != nullptr)
	{
		BinaryTreeNode* _pPreNode = GetMaxNode(_pLeftSubtree);
		Convert(_pLeftSubtree);

		pRoot_->m_pLeft = _pPreNode;
		_pPreNode->m_pRight = pRoot_;
	}

	BinaryTreeNode* _pRightSubtree = pRoot_->m_pRight;
	if (_pRightSubtree != nullptr)
	{
		BinaryTreeNode* _pNextNode = GetMinNode(_pRightSubtree);
		Convert(_pRightSubtree);

		pRoot_->m_pRight = _pNextNode;
		_pNextNode->m_pLeft = pRoot_;
	}

	return _pResult;
}

/***************    main.c     *********************/
int main(int argc, char* argv[])
{
	return 0;
}

