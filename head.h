//define���ڶ��峣�������ڶ�����������ֵ���Ա��ں����޸ġ�
#define MAX_NAME 20;
#define MAX_SEX 5;
#define MAX_NUMBER 20;

#define MAX_P 10;
typedef struct people {                     //typedef���ڽṹ������struct people������,Ϊpeolple
	char name[20];
	int age;
	char sex[5];
	char number[20];
}people;

typedef struct personnel {
	people* p;    //����һ��people���͵ı������������ն������ٵĿռ���׵�ַ�����ڹ���
	int sz;    ///sz����������������ͨѶ¼���������
	int max;    //max��ʾ���ռ�
}pers;   //persΪ�ṹ������

//��������
void incadd(pers* p);
void csh(pers* ps);
void printt(pers* ps);
void dell(pers* ps);
void findd(pers* ps);
void exitt(pers* ps);