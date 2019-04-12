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
*   Created Time: 2019年04月11日 星期四 23时03分43秒
*	Modifed Time: 2019年04月12日 星期五 22时06分41秒
*   Blog: http://www.cnblogs.com/yinheyi
*   Github: https://github.com/yinheyi
*   
***********************************************************************/


// 题目：实现一个函数来匹配 . 和 *,  . 匹配任意字符， * 匹配任意个它前面的字符
// 
// 我的想法：
// 首先对正则表达式进行划分，再从头开始每一部分去匹配字符串。
// 使用多个指针来完成
bool Match1(char* pStr_, char* pPattern_)
{
	// 参数的有效性检测
	if (!pStr_ || !pPattern_)
		return false;

	// 都为空时，返回true
	if (!*pStr_ && !*pPattern_)
		return true;

	// 当正则表达式为空，但是字符串不为空时，返回false
	if (*pStr && !*pPattern_)
		return false;

	// 使用两个指针在正则表达式上移动，使用一个指针在字符串的移动
	//
	//
	// 好吧，我想了想，好多情况，我还是放弃了，直接看答案了
}

// 原书答案
// 的确好！！！！
//
bool match(char* str, char* pattern)
{
	if (str == nullptr && pattern == nullptr)
		return false;

	// 正则表则式开头为"*"时， 不合法，返回false;
	if (*pattern == '*') 
		return false;

	return mathCore(str, pattern);
}

bool matchCore(char* str, char* pattern)
{
	if (*str == '\0' && *pattern == '\0')
		return true;

	if (*str != '\0' && *pattern == '\0')
		return false;

	if (*(pattern + 1) == '*')
	{
		// 当带 * 匹配时， 分三种情况: 匹配0个，匹配1个和匹配多个
		// 这里是核心, 把这里处理好了，都简单！
		if (*pattern == *str || *pattern == '.' && *str != '\0')
		{
			return matchCore(str, pattern + 2)
				|| matchCore(str + 1, pattern + 2)
				|| matchCore(str + 1, pattern);
		}
		else
		{
			return matchCore(str, pattern + 2);
		}
	}

	if (*str == *pattern || *pattern == '.' && *str != '\0')
		return mathCore(str+1, pattern + 1);
	else
		return false;
}
