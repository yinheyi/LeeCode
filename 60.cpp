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
*   Created Time: 2019年05月04日 星期六 17时47分28秒
*   Modifed Time: 2019年05月04日 星期六 20时13分44秒
*   Blog: http://www.cnblogs.com/yinheyi
*   Github: https://github.com/yinheyi
*   
***********************************************************************/

#include <iostream>
#include <cmath>

void Count(int CurrentSum_, int nCurrentDepth_, int Depth_, int ResultArray[])
{
	if (nCurrentDepth_ <  Depth_)
	{
		Count(CurrentSum_ + 1, nCurrentDepth_ + 1, Depth_, ResultArray);
		Count(CurrentSum_ + 2, nCurrentDepth_ + 1, Depth_, ResultArray);
		Count(CurrentSum_ + 3, nCurrentDepth_ + 1, Depth_, ResultArray);
		Count(CurrentSum_ + 4, nCurrentDepth_ + 1, Depth_, ResultArray);
		Count(CurrentSum_ + 5, nCurrentDepth_ + 1, Depth_, ResultArray);
		Count(CurrentSum_ + 6, nCurrentDepth_ + 1, Depth_, ResultArray);
	}
	else
	{
		++ResultArray[CurrentSum_];
	}
}

/***************    main.c     *********************/
int main(int argc, char* argv[])
{
	// 骰子的个数
	int nCount = 10;
	int* array = new int[6 * nCount + 1]{0};
	Count(0, 0, nCount, array);

	int nTobal = std::pow(6, nCount);
	for (int i = nCount; i <= nCount * 6; ++i)
	{
		std::cout << "和为" << i << "的概率为：" << (double)array[i] / nTobal << std::endl;
	}


	return 0;
 }

