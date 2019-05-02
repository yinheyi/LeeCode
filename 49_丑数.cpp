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
*   Created Time: 2019年05月02日 星期四 21时02分07秒
*   Modifed Time: 2019年05月02日 星期四 22时45分34秒
*   Blog: http://www.cnblogs.com/yinheyi
*   Github: https://github.com/yinheyi
*   
***********************************************************************/

// 题目：找丑数，把只包含2,3和5的数称为丑数。求按从小到大第10000个丑数。1也算作丑数吧。
//
// 这个题想了很久，一直想着从数列中找出规律，但是没有找到, 下面是前面的数列：
// 1,
// 2,
// 3,
// 2, 2,
// 5,
// 2, 3
// 2, 2, 2
// 3, 3,
// 2, 5,
// 2, 2, 3,
// 3, 5,
// 2, 2, 2, 2,
// 2, 3, 3
// 2, 2, 5
// 2, 2, 3, 3
// ...
//
// 一开始一直把思路放到找数列的规律上--------如何从已有的丑数中推导出下一个丑数.
// 想了半天，真的找不到方法，我也知道肯定是从已经存在的丑数中或者乘以2,或者乘以3或者乘
// 以5得到，但是就是没有找到固定的方法。。想不出来，看答案吧。
// 看完答案之后学习到了一种新的思维方式————当我们找不到固定的规律的时候，可以把现有的
// 规律都列举出来从中选择我们想要的结果。比如在此题中，如果要的结果肯定是从三种方式中
// 得到，所以可以把乘以3/乘以4/乘以5的结果都求出来，然后再从其它选择即可。
//
// 通过这个题，我们应该学习到一种思维方式，而还是仅仅这个题而已。
// 书中方法：把产生的第一个丑数都存放到一个数组中，我们从已经存在的丑数中选择一个通过
// 乘以2/或者3/或者5来得到一个新的丑数。具体选择哪一个数以及选择乘以2/还是3/还是5呢？
// 没有规律来决定，因此呢，我们都试试就知道了。选择使用三个下标分别标记三个丑数的下标，
// 该三个丑数满足乘以2/或者3/或者5之后会大于当前最大的丑数，但是就可以从新的三个丑数中
// 得到下一个新的丑数了。
//
// 具体代码如下：
#include <iostream>
#include <cassert>
#include <vector>
void GetUnlyNumber(int nNumber_)	 // 参数说明：给定输出的丑数个数
{
	// 给定参数少于等于0个时，返回。
	if (nNumber_ <= 0)
		return;

	std::vector<int> _vecUnlyNumbers;
	_vecUnlyNumbers.push_back(1);	// 添加1.
	int nMulti2 = 0;
	int nMulti3 = 0;
	int nMulti5 = 0;
	while (_vecUnlyNumbers.size() <= nNumber_)
	{
		// 分别乘以2/3/5的值
		int _nResult2 = _vecUnlyNumbers[nMulti2] * 2;
		int _nResult3 = _vecUnlyNumbers[nMulti3] * 3;
		int _nResult5 = _vecUnlyNumbers[nMulti5] * 5;

		// 选择一个最小值
		if (_nResult2 <= _nResult3 && _nResult2 <= _nResult5)
		{
			// 保存新的丑数
			_vecUnlyNumbers.push_back(_nResult2);

			// 更新下标值
			++nMulti2;
			if (_nResult3 == _nResult2)
				++nMulti3;
			if (_nResult5 == _nResult2)
				++nMulti5;
		}
		else if (_nResult3 <= _nResult2 && _nResult3 <= _nResult5)
		{
			// 保存新的丑数
			_vecUnlyNumbers.push_back(_nResult3);

			// 更新下标值
			++nMulti3;
			if (_nResult2 == _nResult3)
				++nMulti2;
			if (_nResult5 == _nResult3)
				++nMulti5;
		}
		else if (_nResult5 <= _nResult2 && _nResult5 <= _nResult3)
		{
			// 保存新的丑数
			_vecUnlyNumbers.push_back(_nResult5);

			// 更新下标值
			++nMulti5;
			if (_nResult2 == _nResult5)
				++nMulti2;
			if (_nResult3 == _nResult5)
				++nMulti3;
		}
		else
		{
			std::cout << _nResult2 << " "<< _nResult3 << " "<< _nResult5 << std::endl;
			assert(false);
			break;
		}
	}

	// 输出
	for (int i = 0; i < _vecUnlyNumbers.size(); ++i)
	{
		std::cout << _vecUnlyNumbers[i] << std::endl;
	}
}


// 测试
/***************    main.c     *********************/
int main(int argc, char* argv[])
{
	GetUnlyNumber(20);
	return 0;
}

