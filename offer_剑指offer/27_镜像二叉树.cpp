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
*   Created Time: 2019年04月16日 星期二 22时35分51秒
*	Modifed Time: 2019年04月16日 星期二 22时56分08秒
*   Blog: http://www.cnblogs.com/yinheyi
*   Github: https://github.com/yinheyi
*   
***********************************************************************/


// Object: Define a function to mirror a Binary Tree. The Binary Tree Node is defined as
// follows:
struct BinaryTreeNode
{
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
	BinaryTreeNode();
};
// Binary Tree Node's constructor
BinaryTreeNode::BinaryTreeNode()
{
	m_nValue = 0;
	m_pLeft = nullptr;
	m_pRight = nullptr;
}

// Thinking: To mirror a Binary Tree is essentially to exchange left and right subtrees
// recursively. So we can write code like this:
void MirrorBinaryTree(BinaryTreeNode* pRoot_)
{
	// when the argument is nullptr, we exit the function directly.
	if (pRoot_ == nullptr)
		return;

	// Exchange left and right children of the binary tree.
	BinaryTreeNode* _pTemp = pRoot_->m_pLeft;
	pRoot_->m_pLeft = pRoot_->m_pRight;
	pRoot_->m_pRight = _pTemp;
	_pTemp = nullptr;

	// Call itself to handle left and right children recursively.
	MirrorBinaryTree(pRoot_->m_pLeft);
	MirrorBinaryTree(pRoot_->m_pRight);
}

/******************    main function     ***********************/
int main()
{
	return 0;
}
