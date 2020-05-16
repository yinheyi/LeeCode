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
*   Created Time: 2019年04月21日 星期日 20时32分08秒
*	Modifed Time: 2019年04月21日 星期日 21时00分33秒
*   Blog: http://www.cnblogs.com/yinheyi
*   Github: https://github.com/yinheyi
*   
***********************************************************************/


#include <iostream>
// 题目：输出所有路径中和为给定值的路径。路径指的是从根节点到叶节点的路径
//
// 二叉树节点的定义
struct BinaryTreeNode
{
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
	BinaryTreeNode(int value = 0, BinaryTreeNode* pLeft = nullptr, BinaryTreeNode* pRight = nullptr);
};

BinaryTreeNode::BinaryTreeNode(int value, BinaryTreeNode* pLeft, BinaryTreeNode* pRight)
{
	m_nValue = value;
	m_pLeft = pLeft;
	m_pRight = pRight;
}

bool IsLeafNode(const BinaryTreeNode* pNode_)
{
	if (pNode_ == nullptr)
		return false;

	if (pNode_->m_pLeft == nullptr && pNode_->m_pRight == nullptr)
		return true;
	else
		return false;
}

void PrintPath(const BinaryTreeNode* pRoot_, int nSum_, int* Sequences_, int nLength_)
{
	if (pRoot_ == nullptr)
		return;

	// 当不是叶结点时
	if (!IsLeafNode(pRoot_))
	{
		int _nCurrentValue = pRoot_->m_nValue;
		if (_nCurrentValue >= nSum_)
			return;

		if (pRoot_->m_pLeft != nullptr)
		{
			Sequences_[nLength_] = _nCurrentValue;
			PrintPath(pRoot_->m_pLeft, nSum_-_nCurrentValue, Sequences_, nLength_ + 1);
		}

		if (pRoot_->m_pRight != nullptr)
		{
			Sequences_[nLength_] = _nCurrentValue;
			PrintPath(pRoot_->m_pRight, nSum_-_nCurrentValue, Sequences_, nLength_ + 1);
		}
	}
	else
	{
		int _nCurrentValue = pRoot_->m_nValue;
		if (_nCurrentValue == nSum_)
		{
			for (int i = 0; i < nLength_; ++i)
				std::cout << Sequences_[i] << " ";
			std::cout << _nCurrentValue << std::endl;
		}
	}
}


/***************    main.c     *********************/
int main(int argc, char* argv[])
{
	BinaryTreeNode* _p4 = new BinaryTreeNode(4);
	BinaryTreeNode* _p7 = new BinaryTreeNode(7);
	BinaryTreeNode* _p5 = new BinaryTreeNode(5, _p4, _p7);
	BinaryTreeNode* _p12 = new BinaryTreeNode(12);
	BinaryTreeNode* _pRoot = new BinaryTreeNode(10, _p5, _p12);

	int array[100] = {0};
	PrintPath(_pRoot, 22, array, 0);
	return 0;
}

