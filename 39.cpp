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
*	Modifed Time: 2019年04月25日 星期四 23时04分50秒
*   Blog: http://www.cnblogs.com/yinheyi
*   Github: https://github.com/yinheyi
*   
***********************************************************************/

#include <cassert>
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

// 分类两半
int partition(int* array_, int nStart_, int nEnd_)
{
	if (array_ == nullptr)
	{
		assert(false);
		throw std::invalid_argument("对不起，你输入的数组不合法");
	}

	if (nEnd_ - nStart_ <= 0)
	{
		assert(false);
		throw std::invalid_argument("对不起，你输入的数组起始值与终止值不合法");
	}

	// 选择第一个数作为基准数字
	int _nRef = array_[nStart_];

	// 找到第一个大于基准数字的下标
	int _nBiggerIndex = -1;
	for (int i = nStart_; i < nEnd_; ++i)
	{
		if (array_[i] > _nRef)
		{
			_nBiggerIndex = i;
			break;
		}
	}

	// 当没有找到比基准数字大的数时，把基准数字移动到最后面
	if (_nBiggerIndex == -1)
	{
		swap(array_, nStart_, nEnd_ - 1);
		return nEnd_ - 1;
	}
	else
	{
		for (int i = _nBiggerIndex + 1; i < nEnd_; ++i)
		{
			if (array_[i] <= _nRef)
			{
				swap(array_, _nBiggerIndex, i);
				++_nBiggerIndex;
			}
		}
		return _nBiggerIndex;
	}
}

/***************    main.c     *********************/
int main(int argc, char* argv[])
{
	return 0;
}

