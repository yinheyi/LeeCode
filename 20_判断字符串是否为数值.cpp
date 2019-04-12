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
*   Created Time: 2019年04月12日 星期五 23时16分40秒
*	Modifed Time: 2019年04月13日 星期六 00时18分14秒
*   Blog: http://www.cnblogs.com/yinheyi
*   Github: https://github.com/yinheyi
*   
***********************************************************************/

#include <string>
#include <iostream>
#include <cctype>		// 使用 isalpha()和isdigit()函数
using std::string;
// 题目： 判断一个字符串是否为数值
// 
//
// 判断一个字符是否为正负号
static inline bool IsPlusOrMinusSign(const char character_)
{
	if (character_ == '+' || character_ == '-')
		return true;
	else
		return false;
}

// 判断是否为一个点
static inline bool IsPoint(const char character_)
{
	if (character_ == '.')
		return true;
	else
		return false;
}

// 判断是否为E/e
static inline bool IsE(const char character_)
{
	if (character_ == 'E' || character_ == 'e')
		return true;
	else
		return false;
}

bool IsNumeric(string& str_)
{
	// 为空时，返回false
	if (str_.empty())
		return false;

	// 如果首字母即还是数字也不是+-, 则返回false
	if (!IsPlusOrMinusSign(str_[0]) && !isdigit(str_[0]))
		return false;

	unsigned int _nIndex = 1;
	bool _bHasPoint = false;
	bool _bHasE = false;
	unsigned int _nSize = str_.size();
	while (_nIndex < _nSize)
	{
		// 当是数字时
		if (isdigit(str_[_nIndex]))
		{
			++_nIndex;
			continue;
		}

		// 当是"."时，
		if (IsPoint(str_[_nIndex]) && _nIndex != _nSize - 1)
		{
			if (!_bHasPoint)
			{
				++_nIndex;
				_bHasPoint = true;
				continue;
			}
			else
				return false;
		}

		// 当时E/或e时
		if (IsE(str_[_nIndex]))
		{
			if (!_bHasE && _nIndex != _nSize - 1)
			{
				_bHasE = true;
				_bHasPoint = true;		// E 后面不能加 .
				++_nIndex;
				continue;
			}
			else
				return false;
		}

		// 当时+-号时
		if (IsPlusOrMinusSign(str_[_nIndex]) && _nIndex != _nSize - 1)
		{
			if (IsE(str_[_nIndex - 1]))
			{
				++_nIndex;
				continue;
			}
			else
				return false;
		}

		// 其它情况返回false;
		return false;
	}

	return true;
}


/**************  测试使用   ***************/

int main()
{
	string _a("+100");
	string _b("3.112123");
	string _c("-1e-16");
	string _d("-12");
	string _e("123-");
	string _f("123e123");

	std::cout << IsNumeric(_a) << std::endl;
	std::cout << IsNumeric(_b) << std::endl;
	std::cout << IsNumeric(_c) << std::endl;
	std::cout << IsNumeric(_d) << std::endl;
	std::cout << IsNumeric(_e) << std::endl;
	std::cout << IsNumeric(_f) << std::endl;

	return 0;
}
