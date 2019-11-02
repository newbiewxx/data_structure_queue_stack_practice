/* 2019年11月2日 19:39:44 */
#include<stdio.h>

/*
回文是指正读反读均相同的字符序列，试写一个算法判定给定的字符序列是否为回文
*/

int IsPalindrome(char * t)
{ 
	// 判断t字符向量是否为回文，是则返回1，否则为0
	InitStack(S);
	len = strlen(t);  // 求向量长度

	for (i=0; i<len/2; i++)
	{
		Push(S, t[i]);  // 将一半数据压入栈中
	}

	if (len % 2 != 0)  // 判断字符是否为奇数个
	{
		i++;
	}

	while (!EmptyStack(S)) // 判断是否栈空
	{
		temp = Pop(S);
		if (temp != t[i])
		{
			return 0;
		}
		else
		{
			i++;
		}
	}
	return 1;  // 比较完毕，是回文
}
