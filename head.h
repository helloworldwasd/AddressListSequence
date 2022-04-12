//define用于定义常量，用于定义数组的最大值，以便于后期修改。
#define MAX_NAME 20;
#define MAX_SEX 5;
#define MAX_NUMBER 20;

#define MAX_P 10;
typedef struct people {                     //typedef用于结构体类型struct people重命名,为peolple
	char name[20];
	int age;
	char sex[5];
	char number[20];
}people;

typedef struct personnel {
	people* p;    //定义一个people类型的变量，用来接收堆区开辟的空间的首地址，便于管理。
	int sz;    ///sz用作计算器，计算通讯录里的人数。
	int max;    //max表示最大空间
}pers;   //pers为结构体类型

//函数声明
void incadd(pers* p);
void csh(pers* ps);
void printt(pers* ps);
void dell(pers* ps);
void findd(pers* ps);
void exitt(pers* ps);