//add.c用于函数的实现
#include"head.h"
#include<stdio.h>
#include<stdlib.h>
void csh(pers* ps) {   //csh函数用来实现结构体pers的初始化
	//动态内存开辟函数会返回开辟好的连续的内存空间的首地址。由p来接收
	ps->p=(people*)calloc(3, sizeof(people));  //在堆空间里开辟3个people大小的空间
	ps->sz = 0;
	ps->max = 3;   
}
void incadd(pers* ps) {
	if (ps->sz == ps->max) {
		//指针类型表示你想以什么方式来操作开辟的动态内存
		people* t=(people*)realloc(ps->p, (ps->sz + 3) * sizeof(people)); //在原有的大小上+3*sizeof(people)
		if (t == NULL) {
			printf("开辟失败");
			return;
		}
		else {
			ps->p = t;
			ps->max += 3;  //最大值增加,以便于下次判断.
			printf("增容成功\n");
		}
	}
	printf("请输入姓名:");
	scanf_s("%s", ps->p[ps->sz].name,20);
	printf("请输入年龄:");
	scanf_s("%d", &(ps->p[ps->sz].age));
	printf("请输入性别:");
	scanf_s("%s", ps->p[ps->sz].sex,5);
	printf("请输入电话号码:");
	scanf_s("%s", ps->p[ps->sz].number,20);
	ps->sz++;
	printf("插入成功!\n");
}
void printt(pers* ps) {    //函数printt用于实现通讯录的全部信息的打印
	printf("%-20s\t%-5s\t%-12s\t%-20s\n", "姓名", "年龄", "性别", "电话");
	int i = 0;
	for (i = 0; i < (ps->sz); i++) {  //通讯录里有几个人，打印几次
		printf("%-20s\t%-5d\t%-12s\t%-20s\n", ps->p[i].name, ps->p[i].age, ps->p[i].sex, ps->p[i].number);
	}
}
static int fd(pers* ps, char name[]) {   //函数fd用于找数组中同名的情况，并返回数组下标。
	int i = 0;
	for (i = 0; i < ps->sz; i++) {  //遍历数组p[]
		if (name == ps->p[i].name) {  
			return i; //如果找到了，返回下标。
		}
	}
	return 0; 
}
void dell(pers* ps) {   //dell函数用于删除通讯录中的数据
	if (ps->sz == 0) {
		printf("通讯录中没有数据，无法删除.\n");
		return;
	}
	char name[10] = "0";
	printf("请输入要删除联系人的姓名:");
	scanf_s("%s", name,10);
	int i=fd(ps, name);  //i表示元素的下标
	int j = 0;
	for (j = i; j < ps->sz-1; j++) {
		ps->p[j] = ps->p[j + 1];
	}
	ps->sz--;                     //当要删除最后一个元素时，不进入循环，sz--，则会忽略最后一个元素。
	printf("删除成功！\n");
}
void findd(pers* ps) {   //findd函数实现查找通讯录里的信息
	char name[10] = "0";
	printf("请输入要查找人的姓名:");
	scanf_s("%s", name, 10);
	int ret = fd(ps, name);
	if (ret == 0) {
		printf("查无此人\n");
	}
	else {
		printf("%-20s\t%-5s\t%-12s\t%-20s\n", "姓名", "年龄", "性别", "电话");
		printf("%-20s\t%-5d\t%-12s\t%-20s\n", ps->p[ret].name, ps->p[ret].age, ps->p[ret].sex, ps->p[ret].number);
	}
}
void exitt(pers* ps) {
	free(ps->p);
	ps->sz = 0;
	ps->max = 3;
}