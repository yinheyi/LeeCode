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
*   Modifed Time: 2019年05月03日 星期五 15时22分21秒
*   Blog: http://www.cnblogs.com/yinheyi
*   Github: https://github.com/yinheyi
*   
***********************************************************************/

// 题目：求一个数在排序数组中的出现的个数。
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
/***************    main.c     *********************/
int main(int argc, char* argv[])
{
	int array[8] = {1, 2, 3, 3, 3, 3, 4, 5};
	std::cout << GetNumber(array, 8, 3) << std::endl;
	return 0;
}

