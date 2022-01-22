#include <stdio.h>
#include <string.h>
#include <Windows.h>
#include <stdlib.h>

//int main()                                        Switch case语句
//{
//    int day = 0;
//    scanf("%d", &day);
//	switch (day)
//	{
//	case 1:
//		printf("Monday\n");
//		break;
//	case 2:
//		printf("Tuesday\n");
//		break;
//	case 3:
//		printf("Wednesday\n");
//		break;
//	case 4:
//		printf("Thurday\n");
//		break;
//	case 5:
//		printf("Friday\n");
//		break;
//	case 6:
//		printf("Saturday\n");
//		break;
//	case 7:
//		printf("Sunday\n");
//		break;
//	}
//}

//int main()                                   //Hello World
//{
//    printf("hello world\n");
//    printf("hello world\n");
//    return 0;
//}

//int main()
//{
//    int a, b;
//    b = 2;
//    a = 4 * b + 7;
//    printf("%d\n", a);
//    return 0;
//}

//int main()                                    //prinf
//{
//    float a = 11.222;
//    printf("%f\n", a);
//    char b = 6;
//    printf("%c\n", b);
//    printf("%d\n", b);
//    int c = 1231231;
//    printf("%d\n", c);
//
//    return 0;
//
//}

//int main()                                //强转
//{
//    int  m = 5;
//    printf("m/2=%d\n", m / 2);
//    printf("(float)(m/2)=%f\n)", (float)(m / 2));
//}

//int main()                                //scanf
//{
//    int a, b;
//    scanf_s("%d", &a);
//    scanf_s("%d", &b);
//    printf("%d", a + b);
//    return 0;
//}

//int main()                        //while  break  continue
//{
//
//	int i = 1;
//	while (i<=10)
//	{
//		if (i == 5)
//			continue;
//		printf("%d", i);
//		i++;
//	}
//	return 0;
//
//}

//int main()                     //putchar
//{
//	int ch = getchar();
//	putchar(ch);
//	printf("%c\n", ch);
//	return 0;
//}

//int main()
//{
//	double a, b, c;
//	scanf("%lf""%lf""%lf", &a, &b, &c);
//	printf("%lf\n""%lf\n""%lf\n", a, b, c);
//	return 0;
//}

//int main()                                      //缓存�?
//{
//	int ret = 0;
//	char password[20] = { 0 };    //定义一个数�?
//	printf("请输入密码：>");
//	scanf("%s", password);   //输入密码并且存放在password里面 123456\n
//	getchar();               //提走 \n 清空缓存�?
//	printf("请确认：Y/N>");
//	ret = getchar();
//	if (ret == 'Y')
//	{
//		printf("成功");
//	}
//	else
//	{
//		printf("失败");
//	}
//	return 0;
//}

//int main()                            //for循环
//{                                     //1.不可在for循环体内修改循环变量，防止for循环失去控制
//	int i;                            //2.建议for语句循环控制变量采用‘前闭后开’区间写�?
//	for ( i = 0; i < 10; i++)
//	{
//		printf("%d\n", i);          //break continue
//	}
//	return 0;
//}

//int main()                                      //阶乘算法
//{
//	int a, n ,s = 1;
//	scanf("%d", &n);
//	for ( a = 1; a < n+1; a++)
//	{
//		s = s * a;
//	}
//	printf("%d", s);
//	return 0;
//}

//int main()                                      //阶乘累加
//{
//	int a = 0;
//	int n = 0;
//	int s = 1;
//	int num1 = 0;
//	int times = 0;
//	scanf("%d", &times);
//	for (n = 1; n <= times; n++)
//	{
//		s = 1;
//		for (a = 1; a <= n; a++)
//		{
//
//			s = s * a;
//		}
//		num1 = num1 + s;
//	}
//	printf("%d", num1);
//	return 0;
//}

//int main()                                                             //顺序查找
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int key = 7;
//	int i = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);                             //求出数组的元素个�?
//	for ( i = 0; i < sz; i++)
//	{
//		if (key==arr[i])
//		{
//			printf("找到了，下标是；%d\n", i);
//			break;
//		}
//	}
//	if (i==sz)
//	{
//		printf("NO FOUND\n");
//
//	}
//	return 0;
//}

//int main()
//{
//	int arr[] = {1,2,4,5,6,7,10,11};
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int left = 0;
//	int right = sz - 1;
//	int k = 1;
//	while (left<=right)
//	{
//		int mid = (left + right) / 2;
//		if (arr[mid] > k)
//		{
//			right = mid - 1;  //右标左移
//		}
//		else if (arr[mid] < k)
//		{
//			left = mid + 1;
//		}
//		else
//		{
//			printf("下标�?%d", mid);
//			break;
//		}
//	}
//	if (left>right)
//	{
//		printf("找不到\n");
//	}
//	return 0;
//}

//int main()                                            //顺序打印
//{
//	char arr1[] = "welcome to bit!!!";
//	char arr2[] = "#################";
//	int left = 0;
//	//int right = sizeof(arr1) / sizeof(arr1[0])-2;   // 字符串后面有 \0
//	int right = strlen(arr1) - 1;                     //数组长度
//
//	while (left<=right)
//	{
//		arr2[left] = arr1[left];
//		arr2[right] = arr1[right];
//		printf("%s\n", arr2);
//		Sleep(1000);	                             //暂停1000毫秒
//		system("cls");                               //执行系统命令的函�?
//		left++;
//		right--;
//	}
//
//}

//int main()                                           //字符串对�?
//{
//	int i = 0;
//	char password[20] = "123456";
//	for (i = 0; i < 3; i++)
//	{
//		printf("请输入密码：>");
//		scanf("%s", password);
//		if (strcmp(password,"123456") == 0 )        //(password == "123456")  比较字符串不�?==
//		{
//			printf("登陆成功\n" );
//			break;
//		}
//		else
//		{
//			printf("密码错误\n");
//		}
//	}
//	if (i==3)
//	{
//		printf("三次密码均错误，退出程序\n");
//	}
//	return 0;
//}

// int main() //辗转相除�?  求最大公因数
// {
// 	int m = 0;
// 	int n = 0;
// 	int r = 0;
// 	scanf("%d%d", &m, &n);
// 	while (m % n)
// 	{
// 		r = m % n;
// 		m = n;
// 		n = r;
// 	}
// 	printf("%d\n", n);
// 	return 0;
// }

// int get_max(int x, int y)                           //寻找两数的大�?
// {
// 	if (x > y)
// 	{
// 		return x;
// 	}
// 	else
// 	{
// 		return y;
// 	}
// }
// int main()
// {
// 	int a = 0;
// 	int b = 1;
// 	int c = 0;

// 	c = get_max(a, b);
// 	printf("%d", c);
// 	return 0;
// }

int search(int arr[], int k, int right)
{

	int left = 0;

	while (left <= right)
	{
		int t = (right + left) / 2;
		if (arr[t] > k)
		{
			right = t - 1;
		}
		else if (arr[t] < k)
		{
			left = t + 1;
		}
		else
		{
			return t;
		}
	}
	return -1;
}

int main()
{
	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	int right = sizeof(arr) / sizeof(arr[0]) - 1;
	int k = 4;
	int ret = search(arr, k, right);

	if (ret == -1)
	{
		printf("can`t find");
	}
	else
	{
		printf("find it it is%d\n", ret);
	}
	return 0;
}