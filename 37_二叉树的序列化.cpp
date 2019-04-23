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
*   Created Time: 2019年04月23日 星期二 21时49分54秒
*	Modifed Time: 2019年04月23日 星期二 22时05分58秒
*   Blog: http://www.cnblogs.com/yinheyi
*   Github: https://github.com/yinheyi
*   
***********************************************************************/

#include <fstream>
// 利用类似中序遍历的方法，对二叉树进行序列化与反序列化
struct BinaryTreeNode
{
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
	BinaryTreeNode();
};
BinaryTreeNode::BinaryTreeNode()
{
	m_nValue = 0;
	m_pLeft = nullptr;
	m_pRight = nullptr;
}

// 反序列化函数
void Deserialize(BinaryTreeNode** pRoot_, istream& stream)
{
	int _nNumber;
	if (ReadStream(stream, &_nNumber))
	{
		*pRoot_ = new BinaryTreeNode();
		(*pRoot_)->m_nValue = _nNumber;
		(*pRoot_)->m_pLeft = nullptr;
		(*pRoot_)->m_pRight = nullptr;

		Deserialize(&((*pRoot_)->m_pLeft), stream);
		Deserialize(&((*pRoot_)->m_pRight), stream);
	}
}

// 序列化函数
void Serialize(BinaryTreeNode* pRoot_, ostream& stream)
{
	if (pRoot_ == nullptr)
	{
		stream << "$";
		return;
	}

	stream << pRoot_->m_nValue << " ";
	Serialize(pRoot_->m_pLeft, stream);
	Serialize(pRoot_->m_pRight, stream);
}

/***************    main.c     *********************/
int main(int argc, char* argv[])
{
	return 0;
}

