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
*   Created Time: 2019年04月26日 星期五 22时31分31秒
*   Modifed Time: 2019年04月26日 星期五 23时18分38秒
*   Blog: http://www.cnblogs.com/yinheyi
*   Github: https://github.com/yinheyi
*   
***********************************************************************/

#include <iostream>
#include <stdexcept>
#include <cassert>
// 题目：输入n个数，找出最小的k个数。
//
// 思路：借助快速排序的想法: 1. 把数组分为两部分，前半部分小于后半部分. 
// 2. 如果前半部分的个数大于k, 则再从前半部分中找出k个数。
// 3. 如果前半部分的个数为m,并且小于k, 则再从后半部分中找出k-m个数字即可。
//
//
// 数组中两个数字的交换函数, 函数调用者应该保证数组下标的正确性。
void swap(int* array, int lhs, int rhs)		// left hand side and right hand side
{
	int nTemp = array[lhs];
	array[lhs] = array[rhs];
	array[rhs]  = nTemp;
}


// 输出给定数组内的值
void OutputArray(int array[], int nLength)
{
	if (array == nullptr || nLength <= 0)
		return;

	for (int i = 0; i < nLength; ++i)
	{
		std::cout << array[i] << " ";
	}
}


// 把数组分为两部分的函数
// 说明：使用[start, end) 表示数组的范围。
// 当数组为空时，返回 start的值。
int Partition(int array[], int nLength, int nStart, int nEnd)
{
	// 参数的合法性检测
	if (array == nullptr || nLength < 0
			|| nStart < 0 || nStart > nLength - 1
			|| nEnd < 0 || nEnd > nLength
			|| nStart - nEnd > 0)
	{
		assert(false);
		throw std::invalid_argument("输入的参数不合法");
	}

	// 数组为空时，返回nStart的值
	if (nStart == nEnd)
		return nStart;

	// 真正对数组进行分半
	int nRef = array[nStart];		// 选择数组中的第一个数作为基准数字
	int nGreaterEqualIndex = nStart;
	for (int i = nStart + 1; i < nEnd; ++i)
	{
		if (array[i] < nRef)
		{
			swap(array, i, nGreaterEqualIndex);
			++nGreaterEqualIndex;
		}
	}

	// 如果选择的基准数字为数组中最小的数字，则分为[该数字]和[剩余数字]两部分。
	// 否则的话，分为[小于基准数字]和[大于或等于基准数字]两部分。
	if (nGreaterEqualIndex == nStart)
		return nGreaterEqualIndex + 1;
	else
		return nGreaterEqualIndex;
}


 void OutputNumbers(int array[], int nLength, int k)
{
	// 参数的合法性检测
	if (array == nullptr || nLength < 0 || nLength < k || k < 0)
	{
		assert(false);
		throw std::invalid_argument("输入的参数不合法");
	}

	// 如果数组为空时，什么也不做
	if (nLength == 0)
		return;

	int nIndex = Partition(array, nLength, 0, nLength);
	if (nIndex < k)
	{
		OutputArray(array, nIndex);
		OutputNumbers(array + nIndex, nLength - nIndex, k - nIndex);
	}
	else if (nIndex == k)
	{
		OutputArray(array, nIndex);
	}
	else
	{
		OutputNumbers(array, nIndex, k);
	}
}


/***************    main.c     *********************/
int main(int argc, char* argv[])
{
	while (true)
	{
		int array[10] = {0};
		std::cout << "Input Ten Integer: ";
		for (int i = 0; i < 10; ++i)
		{
			int a;
			std::cin >> array[i];
		}
		std::cout << std::endl;
		OutputNumbers(array, 10, 5);
		std::cout << std::endl;
	}
	return 0;
}

