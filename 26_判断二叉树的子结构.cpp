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
*   Created Time: 2019年04月15日 星期一 23时11分22秒
*	Modifed Time: 2019年04月16日 星期二 22时26分30秒
*   Blog: http://www.cnblogs.com/yinheyi
*   Github: https://github.com/yinheyi
*   
***********************************************************************/

#include <stdexcept>
// Subject: Determine where Binary Tree B is substructure of Binary Tree A.
// The Binary Node is defined as foolows:
struct BinaryTreeNode
{
	double m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
	BinaryTreeNode();
};
// Constructor
BinaryTreeNode::BinaryTreeNode()
{
	m_nValue = 0.0;
	m_pLeft = nullptr;
	m_pRight = nullptr;
}

// Thinking: define a function to determine if Tree B is substructure of Binary Tree A  
// using recursive struct.
// the input are two pointer to Node, the return value is boolean value.
#define DOUBLE_EQU(x,y) ((x) - (y) <= 1.0e-9 || (x) - (y) >= -1.0e-9)
typedef bool (*pFunc)(const BinaryTreeNode*, const BinaryTreeNode*);
bool IsSubstructure(const BinaryTreeNode* pNodeA_, const BinaryTreeNode* pNodeB_)
{
	// when them both are nullptr, return true;
	if (pNodeA_ == nullptr && pNodeB_ == nullptr)
		return true;

	// when one of them is nullptr, return false;
	if (pNodeA_ == nullptr || pNodeB_ == nullptr)
		return false;

	// when the values of them are not equal, return false;
	if (!DOUBLE_EQU(pNodeA_->m_nValue, pNodeB_->m_nValue))
		return false;

	 return IsSubstructure(pNodeA_->m_pLeft, pNodeB_->m_pLeft)
		 && IsSubstructure(pNodeA_->m_pRight, pNodeB_->m_pRight);
}

// the Preorder traveral of Binary Tree.
bool PreorderTraveral(const BinaryTreeNode* pRootA_,
					  const BinaryTreeNode* pRootB_, pFunc pFunc_)
{
	if (pRootA_ == nullptr && pRootB_ == nullptr)
		return true;

	if (pRootA_ == nullptr || pRootB_ == nullptr)
		return false;

	if (pFunc_ == nullptr)
		throw std::invalid_argument("输入的参数非法");

	if (pFunc_(pRootA_, pRootB_))
		return true;
	else
		return PreorderTraveral(pRootA_->m_pLeft, pRootB_, pFunc_)
			|| PreorderTraveral(pRootA_->m_pRight, pRootB_, pFunc_);
}

/************  main.c      ****************/
int main()
{
	return 0;
}
