#include <iostream>
#include <string>
#include <Windows.h>
#include <algorithm>
using namespace std;

class Credit {
private:
    int len;
    string Surname;
    string Name;
    string SecondName;
    unsigned long long int sum;
    double stavka;
    int lengthYear;
    long int percentSum;
    Credit* mas;
public:
    Credit() : len(0), Surname(""), Name(""), SecondName(""), sum(0), stavka(0), lengthYear(0), percentSum(0), mas(0) {}
    Credit(int ln, string S, string N, string SN, unsigned long long int sm, double st, int leny, long int perSum, Credit* m) {
        len = ln;
        Surname = S;
        Name = N;
        SecondName = SN;
        sum = sm;
        stavka = st;
        lengthYear = leny;
        percentSum = perSum;
        mas = m;
    }
    Credit(const Credit& l) {
        len = l.len;
        Surname = l.Surname;
        Name = l.Name;
        SecondName = l.SecondName;
        sum = l.sum;
        stavka = l.stavka;
        lengthYear = l.lengthYear;
        percentSum = l.percentSum;
        mas = l.mas;
    }
    ~Credit() {}
    void SetAllThings(string inSurName, string inName, string inSecondName, unsigned long long int inSum, double inStavka, int inLen, long int inPer) {
        this->Surname = Surname;
        this->Name = inName;
        this->SecondName = inSecondName;
        this->sum = inSum;
        this->stavka = inStavka;
        this->lengthYear = inLen;
        this->percentSum = inPer;
    }
    string getSurname() {
        return Surname;
    }
    string getName() {
        return Name;
    }
    string getSecondName() {
        return SecondName;
    }
    unsigned long long int getSum() {
        return sum;
    }
    double getStavka() {
        return stavka;
    }
    int getLen() {
        return lengthYear;
    }
    long int getPerSum() {
        return percentSum;
    }
};

void menu_for_sort() {
    system("cls");
    setlocale(LC_ALL, "Russian");
    cout << "|+++++++++++++++++++++++++++++|" << endl;
    cout << "|По какому столбцу отсортировать массив?|" << endl;
    cout << "|1) Фамилия|" << endl;
    cout << "|2) Имя|" << endl;
    cout << "|3) Отчество|" << endl;
    cout << "|4) Сумма|" << endl;
    cout << "|5) Процентная ставка|" << endl;
    cout << "|6) Срок кредита|" << endl;
    cout << "|7) Переплата по кредиту|" << endl;
    cout << "|+++++++++++++++++++++++++++++|" << endl;
}

void menu_print() {
    system("cls");
    setlocale(LC_ALL, "Russian");
    cout << "|+++++++++++++++++++++++++++++|" << endl;
    cout << "|Что вы хотите сделать?|" << endl;
    cout << "|1) Ввод данных|" << endl;
    cout << "|2) Вывести данные|" << endl;
    cout << "|3) Отсортировать по полю|" << endl;
    cout << "|4) Удалить один элемент|" << endl;
    cout << "|5) Удалить все данные из класса(повтор программы)|" << endl;
    cout << "|6) Записать данные в файл|" << endl;
    cout << "|7) Выход|" << endl;
    cout << "|+++++++++++++++++++++++++++++|" << endl;
}

void errmsg() {
    cout << "Произошла ошибка при вводе данных, введено недопустимое значение. Повторите попытку." << endl;
}

unsigned long long int input_long() {
    unsigned long long int c = 0;
    while (!(cin >> c)) {
        cin.clear();
        cin.sync();
        cin.ignore(1000, '\n');
        cout << "Неверное число, повторите попытку" << endl;
    }
    return c;
}

double inputDouble() {
    double c = 0;
    while (!(cin >> c) || (c < 0) || (c > 100)) {
        cin.clear();
        cin.sync();
        cin.ignore(1000, '\n');
        cout << "Неверное число, повторите попытку" << endl;
    }
    return c;
}

int input() {
    int c = 0;
    while (!(cin >> c) || (c <= 0)) {
        cin.clear();
        cin.sync();
        cin.ignore(1000, '\n');
        cout << "Неверное число, повторите попытку" << endl;
    }
    return c;
}


long int CreditPlatezh(unsigned long long int const sum, double const stavka, int const year) {
    int n = year * 12;
    double P = (stavka / 12) / 100;
    double x = sum * (P + (P / (pow(1 + P, n) - 1)));
    x = x * n;
    long int platezh = x - sum;
    return platezh;

}

Credit* ManualEntry(int& length) {
    string Surname;
    string Name;
    string SecondName;
    unsigned long long int sum;
    double stavka;
    int lengthYear;
    long int percentSum;
    cout << "Введите количество клиентов" << endl;
    length = input();
    Credit* m = new Credit[length];
    cin.ignore(255, '\n');
    for (int i = 0; i < length; i++) {
        int x = i + 1;
        cout << "Ввод строки номер " << x << endl;
        cout << "Введите фамилию" << endl;
        cin >> Surname;
        cout << "Введите имя" << endl;
        cin >> Name;
        cout << "Введите отчество" << endl;
        cin >> SecondName;
        cout << "Введите сумму кредита" << endl;
        sum = input_long();
        cout << "Введите процентную ставку в год" << endl;
        stavka = inputDouble();
        cout << "Введите срок кредита(в годах)" << endl;
        lengthYear = input();
        percentSum = CreditPlatezh(sum, stavka, lengthYear);
        cin.clear();
        cin.sync();
        m[i].SetAllThings(Surname, Name, SecondName, sum, stavka, lengthYear, percentSum);
        system("cls");
    }
    menu_print();
    cout << "Успешно заполнено" << endl;
    return m;
}


int main()
{
    int n = 1;
    Credit* m = ManualEntry(n);
    cout << m[0].getName();
}