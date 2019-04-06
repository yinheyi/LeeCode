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
*   Created Time: 2019年04月05日 星期五 22时24分05秒
*	Modifed Time: 2019年04月06日 星期六 10时11分06秒
*   Blog: http://www.cnblogs.com/yinheyi
*   Github: https://github.com/yinheyi
*   
***********************************************************************/

// 斐波那契数列
// f(n) = 0, 	n = 0;
// 		= 1, 	n = 1;
// 		= f(n-1) + f(n-2), n > 1;
//
/**********************  基于递归实现  ************************/
int Fibonacci_Recursion(int nNum_)
{
	if (nNum_ == 0)
		return 0;
	if (nNum_ == 1)
		return 1;
	return Fibonacci_Recursion(nNum_ - 1) + Fibonacci_Recursion(nNum_ - 2);
}


/*******************  基于循环实现  ************************/
int Fibonacci_Cycle(int nNum_)
{
	if (nNum_ == 0)
		return 0;
	if (nNum_ == 1)
		return 1;

	int _nPrePre = 0;
	int _nPre = 1;
	for (int i = 2; i < nNum_; ++i)
	{
		int _nTemp = _nPrePre + _nPre;
		_nPrePre = _nPre;
		_nPre =  _nTemp;
	}
	return _nPrePre + _nPre;
}


/*******************  青蛙跳台阶的问题: 就是斐波那契数列的变形     *******************/
// 问题：一只青蛙一次可以跳1个台阶，也可以一次跳2个台阶。请问： 青蛙跳n 阶台阶有多少可能？
//
//
// 思考：
// 感觉自己真的好笨！这个问题想了好久，不仅仅想这么一个问题，同时在想面对一个问题时，我们
// 的思路是什么样子的呢？就比如这个问题吧，当我们面对这个问题时，我们应该从哪个开始想起呢
// 思路从哪里打开呢？
// 一开始想到的是把大问题划分为多个小问题，比如跳n级台阶，我们可以先跳x阶，再跳n-x阶，其中
// x从1至n-1都有可能！！但是仔细想的时候发现里面有好多重合项,比如说：
// 我们假设跳n阶台阶的方法有f(n)种，当x=1时， 可能性为f(n-1)
// 									当x=2时， 可能性为f(2) * f(n-2)
// 									当x=3时， 可能性为f(3) * f(n-3)
// 									………
// 	我们会发现，
// 	当x = 2时，f(2)有两种可能性，[一次跳一阶，跳两次]和[一次跳2阶，跳一次], 我们发现第一
// 	种可能性在f(n-1)中包括了，所以呢，当x=2时，会有f(n-2)种可能。 
// 	当x = 3时，也同样被f(n-1)和f(n-2)包含了。。。
// 	等等等.
//
//
// 总感觉上面的思考很困难，有一些模糊，有没有其它的思考方式呢？或者换个其它角度解答呢？
// 所以就看了书中答案，发现答案的思路很简单且清晰：
// 从最开始起，青蛙只能跳一个台阶或者跳两个台阶，因此跳一个台阶时，为f(n-1), 跳两个台阶时
// 为f(n-2), 因为跳n个台阶为f(n-1) + f(n-2).
//
// 如此清晰的思路为什么我就想不到呢？问题出在哪，我一直考虑这个问题！
// 当我们面对一个问题时，应该从哪里思考？ 总结不出来！！！！！
//
// 思考问题的方式决定了一切！
