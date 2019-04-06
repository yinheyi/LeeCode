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
*   Created Time: 2019年04月06日 星期六 11时06分26秒
*	Modifed Time: 2019年04月06日 星期六 12时38分26秒
*   Blog: http://www.cnblogs.com/yinheyi
*   Github: https://github.com/yinheyi
*   
***********************************************************************/

// 题目： 查找一个旋转序列中的最小值, 其中旋转之前的序列是按照从小到大排列
//
//
// 思考：对于这个特殊的序列肯定不能使用从头到尾遍历一次的方法。一定要利用上它包含的特性。
// 它有什么特性呢？应该就是有序性: 它是由两段有序的数列组成，并且其它一个序列都大于另一个
// 序列.
// 想到这里，我们再往哪方面想呢？ 如果从头到尾的遍历一遍，时间复杂度为O(n), 那么我们要查找
// 的方法时间复杂度肯定比它少，再少也不可能是O(1), 那就可能是O(logN)了。即然这样的话，我们
// 就可能会想到二分查找方法了。
//
// 假设，旋转序列记作A, A的由两个有序的序列组成，并且第一个序列的值都大于第二个序列的值,
// 当我们从中间选择一个数字m与序列头部的数字作比较，如果该数字大于头部的数字，说明了从头
// 部到中间这一段序列是第一个序列的一部分，因此最小数字从中间到最后这一部分内。如果数字m
// 小于数字头部数字，则相反。
//
//
// 代码实现如下：
#include <vector>
#include <iostream>
#include <stdexcept>

using std::cout;
using std::endl;

/****************************  二分法   **************************/
// 使用vector来实现 
typedef std::vector<int> sequence;
int MinNumber(const sequence& vecArray_)
{
	// 非空检测
	if (vecArray_.empty())
		throw std::out_of_range("序列为空, 元最小值");

	// 只有一个元素时，直接返回就即
	if (vecArray_.size() == 1)
		return vecArray_.front();

	// 当有两个元素时，返回小的那一个
	if (vecArray_.size() == 2)		// 这里应该不需要比较，肯定第二个元素小
		return vecArray_[0] < vecArray_[1] ?  vecArray_[0] : vecArray_[1];

	// 当多个元素时，如果没有旋转，则返回第一个元素
	if (vecArray_.size() > 1 && vecArray_.front() < vecArray_.back())
		return vecArray_.front();

	int _nHead = vecArray_.front();
	sequence::const_iterator _itMiddle = vecArray_.cbegin() + vecArray_.size() / 2;
	if (*_itMiddle > _nHead)
	{
		sequence _nTemp(_itMiddle, vecArray_.cend());
		return MinNumber(_nTemp);
	}
	else
	{
		sequence _nTemp(vecArray_.cbegin(), _itMiddle + 1);
		return MinNumber(_nTemp);
	}
}


// 使用数组来实现, 其中length表示数组的长度
int GetMinNumber(const int* array_, int nLength_)
{
	// 参数检测
	if (!array_)
		throw std::invalid_argument("指针无效");

	// 非空检测
	if (nLength_ <= 0)
		throw std::out_of_range("序列为空, 无最小值");

	// 数组中只有一个元素时，返回
	if (nLength_ == 1)
		return *array_;

	if (nLength_ == 2)		// 后补： 这里可能不需要比较，肯定是第二个元素小
		return array_[0] < array_[1] ? array_[0] : array_[1];

	// 当多个元素时，如果没有旋转，则返回第一个元素
	if (nLength_ > 2 && array_[0] < array_[nLength_ - 1])
		return array_[0];

	int _nFirst = *array_;
	int _nMiddle = nLength_ / 2;
	if (*(array_ + _nMiddle) > _nFirst)
	{
		return GetMinNumber(array_ + _nMiddle, nLength_ - _nMiddle);
	}
	else
	{
		return GetMinNumber(array_, _nMiddle + 1);
	}
}

/**********************   测试一下     *************************/

int main()
{
	sequence _vecArray{3, 4, 5, 1, 2};
	int _nArray[] = {3, 4, 5, 1, 2};
	int _nArrayB[] = {1, 2, 3, 4, 5};
	int _nArrayC[] = {1, 0, 1, 1, 1};
	int _nArrayD[] = {1, 1, 1, 0, 1};
	cout << MinNumber(_vecArray) << endl;
	cout << GetMinNumber(_nArray, 5) << endl;
	cout << GetMinNumber(_nArrayB, 5) << endl;
	cout << GetMinNumber(_nArrayC, 5) << endl;
	cout << GetMinNumber(_nArrayD, 5) << endl;
	return 0;
}
