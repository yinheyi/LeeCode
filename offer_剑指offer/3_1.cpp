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
*	Modifed Time: 2019年03月20日 星期三 00时12分44秒
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
	// 生成20个在[0,19]之间的随机整数
	int array[20] = {0};
	for (int i = 0; i < 20; ++i)
	{
		int rand_number = rand() % 20;
		cout << rand_number << " ";
		array[i] = rand_number;
	}
	cout << endl;


	// 输出里面包含的重要的数字
	 bool bResult = output_duplication(array, 20);
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
		if (_nCurrentNum < 0 || _nCurrentNum >= length_)
			return false;
	}

	// 遍历数组，进行操作
	for (int i = 0; i < length_; ++i)
	{
		// 当前位置上的数字的引用
		int& _nCurrentNum = array_[i];

		// 进行不断交换，直到本身存放正确的数字，或自己的位置被一个重复的数字占据时，停止!
		while (_nCurrentNum != i && _nCurrentNum != -1)
		{
			// 当前数字的索引处存在与当前数字相同的数字时，输出重复数字，并把当前位置的值
			// 置为-1;
			if (array_[_nCurrentNum] != _nCurrentNum)
			{
				int temp = array_[_nCurrentNum];
				array_[_nCurrentNum] = _nCurrentNum;
				_nCurrentNum = temp;
			}
			else
			{
				cout << "发现重复数字:" << _nCurrentNum << endl;
				_nCurrentNum = -1;
				break;
			}
		}
	}
	return true;
}
