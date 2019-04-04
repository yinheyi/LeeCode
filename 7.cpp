/***********************************************************************
*   Copyright (C) 2019  Yinheyi. <chinayinheyi@163.com>
*   
* This program is free software; you can redistribute it and/or
* modify it under the terms of the GNU General Public License
* as published by the Free Software Foundation; either version
* 2 of the License, or (at your option) any later version.

*   Brief:    
*   Author: yinheyi
*   Email: chinayinheyi@163.com
*   Version: 1.0
*   Created Time: 2019年04月04日 星期四 17时40分42秒
*	Modifed Time: 2019年04月04日 星期四 23时49分24秒
*   Blog: http://www.cnblogs.com/yinheyi
*   Github: https://github.com/yinheyi
*   
***********************************************************************/

#include <iostream>
#include <vector>
#include <stack>

using std::stack;
using std::cout;
using std::endl;

// 题目: 根据前序与中序遍历的结果，重建二叉树, 二叉树的节点表示如下:
struct BinaryTreeNode
{
	BinaryTreeNode();		//构造函数
	BinaryTreeNode(int nValue_);

	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};

BinaryTreeNode::BinaryTreeNode()
{
	m_nValue = 0;
	m_pLeft = nullptr;
	m_pRight = nullptr;
}
BinaryTreeNode::BinaryTreeNode(int nValue_)
{
	m_nValue = nValue_;
	m_pLeft = nullptr;
	m_pRight = nullptr;
}


// 在看答案之前，我的思路:
// 1. 根据前序遍历我可以拿到根节点的值，
// 2. 接着可能通过根节点的值把中序遍历的顺序分为左子树和右子树的中序遍历, 
// 3. 接着我又可以根据左子树和右子数的数目把前序遍历的顺序分为左子数的前序遍历和右子数的前序遍历
// 4. 到此时，我们有了左子树的中序遍历和右子树的中序遍历，我们就可以用递归来来解决了。

typedef std::vector<int> sequence;
BinaryTreeNode* Rebulid_BTree(sequence& PreorderSequence_, sequence& InorderSequence_)
{
	// 为空时，返回空树
	if (PreorderSequence_.empty() || InorderSequence_.empty())
		return nullptr;

	// 初始化一个迭代器，并指向指向中序遍历序列中root的值所在位置.
	sequence::iterator _itRootValue = InorderSequence_.begin();
	int _nRootValue = PreorderSequence_.front();
	while (*_itRootValue != _nRootValue)
		++_itRootValue;

	// 此时，我们可以得到左子树与右子树的中序遍历了
	sequence _LeftInorderSequence(InorderSequence_.begin(), _itRootValue);
	sequence _RightInorderSequence(_itRootValue + 1, InorderSequence_.end());

	// 根据左子树与右子树的数目，我们又可以得到左子树与右子树的前序遍历了
	int _nLeftNum = _LeftInorderSequence.size();
	int _nRightNum = _RightInorderSequence.size();
	sequence _LeftPreorderSequence(PreorderSequence_.begin() + 1,
									PreorderSequence_.begin() + 1 + _nLeftNum);
	sequence _RightPreorderSequence(PreorderSequence_.begin() + 1 + _nLeftNum,
									PreorderSequence_.end());
	
	// 接下来， 就可以重建二叉树了
	BinaryTreeNode* _pRoot = new BinaryTreeNode(_nRootValue);
	_pRoot->m_pLeft = Rebulid_BTree(_LeftPreorderSequence, _LeftInorderSequence);
	_pRoot->m_pRight = Rebulid_BTree(_RightPreorderSequence, _RightInorderSequence);
	return _pRoot;
}

// 书上的答案: 采用的是数组完成的，所以传递的是数组的下标指针， 可读性软差一下，但是想比我写的代码执行速度快。

/*************************  为测试而写的  ************************/
// 说明： 1. 基于递归的遍历方法实现方便，代码简洁，但是如果递归过深，可能栈溢出，不安全.
// 		  2. 基于循环的遍历实现方法， 都需要借助栈数据结构来实现, 永远抓住一点：无论是前序
// 		     遍历/中序遍历/后序遍历，永远保持栈顶是我们接下来应该遍历的那个node.
// 		  
// 前序遍历	----基于递归
void PreorderTraversal(BinaryTreeNode* pRoot_)
{
	if (pRoot_ == nullptr)
		return;

	std::cout << pRoot_->m_nValue << " ";
	PreorderTraversal(pRoot_->m_pLeft);
	PreorderTraversal(pRoot_->m_pRight);
}

// 前序遍历	----基于循环
void PreorderTraversal_ByCycle(BinaryTreeNode* pRoot_)
{
	if (pRoot_ == nullptr)
		return;

	// 需要使用到栈数据结构, 先把右子树放到栈中，再把左子树放到栈中
	stack<BinaryTreeNode*> _StackNodes;
	_StackNodes.push(pRoot_);
	while (!_StackNodes.empty())
	{
		BinaryTreeNode* _pCurrentNode = _StackNodes.top();
		_StackNodes.pop();
		if (_pCurrentNode != nullptr)
		{
			std::cout << _pCurrentNode->m_nValue << " ";
			_StackNodes.push(_pCurrentNode->m_pRight);
			_StackNodes.push(_pCurrentNode->m_pLeft);
		}

	}
}

