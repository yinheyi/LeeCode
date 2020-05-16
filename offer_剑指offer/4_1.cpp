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
*   Created Time: 2019年03月20日 星期三 23时55分52秒
*	Modifed Time: 2019年03月21日 星期四 00时16分15秒
*   Blog: http://www.cnblogs.com/yinheyi
*   Github: https://github.com/yinheyi
*   
***********************************************************************/

// 从左下角或右上角进行选择数字, 因为此处的数字满足在当前行最大且当前列最小 或
// 者在当前列大且当前行最小的特点
// 如果矩阵是方阵的话，选择对角线上的数字最方便了。
//
// 下面的参数意义如下:
// array,二维数组指针, row 数组的行数， column, 数组的列数， number 表示待查找的数字
bool find_number(int** array, int row, int column, int number)
{
	// 检测二维数组指针是否有效
	if (!array)
		return false;

	// 用于保存选择的当前数字的位置
	int _nRowNum = 0;
	int _nColumnNum = column - 1;
	while (_nRowNum >= 0 && _nColumnNum >=0)
	{
		// 当前数字与待查找的数字相同时，返回true;
		if (array[_nRowNum][_nColumnNum] == number)
			return true;

		// 当前数字小于待查找的数字时， 可以排除当前行
		if (array[_nRowNum][_nColumnNum] < number)
			_nRowNum += 1;

		// 当前数字小于待查找的数字时， 可以排除当前列
		if (array[_nRowNum][_nColumnNum] > number)
			_nColumnNum -= 1;
	}

	// 当从while里面退出时，说明没有查找到要查找的数字
	return false;
}
