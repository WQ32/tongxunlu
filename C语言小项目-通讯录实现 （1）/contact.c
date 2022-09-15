//实现函数功能
//1.存放1000个好友的信息
// 名字，电话，性别，住址，年龄
// 2.增加好友信息
// 3.删除指定名字的好友消息
// 4.查找好友信息
// 5.修改好友信息
// 6.打印好友信息
// 7.排序

#include "contact.h"

void InitContact(struct Contact* ps)
{
	//设置通讯录最初只有0个元素
	memset(ps->data, 0, sizeof(ps->data));
	ps->size = 0;
}

void AddContact(struct Contact* ps)
{
	if (ps->size == MAX)
	{
		printf("通讯录已满，无法再添加……");
	}
	else
	{
		printf("请输入名字:");
		scanf("%s", ps->data[ps->size].name);
		printf("请输入年龄:");
		scanf("%d", &(ps->data[ps->size].age));  //数字,要取地址
		printf("请输入性别:");
		scanf("%s", ps->data[ps->size].sex);
		printf("请输入电话:");
		scanf("%s", ps->data[ps->size].tele);
		printf("请输入地址:");
		scanf("%s", ps->data[ps->size].addr);
		ps->size++;
		printf("添加成功\n");
	}
}

void ShowContact(const struct Contact* ps)
{
	if (ps->size == 0)
	{
		printf("通讯录为空\n");
	}
	else
	{
		int i = 0;
		//标题
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n", "名字", "年龄", "性别", "电话", "住址");
		//数据
		for (i = 0; i < ps->size; i++)
		{
			printf("%-20s\t%-4d\t%-5s\t%-12s\t%-20s\n",
				ps->data[i].name,
				ps->data[i].age,
				ps->data[i].sex,
				ps->data[i].tele,
				ps->data[i].addr);
		}
	}
}

//用static是指这个函数只在这个文件中使用
static int FindByName(const struct Contact* ps, char name[MAX_NAME]) 
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		if (0 == strcmp(ps->data[i].name,name))
		{
			return i;
		}
	}
	return -1; //找不到的情况
}

void DelContact(struct Contact* ps)
{
	char name[MAX_NAME];
	printf("请输入要删除的人的名字:>");
	scanf("%s", name);
	//1. 查找要删除的人在什么位置
	//找到了返回名字所在元素的下标
	//找不到返回 -1
	int pos = FindByName(ps, name);
	if (pos == -1)
	{
		printf("要删除的人不存在……");
	}
	//2. 删除
	else
	{
		//删除数据
		int j = 0;
		for (j = pos; j < ps->size - 1; j++)
		{
			ps->data[j] = ps->data[j + 1];
		}
		ps->size--;
		printf("删除成功!\n");
	}
}

void SerachContact(const struct Contact* ps)
{
	char name[MAX_NAME];
	printf("请输入要查找的人的名字:>");
	scanf("%s", name);
	int pos = FindByName(ps, name);
	if (pos == -1)
	{
		printf("此人未被查找到……");
	}
	else
	{
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n", "名字", "年龄", "性别", "电话", "住址");
		printf("%-20s\t%-4d\t%-5s\t%-12s\t%-20s\n",
			ps->data[pos].name,
			ps->data[pos].age,
			ps->data[pos].sex,
			ps->data[pos].tele,
			ps->data[pos].addr);
	}
}

void ModifyContact(struct Contact* ps)
{
	char name[MAX_NAME];
	printf("请输入要修改人的姓名:>");
	scanf("%s", name);
	int pos = FindByName(ps, name);
	if (pos == -1)
	{
		printf("不存在这个人……\n");
	}
	else
	{
		printf("请输入名字:>");
		scanf("%s", ps->data[pos].name);
		printf("请输入年龄:>");
		scanf("%d", &(ps->data[pos].age));
		printf("请输入性别:>");
		scanf("%s", ps->data[pos].sex);
		printf("请输入电话:>");
		scanf("%s", ps->data[pos].tele);
		printf("请输入地址:>");
		scanf("%s", ps->data[pos].addr);

		printf("修改完成\n");
	}
}