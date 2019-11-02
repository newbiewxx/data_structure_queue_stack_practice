/* 2019年11月2日 19:53:25 */
#include<stdio.h>

/* 已知f为单链表的表头指针，链表中存储的都是整形数据，是写出以下递归算法  
 * 1. 求链表中最大整数
 * 2. 求链表的结点整数
 * 3. 求所有整数的平均数
 */



// 第一问
int getMaxNumber(Linklist p)
{
	if (!p->next)  // 出口 判断是否指向链尾 
	{
		return p->data;
	}
	else
	{
		int max = getMaxNumber(p->next); // 递归体
		return p->data >=max ? p->data : max; // 返回较大者 
	}
}

// 第二问
int getLength(LinkList p)
{	
	// 递归求解链表的个数
	if (!p>next) // 出口 判断是否指向链尾
	{
		return 1;
	}
	else
	{
		return 	getLength(p->next) + 1;   // 递归体
	}	
}

//第三问
int getAverage(LinkList p, int n)
{
	// 递归求解链表中所有整数的平均值
	if (!p->next) // 出口 判断是否指向链尾
	{
		return p->data;
	}
	else
	{
		double ave = getAverage(p->next, n-1);
		// 递归求解解除尾结点之外其余n-1个节点的平均值
		return (ave*(n-1) + p->data)/n;  // 返回平均值
	}
}
