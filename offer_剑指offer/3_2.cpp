/***********************************************************************
*   Copyright (C) 2018  Yinheyi. <chinayinheyi@163.com>
*   
* This program is free software; you can redistribute it and/or
* modify it under the terms of the GNU General Public License
* as published by the Free Software Foundation; either version
* 2 of the License, or (at your option) any later version.

*   Brief:    
*   Author: yinheyi
*   Email: chinayinheyi@163.com
*   Version: 1.0
*   Created Time: 2019年03月19日 星期二 23时24分29秒
*	Modifed Time: 2019年03月20日 星期三 22时58分53秒
*   Blog: http://www.cnblogs.com/yinheyi
*   Github: https://github.com/yinheyi
*   
***********************************************************************/


#include<iostream>
#include<cstdlib>	// 使用里面的rand()函数
using std::cout;
using std::endl;
using std::rand;

static bool output_duplication(int* array_, int length_);

int main()
{
	// 生成21个在[1,20]之间的随机整数
	int array[21] = {0};
	for (int i = 0; i < 21; ++i)
	{
		int rand_number = rand() % 20 + 1;
		cout << rand_number << " ";
		array[i] = rand_number;
	}
	cout << endl;


	// 输出里面包含的重要的数字
	 bool bResult = output_duplication(array, 21);
	 if (bResult)
		cout << "数组处理完毕!" << endl;
	 else
		cout << "输入的数组不符合要求!" << endl;

	 return 0;
}


// 输出重复数字的主函数
static bool output_duplication(int* array_, int length_)
{
	// 检测输入的指针是否合法
	if (!array_)
		return false;
	// 检测输入的数组内的元素是否合法
	for (int i = 0; i < length_; ++i)
	{
		int _nCurrentNum = array_[i];
		if (_nCurrentNum <= 0 || _nCurrentNum >= length_)
			return false;
	}

	// 数字的范围为[1, length-1]. 我们对这个范围进行二分处理
	// 二分时的依据是：数组中包含的哪一边的个数多于本应该是个数时，就选择哪一边。
	// 其实可能会出现两边的个数都多于正常应该拥有的数目，此时我们选择第一个就可以了。
	int start = 1;
	int end = length_ - 1;		// 根据题目的信息得到的
	while (start < end)			// 当while退出时，一定是start == end
	{
		int middle = start + (end - start >> 1);	// 移位运算符的优先级比加减运算符的优先级低
		// 求数组包含的左边中的个数
		int _nCount = 0;	
		for (int i = 0; i < length_; ++i)
		{
			if (array_[i] >= start && array_[i] <= middle)
				++_nCount;
		}

		// 根据个数，决定选择哪一边
		if (_nCount > middle - start + 1)
			end = middle;
		else
			start = middle + 1;
	}
  
	cout << "其中的一个重复数字为：" << start << endl;

	return true;
}
