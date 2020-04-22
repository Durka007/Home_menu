// sit at home.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <Windows.h>
using namespace std;

class sit_at_home
{
public:
    struct city
    {
        string fio;
        int age;
        bool f;
        int violations;
        city* next;
        city() : fio(""), age(0), f(false), violations(0), next(nullptr) {}
    };
    city* head;

    sit_at_home() : head(nullptr) {}

    void open()
    {
        city* tmp = new city;
        cout << "Введите ФИО : ";
        cin >> tmp->fio;
        cout << "Введите Возраст : ";
        cin >> tmp->age;
        cout << "Необходимость выходить(1(Да)/0(Нет)); ";
        cin >> tmp->f;
        tmp->violations = 0;
        tmp->next = head;
        head = tmp;
        tmp = nullptr;
    }
    void search()
    {
        if (head == nullptr)
            return;
        string fio;
        cout << "ФИО нарушившего:"; cin >> fio;
        city* tmp = head;
        do {
            if (tmp->fio == fio)
            {
                int a;
                cout << "Гражданин найден!\nСколько нарушений добавить?: "; cin >> a;
                tmp->violations += a;
                return;
            }
            tmp = tmp->next;
        } while (tmp);
        cout << "Гражданин не найден!" << endl;
    }
    template <class T>
    void group(T sit_at_home::city::*q, T a, string abs)
    {
        if (head == nullptr)
            return;
        city* tmp = head;
        if (a != 1)
        {
            do {
                if (tmp->*q > a)
                {
                    cout << "ФИО : " << tmp->fio << endl;
                    cout << abs << tmp->*q << endl;
                }
                tmp = tmp->next;
            } while (tmp);
        }
        else {
            do {
                if (tmp->*q < a)
                {
                    cout << "ФИО : " << tmp->fio << endl;
                    cout << abs << tmp->*q << endl;
                }
                tmp = tmp->next;
            } while (tmp);
        }
    }
    void ouput()
    {
        if (head == nullptr)
            return;
        city* tmp = head;
        do {
            cout << "ФИО: " << tmp->fio << endl;
            cout << "Возраст: " << tmp->age << endl;
            tmp = tmp->next;
        } while (tmp);
    }
    void ouput_k()
    {
        if (head == nullptr)
            return;
        city* tmp = head;
        do {
            cout << "ФИО: " << tmp->fio << endl;
            cout << "Возраст: " << tmp->age << endl;
            cout << "Нарушения: " << tmp->violations << endl;
            tmp = tmp->next;
        } while (tmp);
    }
    void sort()
    {
        if (head == nullptr)
            return;
        city* one = head;
        city* two = head->next;
        while (one->next)
        {
            while (two)
            {
                if (one->violations > two->violations)
                {
                    swap(one->fio, two->fio);
                    swap(one->age, two->age);
                    swap(one->f,two->f);
                    swap(one->violations, two->violations);
                }
                two = two->next;
            }
            one = one->next;
            two = one->next;
        }
    }
};
enum class Query
{
    ADD,
    search,
    group_age,
    group_f,
    group_violations,
    sort,
    vivod
};
istream& operator >> (istream& is, Query& q)
{
    int operation;
    cout << "1.Запись" << endl;
    cout << "2.Ввести нарушения " << endl;
    cout << "3.Печать группы риска по возрасту." << endl;
    cout << "4.Печать группы риска по необходимости ." << endl;
    cout << "5.Печать группы риска кто ни разу не нарушал." << endl;
    cout << "6.Сортировка." << endl;
    cout << "7.Вывод." << endl;
    cout << "8.Выход." << endl;
    cout << "Ваш выбор : "; is >> operation;
    system("cls");
    switch (operation)
    {
    case 1: {
        q = Query::ADD;
        break;
    }
    case 2: {
        q = Query::search;
        break; }
    case 3: {
        q = Query::group_age;
        break;
    }
    case 4: {
        q = Query::group_f;
        break;
    }
    case 5: {
        q = Query::group_violations;
        break;
    }
    case 6: {
        q = Query::sort;
        break;
    }
    case 7: {
        q = Query::vivod;
        break;
    }
    }
    return is;
}
int main()
{

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    sit_at_home t1;
    Query q;
    while (cin >> q)
    {
        switch (q)
        {
        case Query::ADD: {
            t1.open();
            break; }

        case Query::search: {
            t1.search();
            break; }

        case Query::group_age: {
            int sit_at_home::city::* p = &sit_at_home::city::age;
            t1.group<int>(p, 40, "Возраст : ");
            break; }
        case Query::group_f: {
            bool sit_at_home::city::* p = &sit_at_home::city::f;
            t1.group<bool>(p, 0, "Необходимость : ");
            break; }
        case Query::group_violations:{
            int sit_at_home::city::* p = &sit_at_home::city::violations;
            t1.group<int>(p, 1, "Нарушения : ");
            break; }
        case Query::sort: {
            t1.sort();
            t1.ouput_k();
            break; }
        case Query::vivod: {
            t1.ouput();
            break; }
        }

    }
    return 0;
}

