/* 2019年11月2日 18:12:05 */
#include<stdio.h>

/* 题目:
假设以带头结点的循环链表表示队列，并且只设一个指针指向队尾元素结点，不设头指针
编写相应的指控队列，判断队列是否为空，入队以及出队的算法
*/



/********************队列链式存储结构****************/
typedef struct QNode
{
	QElemType data;
	struct QNode * next;
}QNode, * QueuePtr;   

typedef struct
{
	QueuePtr rear;     // 只设一个队尾指针
}LinkQueue;

void InitQueue(LinkQueue &Q)
{
	// 置空队列
	Q->rear = Q->rear->next; // 将尾指针指向了头结点

	while (Q->rear != Q->rear->next) {  // 队列非空时
		s = Q->rear->next; // s指向头元素
		Q->rear->next = s->next; // 尾结点指针域指向新的对头元素
		delete s;
	}
}

int EmptyQueue(LinkQueue &Q)
{
	// 判断队是否为空，空返回1，否则返回0
	// 队列只有一个头结点，即当头结点的指针域指向自己时，队为空
	return Q->rear->next->next == Q->rear->next;
}

Status EnQueue(LinkQueue &Q, QElemType e)
{
	// 入队，插入元素e为Q的队尾元素
	p = new QueueNode;  // 创建新结点
	p->data = e;
	p = Q->rear->next;  // 新节点插到队尾
	Q->rear->next = p;
	Q->rear = p;
	return OK;
}

Status DeQueue(LinkQueue &Q, QElemType &e)
{
	// 出队，删除Q的对头元素，用e返回其值
	if (Q->rear->next->next == Q->rear->next) // 队为空
	{
		return ERROR;
	}
	
	p = Q->rear->next->next;  // 保留对头元素
	e = p->data;  // 保存数据
	if (p == Q->rear)  // 只有一个节点时
	{
		Q->rear = Q->rear->next;  // 修改指针，指向头结点
		Q->rear->next = p->next;
	}
	else
		Q->rear->next->next = p->next; // 摘下结点p
	delete p;
	return OK;   // 释放原对头元素的空间
}
