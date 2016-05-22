// income_tax.cpp: определяет точку входа для консольного приложения.
 
//#include "stdafx.h"
#include <iostream>
using namespace std;
int counter_limit (const double &, const double &); // прототип функции для подсчёта необлагаемых минимумов
double tax(const double &, const double &, const int, const double); // прототип функции для начисления подоходного налога
int main(int argc, char* argv[])
{
    cout << "Enter the monthly salary: "; // введите размер месячной заработной платы
    double month_salary; // месечная заработная плата
    cin >> month_salary;
    const char val[] = "UAH"; // тип валюты
    const double exemption_limit = 940; // необлагаемый минимум
    double income_tax; // подоходный налог
    switch (counter_limit (month_salary, exemption_limit)) // расчёт подоходного налога, в зависимости от количества необлагаемых минимумов
    {
        case 0  : {income_tax = 0; break;}                                              // в случае если НДФЛ <= одного необлагаемого минимума
        case 1  : {income_tax = (month_salary - exemption_limit) * 10.0 / 100; break; } // в случае если НДФЛ > одного необлагаемого минимума и меньше либо равно 5 необлагаемых минимумов
        case 2  : {income_tax = tax(month_salary, exemption_limit, 5, 15); break;}      // в случае если НДФЛ > 5 необлагаемых минимумов и меньше либо равно 10 необлагаемым минимумам
        case 3  : {income_tax = tax(month_salary, exemption_limit, 10, 20); break;}     // в случае если НДФЛ > 10 необлагаемых минимумов и меньше либо равно 60 необлагаемым минимумам
        case 4  : {income_tax = tax(month_salary, exemption_limit, 60, 30); break;}     // в случае если НДФЛ > 60 необлагаемых минимумов и меньше либо равно 100 необлагаемым минимумам
        case 5  : {income_tax = tax(month_salary, exemption_limit, 100, 40); break;}    // в случае если НДФЛ > 100 необлагаемых минимумов
        default : {income_tax = 0; cout << "Incorrect entry" << endl;} // в случае ввода отрицательного числа
    }
    cout << "income tax = " << income_tax << " " << val << endl; // вывод подоходного налога
    system("pause");
    return 0;
}
int counter_limit (const double &month_salary,   // месячная зарплата
                   const double &exemption_limit // необлагаемый минимум
                  )                              // функция для подсчёта необлагаемых минимумов
{
    return (month_salary <=      exemption_limit) && (month_salary >= 0)                     ? 0 : // функция вернёт нуль
           (month_salary >       exemption_limit) && (month_salary <= 5 * exemption_limit)   ? 1 : // функция вернёт 1
           (month_salary > 5   * exemption_limit) && (month_salary <= 10 * exemption_limit)  ? 2 : // функция вернёт 2
           (month_salary > 10  * exemption_limit) && (month_salary <= 60 * exemption_limit)  ? 3 : // функция вернёт 3
           (month_salary > 60  * exemption_limit) && (month_salary <= 100 * exemption_limit) ? 4 : // функция вернёт 4
           (month_salary > 100 * exemption_limit) ? 5 : -1; // если условие истинно, то функция вернёт 5, иначе -1
}      
double tax(const double &month_salary,    // месячная зарплата
           const double &exemption_limit, // не облагаемый минимум
           const int number_bids,         // минимальное количество не облагаемых минимумов
           const double percentage        // процент начисления подоходного налога 
          )                               // функция для начисления подоходного налога
{
    return ( ((exemption_limit * number_bids) * 10.0 / 100) + (month_salary - (exemption_limit * number_bids)) * percentage / 100.0); // формула для расчёта подоходного налога
}