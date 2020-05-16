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
*   Created Time: 2019年05月03日 星期五 14时51分57秒
*   Modifed Time: 2019年05月03日 星期五 16时12分35秒
*   Blog: http://www.cnblogs.com/yinheyi
*   Github: https://github.com/yinheyi
*   
***********************************************************************/

// 题目一：求一个数在排序数组中的出现的个数。
// 例如一个排序数组为{1, 2, 3, 3, 3, 3, 4, 5}，则数字3在排序数组中出现的次数为4.
//
// 想法：想到了使用二分法再查找那个数，然后再向前和向后计算重复数字的个数。
//
// 代码如下：
//
#include <iostream>
//  二分函数：给定一个数组和一个数，返回该数在数组中的下标。如果不存在，则返回-1.
int GetIndexDichotomy(int array[], int nLength_, int Key)
{
	if (array == nullptr || nLength_ <= 0)
		return -1;

	int _nMiddle = nLength_ / 2;
	if (array[_nMiddle] == Key)
	{
		return _nMiddle;
	}
	else if (array[_nMiddle] < Key)
	{
		return GetIndexDichotomy(array + _nMiddle, nLength_ -  _nMiddle, Key);
	}
	else
	{
		return GetIndexDichotomy(array, _nMiddle, Key);
	}
}

// 功能函数：实现题目中的要求。
int GetNumber(int array[], int nLength_, int Key)
{
	// 参数的合法性检测
	if (array == nullptr || nLength_ <= 0)
		return 0;

	int _nIndexOfKey = GetIndexDichotomy(array, nLength_, Key);
	// 数组中不存在给定的数
	if (_nIndexOfKey == -1)
		return 0;

	int _nCount = 1;			// 用于保存重复数字的个数
	// 统计给定下标之前的重复数字的个数。
	int _nTemp = _nIndexOfKey - 1;
	while (_nTemp >= 0)
	{
		if (array[_nTemp--] == Key)
			++_nCount;
		else
			break;
	}
	// 统计给定下标之后的重复数字的个数。
	_nTemp = _nIndexOfKey + 1;
	while (_nTemp < nLength_)
	{
		if (array[_nTemp++] == Key)
			++_nCount;
		else
			break;
	}

	return _nCount;
}


// 题目二：求0～n-1中缺失的数字: 给定一个长度为n-1的递增数组，求那个缺失的数字。
// 思路：遇到这种排序的数组，一般我们应该先向二分法上去想，大多数情况下二分法都可以解决
//  就像这个题，也可以使用二分法进行解决。
//
//  如果一个数没有缺失，那么数组中一个数的下标就是它本身。如果查找到一个数的下标还是它本
//  身的话，那么那个缺失的数肯定在该数之前；如果该数的下标就是它本身的话，那么那个缺失
//  的数肯定在该数之后。
//
#include <stdexcept>
#include <cassert>
int GetMissingNumber(int array[], int nStart_, int nEnd_)
{
	if (array == nullptr || nEnd_ - nStart_ <= 0)
	{
		assert(false);
		return -1;
	}

	// 判断是不是从最开始的那个数字缺失
	if (array[nStart_] != nStart_)
		return nStart_;

	// 判断中间缺失的情况
	int _nMiddle = (nEnd_ - nStart_) / 2 + nStart_;
	if (array[_nMiddle] != _nMiddle && array[_nMiddle -1] != _nMiddle - 1)
	{
		return GetMissingNumber(array, nStart_, _nMiddle);
	}
	else
	{
		return GetMissingNumber(array, _nMiddle, nEnd_);
	}
}


// 题目三：数组中数值和下标相等的元素。
// 假设一个单调递增的数组中每一个元素老师整数并且是唯一的，找出任意一个数值等于下标的
// 元素。
//
// 思路：同样是使用二分法进行查找。
//
// 参数array表示数组的指针， 参数[nStart_, nEnd_)表示半闭半开的区间。
int GetNumberEqualIndex(int array[], int nStart_, int nEnd_)
{
	if (array == nullptr || nEnd_ - nStart_ <= 0)
	{
		assert(false);
		throw std::logic_error("参数无效");
	}

	int _nMiddle = nStart_ + (nEnd_ - nStart_) / 2;
	if (array[_nMiddle] == _nMiddle)
	{
		return _nMiddle;
	}
	else if (array[_nMiddle] > _nMiddle)
	{
		return GetNumberEqualIndex(array, nStart_, _nMiddle);
	}
	else
	{
		return GetNumberEqualIndex(array, _nMiddle, nEnd_);
	}
}
/***************    main.c     *********************/
int main(int argc, char* argv[])
{
	// 题目一测试：
	int array[8] = {1, 2, 3, 3, 3, 3, 4, 5};
	std::cout << GetNumber(array, 8, 3) << std::endl;

	// 题目二测试:
	int test1[1] = {1};
	int test2[3] = {0, 1, 3};
	int test3[4] = {0, 1, 3, 4};
	std::cout << GetMissingNumber(test1, 0, 1) << std::endl;
	std::cout << GetMissingNumber(test2, 0, 3) << std::endl;
	std::cout << GetMissingNumber(test3, 0, 4) << std::endl;

	// 题目三测试：
	int test4[5] = {-3, -1, 1, 3, 5};
	std::cout << GetNumberEqualIndex(test4, 0, 5) << std::endl;

	return 0;
}