// 中序遍历 ---- 基于递归
void InorderTraversal(BinaryTreeNode* pRoot_)
{
	if (pRoot_ == nullptr)
		return;

	InorderTraversal(pRoot_->m_pLeft);
	std::cout << pRoot_->m_nValue << " ";
	InorderTraversal(pRoot_->m_pRight);
}

// 中序遍历 ---- 基于循环
void InorderTraversal_ByCycle(BinaryTreeNode* pRoot_)
{
	if (pRoot_ == nullptr)
		return;

	// 初始化一个栈数据结构
	std::stack<BinaryTreeNode*> _StackNodes;

	// 先一股脑地把左子节点放到的栈中， 因为这时栈顶的叶结点就是我们遍历的起点
	BinaryTreeNode* _pCurrentNode = pRoot_;
	while (_pCurrentNode != nullptr)
	{
		_StackNodes.push(_pCurrentNode);
		_pCurrentNode = _pCurrentNode->m_pLeft; 
	}

	while (!_StackNodes.empty())
	{
		// 遍历栈顶的节点
		BinaryTreeNode* _pCurrentNode = _StackNodes.top();
		_StackNodes.pop();
		std::cout << _pCurrentNode->m_nValue << " ";

		// 即然遍历到了当前的节点，说明了它的左子树已经遍历完了，不需要管了。 我们现在
		// 需要关注的是：当前节点的右子树是否为空了, 如果不为空，则需要去处理一下了。
		_pCurrentNode = _pCurrentNode->m_pRight;
		while (_pCurrentNode != nullptr)
		{
			_StackNodes.push(_pCurrentNode);
			_pCurrentNode = _pCurrentNode->m_pLeft; 
		}
	}
}

// 后序遍历 ---- 基于递归
void PostorderTraversal(BinaryTreeNode* pRoot_)
{
	if (pRoot_ == nullptr)
		return;

	PostorderTraversal(pRoot_->m_pLeft);
	PostorderTraversal(pRoot_->m_pRight);
	std::cout << pRoot_->m_nValue << " ";
}

// 后序遍历 ---- 基于循环
void PostorderTraversal_ByCycle(BinaryTreeNode* pRoot_)
{
	if (pRoot_ == nullptr)
		return;

	// 使用一个栈的数据结构
	std::stack<BinaryTreeNode*> _StackNodes;

	// 把我们查找第一个应该遍历的node的路径上经过的所有node按顺序一股脑地压入栈中
	BinaryTreeNode* _pCurrentNode = pRoot_;
	while (_pCurrentNode != nullptr)
	{
		_StackNodes.push(_pCurrentNode);
		// 优先选择不为空的左节点，如果左节点为空，再考虑右节点（右节点为空也没有关系）
		if (_pCurrentNode->m_pLeft != nullptr)
			_pCurrentNode = _pCurrentNode->m_pLeft;
		else
			_pCurrentNode = _pCurrentNode->m_pRight;
	}

	while (!_StackNodes.empty())
	{
		// 遍历栈顶的节点
		BinaryTreeNode* _pCurrentNode = _StackNodes.top();
		_StackNodes.pop();
		std::cout << _pCurrentNode->m_nValue << " ";

		// 既然遍历到了当前节点，说明它的左子树与右子树都遍历完了，不需要管了。我们现在
		// 需要关注的是： 如果当前节点为父节点的左节点，则需要判断父节点的右节点是否为空.
		// 如果不为空，则需要去处理父节点的右节点了。
		//
		// 另外，如果当前节点不右父节点的右节点，也不需要管，因为接下来会去遍历父节点。
		if (!_StackNodes.empty() && _pCurrentNode == _StackNodes.top()->m_pLeft)
		{
			_pCurrentNode = _StackNodes.top()->m_pRight;
			while (_pCurrentNode != nullptr)
			{
				_StackNodes.push(_pCurrentNode);
				if (_pCurrentNode->m_pLeft != nullptr)
					_pCurrentNode = _pCurrentNode->m_pLeft;
				else
					_pCurrentNode = _pCurrentNode->m_pRight;
			}
		}
	}
}

/*****************  主函数   ************************/
int main()
{
	// 初始化前序遍历与中序遍历序列
	sequence _PreorderSequence{1, 2, 4, 7, 3, 5, 6, 8};
	sequence _InorderSequence{4, 7, 2, 1, 5, 3, 8, 6};

	// 重建二叉树
	BinaryTreeNode* _pRoot = Rebulid_BTree(_PreorderSequence, _InorderSequence);

	// 分别执行前序.中序与后序遍历
	cout << " 前序遍历的结果为: " << endl;
	PreorderTraversal(_pRoot);
	cout << endl;

	cout << " 前序遍历的结果为: " << endl;
	PreorderTraversal_ByCycle(_pRoot);
	cout << endl;

	cout << " 中序遍历的结果为: " << endl;
	InorderTraversal(_pRoot);
	cout << endl;

	cout << " 中序遍历的结果为: " << endl;
	InorderTraversal_ByCycle(_pRoot);
	cout << endl;

	cout << " 后序遍历的结果为: " << endl;
	PostorderTraversal(_pRoot);
	cout << endl;

	cout << " 后序遍历的结果为: " << endl;
	PostorderTraversal_ByCycle(_pRoot);
	cout << endl;

	return 0;
}
