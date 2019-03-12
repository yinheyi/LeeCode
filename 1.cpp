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
*   Created Time: 2019年03月12日 星期二 21时50分16秒
*	Modifed Time: 2019年03月12日 星期二 22时11分49秒
*   Blog: http://www.cnblogs.com/yinheyi
*   Github: https://github.com/yinheyi
*   
***********************************************************************/


// 1. 为下面的类型添加赋值运算符
class CMystring
{
public:
	CMystring(char* pData = nullptr);
	CMystring(const CMystring& str);
	CMystring& operator=(const CMystring& other_);
	~CMystring();

private:
	char* m_pData;
}


// 注意事项：
// 1. 自赋值的情况
// 2. 连续赋值的情况————返回引用类型
// 3. 异常安全




// 初级方法
CMystring& CMystring::operator=(const CMystring& other_)
{
	// 考虑自赋值的情况
	if (this != &other_)
	{
		char* _pTemp = new char[strlen(other_.m_pData) + 1];
		strcpy(_pTemp, other_.m_pData);
		delete m_pData;
		m_pData = _pTemp;
	}

	return *this;
}

// 高级方法, 利用局部变量来实现
CMystring& CMystring::operator=(const CMystring& other_)
{
	// 考虑自赋值的情况
	if (this != &other_)
	{
		CMystring _Temp(other_);

		char* _pTemp = _Temp.m_pData;
		_pTemp.m_pData = m_pData;
		m_pData = _pTemp;
	}

	return *this;
}
