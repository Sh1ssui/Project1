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
        cout << "������� ������ ����� �������� �����\n";
        cout << "������� ����� �����: \n";
        cin >> number;
        cout << "������� ���� ���������.�������(12/24): \n";
        cin >> date;
        cout << "������� ������������ ���.��������(284): \n";
        cin >> snumber;
        cout << "������� ���� ����������: \n";
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
        cout << "������� ����� � ������� �� �������: \n";
        cin >> exprensecOne;
        cout << "������� ������� �� ������: \n";
        cin >> exprensecTwo;
        cout << "������� ����� � �������: \n";
        cin >> exprensecThree;
        ofstream file("cards.txt");
        if (!file.is_open())
            cout << "error";
        else
            file << "===�������===\n" << "���� � ������� �� ����=\n" << exprensecOne << "������� �� ������=\n" << exprensecTwo << "������� �� �����=\n" << exprensecThree;
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
        cout << "������� ������ ����� �������� �������\n";
        cout << "������� ����� ��������.��������(U78954568): \n";
        cin >> number;
        cout << "������� ���: \n";
        cin >> code;
        cout << "������� ���� ����������: \n";
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
        cout << "������� ������� ����� � �� �������: \n";
        cin >> exprensecOne;
        cout << "������� ������� �� ������: \n";
        cin >> exprensecTwo;
        cout << "������� ����� � �������: \n";
        cin >> exprensecThree;
        ofstream file("cards.txt");
        if (!file.is_open())
            cout << "error";
        else
            file << "===�������===\n" << "���� � ������� �� ����=\n" << exprensecOne << "������� �� ������=\n" << exprensecTwo << "������� �� �����=\n" << exprensecThree;
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
        cout << "==�������� ��������==\n";
        cout << "1-��������� ��������\n";
        cout << "2-��������� ������\n";
        cout << "3-������ ������� �� ���������\n";
        cout << "4-������ ������� �� ���������\n";
        cout << "Esc-�����\n";
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