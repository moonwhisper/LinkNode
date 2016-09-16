// linknode.cpp : 定义控制台应用程序的入口点。
//

/*主函数功能：从控制台录入一组数（小于10000整数，每个数接一个回车)，存入链表，排序，链表打印输出
三个子功能分别为：链表增加、排序、链表打印
子功能借助于函数实现				  
输入：无
输出：无
*/

#include "stdafx.h"
#include <stdlib.h>

/*定义链表节点*/
typedef struct linknode
{
	int Data;
	linknode* Next;
}LinkNode;

LinkNode *Head=NULL;

bool AddNodeToLink(int InsertData);
void PrintLink();

int _tmain(int argc, _TCHAR* argv[])
{
	int DataTotalNum,Index,TempData;
	bool InsertResult;       /*链表插入结果，true 成功，false 失败*/

	printf("Please input the inter num:");
	scanf("%d",&DataTotalNum);
	printf("Data Input,each data ended with a Enter:");
	
	/*从控制台读取数据，并插入链表*/
	for(Index=0;Index<DataTotalNum;Index++)
	{
		scanf("%d",&TempData);

		InsertResult=AddNodeToLink(TempData);    /*链表插入*/
		if(false==InsertResult)
		{
			printf("Insert fail!\n");
			return 0;
		}
	}

	PrintLink();

	//printf("%d\n",DataTotalNum);

	return 0;
}

bool AddNodeToLink(int InsertData)
{
	LinkNode *CurrentPointer=NULL;/*当前指针，用于定位链表的尾节点*/
	LinkNode *NewPointer=NULL;
	
	NewPointer=(LinkNode *)malloc(sizeof(LinkNode));
	if(NULL==NewPointer)
	{
		printf("Memory alloc fail!!!\n");
		return false; 
	}
	NewPointer->Data=InsertData;   /*新的节点插在链表尾部*/
	NewPointer->Next=NULL;

	if(NULL==Head)					/*链表为空*/
	{
		Head=NewPointer;
		return true;
	}		
	else							/*链表不为空*/
	{
		CurrentPointer=Head;
		while(NULL!=CurrentPointer->Next)
		{
			CurrentPointer=CurrentPointer->Next;
		}
		CurrentPointer->Next=NewPointer;
		return true;
	}
}

void PrintLink()
{
	LinkNode *CurrentPointer=NULL;
	if(NULL==Head)
	{
		printf("The list is empty!!\n");
		return;
	}
	else
	{
		printf("The list values are:");

		CurrentPointer=Head;

		while(NULL!=CurrentPointer->Next)
		{
			printf("%d ",CurrentPointer->Data);
			CurrentPointer=CurrentPointer->Next;
		}

		printf("%d\n",CurrentPointer->Data);
		return;

	}
}