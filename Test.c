#include<stdio.h>
#include"head.h"
void menu() {
	printf("************************************\n");
	printf("*********1.inc*******2.print********\n");
	printf("*********3.del*******4.find*********\n");
	printf("************************************\n");
	printf("**************0.exit****************\n");
}
enum xx {   //����ö������,���ԱΪö�ٳ���
	exit,   //�˳�
	inc,   //����
	print,   //��ӡ
	del,  //ɾ��
	find  //����
};
int main(){
	int input = 0;
	pers ps; //�ýṹ������pers����������������ȡ��Ϣ��
	csh(&ps);    //csh�������ڳ�ʼ���ṹ�����ps��
	do {
		menu();
		printf("������ѡ��:");
		scanf_s("%d", &input);
		switch (input) {
		case exit:
			exitt(&ps); //���ṹ��ps�µĶ�̬�ڴ��ͷš�
			printf("�˳��ɹ���");
			break;
		case inc:
			incadd(&ps);
			break;
		case print:
			printt(&ps);
			break;
		case del:
			dell(&ps);
			break;
		case find:
			findd(&ps);
			break;
		default:
			printf("������������������.\n");
			break;
		}
	} while (input);
	return 0;
}