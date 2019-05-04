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
*   Created Time: 2019年05月04日 星期六 10时57分17秒
*   Modifed Time: 2019年05月04日 星期六 13时43分02秒
*   Blog: http://www.cnblogs.com/yinheyi
*   Github: https://github.com/yinheyi
*   
***********************************************************************/


// 题目：和为s的两个数字。
// 输入一个递增的排序的数组和一个数字s，在数组中查找两个数， 使得它的和正好是要s。
// 如果有多对数字的和等于s，则输出任意一对即可。
//
// 思路：先使用二分法在数组中找到大于等于s的下标，然后从前半部分中找到符合要求的两个数。
//
// 代码如下：
#include <cassert>
#include <iostream>

// 下面函数实现二分法查找大于等于给定值的下标。
int GetIndexByDichotomy(int array[], int nStart_, int nEnd_, int Key)
{
	if (array == nullptr || nStart_ >= nEnd_)
		return -1;

	// 如果是一个元素时，返回该元素的下标。
	if (nEnd_ - nStart_ == 1)
	{
		assert(array[nStart_] >= Key);
		return nStart_;
	}

	int _nMiddle = (nEnd_  - nStart_) / 2 + nStart_;
	if (array[_nMiddle] == Key || (array[_nMiddle] > Key && array[_nMiddle - 1] < Key))
	{
		return _nMiddle;
	}
	else if (array[_nMiddle] > Key)
	{
		return GetIndexByDichotomy(array, nStart_, _nMiddle, Key);
	}
	else
	{
		return GetIndexByDichotomy(array, _nMiddle, nEnd_, Key);
	}
}

// 下面函数实现两数之和等于给定值的两个整数。
void GetTwoNumber(int array[], int nLength_, int key, int& number1, int& number2)
{
	if (array == nullptr || nLength_ <= 1)
		return;

	int nIndex = GetIndexByDichotomy(array, 0, nLength_, key);
	int _nBegin = 0;
	int _nEnd = nIndex - 1;
	while (_nBegin < _nEnd)
	{
		int sum = array[_nBegin] + array[_nEnd];
		if (sum < key)
		{
			++_nBegin;
		}
		else if (sum == key)
		{
			number1 = array[_nBegin];
			number2 = array[_nEnd];
			break;
		}
		else
		{
			--_nEnd;
		}
	}
}

/***************    main.c     *********************/
int main(int argc, char* argv[])
{

	int test1[6] = {1, 2, 4, 7, 11, 15};
	int number1 = 0;
	int number2 = 0;
	GetTwoNumber(test1, 6, 15, number1, number2);
	std::cout << number1 << " " << number2 << std::endl;
	return 0;
}

