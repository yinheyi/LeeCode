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
*   Created Time: 2019年04月23日 星期二 22时23分01秒
*	Modifed Time: 2019年04月23日 星期二 23时13分54秒
*   Blog: http://www.cnblogs.com/yinheyi
*   Github: https://github.com/yinheyi
*   
***********************************************************************/

#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::string;

void swap(char* pFirst_, char* pSecond_)
{
	char _Temp = *pFirst_;
	*pFirst_ = *pSecond_;
	*pSecond_ = _Temp;
}

// 题目：输出字符串的全排列
void Output(char* pStr_, char* pBegin_)
{
	if (pStr_ == nullptr || pBegin_ == nullptr)
		return;

	if (*pBegin_ == '\0')
	{
		cout << pStr_ << " ";
		return;
	}

	int _nCount = 0;
	while (pBegin_[_nCount] != '\0')
	{
		swap(pBegin_, pBegin_ + _nCount);
		Output(pStr_, pBegin_ + 1);
		swap(pBegin_, pBegin_ + _nCount);

		++_nCount;
	}
}

/***************    main.c     *********************/
int main(int argc, char* argv[])
{
	string _strTemp;
	while (cin >> _strTemp)
	{
		char* pChar = const_cast<char*>(_strTemp.c_str());
		Output(pChar, pChar);
		cout << std::endl;
	}
	return 0;
}

