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
*   Created Time: 2019年05月03日 星期五 17时20分49秒
*   Modifed Time: 2019年05月03日 星期五 17时51分24秒
*   Blog: http://www.cnblogs.com/yinheyi
*   Github: https://github.com/yinheyi
*   
***********************************************************************/

// 题目：找出二叉搜索树中第k大的数。
// 使用二叉树的中序遍历来解决。
struct BinaryTreeNode
{
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};

BinaryTreeNode* KthNode(BinaryTreeNode* pRoot_, int& k)
{
	if (pRoot_ == nullptr || k <= 0)
		return nullptr;

	// 左子树
	BinaryTreeNode* _pResult = KthNode(pRoot_->m_pLeft, k);
	if (_pResult != nullptr)
		return _pResult;

	// 中间结点
	--k;
	if (k == 0)
		return pRoot_;

	// 右子树
	return KthNode(pRoot_->m_pRight, k);
}

/***************    main.c     *********************/
int main(int argc, char* argv[])
{
	return 0;
}

