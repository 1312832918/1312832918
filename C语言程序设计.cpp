// 要求：学生的某门课程的信息包括姓名(不超过10个字符)，学号(不超过8个字符)，平时成绩，期末考试成绩，总成绩。其中总成绩按平时成绩30%，
//    期末成绩70%自动进行计算。从键盘输入一个班（全班最多不超过60人）的学生姓名、学号及成绩信息，分别计算下列内容：
// 1、计算期末总成绩；
// 2、按总成绩升序对学生进行排序，并输出排序之后的学生信息，一行一个学生信息；
// 3、按总成绩统计成绩在全班平均分及平均分之上的学生人数，并打印学生人数，占全班学生的百分比，以及学生信息（包括姓名，学号，平时成绩，期末成绩，总成绩）；
// 4、统计各分数段的学生人数及所占的百分比：不及格(0~59)，及格(60~69)，中等(70~79)，良好(80~89)，(90z~100)对于不及格的学生，
//    还要输出对应的学生信息（包括姓名，学号，平时成绩，期末成绩，总成绩）；

#include <stdio.h>
#include <string.h>

//char *s_gets(char *st, int n);
#define MAXNAME 10
#define MAXNUM 8

struct student //定义结构体
{
    char name[MAXNAME + 1]; //姓名
    char id[MAXNUM + 1];    //学号
    int usual_achi;         //平时成绩
    int final_achi;         //期末成绩
    int num_achi;           //总成绩
};

void calculation(struct student a[], int peo); //声明函数
void arry(struct student a[], int peo);
void average(struct student a[], int peo);
void statistics(struct student a[], int peo);
void loadtxet(struct student a[]);

int main()
{
    int lm = 0;
    int i1 = 0;
    int i2 = 0;
    int sum = 0;
    int peo = 60;
    printf("请输入班级人数：\n");
    scanf("%d", &peo);
    printf("班级人数为：%d\n", peo);
    struct student a[60] =
        {
            // {"张军", "21200000", 20, 20, 0},
            // {"张蒙", "214", 40, 40, 40},
            // {"谢俊杰", "215", 100, 100, 0},
            // {"郑良杰", "2143001", 75, 75, 0}
        };
    //scanf("%c,%c,%d,%d", a[3].name, a[3].id, a[3].usual_achi, a[3].final_achi);
    //loadtxet(a);
    printf("请输入：\n");
    printf("姓名：  学号：   平时成绩：  期末成绩：\n");
    for (lm = 0; lm < peo; lm++)
    {
        scanf("%s%s%d%d", &a[lm].name, &a[lm].id, &a[lm].usual_achi, &a[lm].final_achi);
    }
    calculation(a, peo);
    arry(a, peo);
    average(a, peo);
    statistics(a, peo);
    for (i2 = 0; i2 < peo; i2++)
    {
        //printf("%s同学,学号是%s,平时成绩为%d,期末考试成绩为%d,总成绩为%d\n", a[i2].name, a[i2].id, a[i2].usual_achi, a[i2].final_achi, a[i2].num_achi);
    }
}

void loadtext(student a[])
{
    FILE *sj = fopen("C:\\Users\\谢俊杰\\Desktop\\sj.txt", "r"); //("D:\\data.txt","r");
    int in, jn, an[4][5];
    for (in = 0; in < 4; in++)
    {
        for (jn = 0; jn < 5; jn++)
        {
            fscanf(sj, "%s%s%d%d", &a[jn].name, &a[jn].id, &a[jn].usual_achi, &a[jn].final_achi); //读取文件中的数据，遇到空格和换行停止读。
            printf("%s%s%d%d", &a[jn].name, &a[jn].id, &a[jn].usual_achi, &a[jn].final_achi);     //将文件打印出来。
        }
        printf("\n");
    }
    fclose(sj);
}

void calculation(student a[], int peo) //第一题
{
    printf("第一题：  已计算总成绩\n");
    int i3 = 0;
    float sum = 0;
    for (i3 = 0; i3 < peo; i3++)
    {
        sum = a[i3].usual_achi * 0.3 + a[i3].final_achi * 0.7;
        a[i3].num_achi = sum;
    }
}

