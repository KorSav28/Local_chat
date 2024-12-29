#ifndef SOURCE_H
#define SOURCE_H

#include <iostream>
#include <string>
using namespace std;

setlocale(LC_ALL, ""); 

class UserData // ��� �������� ������ � ������������
{
public:
    string login;
    string password;
    string name;
    UserData() { login = ""; password = ""; name = ""; }
    UserData(string login, string password, string name)
    {
        this->login = login;
        this->password = password;
        this->name = name;
    }
};

class User
{
public:
    UserData* user_array;
    int user_count;
    int n;
    string current_name;

    User(int n) : user_count(0), n(n) // ����������� 
    {
        user_array = new UserData[n];
    }

    ~User() // ����������
    {
        delete[] user_array;
    }

    int menu() // ��� ������ ��������: 1.����, 2.�����������, 3.�����
    {
        int number;
        cout << "����� ����������" << endl;
        cout << "�������� ����� ��������: 1.����, 2.�����������, 3.�����" << endl;
        cin >> number;

        if (number == 1)
        {
            Entrance();
        }
        else if (number == 2)
        {
            Registration();
        }
        else if (number == 3)
        {
            cout << "����� �� �������" << endl;
            return 1;
        }
        else
        {
            cout << "������! �������� 1, 2 ��� 3" << endl;
        }
        return 0;
    }

    void Registration() // ��� ����������� ������������ 
    {
        string login, password, name;
        bool success = true;
        bool success1 = true;
        int i = 0;

        while (success1)
        {
            cout << "������� ���� �����: ";
            cin >> login;
            cout << "������� ���� ������: ";
            cin >> password;
            cout << "������� ���� ���: ";
            cin >> name;

            success = true;
            for (i = 0; i < user_count; ++i) {
                if (login == user_array[i].login || name == user_array[i].name) {
                    success = false;
                    break;
                }
            }
            if (success && user_count < n)
            {
                user_array[user_count] = UserData(login, password, name);
                user_count = user_count + 1;
                cout << "�� ������� ������������������!" << endl;
                success1 = false;
            }
            else
            {
                cout << "������������ � ����� ������ ��� ������� ��� ����������. ������� ������ ������" << endl;
            }
        }
        Entrance();
    }

    void Entrance() // ��� ����� ������������������� ������������
    {
        string login, password;
        bool success = true;
        int i = 0;

        while (success)
        {
            cout << "������� ���� �����: ";
            cin >> login;
            cout << "������� ���� ������: ";
            cin >> password;

            for (i = 0; i < user_count; ++i) {
                if (login == user_array[i].login && password == user_array[i].password) {
                    success = false;
                    cout << "�������� �������, " << user_array[i].name << "!" << endl;
                    current_name = user_array[i].name;
                    break;
                }
            }

            if (success)
            {
                cout << "������! �������� ����� ��� ������" << endl;
            }
        }
    }
};

#endif // SOURCE_H
