#pragma execution_character_set("utf-8")


#include <iostream> 
#include <iomanip> 
#include <string> 
#include <Windows.h>
using namespace std;

enum Special { inftech, math, phys};

string specialStr[] = { "Інформаційні технології", "Інформатика", "Математика", "Фізика"};

struct Student
{
    string   prizv;
    unsigned kurs;
    Special   special;
    int phys;
    int math;
    int inftech;
};
void Create(Student* p, const int N);
void Print(Student* p, const int N);
double Math(Student* p, const int N);
double Physics(Student* p, const int N);
double Inftech(Student* p, const int N);
int Count(Student* p, const int N);

int main()
{
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    int N;
    cout << "Введіть N: "; cin >> N;

    Student* p = new Student[N];

    Create(p, N);
    Print(p, N);

    double ser = Math(p, N);
    cout << ser << endl;
    double ser1 = Physics(p, N);
    cout << ser1 << endl;
    double ser2 = Inftech(p, N);
    cout << ser2 << endl;
    int c = Count(p, N);
    cout << c << endl;
    return 0;
}
void Create(Student* p, const int N)
{
    int spec;
    for (int i = 0; i < N; i++)
    {
        cout << "Студент № " << i + 1 << ":" << endl;

        cin.get();
        cin.sync();

        cout << "    прізвище: "; getline(cin, p[i].prizv);
        cout << "    курс: "; cin >> p[i].kurs;
        cout << "    оцінка з математики(0-5): "; cin >> p[i].math;
        cout << "    оцінка з фізики(0-5): "; cin >> p[i].phys;
        cout << "    оцінка з інформатики(0-5): "; cin >> p[i].inftech;
        cout << "    спеціальність (1 - Математика, 2 - Інформатика, 3 - Фізика, 4 - Фізкультура): ";
        cin >> spec;
        p[i].special = (Special)spec;
        cout << endl;
    }
}
void Print(Student* p, const int N)
{
    cout << "==================================================================================================" << endl;
    cout << "|  №  |   Прізвище   |   Курс   |  Спеціальність  |   Математика   |   Фізика   |   Інформ.техн.   |" << endl;
    cout << "--------------------------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < N; i++)
    {
        cout << "| " << setw(3) << right << i + 1 << " ";
        cout << "| " << setw(13) << left << p[i].prizv
            << "|    " << setw(1) << right << p[i].kurs << "   "
            << "| " << setw(20) << left << specialStr[p[i].special] << "  "
            << "|   " << setw(5) << right << p[i].math << "   |   " << setw(5) << right << p[i].phys << "   | " << setw(7) << right << p[i].inftech << "     |" << endl;
    }
    cout <<
        "==================================================================================================" << endl;
    cout << endl;
}
double Math(Student* p, const int N)
{
    cout << "Середній бал з математики:" << endl;
    double b = 0, n = 0;
    for (int i = 0; i < N; i++)
    {
        b = ((p[i].math) * 1.0) + b;
    }
    return b / N;
}
double Physics(Student* p, const int N)
{
    cout << "Середній бал з фізики:" << endl;
    double b = 0, n = 0;
    for (int i = 0; i < N; i++)
    {
        b = ((p[i].phys) * 1.0) + b;
    }
    return b / N;
}
double Inftech(Student* p, const int N)
{
    cout << "Середній бал з інформатики:" << endl;
    double b = 0, n = 0;
    for (int i = 0; i < N; i++)
    {
        b = ((p[i].inftech) * 1.0) + b;
    }
    return b / N;
}
int Count(Student* p, const int N)
{
    cout << "Кількість студентів \"5 або 4 з фізики\" (4, 5):" << endl;
    int k = 0;
    for (int i = 0; i < N; i++)
    {
        if ((p[i].phys == 4) ||
            (p[i].phys == 5))
            k++;
    }
    return k;
}