void arry(student a[], int peo) //第二题 冒泡排序
{
    printf("第二题：\n");
    int i6 = 0;
    int i, j, usual, final;
    struct student b[1];
    for (j = 0; j < peo - 1; j++)
    {
        for (i = 0; i < peo - 1 - j; i++)
        {
            if (a[i].num_achi > a[i + 1].num_achi)
            {
                b[0] = a[i];
                a[i] = a[i + 1];
                a[i + 1] = b[0];
            }
        }
    }
    for (i6 = 0; i6 < peo; i6++)
    {
        printf("%s同学,学号是%s,平时成绩为%d,期末考试成绩为%d,总成绩为%d\n", a[i6].name, a[i6].id, a[i6].usual_achi, a[i6].final_achi, a[i6].num_achi);
    }
}

void average(student a[], int peo)
{
    printf("第三题：\n");
    int i4 = 0;
    int i5 = 0;
    int ave = 0;
    int num = 0;
    int sum = 0;
    for (i4 = 0; i4 < peo; i4++)
    {
        num = num + a[i4].num_achi;
        //printf("%d\n", a[i4].num_achi);
    }
    ave = num / 4;
    for (i5 = 0; i5 < peo; i5++)
    {
        if (a[i5].num_achi > ave)
        {
            sum++;
            //printf("%s同学,学号是%s,平时成绩为%d,期末考试成绩为%d,总成绩为%d\n", a[i5].name, a[i5].id, a[i5].usual_achi, a[i5].final_achi, a[i5].num_achi);
        }
    }
    //printf("总数是%d\n", num);
    //printf("平均数%d\n", ave);
    printf("有%d位同学的分数高于班级平均分,他们是：\n", sum);
    for (i5 = 0; i5 < peo; i5++)
    {
        if (a[i5].num_achi > ave)
        {
            //sum++;
            printf("%s同学,学号是%s,平时成绩为%d,期末考试成绩为%d,总成绩为%d\n", a[i5].name, a[i5].id, a[i5].usual_achi, a[i5].final_achi, a[i5].num_achi);
        }
    }
}

void statistics(student a[], int peo)
{
    printf("第四题：\n");
    int i7 = 0;
    int f1 = 0;   //不及格人数
    int f2 = 0;   //及格人数
    int f3 = 0;   //中等人数
    int f4 = 0;   //良好人数
    int f5 = 0;   //优秀人数
    float d1 = 0; //不及格比例
    float d2 = 0; //及格比例
    float d3 = 0; //中等比例
    float d4 = 0; //良好比例
    float d5 = 0; //优秀比例
    int sum = 4;  //总数
    for (i7 = 0; i7 < peo; i7++)
    {
        int n = a[i7].num_achi;
        //printf("%d\n", n);
        if (n < 60 && n >= 0)
        {
            f1++;
            printf("不及格的是%s同学,学号是%s,平时成绩为%d,期末考试成绩为%d,总成绩为%d\n", a[i7].name, a[i7].id, a[i7].usual_achi, a[i7].final_achi, a[i7].num_achi);
            //printf("不及格");
        }
        else if (n < 70 && n >= 60)
        {
            f2++;
            //printf("及格");
        }
        else if (n < 80 && n >= 70)
        {
            f3++;
            //printf("中等");
        }
        else if (n < 90 && n >= 80)
        {
            f4++;
            //printf("良好");
        }
        else
        {
            f5++;
            //printf("优秀");
        }
    }
    d1 = f1 * 100 / peo;
    d2 = f2 * 100 / peo;
    d3 = f3 * 100 / peo;
    d4 = f4 * 100 / peo;
    d5 = f5 * 100 / peo;
    printf("不及格的人数占%%%f\n", d1);
    printf("及格的人数占%%%f\n", d2);
    printf("中等的人数占%%%f\n", d3);
    printf("良好的人数占%%%f\n", d4);
    printf("优秀的人数占%%%f\n", d5);
}