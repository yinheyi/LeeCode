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
*   Created Time: 2019年04月29日 星期一 22时57分43秒
*   Modifed Time: 2019年04月29日 星期一 23时47分03秒
*   Blog: http://www.cnblogs.com/yinheyi
*   Github: https://github.com/yinheyi
*   
***********************************************************************/

#include <iostream>
#include <map>
#include <stdexcept>
// 题目：给定一个数字，按照如下翻译：0对应a, 1对应b, 2对应c,......, 25对应z.
// 给定一个数，求它可以对应多少种翻译？
// 例如12258可以对应5种翻译，分别为: bccfi, bwfi, bczi, mcfi, mzi.
//
// 思路：看到该题，第一想到的就是动态规划，我们完全可以使用动态规划来解决。


/***********   自顶而下的方法： 为了方便，我们从后向前翻译。   ****************/
// 定义一个全局map, 用于保存中间结果
std::map<int, int> _mapNum2Count;
int GetTranslationCount(int nNumber)
{
	// 如果给定的参数小于0,抛出异常
	if (nNumber <0)
	{
		throw std::invalid_argument("参数不合法");
	}

	// 检测之前有没有计算过该结果， 对于map来说，如果之前没有存放在map中，则会初始化为0
	if (_mapNum2Count[nNumber] != 0)
		return _mapNum2Count[nNumber];

	// 当小于10时，返回1
	if (nNumber < 10)
	{
		_mapNum2Count[nNumber] = 1;		//保存中间结果
		return 1;
	}
	else
	{
		// 求去掉右边1位后表示的剩余数字及该数字可以翻译的种数.
		int _nLeft1 = nNumber / 10;
		int _nCount1 = GetTranslationCount(_nLeft1);
		_mapNum2Count[_nLeft1] = _nCount1;		// 保存中间结果
		
		// 求最右边的两位数字, 需要根据它来判断能否对最右边两位进行翻译
		if (nNumber % 100  <= 25)
		{
			// 求去掉右边两位后表示的剩余数字及该数字可以翻译的种数.
			int _nLeft2 = nNumber / 100;
			int _nCount2 = GetTranslationCount(_nLeft2);
			_mapNum2Count[_nLeft2] = _nCount2;		// 保存中间结果

			return _nCount1 + _nCount2;
		}
		else
		{
			return _nCount1;
		}
	}
}

/****************   自下而上的方法， 使用循环来解决     *************/



/***************    main.c     *********************/
int main(int argc, char* argv[])
{
	std::cout << GetTranslationCount(12258) << std::endl;
	return 0;
}

