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
*   Created Time: 2019年03月21日 星期四 00时19分45秒
*	Modifed Time: 2019年03月21日 星期四 00时26分51秒
*   Blog: http://www.cnblogs.com/yinheyi
*   Github: https://github.com/yinheyi
*   
***********************************************************************/


// 下面这段代码要说明一个知识点：
// 为了节省内存，在c或c++中，把常量字符串放到单独的一个内存区域中。 重点来了，那
// 就是当多个指针被赋值给相同的字符串时，它们实际上会指向相同的地址。
#include<stdio.h>
int main()
{
	char str1[] = "hello, world!";
	char str2[] = "hello, world!";

	char* str3 = "hello, world!";
	char* str4 = "hello, world!";

	// 这里比较的其实是指针;
	if (str1 == str2)
		printf("str1 与 str2 相等!\n");
	else
		printf("str1 与 str2 不相等!\n");

	// 这里比较的其实也是指针;
	if (str3 == str4)
		printf("str3 与 str4 相等!\n");
	else
		printf("str3 与 str4 不相等!\n");

	return 0;
}

