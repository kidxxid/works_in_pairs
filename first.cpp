#include <bits/stdc++.h>
using namespace std;

typedef struct Student
{
    string name; //姓名
    int number;  //学号
    int count;   //迟到次数
    int flag;    // 80%缺勤标志 1为不是此类人

} S;
S s[90];              //学生结构体
int abs80_count = 90; // 80%缺勤人数
int class_count = 0;  //上课次数
int total_number = 0; //总有效点名次数
int total_count = 0;  //总请求次数
int absent_count = 0; //经常缺席人数
S as[90];             //经常缺席学生数组

//初始化
void Init()
{
    for (int i = 0; i < 90; i++)
    {
        s[i].count = 0;
        s[i].flag = 0;
    }
}

//如果 上课次数-s.count==5,则不是80%缺勤的人
//如果
void Deal()
{
    for (int i = 0; i < 90; i++)
    {
        if (class_count - s[i].count == 5)
        {
            s[i].flag = 1;
        }
    }
}

//更新经常缺勤名单
void Update()
{
    int j = 0;
    for (int i = 0; i < 90; i++)
    {
        if (s[i].flag == 0)
        {
            as[j] = s[i];
            j++;
        }
    }
    absent_count = j;
}

int main()
{
    Init();

    return 0;
}