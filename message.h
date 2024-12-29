#ifndef MESSAGE_H
#define MESSAGE_H

#include <iostream>
#include <string>
#include "Source.h"
using namespace std;

setlocale(LC_ALL, ""); 

struct Message // для хранения данных о сообщениях, их отправителях и получателях 
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

    Account(int n) : mes_arr_size(0) // конструктор
    {
        message_array = new Message[n];
    }

    ~Account() // деструктор 
    {
        delete[] message_array;
    }

    int menu1(User& user) // метод для выбора действия 1.Написать личное сообщение; 2. Написать сообщение всем пользователям; 3.Выход
    {
        bool open = true;
        while (open)
        {
            int num;
            cout << "Выберете действие: 1.Написать личное сообщение; 2. Написать сообщение всем пользователям; 3.Выход: " << endl;
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
                cout << "Ошибка! Выберете 1, 2 или 3" << endl;
            }
        }
        return 0;
    }

    void Person_message(User& user) // для ввода сообщения конкретному пользователю
    {
        cout << "Выберете номер аккаунта: "<<endl;
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
            cout << "Ваше сообщение: ";
            cin.ignore();
            getline(cin, message);

            message_array[mes_arr_size] = Message(current_name, user.user_array[m - 1].name, message);
            mes_arr_size++;
        }
        else
        {
            cout << "Ошибка! Неверный номер аккаунта" << endl;
        }
    }

    void All_message(User& user) // для ввода сообщения всем пользователям
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
        cout << "Ваше сообщение: ";
        cin.ignore();
        getline(cin, message);

        message_array[mes_arr_size] = Message(current_name, getter, message);
        mes_arr_size++;
    }
};

#endif // MESSAGE_H