#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

//********************************************************
//������������
bool login(int account_Number, int password);
void menu();
void show(int balance);
bool withdraw(int &balance);
void deposit(int &balance);
bool transfer(int &balance);
bool change_Password(int &password);
//�˴��������1
//********************************************************

int main() //������
{
    int account_Number; //Ԥ���˺�
    int password;       //Ԥ������
    int balance;        //���

    ifstream File1("data.txt"); //�����ļ�����������
    if (File1)                  //����ļ����ڣ�����ļ��ж����˺š����뼰���
    {
        cout << "�˻��Ѵ���,�˻���Ϣ����ɹ���" << endl;
        File1 >> account_Number >> password >> balance;
    }
    else //����ļ������ڣ��򴴽����˻�
    {
        cout << "�˻���Ϣ�����ڣ��������˻���" << endl;
        cout << "�������˺ţ�";
        cin >> account_Number;
        cout << "���������룺";
        cin >> password;
        balance = 0;
        cout << "\n�����ɹ�!" << endl;
    }
    File1.close();

    if (!login(account_Number, password)) //����login()�������е�¼��֤
    {
        cout << "�˺�����������󳬹�ָ���������޷�����ϵͳ��" << endl;
        return 0;
    }

    int choice;
    do
    {
        menu(); //���ú���menu()������˵���
        cout << "������ѡ��:";
        cin >> choice;
        switch (choice) //�����û�����Ĳ���ѡ���������Ӧ�ĺ���ִ�й��ܣ����û�ѡ���˳�ʱ��������
        {
        case 1:
            show(balance);
            break;

        case 2:
            if (withdraw(balance))
                cout << "ȡ������ɹ�!���Ϊ��" << balance << endl;
            else
                cout << "ȡ�����ʧ��!" << endl;
            break;

        case 3:
            deposit(balance);
            cout << "�������ɹ�!���Ϊ��" << balance << endl;
            break;

        case 4:
            if (transfer(balance))
                cout << "ת�˲����ɹ�!���Ϊ��" << balance << endl;
            else
                cout << "ת�˲���ʧ��!" << endl;
            break;

        case 5:
            if (change_Password(password))
                cout << "�޸���������ɹ�!" << endl;
            else
                cout << "�޸��������ʧ��!" << endl;
            break;
        }
    } while (choice != 0);

    ofstream File2("data.txt");                                   //�����ļ�����������
    File2 << account_Number << " " << password << " " << balance; //���˺š����뼰���д���ļ�
    cout << "�˻���Ϣ����ɹ���ллʹ�ñ�ϵͳ��" << endl;
    File2.close();
}

bool login(int account_Number, int password) //��¼��֤����
{
    //�û������˺ż����룬��ȷ����true�������������룻���󳬹�3�Σ��������򣬷���false
    //�ο�ʵѵ2��2��
    //�˴��������2
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

void menu() //��ʾ���˵�����
{
    printf("***********************************��ӭʹ�ñ�ϵͳ***********************************\n");
    printf("           1.��ѯ                                           2.ȡ��\n");
    printf("           3.���                                           4.ת��\n");
    printf("           5.�޸�����                                       0.�˳�\n");
    printf("**********************************************************************************\n");
}

void show(int balance) //��ѯ����
{
    int out = balance;
    cout << "������Ϊ:" << out << endl;
}

bool withdraw(int &balance) //ȡ���
{                           //�û�����ȡ�������<=��ȡ��ɹ�������true�����򷵻�false
    int num;
    printf("������ȡ������");
    cin >> num;
    if (num > balance)
    {
        printf("�������㣬���������룡");
        return 0;
    }
    else
    {
        balance = balance - num;
        printf("ȡ��ɹ���");
        return 1;
    }
}

void deposit(int &balance) //����
{
    int num;
    printf("������������ֵ");
    cin >> num;
    balance = balance + num;
}

bool transfer(int &balance) //ת�˺���
{                           //�û�����ת���˺ż�������<=��ת�˳ɹ�������true������ʧ�ܣ�����false
    printf("������ת���˺�");
    printf("������ת���˺�"); //����д
    return 1;
}

bool change_Password(int &password) //�޸����뺯��
{                                   //�û�����ԭ���룬��ԭ������ȷ�����������������룬����ͬ���޸ĳɹ�����true������ʧ�ܣ�����false��
    int a = 0;
    int newpass = 0;
    int newpass2 = 0;
    cout << "�����뵱ǰ����" << endl;
    cin >> a;
    if (a == password)
    {
        cout << "������������" << endl;
        cin >> newpass;
        cout << "���ٴ�����������" << endl;
        cin >> newpass2;
        if (newpass == newpass2)
        {
            password = newpass;
            cout << "�����޸ĳɹ�" << endl;
        }
    }

    return 0;
}
