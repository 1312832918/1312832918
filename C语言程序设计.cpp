// Ҫ��ѧ����ĳ�ſγ̵���Ϣ��������(������10���ַ�)��ѧ��(������8���ַ�)��ƽʱ�ɼ�����ĩ���Գɼ����ܳɼ��������ܳɼ���ƽʱ�ɼ�30%��
//    ��ĩ�ɼ�70%�Զ����м��㡣�Ӽ�������һ���ࣨȫ����಻����60�ˣ���ѧ��������ѧ�ż��ɼ���Ϣ���ֱ�����������ݣ�
// 1��������ĩ�ܳɼ���
// 2�����ܳɼ������ѧ���������򣬲��������֮���ѧ����Ϣ��һ��һ��ѧ����Ϣ��
// 3�����ܳɼ�ͳ�Ƴɼ���ȫ��ƽ���ּ�ƽ����֮�ϵ�ѧ������������ӡѧ��������ռȫ��ѧ���İٷֱȣ��Լ�ѧ����Ϣ������������ѧ�ţ�ƽʱ�ɼ�����ĩ�ɼ����ܳɼ�����
// 4��ͳ�Ƹ������ε�ѧ����������ռ�İٷֱȣ�������(0~59)������(60~69)���е�(70~79)������(80~89)��(90z~100)���ڲ������ѧ����
//    ��Ҫ�����Ӧ��ѧ����Ϣ������������ѧ�ţ�ƽʱ�ɼ�����ĩ�ɼ����ܳɼ�����

#include <stdio.h>
#include <string.h>

//char *s_gets(char *st, int n);
#define MAXNAME 10
#define MAXNUM 8

struct student //����ṹ��
{
    char name[MAXNAME + 1]; //����
    char id[MAXNUM + 1];    //ѧ��
    int usual_achi;         //ƽʱ�ɼ�
    int final_achi;         //��ĩ�ɼ�
    int num_achi;           //�ܳɼ�
};

void calculation(struct student a[], int peo); //��������
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
    printf("������༶������\n");
    scanf("%d", &peo);
    printf("�༶����Ϊ��%d\n", peo);
    struct student a[60] =
        {
            // {"�ž�", "21200000", 20, 20, 0},
            // {"����", "214", 40, 40, 40},
            // {"л����", "215", 100, 100, 0},
            // {"֣����", "2143001", 75, 75, 0}
        };
    //scanf("%c,%c,%d,%d", a[3].name, a[3].id, a[3].usual_achi, a[3].final_achi);
    //loadtxet(a);
    printf("�����룺\n");
    printf("������  ѧ�ţ�   ƽʱ�ɼ���  ��ĩ�ɼ���\n");
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
        //printf("%sͬѧ,ѧ����%s,ƽʱ�ɼ�Ϊ%d,��ĩ���Գɼ�Ϊ%d,�ܳɼ�Ϊ%d\n", a[i2].name, a[i2].id, a[i2].usual_achi, a[i2].final_achi, a[i2].num_achi);
    }
}

void loadtext(student a[])
{
    FILE *sj = fopen("C:\\Users\\л����\\Desktop\\sj.txt", "r"); //("D:\\data.txt","r");
    int in, jn, an[4][5];
    for (in = 0; in < 4; in++)
    {
        for (jn = 0; jn < 5; jn++)
        {
            fscanf(sj, "%s%s%d%d", &a[jn].name, &a[jn].id, &a[jn].usual_achi, &a[jn].final_achi); //��ȡ�ļ��е����ݣ������ո�ͻ���ֹͣ����
            printf("%s%s%d%d", &a[jn].name, &a[jn].id, &a[jn].usual_achi, &a[jn].final_achi);     //���ļ���ӡ������
        }
        printf("\n");
    }
    fclose(sj);
}

void calculation(student a[], int peo) //��һ��
{
    printf("��һ�⣺  �Ѽ����ܳɼ�\n");
    int i3 = 0;
    float sum = 0;
    for (i3 = 0; i3 < peo; i3++)
    {
        sum = a[i3].usual_achi * 0.3 + a[i3].final_achi * 0.7;
        a[i3].num_achi = sum;
    }
}

void arry(student a[], int peo) //�ڶ��� ð������
{
    printf("�ڶ��⣺\n");
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
        printf("%sͬѧ,ѧ����%s,ƽʱ�ɼ�Ϊ%d,��ĩ���Գɼ�Ϊ%d,�ܳɼ�Ϊ%d\n", a[i6].name, a[i6].id, a[i6].usual_achi, a[i6].final_achi, a[i6].num_achi);
    }
}

void average(student a[], int peo)
{
    printf("�����⣺\n");
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
            //printf("%sͬѧ,ѧ����%s,ƽʱ�ɼ�Ϊ%d,��ĩ���Գɼ�Ϊ%d,�ܳɼ�Ϊ%d\n", a[i5].name, a[i5].id, a[i5].usual_achi, a[i5].final_achi, a[i5].num_achi);
        }
    }
    //printf("������%d\n", num);
    //printf("ƽ����%d\n", ave);
    printf("��%dλͬѧ�ķ������ڰ༶ƽ����,�����ǣ�\n", sum);
    for (i5 = 0; i5 < peo; i5++)
    {
        if (a[i5].num_achi > ave)
        {
            //sum++;
            printf("%sͬѧ,ѧ����%s,ƽʱ�ɼ�Ϊ%d,��ĩ���Գɼ�Ϊ%d,�ܳɼ�Ϊ%d\n", a[i5].name, a[i5].id, a[i5].usual_achi, a[i5].final_achi, a[i5].num_achi);
        }
    }
}

void statistics(student a[], int peo)
{
    printf("�����⣺\n");
    int i7 = 0;
    int f1 = 0;   //����������
    int f2 = 0;   //��������
    int f3 = 0;   //�е�����
    int f4 = 0;   //��������
    int f5 = 0;   //��������
    float d1 = 0; //���������
    float d2 = 0; //�������
    float d3 = 0; //�еȱ���
    float d4 = 0; //���ñ���
    float d5 = 0; //�������
    int sum = 4;  //����
    for (i7 = 0; i7 < peo; i7++)
    {
        int n = a[i7].num_achi;
        //printf("%d\n", n);
        if (n < 60 && n >= 0)
        {
            f1++;
            printf("���������%sͬѧ,ѧ����%s,ƽʱ�ɼ�Ϊ%d,��ĩ���Գɼ�Ϊ%d,�ܳɼ�Ϊ%d\n", a[i7].name, a[i7].id, a[i7].usual_achi, a[i7].final_achi, a[i7].num_achi);
            //printf("������");
        }
        else if (n < 70 && n >= 60)
        {
            f2++;
            //printf("����");
        }
        else if (n < 80 && n >= 70)
        {
            f3++;
            //printf("�е�");
        }
        else if (n < 90 && n >= 80)
        {
            f4++;
            //printf("����");
        }
        else
        {
            f5++;
            //printf("����");
        }
    }
    d1 = f1 * 100 / peo;
    d2 = f2 * 100 / peo;
    d3 = f3 * 100 / peo;
    d4 = f4 * 100 / peo;
    d5 = f5 * 100 / peo;
    printf("�����������ռ%%%f\n", d1);
    printf("���������ռ%%%f\n", d2);
    printf("�еȵ�����ռ%%%f\n", d3);
    printf("���õ�����ռ%%%f\n", d4);
    printf("���������ռ%%%f\n", d5);
}