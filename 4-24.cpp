
#include <conio.h>
#include <locale>
#include <iostream>

using namespace std;

double sumN(double, int, double&);
double sumE(double, double, int&);

int main()
{
    setlocale(LC_ALL, "rus");
    int z = 1;
    cout << "хотите начать? 1- да   0- нет \n";
    cout << "Введите вариант ответа: \n";
    cin >> z;
    while (z != 0)
    {

        cout << "Вычисление значений функции ln(x)\n\n";
        double x; // Значение аргумента
        double func; // Точное значение функции
        double sum; // Значение частичной суммы
        int n; // Число слагаемых в частичной сумме



        cout << "Задание 1 \n";
        cout << "Введите значение аргумента > ";
        cin >> x;
        if (x <= 0.5)
        {
            cout << "Аргумент должен быть > 1/2";
            return 0;
        }
        cout << "Задайте число слагаемых > ";
        cin >> n;
        func = log(x);// Вычисление "точного" значения
        double last;
        sum = sumN(x, n, last);
        cout << "Точное значение функции равно " << func << endl;
        cout << "Частичная сумма ряда равна " << sum << endl;
        cout << "Абсолютная погрешность равна " << fabs(func - sum) << endl;
        cout << "Последнее слагаемое равно " << last << endl;

        cout << "\nЗадание 2" << endl;
        double E;
        cout << "Введите значение аргумента > ";
        cin >> x;
        if (x <= 0.5)
        {
            cout << "Аргумент должен быть > 1/2";
            return 0;
        }
        cout << "Задайте точность вычислений > ";
        cin >> E;
        func = log(x);// Вычисление "точного" значения
        sum = sumE(x, E, n);
        cout << "Точное значение функции равно " << func << endl;
        cout << "Частичная сумма ряда c заданной точностью равна " << sum << endl;
        cout << "Учтено " << n << " членов ряда" << endl;
        sum = sumE(x, E / 10, n);
        cout << "Частичная сумма ряда c точностью, большей в 10 раз, равна " << sum << endl;
        cout << "Учтено " << n << " членов ряда" << endl;
        cout << " Хотите продолжить ? 1- да    0- нет";
        cin >> z;
    }
    return 0;
}
double sumN(double x, int n, double& last)
{
    // Инициализация переменной last
    last = (x - 1) / x;
    double sum = last;
    for (int i = 1; i < n; ++i)
    {
        double r; // Отношение i-го слагаемлого к (i - 1)-му
       // Вычисление значения r
        r = (x - 1) * i / x / (i + 1);
        last *= r;
        sum += last;
    }
    return sum;
}


double sumE(double x, double E, int& n)
{
    double last;
    // Инициализация переменной last
    last = (x - 1) / x;
    double sum = last;
    for (n = 1; fabs(last) > E; ++n)
    {
        double r; // Отношение n-го слагаемлого к (n - 1)-му
      // Вычисление значения r
        r = (x - 1) * n / x / (n + 1);
        last *= r;
        sum += last;
    }
    return sum;
}