// ����

#include  "contact.h"

void menu()
{
	printf("**************************************************\n");
	printf("*********   1.add                2.del    ********\n");
	printf("*********   3.search             4.modify ********\n");
	printf("*********   5.show               6.sort   ********\n");
	printf("*********   0.exit                        ********\n");
	printf("**************************************************\n");
}

int main()
{
	int input = 0;
	//����ͨѶ¼
	//con����ͨѶ¼����߰�����1000��Ԫ�ص�����size
	struct Contact con;
	//��ʼ��ͨѶ¼
	InitContact(&con);
	do
	{
		menu();
		printf("��ѡ��:>");
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
			AddContact(&con);
			break;
		case DEL:
			DelContact(&con);
			break;
		case SERACH:
			SerachContact(&con);
			break;
		case MODIFY:
			ModifyContact(&con);
			break;
		case SHOW:
			ShowContact(&con);
			break;
		case SORT:
			break;
		case EXIT:
			printf("�˳�ͨѶ¼\n");
			break;
		default:
			printf("�����������������:\n");
			break;
		}
	} while (input);
	return 0;
}