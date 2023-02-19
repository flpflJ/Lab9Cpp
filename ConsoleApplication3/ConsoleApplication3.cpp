#include <iostream>
#include <string>
#include <Windows.h>
#include <algorithm>
using namespace std;
// ������ ���������: 2 ������ �������� � ���
class Credit {
private:
    char* Surname;
    string Name;
    string SecondName;
    unsigned long long int sum;
    double stavka;
    int lengthYear;
    long int percentSum;
public:
    Credit() : Surname(0), Name(""), SecondName(""), sum(0), stavka(0), lengthYear(0), percentSum(0) {}
    Credit(char* S, string N, string SN, unsigned long long int sm, double st, int leny) {

        Surname = new char[strlen(S)+1];
        strcpy_s(Surname, strlen(S) + 1, S);
        Name = N;
        SecondName = SN;
        sum = sm;
        stavka = st;
        lengthYear = leny;
        CreditPlatezh(sum, stavka, lengthYear);
    }

    Credit(const Credit& l) {
        Surname = new char[strlen(l.Surname) + 1];
        strcpy_s(Surname, strlen(l.Surname) + 1, l.Surname);
        Name = l.Name;
        SecondName = l.SecondName;
        sum = l.sum;
        stavka = l.stavka;
        lengthYear = l.lengthYear;
        percentSum = l.percentSum;
    }
    ~Credit() {
        if (Surname) { delete[] Surname; }
    }
    void SetThings(char* S, string N, string SN, unsigned long long int sm, double st, int leny){
        Surname = new char[strlen(S) + 1];
        strcpy_s(Surname, strlen(S) + 1, S);
        Name = N;
        SecondName = SN;
        sum = sm;
        stavka = st;
        lengthYear = leny;
        CreditPlatezh(sum, stavka, lengthYear);
    }
    char* getSurname() {
        return Surname;
    }
    int getSurnameLength() {
        return (strlen(Surname)+1);
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
    void CreditPlatezh(unsigned long long int const sum, double const stavka, int const year) {
        int n = year * 12;
        double P = (stavka / 12) / 100;
        double x = sum * (P + (P / (pow(1 + P, n) - 1)));
        x = x * n;
        long int platezh = x - sum;
        percentSum = platezh;
    }
    void PrintAllThings() {
        cout << "+++++++++++++++++++++++++++++++++++++++++" << endl;
        cout << "�������: " << Surname << endl;
        cout << "���: " << Name << endl;
        cout << "��������: " << SecondName << endl;
        cout << "����� �������: " << sum << endl;
        cout << "���������� ������ � ���: " << stavka << "%" << endl;
        cout << "���� �������: " << lengthYear << " ���/����" << endl;
        cout << "��������� �� ������� ����������: " << percentSum << " �������� ������" << endl;
        cout << "+++++++++++++++++++++++++++++++++++++++++" << endl;
    }
};

class CreditContainer {
private:
    int mas_len;
    Credit* mas;
public:
    CreditContainer() : mas_len(0), mas(NULL) {}
    CreditContainer(int len) {
        mas_len = len;
        mas = new Credit[mas_len];
    }
    CreditContainer(const CreditContainer& cp) {
        mas = new Credit[cp.mas_len];
        mas_len = cp.mas_len;
        for (int i = 0; i < cp.mas_len; i++) {
            Credit buffer = cp.mas[i];
            mas[i].SetThings(buffer.getSurname(), buffer.getName(), buffer.getSecondName(), buffer.getSum(), buffer.getStavka(), buffer.getLen());
        }
    }
    ~CreditContainer() {
        if (mas) {
            delete[] mas;
        }
    }
    void Set_Mas_Things(int i, char* Surname, string Name, string SecondName, unsigned long long int sum, double stavka, int len) {
        if (i < mas_len) {
            mas[i].SetThings(Surname, Name, SecondName, sum, stavka, len);
        }
    }
};

unsigned long long int input_long() {
    unsigned long long int c = 0;
    while (!(cin >> c)) {
        cin.clear();
        cin.sync();
        cin.ignore(1000, '\n');
        cout << "�������� �����, ��������� �������" << endl;
    }
    return c;
}

double inputDouble() {
    double c = 0;
    while (!(cin >> c) || (c < 0) || (c > 100)) {
        cin.clear();
        cin.sync();
        cin.ignore(1000, '\n');
        cout << "�������� �����, ��������� �������" << endl;
    }
    return c;
}

int input() {
    int c = 0;
    while (!(cin >> c) || (c <= 0)) {
        cin.clear();
        cin.sync();
        cin.ignore(1000, '\n');
        cout << "�������� �����, ��������� �������" << endl;
    }
    return c;
}

void menu_for_sort() {
    system("cls");
    setlocale(LC_ALL, "Russian");
    cout << "|+++++++++++++++++++++++++++++|" << endl;
    cout << "|�� ������ ������� ������������� ������?|" << endl;
    cout << "|1) �������|" << endl;
    cout << "|2) ���|" << endl;
    cout << "|3) ��������|" << endl;
    cout << "|4) �����|" << endl;
    cout << "|5) ���������� ������|" << endl;
    cout << "|6) ���� �������|" << endl;
    cout << "|7) ��������� �� �������|" << endl;
    cout << "|+++++++++++++++++++++++++++++|" << endl;
}

void menu_print() {
    system("cls");
    setlocale(LC_ALL, "Russian");
    cout << "|+++++++++++++++++++++++++++++|" << endl;
    cout << "|��� �� ������ �������?|" << endl;
    cout << "|1) ���� ������|" << endl;
    cout << "|2) ������� ������|" << endl;
    cout << "|3) ������������� �� ����|" << endl;
    cout << "|4) ������� ���� �������|" << endl;
    cout << "|5) ������� ��� ������ �� ������(������ ���������)|" << endl;
    cout << "|6) �������� ������ � ����|" << endl;
    cout << "|7) �����|" << endl;
    cout << "|+++++++++++++++++++++++++++++|" << endl;
}

void errmsg() {
    cout << "��������� ������ ��� ����� ������, ������� ������������ ��������. ��������� �������." << endl;
}

/*void ManualEntry(Credit* m, int& length) {
    string Surname;
    string Name;
    string SecondName;
    unsigned long long int sum;
    double stavka;
    int lengthYear;
    long int percentSum;
    cout << "������� ���������� ��������" << endl;
    length = input();
    cin.ignore(255, '\n');
    for (int i = 0; i < length; i++) {
        int x = i + 1;
        cout << "���� ������ ����� " << x << endl;
        cout << "������� �������" << endl;
        cin >> Surname;
        cout << "������� ���" << endl;
        cin >> Name;
        cout << "������� ��������" << endl;
        cin >> SecondName;
        cout << "������� ����� �������" << endl;
        sum = input_long();
        cout << "������� ���������� ������ � ���" << endl;
        stavka = inputDouble();
        cout << "������� ���� �������(� �����)" << endl;
        lengthYear = input();
        percentSum = CreditPlatezh(sum, stavka, lengthYear);
        cin.clear();
        cin.sync();
        m[i].SetAllThings(Surname, Name, SecondName, sum, stavka, lengthYear, percentSum);
        system("cls");
    }
    menu_print();
    cout << "������� ���������" << endl;
}*/
/*void ManualEntry(Credit m, int& length) {
    string Surname;
    string Name;
    string SecondName;
    unsigned long long int sum;
    double stavka;
    int lengthYear;
    long int percentSum;
    cout << "������� ���������� ��������" << endl;
    length = input();
    cin.ignore(255, '\n');
    //m.SetArray(length);
    for (int i = 0; i < length; i++) {
        int x = i + 1;
        cout << "���� ������ ����� " << x << endl;
        cout << "������� �������" << endl;
        cin >> Surname;
        cout << "������� ���" << endl;
        cin >> Name;
        cout << "������� ��������" << endl;
        cin >> SecondName;
        cout << "������� ����� �������" << endl;
        sum = input_long();
        cout << "������� ���������� ������ � ���" << endl;
        stavka = inputDouble();
        cout << "������� ���� �������(� �����)" << endl;
        lengthYear = input();
        percentSum = CreditPlatezh(sum, stavka, lengthYear);
        cin.clear();
        cin.sync();
        //m.SetArrThings(Surname, Name, SecondName, sum, stavka, lengthYear, percentSum, i);
    }
}*/


int main()
{
    setlocale(LC_ALL, "Russian");
    int n = 1;
    Credit m;
    cout << "ABCD";
    //ManualEntry(m,n);
    //Credit s = m.getArr(d); // �� ������, ��� ��� ��������.
    //cout << s.getName();
}
