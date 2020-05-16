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
*   Created Time: 2019年05月03日 星期五 17时51分56秒
*   Modifed Time: 2019年05月03日 星期五 22时08分27秒
*   Blog: http://www.cnblogs.com/yinheyi
*   Github: https://github.com/yinheyi
*   
***********************************************************************/


// 题目一：求二叉树的深度
// 使用深度优先搜索来解决。
struct BinaryTreeNode
{
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};

// 自己想的方法
void DepthofBinaryTree(BinaryTreeNode* pRoot_, int nDepth_, int& nMaxDepth_)
{
	if (pRoot_ == nullptr)
		return;

	if (nDepth_ > nMaxDepth_)
	{
		nMaxDepth_ = nDepth_;
	}

	DepthofBinaryTree(pRoot_->m_pLeft, nDepth_ + 1, nMaxDepth_);
	DepthofBinaryTree(pRoot_->m_pRight, nDepth_ + 1, nMaxDepth_);
}


// 书中答案更简单
int TreeDepth(BinaryTreeNode* pRoot_)
{
	if (pRoot_ == nullptr)
		return 0;
	int nLeftDepth = TreeDepth(pRoot_->m_pLeft);
	int nRightDepth = TreeDepth(pRoot_->m_pRight);

	return nLeftDepth > nRightDepth ? (nLeftDepth + 1) : (nRightDepth + 1);
}


// 题目二：判断一个树是不是一棵平衡二叉树。
#define MAX(x,y) ((x) > (y) ? (x) : (y))
#define ABS(x) ((x) > 0 ? (x) : -1*(x))
bool IsBalancedTree(BinaryTreeNode* pRoot_, int& nDepth_)
{
	if (pRoot_ == nullptr)
	{
		nDepth_ = 0;
		return true;
	}

	int nLeftDepth = 0;
	bool _bLeft = IsBalancedTree(pRoot_->m_pLeft, nLeftDepth);
	int nRightDepth = 0;
	bool _bRight = IsBalancedTree(pRoot_->m_pRight, nRightDepth);
	nDepth_ = MAX(nLeftDepth,nRightDepth) + 1;
	if (_bLeft && _bRight && ABS(nLeftDepth - nRightDepth) <= 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/***************    main.c     *********************/
int main(int argc, char* argv[])
{
	return 0;
}

