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
*   Created Time: 2019年04月07日 星期日 14时15分32秒
*	Modifed Time: 2019年04月07日 星期日 16时33分09秒
*   Blog: http://www.cnblogs.com/yinheyi
*   Github: https://github.com/yinheyi
*   
***********************************************************************/


// 机器人的移动:在一个m*n的矩阵中， 机器人从（0,0）开始移动，只能进入这么一些格子：
// 格子的坐标的所有位之和小于等于k. 请问：机器人可以进入多少个格子呢？
//

#include <queue>		// 广度遍历使用
#include <iostream>
#include <cstring>		// 使用memset函数

typedef std::pair<int, int> Grid;
typedef std::queue<Grid> GridQueue;
// 用于判断机器人是否可以进入一个格子.
bool IsValid(int nRows_, int nColumns_, Grid grid_, bool* pVisited_, int nMaximum_)
{
	int _nRow = grid_.first;
	int _nColumn = grid_.second;

	// 1. 当访问过该格子时，就不需要再进入了。
	if (pVisited_[_nRow * nColumns_ + _nColumn])
		return false;

	// 2. 当坐标值超过了范围时，返回false;
	if (_nRow < 0 || _nRow >= nRows_)
		return false;
	if (_nColumn < 0 || _nColumn >= nColumns_)
		return false;

	// 3. 判断坐标位数之和是否满足条件
	int _nSum = 0;
	while (_nRow > 0)		 // 求行的所有位之和
	{
		_nSum += _nRow % 10;
		_nRow = _nRow / 10;
	}

	while (_nColumn > 0)	 // 求列的所有位之和
	{
		_nSum += _nColumn % 10;
		_nColumn = _nColumn / 10;
	}

	if (_nSum > nMaximum_)
		return false;
	else
		return true;
}

/************************   广度遍历优先解法：基于队列  *****************************/
int movingCount_ByQueue(int nRows_, int nColumns_, int nMaximum_) 
{
	// 处理一下特殊的情况
	if (nRows_ <= 0 || nColumns_ <= 0 || nMaximum_ < 0)
		return 0;

	// 初始化已经进入的格子数目为0, 并且把所有格子都初始化为没有访问过
	int _nCount = 0;
	bool* _pVisited = new bool[nRows_ * nColumns_];
	std::memset(_pVisited, 0, nRows_ * nColumns_);

	// 定义一个队列，存放格子的坐标, 并把(0, 0)添加到队列中
	GridQueue _Queue;
	_Queue.push(std::make_pair(0, 0));
	_nCount += 1;
	_pVisited[0] = true;

	while (!_Queue.empty())
	{
		Grid _CurrentGrid = _Queue.front();
		int _nCurrentRow = _CurrentGrid.first;
		int _nCurrentColumn = _CurrentGrid.second;

		// 当前网格左边的网格
		Grid _LeftGrid(_nCurrentRow, _nCurrentColumn - 1);
		if (IsValid(nRows_, nColumns_, _LeftGrid, _pVisited, nMaximum_))
		{
			_Queue.push(_LeftGrid);
			_nCount += 1;
			_pVisited[_LeftGrid.first * nColumns_ + _LeftGrid.second] = true;
		}

		// 当前网格右边的网格
		Grid _RightGrid(_nCurrentRow, _nCurrentColumn + 1);
		if (IsValid(nRows_, nColumns_, _RightGrid, _pVisited, nMaximum_))
		{
			_Queue.push(_RightGrid);
			_nCount += 1;
			_pVisited[_RightGrid.first * nColumns_ + _RightGrid.second] = true;
		}

		// 当前网格下边的网格
		Grid _BottomGrid(_nCurrentRow + 1, _nCurrentColumn);
		if (IsValid(nRows_, nColumns_, _BottomGrid, _pVisited, nMaximum_))
		{
			_Queue.push(_BottomGrid);
			_nCount += 1;
			_pVisited[_BottomGrid.first * nColumns_ + _BottomGrid.second] = true;
		}

		// 当前网格上边的网格
		Grid _TopGrid(_nCurrentRow - 1, _nCurrentColumn - 1);
		if (IsValid(nRows_, nColumns_, _TopGrid, _pVisited, nMaximum_))
		{
			_Queue.push(_TopGrid);
			_nCount += 1;
			_pVisited[_TopGrid.first * nColumns_ + _TopGrid.second] = true;
		}

		_Queue.pop();
	}

	delete [] _pVisited;
	return _nCount;
}

/***************************  基于深度优先:需要用到回溯法  **************************/
// 下面基于递归实现（当然，也可以使用基于栈的循环实现）
//
//
void  DFS_Core(int nRows_, int nColumns_, Grid grid_, bool* pVisited_,
				int* pCount_, int nMaximum_);
int movingCount_DFS(int nRows_, int nColumns_, int nMaximum_) 
{
	// 处理一下特殊的情况
	if (nRows_ <= 0 || nColumns_ <= 0 || nMaximum_ < 0)
		return 0;

	// 初始化已经进入的格子数目为0, 并且把所有格子都初始化为没有访问过
	int _nCount = 0;
	bool* _pVisited = new bool[nRows_ * nColumns_];
	std::memset(_pVisited, 0, nRows_ * nColumns_);

	// 初始化当前的grid为（0, 0)
	Grid _CurrentGrid(0, 0);
	DFS_Core(nRows_, nColumns_, _CurrentGrid, _pVisited, &_nCount, nMaximum_);

	delete [] _pVisited;
	return _nCount;
}

void  DFS_Core(int nRows_, int nColumns_, Grid grid_, bool* pVisited_,
				int* pCount_, int nMaximum_)
{
	int _nCurrentRow = grid_.first;
	int _nCurrentColumn = grid_.second;
	if (IsValid(nRows_, nColumns_, grid_, pVisited_, nMaximum_))
	{
		*pCount_ += 1;
		pVisited_[grid_.first * nColumns_ + grid_.second] = true;

		// 下面进行深度遍历, 分别访问左/右/下/上
		Grid _LeftGrid(_nCurrentRow, _nCurrentColumn - 1);
		DFS_Core(nRows_, nColumns_, _LeftGrid, pVisited_, pCount_, nMaximum_);

		Grid _RightGrid(_nCurrentRow, _nCurrentColumn + 1);
		DFS_Core(nRows_, nColumns_, _RightGrid, pVisited_, pCount_, nMaximum_);

		Grid _BottomGrid(_nCurrentRow + 1, _nCurrentColumn);
		DFS_Core(nRows_, nColumns_, _BottomGrid, pVisited_, pCount_, nMaximum_);

		Grid _TopGrid(_nCurrentRow - 1, _nCurrentColumn - 1);
		DFS_Core(nRows_, nColumns_, _TopGrid, pVisited_, pCount_, nMaximum_);
	}
}


/****************    测试使用    ******************/

int main()
{
	int _nRows = 100;
	int _nColumns = 100;
	int _nMaximum = 18;

	int _nResult1 = movingCount_ByQueue(_nRows, _nColumns, _nMaximum);
	int _nResult2 = movingCount_DFS(_nRows, _nColumns, _nMaximum);

	std::cout << _nResult1 << std::endl;
	std::cout << _nResult2 << std::endl;

	return 0;
}

