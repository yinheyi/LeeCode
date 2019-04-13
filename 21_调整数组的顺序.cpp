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
*   Created Time: 2019年04月13日 星期六 21时53分52秒
*	Modifed Time: 2019年04月13日 星期六 22时59分54秒
*   Blog: http://www.cnblogs.com/yinheyi
*   Github: https://github.com/yinheyi
*   
***********************************************************************/

#include <iostream>
// 题目： 调整一个数组的顺序，使其奇数在前，偶数在后
//
//
static bool IsOdd(int nNumber_)
{
	return nNumber_ & 0x1; 
}

typedef bool (*FuncPtr)(int);
// 参数说明： 
// pArray_:指向数组首元素的指针; nLength_: 数组的长度; pFunc, 函数指针
static bool AdjustArray(int* pArray_, int nLength_, FuncPtr pFunc_)
{
	// 参数的合法性分析
	if (pArray_ == nullptr)
		return false;
	if (nLength_ < 0)
		return false;
	if (nLength_ <= 1)
		return true;

	// 执行操作:
	int _nStart = 0;
	int _nEnd = nLength_ - 1;
	while (true)
	{
		// 从前往后找到第一个偶数
		while (pFunc_(pArray_[_nStart]) && _nStart < _nEnd)
			++_nStart;

		// 从后向前找到第一个奇数
		while (!pFunc_(pArray_[_nEnd]) && _nEnd > _nStart)
			--_nEnd;

		// 判断
		if (_nStart < _nEnd)
		{
			int _nTemp = pArray_[_nStart];
			pArray_[_nStart] = pArray_[_nEnd];
			pArray_[_nEnd] = _nTemp;
		}
		else
			break;
	}
	return true;
}


/*********************  测试使用       ***************************/
int main()
{
	int _nTest1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
	int _nTest2[] = {};
	int _nTest3[] = {1};
	int _nTest4[] = {2, 1};

	std::cout << "第一个结果：" << std::endl;
	std::cout << AdjustArray(_nTest1, 20, IsOdd) << std::endl;
	for (int i = 0; i < 20; ++i)
		std::cout << _nTest1[i] << std::endl;

	std::cout << "第二个结果：" << std::endl;
	std::cout << AdjustArray(_nTest2, 0, IsOdd) << std::endl;

	std::cout << "第三个结果：" << std::endl;
	std::cout << AdjustArray(_nTest3, 1, IsOdd) << std::endl;
	for (int i = 0; i < 1; ++i)
		std::cout << _nTest3[i] << std::endl;

	std::cout << "第四个结果：" << std::endl;
	std::cout << AdjustArray(_nTest4, 2, IsOdd) << std::endl;
	for (int i = 0; i < 2; ++i)
		std::cout << _nTest4[i] << std::endl;

	return 0;
}
