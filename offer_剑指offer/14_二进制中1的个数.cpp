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
*   Created Time: 2019年04月08日 星期一 21时45分10秒
*	Modifed Time: 2019年04月08日 星期一 22时55分46秒
*   Blog: http://www.cnblogs.com/yinheyi
*   Github: https://github.com/yinheyi
*   
***********************************************************************/

// 实现一个函数， 输入一个整数，输出该数二进制表示中1的个数。
//
//
#include <iostream>
unsigned int NumberOf1(int nNum_)
{
	// 转换为无符号数, 避免符号位的影响
	unsigned int _nTranslate = static_cast<unsigned int>(nNum_);
	unsigned int _nCount = 0;
	while (_nTranslate)
	{
		// 检测最后一位是否为1
	//	if (_nTranslate % 2 == 1)
		if (_nTranslate & 0x00000001)
			++_nCount;

		_nTranslate >>= 1;
	}
	return _nCount;
}

// 书中提供了一种让人眼前一亮的方法
// 原理：对一个非零的数减1, 都可以把最靠近右边的那个1变为0, 并且如果这个1右边还有0,则都会
// 变成1, 而1左边的数不变。
// 代码如下：
int NumberOf1_version2(int nNumber_)
{
	int _nCount = 0;
	while (nNumber_)
	{
		++_nCount;
		nNumber_ &= nNumber_ - 1;
	}
	return _nCount;
}

int main()
{
	int _nNum1 = 9;
	int _nNum2 = -1;
	int _nNum3 = -2;
	int _nNum4 = -3;
	int _nNum5 = -4;

	std::cout << "方法1的输出结果：" << std::endl;
	std::cout << NumberOf1(_nNum1) << std::endl;
	std::cout << NumberOf1(_nNum2) << std::endl;
	std::cout << NumberOf1(_nNum3) << std::endl;
	std::cout << NumberOf1(_nNum4) << std::endl;
	std::cout << NumberOf1(_nNum5) << std::endl;

	std::cout << "方法2的输出结果：" << std::endl;
	std::cout << NumberOf1_version2(_nNum1) << std::endl;
	std::cout << NumberOf1_version2(_nNum2) << std::endl;
	std::cout << NumberOf1_version2(_nNum3) << std::endl;
	std::cout << NumberOf1_version2(_nNum4) << std::endl;
	std::cout << NumberOf1_version2(_nNum5) << std::endl;

	return 0;
}

