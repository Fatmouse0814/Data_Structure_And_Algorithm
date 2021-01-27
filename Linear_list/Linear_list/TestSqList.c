#include<stdio.h>
#include"TestSqList.h"

Status Test_CreateList(SqListPtr list, ElemType data[], int n)
{
	int i;
	Status s = fail;
	s = List_Init(list);
	if (s == success)
	{
		for (i = 0; i < n; i++)
		{
			s = List_Insert(list, (i+1), data[i]);
			if (s != success)
				break;
		}
		List_Print(list);
	}
	return s;
}
Status Test_ClearList(SqListPtr list)
{
	Status s = fail;
	if (!List_Empty(list))
	{
		List_Clear(list);
		if (List_Empty(list))
		{
			s = success;
		}
	}
	return s;
}
Status Test_RetrivalPriorNext(SqListPtr list,int pos)
{
	Status s = range_error;
	ElemType e;
	s = List_Retrival(list, pos, &e);
	if (s == success)
	{
		printf("%d位置的元素是%d\n",pos,e);
		s = List_Prior(list, pos, &e);
		if (s == success)
		{
			printf("前驱元素是%d\n", e);
		}
		else printf("查找前驱元素失败");

		s = List_Next(list, pos, &e);
		if (s == success)
		{
			printf("后继元素是%d\n", e);
		}
		else printf("查找后继元素失败");
	}
	return s;
}
Status Test_Locate(SqListPtr list,ElemType e)
{
	Status s;
	int pos;
	s = List_Locate(list, e, &pos);
	if (s == success)
	{
		printf("%d的元素处于%d\n", e, pos);
	}
	else printf("查找位置失败\n");
	return s;
}
void Test_Size(SqListPtr list)
{
	int len;
	len = List_Size(list);
	printf("线性表的长度是%d\n", len);
}