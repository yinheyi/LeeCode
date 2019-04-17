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
*   Created Time: 2019年04月17日 星期三 21时45分56秒
*	Modifed Time: 2019年04月17日 星期三 23时25分13秒
*   Blog: http://www.cnblogs.com/yinheyi
*   Github: https://github.com/yinheyi
*   
***********************************************************************/

#include <vector>
#define IN 
#define OUT 
// Subject: Write a function to determine whether a Binary Tree is a symmetrical. 
// Thinking: Look at a symmetrical Binary Tree, we will find that if a Binary Tree is 
// symmetrical, the Sequences of inorder traversal is also symmetrical. So ,we can write
// our code quickly.
//
struct BinaryTreeNode
{
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
	BinaryTreeNode();
};
typedef std::vector<const BinaryTreeNode*> vecNodes;
// The constructor of Binary Tree Node.
BinaryTreeNode::BinaryTreeNode()
{
	m_nValue = 0;
	m_pLeft = nullptr;
	m_pRight = nullptr;
}

// node collector function
void CollectNode(IN const BinaryTreeNode* CurrentNode_, 
				IN OUT vecNodes& NodeContainter_)
{
	NodeContainter_.push_back(CurrentNode_);
}
typedef void (*callback)(IN const BinaryTreeNode*, IN OUT vecNodes&);

// Inorder traversal function for a binary tree.
void InorderTraversal(IN const BinaryTreeNode* pRoot_, IN callback pFunc_,
						IN OUT vecNodes& NodeContainer_)
{
	// In order to distingguish the situation where the nodes'values are all same but
	// the binary tree is not symmetrical, we also should collect nullptr pointer.
	if (pRoot_ == nullptr)
	{
		pFunc_(pRoot_, NodeContainer_);
		return;
	}

	// others
	InorderTraversal(pRoot_->m_pLeft, pFunc_, NodeContainer_);
	pFunc_(pRoot_, NodeContainer_);
	InorderTraversal(pRoot_->m_pRight, pFunc_, NodeContainer_);
}

// The return value is a boolean type that indicate the result.
// The pRoot_ is the root of a Binary Tree to estimated.
bool IsSymmetricalBinaryTree(const BinaryTreeNode* pRoot_)
{
	// if the binary tree is empty, we shoud return true;
	if (pRoot_ == nullptr)
		return true;

	// define a vector to store the inorder traversal sequences of the tree.
	vecNodes _NodeContainer;
	InorderTraversal(pRoot_, CollectNode, _NodeContainer);

	// Do Test whether the sequences is symmetrical.
	unsigned int _nSize = _NodeContainer.size();
	if (_nSize <= 1)
		return true;

	unsigned int _nStart = 0;
	unsigned int _nEnd = _nSize - 1;
	while (_nStart < _nEnd)
	{
		if (_NodeContainer[_nStart] == nullptr && _NodeContainer[_nEnd] == nullptr)
		{
			++_nStart;
			--_nEnd;
			continue;
		}

		if (_NodeContainer[_nStart]->m_nValue != _NodeContainer[_nEnd]->m_nValue)
		{
			return false;
		}
		else
		{
			++_nStart;
			--_nEnd;
			continue;
		}
	}
	return true;
}

// the answer in the book
// It is so clean !!!!!!!!1
bool IsSymmetrical_Core(BinaryTreeNode* pFirst_, BinaryTreeNode* pSecond_)
{
	if (pFirst_ == nullptr && pSecond_ == nullptr)
		return true;
	if (pFirst_ == nullptr || pSecond_ == nullptr)
		return false;
	if (pFirst_->m_nValue != pSecond_->m_nValue)
		return false;
	return IsSymmetrical_Core(pFirst_->m_pLeft, pSecond_->m_pRight)
		&& IsSymmetrical_Core(pFirst_->m_pRight, pSecond_->m_pLeft);
}

bool isSymmetrical(BinaryTreeNode* pRoot_)
{
	return IsSymmetrical_Core(pRoot_, pRoot_);
}

/*******************    main.c     ***************/
int main()
{
	return 0;
}
