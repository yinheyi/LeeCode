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
*   Created Time: 2019年04月08日 星期一 23时28分07秒
*	Modifed Time: 2019年04月09日 星期二 00时20分08秒
*   Blog: http://www.cnblogs.com/yinheyi
*   Github: https://github.com/yinheyi
*   
***********************************************************************/

#include <iostream>
#include  <stdexcept>

// 题目：求数值为整数的幂次方
//
//
//
// 定义一个宏，用于比较double类型的值是否相等
#define DOUBLE_EQU(x,y) ((x)-(y) <= 1.0e-9 && (x) - (y) >= -1.0e-9)
double Power(double nBase_, int nPower_)
{
	// 对没有意义的结果值进行过滤
	if (DOUBLE_EQU(nBase_, 0.0) && nPower_ <= 0)
		throw std::domain_error("参数对应的结果值不存在");

	// 特殊情况处理
	if (nPower_ == 0)
		return 1;

	// 都先作为正整数处理
	bool _bNegative = false;
	if (nPower_ < 0)
	{
		_bNegative = true;
		nPower_ = -nPower_;
	}

	double _nResult = 0.0;
	double _nHalfResult = Power(nBase_, nPower_ >> 1);

	// 判断幂值的奇偶性
	if (nPower_ & 1)
		_nResult =  _nHalfResult * _nHalfResult * nBase_;
	else
		_nResult = _nHalfResult * _nHalfResult;

	if (_bNegative)
		return 1 / _nResult;
	else
		return _nResult;
}

int main()
{
	double _nResult = 0.0;

	std::cout << "测试1" << std::endl;
	try
	{
		_nResult = Power(0.5, 2);
		std::cout << _nResult << std::endl;
	}
	catch (std::domain_error& _Error)
	{
		std::cout << _Error.what() << std::endl;
	}

	// 测试2
	std::cout << "测试2" << std::endl;
	try
	{
		_nResult = Power(0.0, 0);
		std::cout << _nResult << std::endl;
	}
	catch (std::domain_error& _Error)
	{
		std::cout << _Error.what() << std::endl;
	}

	// 测试3
	std::cout << "测试3" << std::endl;
	try
	{
		_nResult = Power(0.0, -2);
		std::cout << _nResult << std::endl;
	}
	catch (std::domain_error& _Error)
	{
		std::cout << _Error.what() << std::endl;
	}

	// 测试4
	std::cout << "测试4" << std::endl;
	try
	{
		_nResult = Power(-2.0, -3);
		std::cout << _nResult << std::endl;
	}
	catch (std::domain_error& _Error)
	{
		std::cout << _Error.what() << std::endl;
	}

	return 0;
}
