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
*   Created Time: 2019年04月29日 星期一 21时50分42秒
*   Modifed Time: 2019年04月29日 星期一 22时52分51秒
*   Blog: http://www.cnblogs.com/yinheyi
*   Github: https://github.com/yinheyi
*   
***********************************************************************/


#include <vector>
#include <iostream>
#include <algorithm>
// 题目：输入一个数组，把数组中的数字拼接起来排成一个数，求出拼接最小的数字。
//
//
// 该函数求给定一个数是几位数
int digitOfNumber(int nNumber_)
{
	int _nResult = 0;
	while (nNumber_)
	{
		++_nResult;
		nNumber_ /= 10;
	}

	return _nResult;
}

// 该函数求一个数的整数次幂。
int Power(int nbase_, int nPower_)
{
	if (nPower_ ==0)
	{
		return 1;
	}
	else if (nPower_ == 1)
	{
		return nbase_;
	}
	else
	{
		int _nHalf = nPower_ / 2;
		int _nModulus = nPower_ % 2;
		int _nHalfResult = Power(nbase_, _nHalf);
		return _nHalfResult * _nHalfResult * Power(nbase_, _nModulus);
	}
}


// 比较两个数的大小。
// 原则：给定两个数x和y,如果x-y小于y-x,则x小y大。
// 如果x-y和y-x相同，则位数多的那个小。
// 如果x和y相同，则x小。
bool Compare(int lhs_, int rhs_)
{
	if (lhs_ == rhs_)
		return true;

	int _nFirstDigit = digitOfNumber(lhs_);
	int _nSecondDigit = digitOfNumber(rhs_);

	long long _First = lhs_ * Power(10, _nSecondDigit) + rhs_;
	long long _Second = rhs_ * Power(10, _nFirstDigit) + lhs_;

	return _First < _Second;
}

/***************    main.c     *********************/
int main(int argc, char* argv[])
{
	std::vector<int> _test1{3, 32, 321};
	// 调用stl的排序函数进行排序。
	std::sort(_test1.begin(), _test1.end(), Compare);
	for (int i = 0; i < _test1.size(); ++i)
	{
		std::cout << _test1[i];
	}
	std::cout << std::endl;

	return 0;
}

