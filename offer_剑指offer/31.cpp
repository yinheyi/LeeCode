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
*   Created Time: 2019年04月21日 星期日 18时56分12秒
*	Modifed Time: 2019年04月21日 星期日 19时40分21秒
*   Blog: http://www.cnblogs.com/yinheyi
*   Github: https://github.com/yinheyi
*   
***********************************************************************/

#include <stack>
#include <iostream>
// Objec: give you a push-stack sequence, and determine whether anther sequence is pop-stack order.
//
bool IsPopOrder(const int* pPush, const int* pPop, int nLength)
{
	if (pPush == nullptr || pPop == nullptr)
		return true;

	// first, we reversely push the Popsequence into a stack
	std::stack<int> _PopStack;
	for (int i = nLength - 1; i >= 0 ; --i)
	{
		_PopStack.push(pPop[i]);
	}

	// then,
	int _nCount = 0;
	std::stack<int> _PushStack;
	while (_nCount <= nLength && !_PopStack.empty())
	{
		// if the stack is empty, we push a number into it.
		if (_PushStack.empty())
		{
			if (_nCount == nLength)
				break;

			_PushStack.push(pPush[_nCount]);
			++_nCount;
		}

		// if the top of pushStack is not equal to popStack, we push a number into it.
		if (_PushStack.top() != _PopStack.top())
		{
			if (_nCount == nLength)
				break;

			_PushStack.push(pPush[_nCount]);
			++_nCount;
		}
		else	 // if the top of pushStack is equal to popStack, we pop number.
		{
			_PushStack.pop();
			_PopStack.pop();
		}
	}

	if (_PopStack.empty() && _PushStack.empty())
		return true;
	else
		return false;
}

/***************    main.c     *********************/

int main(int argc, char* argv[])
{
	int nLength = 5;
	int pushArray[] = {1, 2, 3, 4, 5};
	int PopArray1[] = {4, 5, 3, 2, 1};
	int PopArray2[] = {4, 3, 5, 1, 2};

	std::cout << IsPopOrder(pushArray, PopArray1, 5) << std::endl;
	std::cout << IsPopOrder(pushArray, PopArray2, 5) << std::endl;
	return 0;
}

