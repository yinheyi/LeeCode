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
*   Created Time: 2019年04月27日 星期六 10时22分43秒
*   Modifed Time: 2019年04月27日 星期六 10时59分35秒
*   Blog: http://www.cnblogs.com/yinheyi
*   Github: https://github.com/yinheyi
*   
***********************************************************************/


#include <stdexcept>
#include <iostream>
// 题目：输入一个整数数组，里面包含正数与负数， 求和为最大的子数组。要求：时间复杂度为O(n).
//
// 思路：1. 先找到第一个正数作为最大值。
//       2. 从此处开始求累加和，在求的过程中不断更新最大值。
//       3. 当累加和小于等于零时，再次找到一个加数，从那里开始求累加和，在求各的过程中同
//			样不断地更新最大值。
//
// 求最大子数组的和
double  MaxSumofSubArray(int array[], int nLength)
{
	// 参数的合法性检测
	if (array == nullptr || nLength <= 0)
		return 0;

	// 1. 首先查找第一个正数。
	double nMaxSum = -1;		// 保存最大子数组的和
	double nIndex = -1;			// 保存第一正数的下标
	for (int i = 0; i < nLength; ++i)
	{
		if (array[i] > 0)
		{
			nMaxSum = array[i];
			nIndex = i;
			break;
		}
	}

	// 2. 查找完之后检测一下是否存在正数，如果不存在正数，则抛出异常。
	if (nMaxSum == -1)
	{
		throw std::domain_error("参数对应的结果值不存在， 因为数组中没有正数，不符合要求");
	}

	// 3. 更新最大值
	double nSum = nMaxSum;
	for (int i = nIndex + 1; i < nLength; ++i)
	{
		nSum += array[i];

		if (nSum > nMaxSum)		 // 更新最大值
			nMaxSum = nSum;
		if (nSum <= 0)			 // 当前面的累加和小于等于零时，置为0, 重新计算。
			nSum = 0;
	}

	// 3. 返回最大和
	return nMaxSum;
}
/***************    main.c     *********************/
int main(int argc, char* argv[])
{
	// 测试用例
	int array1[8] = {1, -2, 3, 10, -4, 7, 2, -5};
	int array2[4] = {-1, -2, -3, -4};
	int array3[4] = {1, 2, 3, 4};
	int array4[1] = {10};
	int array5[] = {};

	// 测试1
	std::cout << "数组1的最大子数组的和为：" << std::endl;
	try
	{
		std::cout << MaxSumofSubArray(array1, 8) << std::endl;
	}
	catch(std::domain_error& _error)
	{
		std::cout << _error.what() << std::endl;
	}

	// 测试2
	std::cout << "数组2的最大子数组的和为：" << std::endl;
	try
	{
		std::cout << MaxSumofSubArray(array2, 4) << std::endl;
	}
	catch(std::domain_error& _error)
	{
		std::cout << _error.what() << std::endl;
	}

	// 测试3
	std::cout << "数组3的最大子数组的和为：" << std::endl;
	try
	{
		std::cout << MaxSumofSubArray(array3, 4) << std::endl;
	}
	catch(std::domain_error& _error)
	{
		std::cout << _error.what() << std::endl;
	}

	// 测试4
	std::cout << "数组4的最大子数组的和为：" << std::endl;
	try
	{
		std::cout << MaxSumofSubArray(array4, 1) << std::endl;
	}
	catch(std::domain_error& _error)
	{
		std::cout << _error.what() << std::endl;
	}

	// 测试5
	std::cout << "数组5的最大子数组的和为：" << std::endl;
	try
	{
		std::cout << MaxSumofSubArray(array5, 0) << std::endl;
	}
	catch(std::domain_error& _error)
	{
		std::cout << _error.what() << std::endl;
	}

	return 0;
}
