#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
using namespace std;
class Cards
{
public:
    int number;
    int date;
    int snumber;
    int balance;
    int exprensecOne;
    int exprensecTwo;
    int exprensecThree;
    Cards() {}
    Cards(int n, int d, int sn, int b, int e, int ex, int exp)
    {
        number = n;
        date = d;
        snumber = sn;
        balance = b;
        exprensecOne = e;
        exprensecTwo = ex;
        exprensecThree = exp;
    }
    void replenishment()
    {
        cout << "Введите данные чтобы добавить карту\n";
        cout << "Введите номер карты: \n";
        cin >> number;
        cout << "Введите срок окончания.напимер(12/24): \n";
        cin >> date;
        cout << "введите трехзначнный код.Например(284): \n";
        cin >> snumber;
        cout << "введите суму пополнения: \n";
        cin >> balance;
        ofstream file("cards.txt");
        if (!file.is_open())
            cout << "error";
        else
            file << "number - \n" << number << "date - \n" << date << "code - \n" << snumber << "balance\n" << balance;
        file.close();
    }
    void Exprenses()
    {
        cout << "Введите число и затраты на сегодня: \n";
        cin >> exprensecOne;
        cout << "введите затраты за неделю: \n";
        cin >> exprensecTwo;
        cout << "Введите месяц и затраты: \n";
        cin >> exprensecThree;
        ofstream file("cards.txt");
        if (!file.is_open())
            cout << "error";
        else
            file << "===ЗАТРАТЫ===\n" << "Дата и затрата за день=\n" << exprensecOne << "Затрата за неделю=\n" << exprensecTwo << "Затраты за месяц=\n" << exprensecThree;
        file.close();
    }
};
class Wallets : protected Cards
{
public:
    Wallets() {}
    Wallets(int n, int d, int sn, int b, int e, int ex, int exp, int c) :Cards(n, d, sn, b, e, ex, exp)
    {
        code = c;
    }
    void replenishment2()
    {
        cout << "Введите данные чтобы добавить кошелек\n";
        cout << "Введите номер кошелька.Например(U78954568): \n";
        cin >> number;
        cout << "введите код: \n";
        cin >> code;
        cout << "введите суму пополнения: \n";
        cin >> balance;
        ofstream file("cards.txt");
        if (!file.is_open())
            cout << "error";
        else
            file << "number - \n" << number << "Code - \n" << code;
        file.close();
    }
    void Exprenses2()
    {
        cout << "Введите затраты число и на сегодня: \n";
        cin >> exprensecOne;
        cout << "введите затраты за неделю: \n";
        cin >> exprensecTwo;
        cout << "Введите месяц и затраты: \n";
        cin >> exprensecThree;
        ofstream file("cards.txt");
        if (!file.is_open())
            cout << "error";
        else
            file << "===ЗАТРАТЫ===\n" << "Дата и затрата за день=\n" << exprensecOne << "Затрата за неделю=\n" << exprensecTwo << "Затраты за месяц=\n" << exprensecThree;
        file.close();
    }
private:
    int code;
};
int main()
{
    setlocale(LC_ALL, "rus");
    char a;
    Cards* s;
    Cards c;
    Wallets w;
    do
    {
        cout << "==Выберите операцию==\n";
        cout << "1-пополнить кредитку\n";
        cout << "2-пополнить кошель\n";
        cout << "3-внести затраты по кредиткам\n";
        cout << "4-внести затраты по кошелькам\n";
        cout << "Esc-выход\n";
        a = _getch();
        switch (a)
        {
        case '1':
            c.replenishment();
            break;
        case '2':
            w.replenishment2();
            break;
        case '3':
            c.Exprenses();
            break;
        case '4':
            w.Exprenses2();
        }
    } while (a != 27);
}