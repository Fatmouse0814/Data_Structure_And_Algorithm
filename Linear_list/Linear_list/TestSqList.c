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
		printf("%dλ�õ�Ԫ����%d\n",pos,e);
		s = List_Prior(list, pos, &e);
		if (s == success)
		{
			printf("ǰ��Ԫ����%d\n", e);
		}
		else printf("����ǰ��Ԫ��ʧ��");

		s = List_Next(list, pos, &e);
		if (s == success)
		{
			printf("���Ԫ����%d\n", e);
		}
		else printf("���Һ��Ԫ��ʧ��");
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
		printf("%d��Ԫ�ش���%d\n", e, pos);
	}
	else printf("����λ��ʧ��\n");
	return s;
}
void Test_Size(SqListPtr list)
{
	int len;
	len = List_Size(list);
	printf("���Ա�ĳ�����%d\n", len);
}