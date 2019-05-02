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
*   Created Time: 2019年05月02日 星期四 17时13分48秒
*   Modifed Time: 2019年05月02日 星期四 17时48分23秒
*   Blog: http://www.cnblogs.com/yinheyi
*   Github: https://github.com/yinheyi
*   
***********************************************************************/

#include <string>
#include <iostream>
// 题目：请从字符串中找出一个最长的不包含重复字符的子字符串，返回该最长子字符串的长度。
// 
// 该题我真的想了很久，真的没有想到好的办法。自己太笨！
// 原书中的字符真牛逼。。。如果我们直接采用最笨最直接的方法的话，复杂度为O(n3),但是书的
// 答案直接把复杂度降为O（n）。
//  牛逼，打内心的偑服!.
//
// 思路：
// 核心1：使用f（i）表示以第i个下标结尾的字符串的最大长度，当我们当f(i+1)时，我们可以利用
// f(i)的结果。
// 核心2：当判断上一个字符串中是否包含下一个字符时，没有使用循环把字符串遍历一遍来实现，而
// 是很巧妙地使用了一个数组直接记住了上一个字符串的每一个字符出现的下标位置。这一点很值得
// 学习!
//
//
// 直接上源码！
int longestSubString(const std::string& str)
{
	if (str.size() < 2)
		return str.size();

	int array[26] = {-1};		// 记录字符串出现的下标位置,初始化为-1.
	int maxLength = 0;			// 保存最大非重复字符串的长度
	int currentLength = 0;		// 保存当前的字符串的长度 
	for (int i = 0; i < str.size(); ++i)
	{
		int preIndex = array[str[i] - 'a'];		// 上一次该字符出现的下标
		if (preIndex == -1 || i - preIndex > currentLength)
		{
			++currentLength;
			maxLength = maxLength > currentLength ? maxLength : currentLength;
		}
		else
		{
			currentLength = i - preIndex;
		}
		array[str[i] - 'a'] = i;
	}

	return maxLength;
}
/***************    main.c     *********************/
int main(int argc, char* argv[])
{
	std::string _test("arabcacfr");
	std::cout << longestSubString(_test) << std::endl;
	return 0;
}

