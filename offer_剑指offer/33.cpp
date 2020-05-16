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
*   Created Time: 2019年04月21日 星期日 20时14分06秒
*	Modifed Time: 2019年04月21日 星期日 20时31分27秒
*   Blog: http://www.cnblogs.com/yinheyi
*   Github: https://github.com/yinheyi
*   
***********************************************************************/

//题目：判断一个序列是否为二叉搜索树的后序遍历
// 1. 二叉搜索树的特点是：左节点 < 父节点 < 右节点
// 后序遍历的特点为: 最后遍历父节点。如果给定我们一个序列，我们可以确定最后一个为根节点
// 的值.然后我们可以找到左子树和右子树。再使用递归进行不断的判断。
bool IsPostTraversal(const int* pSequences_, int nLength)
{
	// empty tree
	if (pSequences_ == nullptr)
		return true;

	int _nRootValue = pSequences_[nLength - 1];

	// to find left Subtree
	int _nLeftCount = 0;
	while (pSequences_[_nLeftCount] < _nRootValue)
	{
		++_nLeftCount;
	}

	// to find right Subtree
	int _nRightCount = 0;
	while (pSequences_[_nLeftCount + _nRightCount] > _nRootValue)
	{
		++_nRightCount;
	}

	return IsPostTraversal(pSequences_, _nLeftCount)
			&& IsPostTraversal(pSequences_ + _nLeftCount, _nRightCount);
}

/***************    main.c     *********************/
int main(int argc, char* argv[])
{
	return 0;
}

