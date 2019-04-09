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
*   Created Time: 2019年04月09日 星期二 21时42分20秒
*	Modifed Time: 2019年04月09日 星期二 22时45分01秒
*   Blog: http://www.cnblogs.com/yinheyi
*   Github: https://github.com/yinheyi
*   
***********************************************************************/

#include <iostream>
#include <stdexcept>

// 当超过 unsigned long long 类型时，就无法表示了。
// 在能表示的范围内，使用简单的方法，否则使用数组来实现
void PrintOne2MaxDigit(int nDigit_)
{
	if (nDigit_ <= 0) 
		throw std::domain_error("参数对于的结果值不存在");

	// 根据不同的计算机系统,求得不同的最大能表示的无符号整数。
	unsigned long long _nMax = 0;
	if (sizeof(_nMax) == 4)
		_nMax = 0xffffffff;
	else if (sizeof(_nMax) == 8)
		_nMax = 0xffffffffffffffff;
	else
		_nMax = 0xffff;

	// 计算最大无符号整数对应的位数
	unsigned int _nMaxDigit = 0;
	while (_nMax)
	{
		_nMax /= 10;
		++_nMaxDigit;
	}

	// 当给定的位数在能表示的范围内时，使用最直接的方法.
	// 下面 if 语句减1的目的在于：
	// 计算机虽然能表示最大的整数为n位，但表示不了最大的n位整数。
	if (nDigit_ < _nMaxDigit - 1)
	{
		// 求给定位数的最大整数+1
		unsigned long long  _nMaxNumberofNDigit = 1;
		while (nDigit_--)
		{
			_nMaxNumberofNDigit *= 10;
		}

		// 输出
		for (unsigned long long i = 1; i < _nMaxNumberofNDigit; ++i)
		{
			std::cout << i << " ";
		}
	}
	else
	{

		int* _Array = new int[nDigit_];
		delete[] _Array;
	}
}


/****************   测试代码    ******************************/
int main(int argc, char** argv)
{
	if (argc >2)
		throw std::invalid_argument("参数个数过多");

	// 把给定的参数转换为给int， 默认初始化为初始化为1
	int _nDigit = 1;
	if (argc == 2)
	{
		try
		{
			_nDigit = std::stoi(argv[1]);
		}
		catch (std::invalid_argument& _Error)
		{
			std::cout << _Error.what() << std::endl;
			std::cout << " 输入的参数有误 " << std::endl;
			exit(-1);
		}
	}

	// 打印从1到最大的整数
	try
	{
		PrintOne2MaxDigit(_nDigit);
	}
	catch (std::domain_error & _Error)
	{
		std::cout << _Error.what() << std:: endl;
		exit(-1);
	}

	return 0;
}
