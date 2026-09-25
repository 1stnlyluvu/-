#include <iostream>
#include <string>
#include <cmath>
#include <cstdio>
#include <windows.h>

using namespace std;

int main() {

    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    while (true) {

        string equation;
        double a, b, c;

        cout << "\nВведите уравнение без пробелов: ";
        cin >> equation;

        if (equation == "exit")
            break;

        if (equation.rfind("x^2", 0) == 0)
            equation = "1" + equation;

        if (equation.rfind("-x^2", 0) == 0)
            equation.replace(0, 1, "-1");

        int pos = equation.find("x^2") + 3;

        if (equation.substr(pos, 2) == "+x")
            equation.insert(pos + 1, "1");

        if (equation.substr(pos, 2) == "-x")
            equation.insert(pos + 1, "1");

        if (sscanf_s(equation.c_str(),
            "%lfx^2%lfx%lf=0", &a, &b, &c) != 3) {

            cout << "Неверный формат уравнения" << endl;
            continue;
        }

        cout << "\na = " << a;
        cout << "\nb = " << b;
        cout << "\nc = " << c << endl;

        double sum = -b / a;
        double product = c / a;

        cout << "\nПо теореме Виета:";
        cout << "\nx1 + x2 = " << sum;
        cout << "\nx1 * x2 = " << product << endl;

        double D = b * b - 4 * a * c;

        if (D < 0) {
            cout << "\nДействительных корней нет" << endl;
        }
        else if (D == 0) {
            double x = -b / (2 * a);
            cout << "\nx1 = x2 = " << x << endl;
        }
        else {
            double x1 = (-b + sqrt(D)) / (2 * a);
            double x2 = (-b - sqrt(D)) / (2 * a);

            cout << "\nx1 = " << x1;
            cout << "\nx2 = " << x2 << endl;
        }
    }

    return 0;
}