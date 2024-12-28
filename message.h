#ifndef MESSAGE_H
#define MESSAGE_H

#include <iostream>
#include <string>
#include "Source.h"
using namespace std;

struct Message
{
    string sender;
    string getter;
    string message;
    Message() { sender = ""; getter = ""; message = ""; }
    Message(string sender, string getter, string message)
    {
        this->sender = sender;
        this->getter = getter;
        this->message = message;
    }
};

class Account
{
public:
    int mes_arr_size;
    Message* message_array;
    string current_name;

    Account(int n) : mes_arr_size(0)
    {
        message_array = new Message[n];
    }

    ~Account()
    {
        delete[] message_array;
    }

    int menu1(User& user)
    {
        bool open = true;
        while (open)
        {
            int num;
            cout << "�������� ��������: 1.�������� ������ ���������; 2. �������� ��������� ���� �������������; 3.�����: " << endl;
            cin >> num;
            if (num == 1)
            {
                Person_message(user);
            }
            else if (num == 2)
            {
                All_message(user);
            }
            else if (num == 3)
            {
                current_name = " ";
                open = false;
            }
            else
            {
                cout << "������! �������� 1, 2 ��� 3" << endl;
            }
        }
        return 0;
    }

    void Person_message(User& user)
    {
        cout << "�������� ����� ��������: "<<endl;
        int m;
        string sender, getter, message;
        for (int i = 0; i < user.user_count; ++i)
        {
            cout << i + 1 << ". " << user.user_array[i].login << endl;
        }
        cin >> m;
        if (m > 0 && m <= user.user_count)
        {
            for (int i = 0; i < mes_arr_size; i++)
            {
                if ((message_array[i].sender == current_name && message_array[i].getter == user.user_array[m - 1].name) || (message_array[i].sender == user.user_array[m - 1].name && message_array[i].getter == current_name))
                {
                    cout << message_array[i].sender << ": " << message_array[i].message << endl;
                }
            }
            cout << "���� ���������: ";
            cin.ignore();
            getline(cin, message);

            message_array[mes_arr_size] = Message(current_name, user.user_array[m - 1].name, message);
            mes_arr_size++;
        }
        else
        {
            cout << "������! �������� ����� ��������" << endl;
        }
    }

    void All_message(User& user)
    {
        string message;
        string getter = "everyone";
        for (int i = 0; i < mes_arr_size; i++)
        {
            if (message_array[i].getter == "everyone")
            {
                cout << message_array[i].sender << ": " << message_array[i].message << endl;
            }
        }
        cout << "���� ���������: ";
        cin.ignore();
        getline(cin, message);

        message_array[mes_arr_size] = Message(current_name, getter, message);
        mes_arr_size++;
    }
};

#endif // MESSAGE_H