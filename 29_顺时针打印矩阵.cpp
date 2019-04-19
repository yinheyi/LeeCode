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
*   Created Time: 2019年04月17日 星期三 23时27分56秒
*	Modifed Time: 2019年04月19日 星期五 22时13分21秒
*   Blog: http://www.cnblogs.com/yinheyi
*   Github: https://github.com/yinheyi
*   
***********************************************************************/

#include <iostream>
#include <cstring>
// Topic: output the value of a matrix clockwisely.
// Thinking: At first, we define a function the rotate a matrix anticlockly.
// then, output the first row of a matrix. Ok, let's do it.
//
// Using one-dimensional array to represent a matrix.
// if a number is matrix[x][y] of a nRow-nColumn Matrix, Aftrer rotate the matrix 
// anticlockly, the numer will be NewMatrix[nColumn - 1 - y][x] of a nColumn-nRow NewMatrix.
void RotateMatix(int* matrix, int& nRow_, int& nColumn_)
{
	int _newMatrix[nRow_ * nColumn_] = {0};
	int _newRow = nColumn_;
	int _newColumn = nRow_;

	for (int i = 0; i < nRow_; ++i)
	{
		for (int j = 0; j < nColumn_; ++j)
		{
			int _nNewRowIndex = nColumn_ - 1 - j;
			int _nNewColumnIndex = i;
			*(_newMatrix + _nNewRowIndex * _newColumn + _nNewColumnIndex) = *(matrix + i * nColumn_ + j);
		}
	}

	// update the matrix and row-column value.
	memcpy(matrix, _newMatrix, sizeof(int) * nRow_ * nColumn_);
	nRow_ = _newRow;
	nColumn_ = _newColumn;
}

// define a function to output first row
void OutputFirstRow(int*& matrix, int& nRow_, int& nColumn_)
{
	if (nRow_ <= 0 || nColumn_ <= 0)
		return;

	for (int i = 0; i < nColumn_; ++i)
	{
		std::cout << *matrix++ << " ";
	}

	--nRow_;
}

/***************    main.c     *********************/
int main(int argc, char* argv[])
{

	int _nRow = 4;
	int _nColumn = 4;
	int matrix[16] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
	int* _pCursor = matrix;
	while (_nRow > 0 && _nColumn > 0)
	{
		OutputFirstRow(_pCursor, _nRow, _nColumn);
		std::cout << std::endl;
		RotateMatix(_pCursor, _nRow, _nColumn);
	}

	return 0;
}

