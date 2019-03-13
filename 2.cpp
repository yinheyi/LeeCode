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
*   Created Time: 2019年03月12日 星期二 22时45分46秒
*	Modifed Time: 2019年03月13日 星期三 22时13分33秒
*   Blog: http://www.cnblogs.com/yinheyi
*   Github: https://github.com/yinheyi
*   
***********************************************************************/
#include <iostream>
#include <mutex>	// 用于线程加锁

using std::cout;
using std::endl;
using std::mutex;


// 方法一：线程安全的饿汉模式
class singleon1
{
public:
	static singleon1* getInstance();

private:
	singleon1() {};
	static singleon1* ms_pInstance;
};

// 这里我有一些疑惑：为什么这里可以使用new? 是因为ms_pInstance是类内的静态成员吗？
singleon1* singleon1::ms_pInstance = new singleon1;
singleon1* singleon1::getInstance()
{
	return ms_pInstance;
}



// 方法二： 异常安全的懒汉模式
class singleon2
{
public:
	static singleon2* GetInstance();
private:
	singleon2() {};	// 禁止构造
	singleon2& operator=(const singleon2&);	// 禁止拷贝
	static singleon2* ms_pInstance;
	static mutex ms_mutex;
};

singleon2* singleon2::ms_pInstance = nullptr;
mutex singleon2::ms_mutex;
singleon2* singleon2::GetInstance()
{
	if (ms_pInstance == nullptr)
	{
		ms_mutex.lock();
		if (ms_pInstance == nullptr)
		{
			ms_pInstance = new singleon2;
		}
		ms_mutex.unlock();
	}
	return ms_pInstance;
}

int main()
{
	return 0;
}
