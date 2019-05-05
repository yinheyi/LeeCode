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
*   Created Time: 2019年05月04日 星期六 14时51分09秒
*   Modifed Time: 2019年05月04日 星期六 15时00分46秒
*   Blog: http://www.cnblogs.com/yinheyi
*   Github: https://github.com/yinheyi
*   
***********************************************************************/


#include <iostream>

// 题目二：左旋转字符串
//
void LeftRotate(char array[], int nLength_, int n)
{
	if (array == nullptr || nLength_ <= n)
		return;

	// 交换前n个与最后n个。
	for (int i = n - 1, j = nLength_ - 1; i>= 0;  --i, --j)
	{
		int nTemp = array[i];
		array[i] = array[j];
		array[j] = nTemp;
	}

	LeftRotate(array, nLength_ - n, n);
}

/***************    main.c     *********************/
int main(int argc, char* argv[])
{
	char test1[7] = {'a', 'b', 'c', 'd', 'e', 'f', 'g'};
	LeftRotate(test1, 7, 2);

	for (int i = 0; i < 7; ++i)
	{
		std::cout << test1[i];
	}
	std::cout << std::endl;
	return 0;
}

