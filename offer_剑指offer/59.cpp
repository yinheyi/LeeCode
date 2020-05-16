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
*   Created Time: 2019年05月04日 星期六 15时20分50秒
*   Modifed Time: 2019年05月04日 星期六 17时12分06秒
*   Blog: http://www.cnblogs.com/yinheyi
*   Github: https://github.com/yinheyi
*   
***********************************************************************/


// 题目：滑动窗口的最大值。
// 给定一个数组和滑动窗口的大小，请找出所有滑动窗口里的最大值。例如，如果输入数组{2,3,
// 4, 2, 6, 2, 5, 1}及滑动窗口的大小3, 那么一共存在6个滑动窗口，它们的最大值分别为
// {4, 4, 6, 6, 6, 5}。
//
//
#define MAX(x,y) ((x) > (y) ? (x) : (y))

#include <iostream>
#include <vector>
typedef std::vector<int> DynamicArray;
void MaxInwindows(int array[], int nLength_, int nWindowSize_, DynamicArray& vecResult_)
{
	if (array == nullptr || nLength_ < nWindowSize_)
		return;

	for (int i = 0; i < nLength_; ++i)
	{
		if (vecResult_.empty())
		{ 
			vecResult_.push_back(array[i]);
		}
		else
		{
			if (vecResult_.back() < array[i])
			{
				// 只影响窗口大小减1范围
				//  这里有一个坑，要想宏定义的函数MAX运行正常，必须都转换为有符号类型 
				int RangeStart = MAX(0, static_cast<int>(vecResult_.size()) - nWindowSize_ + 1);
				int RangeEnd = vecResult_.size();

				for (int j = RangeStart; j <  RangeEnd; ++j)
				{
					vecResult_[j] = MAX(array[i], vecResult_[j]);
				}
			}
			vecResult_.push_back(array[i]);
		}
	}

	// 去除尾部多余的
	for (int i = 0; i < nWindowSize_ - 1; ++i)
	{
		vecResult_.pop_back();
	}
}


/***************    main.c     *********************/
int main(int argc, char* argv[])
{

	DynamicArray _Results;
	int array[8] = {2, 3, 4, 2, 6, 2, 5, 1};
	MaxInwindows(array, 8, 3, _Results);
	for (int i = 0; i < _Results.size(); ++i)
	{
		std::cout << _Results[i] << " ";
	}
	std::cout << std::endl;

	return 0;
}

