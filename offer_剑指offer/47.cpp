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
*   Created Time: 2019年05月02日 星期四 09时49分47秒
*   Modifed Time: 2019年05月02日 星期四 16时33分26秒
*   Blog: http://www.cnblogs.com/yinheyi
*   Github: https://github.com/yinheyi
*   
***********************************************************************/

#define MAX(x,y) ((x) > (y) ? (x) : (y))
int GetMaxValue(const int* Array, int rows, int columns)
{
	if (Array == nullptr || rows <=0 || columns <= 0)
		return 0;

	// 使用一个一维数组保存最大值
	int* maxValues = new int[columns]{0};
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < columns; ++j)
		{
			int up = 0;		// 待求网格上方网格的最优解
			int left = 0;	// 待求网格左边网格的最优解
			if (i > 0)
				up = maxValues[j];
			if (j > 0)
				left = maxValues[j - 1];
			maxValues[j] = MAX(up,left) + Array[i * columns + j];
		}
	}

	int result = maxValues[columns - 1];
	delete [] maxValues;
	return result;
}
/***************    main.c     *********************/
int main(int argc, char* argv[])
{
	return 0;
}

