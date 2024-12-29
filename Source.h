#ifndef SOURCE_H
#define SOURCE_H

#include <iostream>
#include <string>
using namespace std;

setlocale(LC_ALL, ""); 

class UserData // для хранения данных о пользователе
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

    User(int n) : user_count(0), n(n) // конструктор 
    {
        user_array = new UserData[n];
    }

    ~User() // деструктор
    {
        delete[] user_array;
    }

    int menu() // для выбора операции: 1.Вход, 2.Регистрация, 3.Выход
    {
        int number;
        cout << "Добро пожаловать" << endl;
        cout << "Выберете номер операции: 1.Вход, 2.Регистрация, 3.Выход" << endl;
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
            cout << "Выход из системы" << endl;
            return 1;
        }
        else
        {
            cout << "Ошибка! Выберете 1, 2 или 3" << endl;
        }
        return 0;
    }

    void Registration() // для регистрации пользователя 
    {
        string login, password, name;
        bool success = true;
        bool success1 = true;
        int i = 0;

        while (success1)
        {
            cout << "Введите свой логин: ";
            cin >> login;
            cout << "Введите свой пароль: ";
            cin >> password;
            cout << "Введите свое имя: ";
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
                cout << "Вы успешно зарегистрировались!" << endl;
                success1 = false;
            }
            else
            {
                cout << "Пользователь с таким именем или логином уже существует. Введите данные заново" << endl;
            }
        }
        Entrance();
    }

    void Entrance() // для входа зарегистрированного пользователя
    {
        string login, password;
        bool success = true;
        int i = 0;

        while (success)
        {
            cout << "Введите свой логин: ";
            cin >> login;
            cout << "Введите свой пароль: ";
            cin >> password;

            for (i = 0; i < user_count; ++i) {
                if (login == user_array[i].login && password == user_array[i].password) {
                    success = false;
                    cout << "Хорошего общения, " << user_array[i].name << "!" << endl;
                    current_name = user_array[i].name;
                    break;
                }
            }

            if (success)
            {
                cout << "Ошибка! Неверный логин или пароль" << endl;
            }
        }
    }
};

#endif // SOURCE_H
