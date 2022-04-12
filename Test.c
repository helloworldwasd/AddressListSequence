#include<stdio.h>
#include"head.h"
void menu() {
	printf("************************************\n");
	printf("*********1.inc*******2.print********\n");
	printf("*********3.del*******4.find*********\n");
	printf("************************************\n");
	printf("**************0.exit****************\n");
}
enum xx {   //定义枚举类型,其成员为枚举常量
	exit,   //退出
	inc,   //增加
	print,   //打印
	del,  //删除
	find  //查找
};
int main(){
	int input = 0;
	pers ps; //用结构体类型pers创建变量，用来存取信息。
	csh(&ps);    //csh函数用于初始化结构体变量ps。
	do {
		menu();
		printf("请输入选项:");
		scanf_s("%d", &input);
		switch (input) {
		case exit:
			exitt(&ps); //讲结构体ps下的动态内存释放。
			printf("退出成功！");
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
			printf("输入有误，请重新输入.\n");
			break;
		}
	} while (input);
	return 0;
}