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
*   Created Time: 2019年04月05日 星期五 10时58分24秒
*	Modifed Time: 2019年04月05日 星期五 13时18分56秒
*   Blog: http://www.cnblogs.com/yinheyi
*   Github: https://github.com/yinheyi
*   
***********************************************************************/

// 题目： 给定一个二叉树和其中的一个节点，如果找出中序遍历中的下一个节点？
// 树的每一个节点不仅有左右子节点，还有父节点,节点定义如下:
BinaryTreeNode
{
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
	BinaryTreeNode* m_pParent;
}

// 分析：既然每一个节点包含了指向父节点的指针，那么我们只要能拿到当前节点（不需要二叉树的
// 根节点了）,就可以知道中序遍历的下一个节点了。
// 具体如下： 此时相当于遍历到了当前节点,那么它的左子节点也肯定已经遍历过了，不需要管了。
// 接下来要遍历的是它的右子节点。如果右子节点存在, 接下来的重点就是如何在右子树上找到我们
// 应该遍历的节点————方法就是：一直沿着右子树的左节点一直找下去，直到叶节点为止就可以了。
// 如果 右子节点不存在，则遍历父节点。

BinaryTreeNode* FindNextNode_InorderTraserval(BinaryTreeNode* pNode_)
{
	// 检测指针是否合法，为空时返回nullptr
	if (!pNode_)
		return nullptr;

	// 接着判断是否存在右子节点，如果存在, 需要从右子树中找到应该遍历的节点, 如果不存在，
	// 则返回nullptr.
	if (pNode_->m_pRight)
	{
		BinaryTreeNode* _pCurrentNode = pNode_->m_pRight;
		// 沿着左子节点一直查找下去，直到叶结点为止, 此时的叶结点就是接下来要遍历的节点
		while (_pCurrentNode->m_pLeft)
			_pCurrentNode = _pCurrentNode->m_pLeft;
		return _pCurrentNode;
	}

	// 如果存在父节点，下一个应该遍历的节点就是父节点
	if (pNode_->m_pParent)
		return pNode_->m_pParent;
	else
		return nullptr;
}


/***********************    上面的解答有误      ******************************/

// 看到书本上的答案之后，发现自己是错的。错误的原因在于：
// 当遍历完当前节点时，接下来需要遍历的是它的右子树，这个是正确的。关键时，如果当右子树不
// 存在时，一定是去遍历父节点吗？？
// 如果当前节点为父节点的左子节点，此时去遍历父节点没有问题，如果当前节点为父节点的右子节
// 点，则肯定不应该去遍历父节点, 这里怎么办？如果找到应该遍历的那个节点呢？
// 此时，我们需要沿着父节点一直向上查找，一直找到这个一个节点，该节点是它父节点的左节点,
// 该节点的父节点就是我们要遍历的节点! 

// 版本1:
BinaryTreeNode* FindNextNode_InorderTraserval(BinaryTreeNode* pNode_)
{
	// 检测指针是否合法，为空时返回nullptr
	if (!pNode_)
		return nullptr;

	// 接着判断是否存在右子节点，如果存在, 需要从右子树中找到应该遍历的节点, 如果不存在，
	// 则返回nullptr.
	if (pNode_->m_pRight)
	{
		BinaryTreeNode* _pCurrentNode = pNode_->m_pRight;
		// 沿着左子节点一直查找下去，直到叶结点为止, 此时的叶结点就是接下来要遍历的节点
		while (_pCurrentNode->m_pLeft)
			_pCurrentNode = _pCurrentNode->m_pLeft;
		return _pCurrentNode;
	}

	BinaryTreeNode* _pParent = pNode_->m_pParent;
	// 当前节点的父节点存在时，分两种情况处理：
	// 1. 如果当前节点是父节点的左节点，则返回父节点
	// 2. 如果当前节点为父节点的右节点时，需要一直查找到满足条件为止;
	// 当前节点的父节点不存在时，返回空;
	if (_pParent)
	{
		if (_pParent->m_pLeft == pNode_)	// 为左节点
			return _pParent;
		else		// 为右节点
		{
			while (_pParent != pRoot_)	// 其中 root表示树的根结点, 参数没有传进来
			{
				BinaryTreeNode* _pGrandpa = _pParent->m_pParent;
				if (_pGrandpa->m_pLeft == _pParent) 
					return _pGrandpa;
				else
					_pParent = _pGrandpa;
			}
			return nullptr;
		}
	}
	else	// 当父节点不存在时，返回空
		return nullptr;
}


// 上面的代码可以简化一下：
// 版本2:
BinaryTreeNode* FindNextNode_InorderTraserval(BinaryTreeNode* pNode_)
{
	// 检测指针是否合法，为空时返回nullptr
	if (!pNode_)
		return nullptr;

	// 接着判断是否存在右子节点，如果存在, 需要从右子树中找到应该遍历的节点, 如果不存在，
	// 则返回nullptr.
	if (pNode_->m_pRight)
	{
		BinaryTreeNode* _pCurrentNode = pNode_->m_pRight;
		// 沿着左子节点一直查找下去，直到叶结点为止, 此时的叶结点就是接下来要遍历的节点
		while (_pCurrentNode->m_pLeft)
			_pCurrentNode = _pCurrentNode->m_pLeft;
		return _pCurrentNode;
	}

	// 当前节点的父节点存在时，分两种情况处理：
	// 1. 如果当前节点是父节点的左节点，则返回父节点
	// 2. 如果当前节点为父节点的右节点时，需要一直查找到满足条件为止;
	// 当前节点的父节点不存在时，返回空;

	BinaryTreeNode* _pCurrentNode = pNode_;
	BinaryTreeNode* _pParent = pNode_->m_pParent;
	while (_pParent && _pParent->m_pRight == _pCurrentNode)
	{
		_pCurrentNode = _pParent;
		_pParent = _pCurrentNode->m_pParent;
	}
	return _pParent;
}
