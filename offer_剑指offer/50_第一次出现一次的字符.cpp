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
*   Created Time: 2019年05月03日 星期五 10时41分41秒
*   Modifed Time: 2019年05月03日 星期五 11时01分48秒
*   Blog: http://www.cnblogs.com/yinheyi
*   Github: https://github.com/yinheyi
*   
***********************************************************************/


#include <iostream>
// 题目一：求字符串的第一次出现一次的字符
//
// 思路：建立一个一维数组用于存放26个字符出现的次数，然后再从遍历数组查找到第一次出现的
// 字符。
char FirstNotrepetiveCharacter(const char* pStr_)
{
	// if the ptr is nullptr, return null.
	if (pStr_ == nullptr)
		return 0;

	// define a array to store the character counts, the array is inited as -1.
	int characterCount[26] = {0};

	// traversal the string and store every character.
	char* _pTemp = const_cast<char*>(pStr_);
	while (*_pTemp)
	{
		++characterCount[*_pTemp - 'a'];	// assuming that all inputs are lowercase.
		++_pTemp;
	}

	// find the first non-repetive character.
	for (int i = 0; i < 26; ++i)
	{
		if (characterCount[i] == 1)
			return 'a' + i;
	}

	// if is does not exsit, return 0.
	return 0;
}
/***************    main.c     *********************/
int main(int argc, char* argv[])
{

	const char* _pTest1  = "abaccdeff";
	std::cout << FirstNotrepetiveCharacter(_pTest1) << std::endl;
	return 0;
}

