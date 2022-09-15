//��������

#include <stdio.h>
#include <string.h>

#define MAX 1000

#define MAX_NAME 20
#define	MAX_SEX 5
#define MAX_TELE 12
#define MAX_ADDR 20


enum Option
{
	EXIT, //0
	ADD,  //1
	DEL, 
	SERACH,
	MODIFY,
	SHOW,
	SORT

};

struct PeoInFo
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
};

//ͨѶ¼����
struct Contact
{
	//���1000����Ϣ
	struct PeoInFo data[MAX];
	//��¼��ǰ�Ѿ��е�Ԫ�ظ���
	int size;
};

//��������
//��ʼ��ͨѶ¼�ĺ���
void InitContact(struct Contact* ps);

//����һ����Ϣ��ͨѶ¼
void AddContact(struct Contact* ps);

//��ӡͨѶ¼�е���Ϣ
void ShowContact(const struct Contact* ps);

//ɾ��ָ������ϵ��
void DelContact(struct Contact* ps);

//����ָ�����˵���Ϣ
void SerachContact(const struct Contact* ps);

//�޸�ָ����ϵ��
void ModifyContact(struct Contact* ps);