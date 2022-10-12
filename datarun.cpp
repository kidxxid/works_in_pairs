#include "inclu.h"
#include "data.h"
using namespace std;

int main()
{
    for (int i = 0; i < 5; i++)
    {
        List();
    }
    return 0;
}
void Init()
{
    int j;
    for (int i = 0; i < 90; i++)
    {
        s[i].count = 0;
        s[i].flag = 0;
        for (j = 0; j < 20; j++)
        {
            s[i].a[j] = 1;
        }
        for (int i = 0; i < 90; i++)
        {
            j = rand() % 30;
            s[i].credit = 0.1 * j + 1; //����
        }
    }
}

void List()
{ //表单

    int temp[11] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}, t, t1, j, bd = 0, k;
    Init();
    con = rand() % 4 + 5;
    for (int i = 0; i < con; i++)
    { //给5-8人设置缺勤情况
        t = rand() % 90;
        for (j = 0; j < 8; j++)
        {
            if (t == temp[j] || s[t].credit > 2.5)
            {
                i--;
                break;
            }
        }
        if (j == 8)
        {
            temp[bd] = t;
            bd++;
            for (k = 0; k < 16; k++)
            {
                t1 = rand() % 20;
                if (s[t].a[t1] == 1)
                {
                    s[t].a[t1] = 0;
                }
                else
                {
                    k--;
                }
            }
        }
    }
    for (int i = 0; i < 20; i++)
    { // 0-3
        bd = con;
        for (j = con; j < 11; j++)
        {
            temp[con] = -1;
        }
        t = rand() % 4;
        for (k = 0; k < t; k++)
        {
            t1 = rand() % 90;
            for (j = 0; j < con + t; j++)
            {
                if (t1 == temp[k])
                {
                    k--;
                    break;
                }
            }
            if (j == con + t)
            {
                temp[bd] = t1;
                bd++;
                s[t1].a[i] = 0;
            }
        }
    }
    FILE *fp;
    if (course == 0)
        fp = fopen("科目1.txt", "w+"); //打开文件以便写入数据
    if (course == 1)
        fp = fopen("科目2.txt", "w+"); //打开文件以便写入数据
    if (course == 2)
        fp = fopen("科目3.txt", "w+"); //打开文件以便写入数据
    if (course == 3)
        fp = fopen("科目4.txt", "w+"); //打开文件以便写入数据
    if (course == 4)
        fp = fopen("科目5.txt", "w+"); //打开文件以便写入数据
    for (int i = 0; i < 90; i++)
    {
        for (j = 0; j < 20; j++)
        {
            //将a数组中的整数写入fp指向的c:\a.txt文件
            if (j == 0)
            {
                fprintf(fp, "学生_%2d 绩点_%.2f ", i, s[i].credit);
            }
            fprintf(fp, "%d ", s[i].a[j]);
            if (j == 19)
                fprintf(fp, "\n");
        }
    }
    fclose(fp); //写入完毕，关闭文件
}