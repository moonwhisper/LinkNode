// linknode.cpp : �������̨Ӧ�ó������ڵ㡣
//

/*���������ܣ��ӿ���̨¼��һ������С��10000������ÿ������һ���س�)�������������������ӡ���
�����ӹ��ֱܷ�Ϊ���������ӡ����������ӡ
�ӹ��ܽ����ں���ʵ��				  
���룺��
�������
*/

#include "stdafx.h"
#include <stdlib.h>

/*��������ڵ�*/
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
	bool InsertResult;       /*�����������true �ɹ���false ʧ��*/

	printf("Please input the inter num:");
	scanf("%d",&DataTotalNum);
	printf("Data Input,each data ended with a Enter:");
	
	/*�ӿ���̨��ȡ���ݣ�����������*/
	for(Index=0;Index<DataTotalNum;Index++)
	{
		scanf("%d",&TempData);

		InsertResult=AddNodeToLink(TempData);    /*�������*/
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
	LinkNode *CurrentPointer=NULL;/*��ǰָ�룬���ڶ�λ�����β�ڵ�*/
	LinkNode *NewPointer=NULL;
	
	NewPointer=(LinkNode *)malloc(sizeof(LinkNode));
	if(NULL==NewPointer)
	{
		printf("Memory alloc fail!!!\n");
		return false; 
	}
	NewPointer->Data=InsertData;   /*�µĽڵ��������β��*/
	NewPointer->Next=NULL;

	if(NULL==Head)					/*����Ϊ��*/
	{
		Head=NewPointer;
		return true;
	}		
	else							/*����Ϊ��*/
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