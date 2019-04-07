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
*   Created Time: 2019年04月07日 星期日 13时30分51秒
*	Modifed Time: 2019年04月07日 星期日 13时56分17秒
*   Blog: http://www.cnblogs.com/yinheyi
*   Github: https://github.com/yinheyi
*   
***********************************************************************/


// 第12题中的答案：
// 下面的代码来自原书
bool HasPath(char* matrix, int rows, int cols, char* str)
{
	// 参数的合法性检测
	if (!matrix || !str || rows < 1 || cols < 1)
		return false;

	// 新建一个数组，用于标记字符矩阵中每一个字符是否被访问过, 并被初始化为false
	bool* visited = new bool[rows * cols];
	memset(visited, 0, rows * cols);

	// 遍历矩阵中的每一个位置作为路径的起始处
	int pathLength = 0;
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			if (HasPathCore(matrix, rows, cols, i, j, str, pathLength, visited)
					return true;
		}
	}
}

	// 对HasPathCore函数的定义
bool HasPathCore(char* matrix, int rows, int cols, int row, int col,
					char* str, int pathLength, bool* visited)
{
	// 参数的合法性分析	
	// 省略

	if (str[pathLength] == '\0')
		return true;

	bool HasPath = false;
	if ( row <rows && row >= 0
			&& col < cols && col >=0
			&& !visited[row * cols + col]
			&& matrix[row * cols + col] == str)
	{
		// 后面的查找，需要依赖这两个状态，所以需要更新状态 
		visited[row * cols + col] = true;
		pathLength += 1;

		if (HasPathCore(matrix, rows, cols, row, col + 1, str, pathLength, visited)
	   		|| HasPathCore(matrix, rows, cols, row, col - 1, str, pathLength, visited) 
			|| HasPathCore(matrix, rows, cols, row - 1, col, str, pathLength, visited) 
			|| HasPathCore(matrix, rows, cols, row + 1, col, str, pathLength, visited))
			HasPath = true;
		else
		{
			visited[row * cols + col] = false;
			pathLength -= 1;
		}
	}

	return HasPath;
}
