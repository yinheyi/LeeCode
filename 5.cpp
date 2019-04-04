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
*   Created Time: 2019年03月21日 星期四 00时32分03秒
*	Modifed Time: 2019年03月21日 星期四 20时45分39秒
*   Blog: http://www.cnblogs.com/yinheyi
*   Github: https://github.com/yinheyi
*   
***********************************************************************/

#include <cstring>		// strlen()的使用
#include <cassert>		// assert()的使用
#include <stdio.h>

bool SubstituteBlank(char* pString_)
{
	// 检测字符串是否合法
	if (!pString_)
	{
		assert(false);
		return false;
	}

	// 字符串的长度
	int _nLength = strlen(pString_);
	int _nCount = 0;			// 用于保存字符串的包含的空格的个数
	for (int i = 0; i <_nLength; ++i)
	{
		if (*(pString_ + i) == ' ')
			++_nCount;
	}

	// 定义两个指针分别指向替换前和替换后的字符串尾部(\0处）
	char *_pBefore = pString_ + _nLength;
	char *_pAfter = pString_ + _nLength + 2 * _nCount;
	while (_pBefore >= pString_)
	{
		if (*_pBefore != ' ')
			*_pAfter-- = *_pBefore--;
		else
		{
			*_pAfter-- = '0';
			*_pAfter-- = '2';
			*_pAfter-- = '%';
			--_pBefore;
		}
	}
	return true;
}

int main()
{
	char _String[100] = "Hello, world!!";
	printf("%s\n", _String);

	if (!SubstituteBlank(_String))
		return -1;

	printf("%s\n", _String);
}
