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
#define AscendingOrder 2
#define DescendingOrder 1
/*定义链表节点*/
typedef struct linknode
{
	int Data;
	linknode* Next;
}LinkNode;

LinkNode *Head=NULL;

bool AddNodeToLink(int InsertData);
void PrintLink();
void SortLink();

int _tmain(int argc, _TCHAR* argv[])
{
	int DataTotalNum,Index,TempData;
	bool InsertResult;       /*链表插入结果，true 成功，false 失败*/

	printf("Please input the inter num:");
	scanf("%d",&DataTotalNum);

	if(DataTotalNum <= 0)
	{
		printf("Data num error!\n");
		return 0;
	}

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

	SortLink();

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


void SortLink()
{
	LinkNode *OuterLoopPointer=NULL;/*外层循环遍历指针*/
	LinkNode *InnerLoopPointer=NULL;/*内层循环遍历指针*/
	int DataTemp;					/*存储内层循环遍历找到的极值*/
	LinkNode *IndexPointer=NULL;	/*内层循环遍历极值对应的指针*/

	if(NULL==Head)
	{
		printf("The list is empty!!!\n");
		return;
	}

	if(NULL==Head->Next)
	{
		printf("There is only one node in the list, so no need to rank it!!!\n");
		return;
	}
	
	OuterLoopPointer=Head;

	while(NULL != OuterLoopPointer->Next)
	{
		InnerLoopPointer=OuterLoopPointer->Next;

		DataTemp=InnerLoopPointer->Data;
		IndexPointer=InnerLoopPointer;

		while(NULL != InnerLoopPointer)
		{
			InnerLoopPointer=InnerLoopPointer->Next;

			if(NULL != InnerLoopPointer)
			{
				if(InnerLoopPointer->Data < DataTemp)
				{
					DataTemp=InnerLoopPointer->Data;
					IndexPointer=InnerLoopPointer;
				}
			}
		}

		/*如果内层循环遍历出来的极小值比当前外层循环值小，则交换数据域*/
		if(DataTemp < OuterLoopPointer->Data)
		{
			IndexPointer->Data=OuterLoopPointer->Data;
			OuterLoopPointer->Data=DataTemp;
		}


		OuterLoopPointer=OuterLoopPointer->Next;/*移动外部循环指针*/

	}

}