#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

//********************************************************
//函数声明部分
bool login(int account_Number, int password);
void menu();
void show(int balance);
bool withdraw(int &balance);
void deposit(int &balance);
bool transfer(int &balance);
bool change_Password(int &password);
//此处完成任务1
//********************************************************

int main() //主函数
{
    int account_Number; //预设账号
    int password;       //预设密码
    int balance;        //余额

    ifstream File1("data.txt"); //产生文件输入流对象
    if (File1)                  //如果文件存在，则从文件中读出账号、密码及余额
    {
        cout << "账户已存在,账户信息读入成功！" << endl;
        File1 >> account_Number >> password >> balance;
    }
    else //如果文件不存在，则创建新账户
    {
        cout << "账户信息不存在！创建新账户：" << endl;
        cout << "请输入账号：";
        cin >> account_Number;
        cout << "请输入密码：";
        cin >> password;
        balance = 0;
        cout << "\n开户成功!" << endl;
    }
    File1.close();

    if (!login(account_Number, password)) //调用login()函数进行登录验证
    {
        cout << "账号密码输入错误超过指定次数，无法进入系统！" << endl;
        return 0;
    }

    int choice;
    do
    {
        menu(); //调用函数menu()输出主菜单；
        cout << "请输入选项:";
        cin >> choice;
        switch (choice) //接收用户输入的操作选项，并调用相应的函数执行功能；当用户选择退出时结束程序
        {
        case 1:
            show(balance);
            break;

        case 2:
            if (withdraw(balance))
                cout << "取款操作成功!余额为：" << balance << endl;
            else
                cout << "取款操作失败!" << endl;
            break;

        case 3:
            deposit(balance);
            cout << "存款操作成功!余额为：" << balance << endl;
            break;

        case 4:
            if (transfer(balance))
                cout << "转账操作成功!余额为：" << balance << endl;
            else
                cout << "转账操作失败!" << endl;
            break;

        case 5:
            if (change_Password(password))
                cout << "修改密码操作成功!" << endl;
            else
                cout << "修改密码操作失败!" << endl;
            break;
        }
    } while (choice != 0);

    ofstream File2("data.txt");                                   //产生文件输入流对象
    File2 << account_Number << " " << password << " " << balance; //将账号、密码及余额写入文件
    cout << "账户信息保存成功，谢谢使用本系统！" << endl;
    File2.close();
}

bool login(int account_Number, int password) //登录验证函数
{
    //用户输入账号及密码，正确返回true，错误重新输入；错误超过3次，结束程序，返回false
    //参考实训2第2题
    //此处完成任务2
    for (int i = 0; i < 3; i++)
    {
        int m = 0, n = 0;
        int name, password1;
        printf("please input name:");
        scanf("%d", &name);
        printf("please input password:");
        scanf("%d", &password1);

        if (name == account_Number && password1 == password)
        {
            int ret = 1;
            return ret;
            break;
        }
        else
        {
            cout << "warning,please putin again" << endl;
        }
        // int size1 = strlen(name) > strlen(name2) ? strlen(name) : strlen(name2);
        // int size2 = strlen(password) > strlen(password2) ? strlen(password) : strlen(password2);

        // for (int i = 0; i < size1; i++)
        // {
        //     if (name[i] != name2[i])
        //         m = 1;
        // }
        // for (int i = 0; i < size2; i++)
        // {
        //     if (password2[i] != password[i])
        //         n = 1;
        // }
        // if (!m && !n)
        // {
        //     printf("YES\n");
        //     break;
        // }
    }
    return 0;
}

void menu() //显示主菜单函数
{
    printf("***********************************欢迎使用本系统***********************************\n");
    printf("           1.查询                                           2.取款\n");
    printf("           3.存款                                           4.转账\n");
    printf("           5.修改密码                                       0.退出\n");
    printf("**********************************************************************************\n");
}

void show(int balance) //查询余额函数
{
    int out = balance;
    cout << "你的余额为:" << out << endl;
}

bool withdraw(int &balance) //取款函数
{                           //用户输入取款金额，如金额<=余额，取款成功，返回true；否则返回false
    int num;
    printf("请输入取款数额");
    cin >> num;
    if (num > balance)
    {
        printf("您的余额不足，请重新输入！");
        return 0;
    }
    else
    {
        balance = balance - num;
        printf("取款成功！");
        return 1;
    }
}

void deposit(int &balance) //存款函数
{
    int num;
    printf("请输入存入的数值");
    cin >> num;
    balance = balance + num;
}

bool transfer(int &balance) //转账函数
{                           //用户输入转入账号及金额，如金额<=余额，转账成功，返回true；否则失败，返回false
    printf("请输入转出账号");
    printf("请输入转入账号"); //不会写
    return 1;
}

bool change_Password(int &password) //修改密码函数
{                                   //用户输入原密码，如原密码正确，则两次输入新密码，若相同，修改成功返回true；否则失败，返回false；
    int a = 0;
    int newpass = 0;
    int newpass2 = 0;
    cout << "请输入当前密码" << endl;
    cin >> a;
    if (a == password)
    {
        cout << "请输入新密码" << endl;
        cin >> newpass;
        cout << "请再次输入新密码" << endl;
        cin >> newpass2;
        if (newpass == newpass2)
        {
            password = newpass;
            cout << "密码修改成功" << endl;
        }
    }

    return 0;
}
