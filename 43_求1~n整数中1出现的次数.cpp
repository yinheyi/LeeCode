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
*   Created Time: 2019年04月28日 星期日 07时15分21秒
*   Modifed Time: 2019年04月28日 星期日 23时35分27秒
*   Blog: http://www.cnblogs.com/yinheyi
*   Github: https://github.com/yinheyi
*   
***********************************************************************/


#include <iostream>
// 题目： 求1~n中整数中出现1的个数， 例如输入12, 这些数字中包含1的有：1, 10, 11, 12,共有
// 5个1.
//
// 想法： 先求个位数中的1的个数, 再求十位数中出现中的1的个数, ......
// 1. 对于个位数来说，个数位中的1,随着整数不断的增加时每10次出现一次， 并且还要考虑当前
// 	  个位数的大小（就是不足10个一循环时中的1），可以总结为： 
// 	  n/10 * 1 +  当 n%10 < 1时, 为0;
//                当 n%10 >= 1并且 <2时，为n%1 + 1, 即为1
//                当 n%10 >= 2时， 为1;
// 2. 对于 十位数来说， 十位数中的1，随着整数不断的增加时每100次出现10次， 并且同样要考
//    虑不满足100次一循环的时候（就是考虑十位数与个位数的大小）， 可以总结为：
//    n/100 * 10 + 当 n%100 < 10时， 为0.
//                 当 n%100 >= 10 并且 <20时， 为n%10 + 1.
//                 当 n%100 >= 20时， 为10.
//3. 对于百位数来说， 百位数中的1随着整数不断增加时每1000次出现100次， 并且同样要考虑不
//   足 1000次一循环的时候，可以总结为：
//   n / 1000 * 100 + 当 n%1000 < 100时， 为0
//                    当 n%1000 >= 100 并且< 200时， 为n%100 + 1.
//                    当 n%1000 >= 200时，为100.
//4. .....
//5. .....
//6. .....
//
int Numof1(int number)
{
	int nSum = 0;
	int nFactor = 10;
	while (true)
	{
		int nQuotient = number / nFactor;
		int nModulus = number % nFactor;
		int nDeci = nFactor / 10;

		// a...........
		if (nModulus  <  nDeci)
		{
			// do nothting.
		}
		else if (nModulus >= nDeci && nModulus < 2 * nDeci)
		{
			nSum = nSum + number % nDeci + 1;
		}
		else
		{
			nSum += nDeci;
		}

		// d.......
		if (nQuotient == 0)
		{
			break;
		}
		else
		{
			nSum += nQuotient * nDeci;
			nFactor *= 10;
		}
	}

	return nSum;
}
/***************    main.c     *********************/
int main(int argc, char* argv[])
{
	int nInputValue;
	while (std::cin >> nInputValue)
	{
		std::cout << Numof1(nInputValue) << std::endl;
	}

	return 0;
}

