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
*   Created Time: 2019年04月25日 星期四 21时55分04秒
*	Modifed Time: 2019年04月26日 星期五 22时08分49秒
*   Blog: http://www.cnblogs.com/yinheyi
*   Github: https://github.com/yinheyi
*   
***********************************************************************/

#include <cassert>
#include <iostream>
#include <stdexcept>

// 使用该函数时，应该保证nFirst与nSecond的有效性
void swap(int* array_, int nFirst_, int nSecond_)
{
	if (array_ == nullptr)
		return;

	int nTemp = array_[nFirst_];
	array_[nFirst_] = array_[nSecond_];
	array_[nSecond_] = nTemp;
}

// 把一个数组分为两部分, 第一部分都小于第二部分.
// 输入的参数 ：array_表示数组的指针， nLength_表示数组中元素的个数
// 				nStart_ 与 nEnd_ 为前闭后开区间, 表示数组中的元素
// 返回值为数组的下标index,数组分为了[nStart_, index) 和 [index, nEnd_).
// 边界考虑： 当数组为空时，返回值为nStart_;
//
// 总体思路: 选择数组中的第一个数字作为基准数字，小于该基准数字的数移动到数组的前半部
// 分， 大于或等于基准数字的数移动到数组的后半部分。 使用一个下标始终指向数组中第一个
// 大于等于基准数字的位置, 再使用另一个下标在数组中进行移动，如果遇到小于基准数字的数，
// 就到第一个大于等于基准数字的数进行交换。
//
int partition(int* array_, int nLength_, int nStart_, int nEnd_)
{
	if (array_ == nullptr)
	{
		assert(false);
		throw std::invalid_argument("对不起，你输入的数组指针不合法");
	}

	if (nStart_ < 0 || nStart_ >= nLength_		// 开始值不合法
			|| nEnd_ < 0 || nEnd_ > nLength_	// 终止值不合法
			|| nStart_ > nEnd_)					// 开始值与终止值不合法
	{
		assert(false);
		throw std::invalid_argument("对不起，你输入的数组起始值与终止值不合法");
	}

	if (nStart_ == nEnd_)
		return nStart_;

	int _nRef = array_[nStart_]; 	// 选择数组中的第一个数作为基准数字
	int _nGEIndex = nStart_;		// 该值指向数组内第一个大于或等于基准数字的下标。

	// 该循环实现把小于基准数字的数移动到前半部分
	for (int i = nStart_ + 1; i < nEnd_; ++i)
	{
		if (array_[i] < _nRef)
		{
			swap(array_, i, _nGEIndex);
			++_nGEIndex;
		}
	}

	// 如果数组中的第一个数字正好是数组中最小的数字时，这时把数组分为该数字和剩余数字两
	// 部分。 否则的话，分成小于基准数字和大于等于基准数字这两部分.
	if (_nGEIndex == nStart_)
		return _nGEIndex + 1;
	else
		return _nGEIndex;
}

int GetTheNumber(int* array_, int length_)
{
	if (array_ == nullptr || length_ <= 0)
	{
		assert(false);
		throw std::invalid_argument("对不起，你输入的数组不合法");
	}

	if (length_ == 1)
		return array_[0];

	int nMiddle = length_ >> 1;
	int nStart = 0;
	int nEnd = length_;
	int index = partition(array_, length_, nStart, nEnd);
	while (index != nMiddle)
	{
		if (index > nMiddle)
			nEnd = index;
		else
			nStart = index;

		index = partition(array_, length_, nStart, nEnd);
	}

	// 最后要核实一下该值的个数是否大于数组个数的一半
	int _nResult = array_[index];
	int _nCount = 0;
	for (int i = 0; i < length_; ++i)
	{
		if (array_[i] == _nResult)
			++_nCount;
	}

	if (_nCount > nMiddle)
		return _nResult;
	else
	{
		assert(false);
		std::cerr << "数组中没有个数超过一半的数" << std::endl;
		throw;
	}
}

/***************    main.c     *********************/
int main(int argc, char* argv[])
{

	int array[9] = {1, 2, 3, 5, 6, 8, 5, 0, 2};
	std::cout << GetTheNumber(array, 9) << std::endl;

	return 0;
}

