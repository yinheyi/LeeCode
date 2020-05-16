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
*   Created Time: 2019年05月04日 星期六 10时01分47秒
*   Modifed Time: 2019年05月04日 星期六 10时44分00秒
*   Blog: http://www.cnblogs.com/yinheyi
*   Github: https://github.com/yinheyi
*   
***********************************************************************/


// 找到从右到从左第一个为1的位, 最右边的位为第0位。
unsigned int FindFirstBitIs1(int num)
{
	int index = 0;
	while (((num & 1) == 0) && (index < 8 * sizeof(int)))
	{
		num = num >> 1;
		++index;
	}

	return index;
}

// 判断一个数的二进制的第i位是否为1.
bool IsBit1(int num, unsigned int index)
{
	int nTemp = 1 << index;
	return num & nTemp;

	// 或者如下：
	// num = num >> index;
	// return num & 1;
}


// 功能主函数
void FindNums(int array[], int nLength_, int& nNum1_, int& nNum2_)
{
	if (array == nullptr && nLength_ < 2)
		return;

	int resultExclusiveOR = 0;
	for (int i = 0; i < nLength_; ++i)
	{
		resultExclusiveOR ^= array[i];
	}

	unsigned int index = FindFirstBitIs1(resultExclusiveOR);

	nNum1_ = nNum2_ = 0;
	for (int i = 0; i < nLength_; ++i)
	{
		if (IsBit1(array[i], index))
		{
			nNum1_ ^= array[i];
		}
		else
		{
			nNum2_ ^= array[i];
		}
	}
}


// 题目二：数组中唯一出现一次的数字。
// 在一个数组中除了一个数字只出现了一次之外，其他的数字都出现了三次。请找出那个只出现
// 了一次的数字。
//
//
//
/***************    main.c     *********************/
int main(int argc, char* argv[])
{
	return 0;
}

