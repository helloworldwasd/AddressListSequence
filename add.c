//add.c���ں�����ʵ��
#include"head.h"
#include<stdio.h>
#include<stdlib.h>
void csh(pers* ps) {   //csh��������ʵ�ֽṹ��pers�ĳ�ʼ��
	//��̬�ڴ濪�ٺ����᷵�ؿ��ٺõ��������ڴ�ռ���׵�ַ����p������
	ps->p=(people*)calloc(3, sizeof(people));  //�ڶѿռ��￪��3��people��С�Ŀռ�
	ps->sz = 0;
	ps->max = 3;   
}
void incadd(pers* ps) {
	if (ps->sz == ps->max) {
		//ָ�����ͱ�ʾ������ʲô��ʽ���������ٵĶ�̬�ڴ�
		people* t=(people*)realloc(ps->p, (ps->sz + 3) * sizeof(people)); //��ԭ�еĴ�С��+3*sizeof(people)
		if (t == NULL) {
			printf("����ʧ��");
			return;
		}
		else {
			ps->p = t;
			ps->max += 3;  //���ֵ����,�Ա����´��ж�.
			printf("���ݳɹ�\n");
		}
	}
	printf("����������:");
	scanf_s("%s", ps->p[ps->sz].name,20);
	printf("����������:");
	scanf_s("%d", &(ps->p[ps->sz].age));
	printf("�������Ա�:");
	scanf_s("%s", ps->p[ps->sz].sex,5);
	printf("������绰����:");
	scanf_s("%s", ps->p[ps->sz].number,20);
	ps->sz++;
	printf("����ɹ�!\n");
}
void printt(pers* ps) {    //����printt����ʵ��ͨѶ¼��ȫ����Ϣ�Ĵ�ӡ
	printf("%-20s\t%-5s\t%-12s\t%-20s\n", "����", "����", "�Ա�", "�绰");
	int i = 0;
	for (i = 0; i < (ps->sz); i++) {  //ͨѶ¼���м����ˣ���ӡ����
		printf("%-20s\t%-5d\t%-12s\t%-20s\n", ps->p[i].name, ps->p[i].age, ps->p[i].sex, ps->p[i].number);
	}
}
static int fd(pers* ps, char name[]) {   //����fd������������ͬ��������������������±ꡣ
	int i = 0;
	for (i = 0; i < ps->sz; i++) {  //��������p[]
		if (name == ps->p[i].name) {  
			return i; //����ҵ��ˣ������±ꡣ
		}
	}
	return 0; 
}
void dell(pers* ps) {   //dell��������ɾ��ͨѶ¼�е�����
	if (ps->sz == 0) {
		printf("ͨѶ¼��û�����ݣ��޷�ɾ��.\n");
		return;
	}
	char name[10] = "0";
	printf("������Ҫɾ����ϵ�˵�����:");
	scanf_s("%s", name,10);
	int i=fd(ps, name);  //i��ʾԪ�ص��±�
	int j = 0;
	for (j = i; j < ps->sz-1; j++) {
		ps->p[j] = ps->p[j + 1];
	}
	ps->sz--;                     //��Ҫɾ�����һ��Ԫ��ʱ��������ѭ����sz--�����������һ��Ԫ�ء�
	printf("ɾ���ɹ���\n");
}
void findd(pers* ps) {   //findd����ʵ�ֲ���ͨѶ¼�����Ϣ
	char name[10] = "0";
	printf("������Ҫ�����˵�����:");
	scanf_s("%s", name, 10);
	int ret = fd(ps, name);
	if (ret == 0) {
		printf("���޴���\n");
	}
	else {
		printf("%-20s\t%-5s\t%-12s\t%-20s\n", "����", "����", "�Ա�", "�绰");
		printf("%-20s\t%-5d\t%-12s\t%-20s\n", ps->p[ret].name, ps->p[ret].age, ps->p[ret].sex, ps->p[ret].number);
	}
}
void exitt(pers* ps) {
	free(ps->p);
	ps->sz = 0;
	ps->max = 3;
}