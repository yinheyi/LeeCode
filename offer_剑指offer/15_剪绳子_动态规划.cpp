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
*   Created Time: 2019年04月07日 星期日 20时40分06秒
*	Modifed Time: 2019年04月07日 星期日 22时42分40秒
*   Blog: http://www.cnblogs.com/yinheyi
*   Github: https://github.com/yinheyi
*   
***********************************************************************/

#include <iostream>

// 给一个长度为n的绳子，剪成k段，要求k段的乘积最大。请问怎么剪？
//
//
// 1. 使用动态规划(dynamic programming)解决：
// 该题与之前青蛙跳台阶有一些类似，绳子长n,共剪k段，我们首先剪第一段，第一段可以剪的长度记
// 作i, 则i的范围为：[1, n-k+1], 然后再从剩下的n-i长度中剪k-1段，这就相当于一个子问题了。
// 最优解应该在i= 1, 2, ... , n-k+1之中。
//
// a. 动态规划：从上到下求解， 里面包含了很多重复的子问题的解。
// 对于下面代码的优化：对子问题求解之后进行保存，当再次遇到子问题时，先查看保存的结果中
// 有没有最优解。
int MaxProduct_DP_TopDown(int nLength_, int nCount_)
{
	// 当剪成一段时，直接返回整段的长度
	if (nCount_ == 1)
		return nLength_;

	int _nMaximum = 0;
	for (int i = 1; i <= nLength_ - nCount_ + 1; ++i)
	{
		int _nTemp = i * MaxProduct_DP_TopDown(nLength_ - i, nCount_ - 1);

		// 更新最大值；
		if (_nTemp > _nMaximum)
		{
			_nMaximum = _nTemp;
		}
	}

	return _nMaximum;
}

// 看完原书的答案之后，发现只给定一个长度参数，不限制段数, 因此上面的代码可以修改为如下：
int MaxProduct_DP_TopDown(int nLength_)
{
	if (nLength_ == 0)
		return 1;

	int _nMaximum = 0;
	for (int i = 1; i <= nLength_; ++i)
	{
		int _nTemp = i * MaxProduct_DP_TopDown(nLength_ - i);

		// 更新最大值；
		if (_nTemp > _nMaximum)
		{
			_nMaximum = _nTemp;
		}
	}
	return _nMaximum;
}

// 上面的代码有缺陷，下面是书中给出的自下到上的解决方案 
int MaxProduct_DP_BottomUP(int nLength_)
{
	if (nLength_ < 2)
		return 0;
	if (nLength_ == 2)
		return 1;
	if (nLength_ == 3)
		return 2;

	int* ArrayProduct = new int[nLength_ + 1];

	// 下面的几个初始化值为后续作准备, 定义到4就够了，因为子长度 > 4 时， 它们最优解大于
	// 它们本身；
	ArrayProduct[0] = 0;		//永远用不到
	ArrayProduct[1] = 1;
	ArrayProduct[2] = 2;
	ArrayProduct[3] = 3;
	ArrayProduct[4] = 4;

	for (int i = 5; i <= nLength_; ++i)
	{
		// 求取长度为i时的最优值
		int _nMax = 0;
		for (int j = 1; j <= i / 2; ++j)
		{
			int _nCurrentProduct = ArrayProduct[j] * ArrayProduct[i - j];
			if (_nCurrentProduct > _nMax)
				_nMax = _nCurrentProduct;
		}
		ArrayProduct[i] = _nMax;
	}

	int _nMaxProduct = ArrayProduct[nLength_];
	delete [] ArrayProduct;
	return _nMaxProduct;
}


// 测试代码
int main()
{
	int _nLength = 8;
	int _nCount = 3;
	std::cout << MaxProduct_DP_TopDown(8, 3) << std::endl;
	std::cout << MaxProduct_DP_TopDown(8) << std::endl;
	std::cout << MaxProduct_DP_BottomUP(8) << std::endl;
	return 0;
}
