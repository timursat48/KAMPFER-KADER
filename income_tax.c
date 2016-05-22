// income_tax.cpp: ���������� ����� ����� ��� ����������� ����������.
 
//#include "stdafx.h"
#include <iostream>
using namespace std;
int counter_limit (const double &, const double &); // �������� ������� ��� �������� ������������ ���������
double tax(const double &, const double &, const int, const double); // �������� ������� ��� ���������� ����������� ������
int main(int argc, char* argv[])
{
    cout << "Enter the monthly salary: "; // ������� ������ �������� ���������� �����
    double month_salary; // �������� ���������� �����
    cin >> month_salary;
    const char val[] = "UAH"; // ��� ������
    const double exemption_limit = 940; // ������������ �������
    double income_tax; // ���������� �����
    switch (counter_limit (month_salary, exemption_limit)) // ������ ����������� ������, � ����������� �� ���������� ������������ ���������
    {
        case 0  : {income_tax = 0; break;}                                              // � ������ ���� ���� <= ������ ������������� ��������
        case 1  : {income_tax = (month_salary - exemption_limit) * 10.0 / 100; break; } // � ������ ���� ���� > ������ ������������� �������� � ������ ���� ����� 5 ������������ ���������
        case 2  : {income_tax = tax(month_salary, exemption_limit, 5, 15); break;}      // � ������ ���� ���� > 5 ������������ ��������� � ������ ���� ����� 10 ������������ ���������
        case 3  : {income_tax = tax(month_salary, exemption_limit, 10, 20); break;}     // � ������ ���� ���� > 10 ������������ ��������� � ������ ���� ����� 60 ������������ ���������
        case 4  : {income_tax = tax(month_salary, exemption_limit, 60, 30); break;}     // � ������ ���� ���� > 60 ������������ ��������� � ������ ���� ����� 100 ������������ ���������
        case 5  : {income_tax = tax(month_salary, exemption_limit, 100, 40); break;}    // � ������ ���� ���� > 100 ������������ ���������
        default : {income_tax = 0; cout << "Incorrect entry" << endl;} // � ������ ����� �������������� �����
    }
    cout << "income tax = " << income_tax << " " << val << endl; // ����� ����������� ������
    system("pause");
    return 0;
}
int counter_limit (const double &month_salary,   // �������� ��������
                   const double &exemption_limit // ������������ �������
                  )                              // ������� ��� �������� ������������ ���������
{
    return (month_salary <=      exemption_limit) && (month_salary >= 0)                     ? 0 : // ������� ����� ����
           (month_salary >       exemption_limit) && (month_salary <= 5 * exemption_limit)   ? 1 : // ������� ����� 1
           (month_salary > 5   * exemption_limit) && (month_salary <= 10 * exemption_limit)  ? 2 : // ������� ����� 2
           (month_salary > 10  * exemption_limit) && (month_salary <= 60 * exemption_limit)  ? 3 : // ������� ����� 3
           (month_salary > 60  * exemption_limit) && (month_salary <= 100 * exemption_limit) ? 4 : // ������� ����� 4
           (month_salary > 100 * exemption_limit) ? 5 : -1; // ���� ������� �������, �� ������� ����� 5, ����� -1
}      
double tax(const double &month_salary,    // �������� ��������
           const double &exemption_limit, // �� ���������� �������
           const int number_bids,         // ����������� ���������� �� ���������� ���������
           const double percentage        // ������� ���������� ����������� ������ 
          )                               // ������� ��� ���������� ����������� ������
{
    return ( ((exemption_limit * number_bids) * 10.0 / 100) + (month_salary - (exemption_limit * number_bids)) * percentage / 100.0); // ������� ��� ������� ����������� ������
}