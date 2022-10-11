#include <bits/stdc++.h>
#include <time.h>
using namespace std;
typedef struct Student
{
	int a[20];	   //考勤情况 0为未到 1为到
	double credit; //绩点
	int flag;	   // 80%缺勤标志 1为不是此类人
	int count;	   //已经缺勤次数
} S;
S s[90];			   //学生结构体
int absent_count = 90; // 80%缺勤人数
int class_count = 0;   //上课次数
int total_number = 0;  //总有效点名次数
int total_count = 0;   //总请求次数
S as[90];			   //经常缺席学生数组
int con = 0;		   // 5-8人迟到，给五次
int course = 0;		   //上课种类科目1科目2


void Init();
double calculateE();
void Deal();
void Update();