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
*   Created Time: 2019年04月29日 星期一 20时16分09秒
*   Modifed Time: 2019年04月29日 星期一 21时50分07秒
*   Blog: http://www.cnblogs.com/yinheyi
*   Github: https://github.com/yinheyi
*   
***********************************************************************/


#include <stdexcept>
#include <iostream>
#include <cassert>
// 数字以0123456789101112131415......的形式排列，求出第n位对应的数字。
// 想法：
// 前10个数为0, 1, 2, 3, 4, ，5, 6, 7, 8, 9
// 后90×2个数为：10,11, 12, ......, 99
// 后900×3个数为：100, 101, 102,  ......, 999
// 后9000×4个数为：1000, 1001, 1002, ......, 9999
// .....
// .....
// .....
//
// 求给定正整数的第几位， 从左到右分别为第0位，第1位等。
// 参数说明：number为给定的正整数， digits为该正整数的位数， index为需要求的第几位
int digitAtIndexOfaNumber(int number, int digits, int index)
{
	if (index >= digits)
	{
		throw std::invalid_argument("参数不合法");
	}

	// 从右向左求
	int nTemp = number;
	int nResult = 0;
	while (digits -1 >= index)
	{
		nResult = nTemp % 10;
		nTemp /= 10;
		--digits;
	}

	return nResult;
}


// 功能主函数
int GetNumberAtN(int n)
{
	// 当n <0时，
	if (n < 0)
	{
		throw std::invalid_argument("无效参数");
	}

	// 当 n<10 时
	if (n < 10)
	{
		return n;
	}

	// 当 n >=10时，是有规律的：
	int nDigit = 2;		// 初始化第n位对应的那个数是几位的整数。
	int nBase = n - 10;	// 规律中的值
	int nFactor = 90;	// 规律中的值
	while (nBase >= nFactor * nDigit)
	{
		nBase = nBase - nFactor * nDigit;
		++nDigit;
		nFactor *= 10;
	}

	// 求出来了对应的那个数
	int nNumber = nFactor / 9 + nBase / nDigit;
	// 求出对应的该数的第几位(从0开始）
	int nIndex = nBase % nDigit;

	return digitAtIndexOfaNumber(nNumber, nDigit, nIndex);
}


// 测试代码
/***************    main.c     *********************/
int main(int argc, char* argv[])
{
	std::cout << GetNumberAtN(0) << std::endl;
	std::cout << GetNumberAtN(9) << std::endl;
	std::cout << GetNumberAtN(13) << std::endl;
	std::cout << GetNumberAtN(19) << std::endl;
	std::cout << GetNumberAtN(21) << std::endl;

	return 0;
}

