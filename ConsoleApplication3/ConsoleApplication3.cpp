#include <iostream>
#include <string>
#include <Windows.h>
#include <algorithm>
#include <ostream>
using namespace std;
// Задача следующая: 2 класса замутить и все
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
        cout << "Фамилия: " << Surname << endl;
        cout << "Имя: " << Name << endl;
        cout << "Отчество: " << SecondName << endl;
        cout << "Сумма кредита: " << sum << endl;
        cout << "Процентная ставка в год: " << stavka << "%" << endl;
        cout << "Срок кредита: " << lengthYear << " лет/года" << endl;
        cout << "Переплата по кредиту составляет: " << percentSum << " условных единиц" << endl;
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
    void PrintAll() {
        for (int i = 0; i < mas_len; i++) {
            cout << "Клиент № " << i + 1 << endl;
            mas[i].PrintAllThings();
        }
    }
    void Clear(int mas_len){
        if (mas) {
            delete[] mas;
        }
        mas = new Credit[mas_len];
        this->mas_len = mas_len;
    }
};

char* inputString() {
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    char* stringInput = new char[255];
    cin.getline(stringInput, 255, '\n');
    return stringInput;
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

void ManualEntry(CreditContainer& mas, int& length) {
    cout << "Введите количество клиентов" << endl;
    length = input();
    char* Surname = 0;
    string Name = "";
    string SecondName = "";
    unsigned long long int sum = 0;
    int stavka = 0;
    int lengthYear = 0;
    mas.Clear(length);
    cin.ignore(255, '\n');
    for (int i = 0; i < length; i++) {
        int x = i + 1;
        cout << "Ввод строки номер " << x << endl;
        cout << "Введите фамилию" << endl;
        Surname = inputString();
        cout << "Введите имя" << endl;
        Name = inputString();
        cout << "Введите отчество" << endl;
        SecondName = inputString();
        cout << "Введите сумму кредита" << endl;
        sum = input_long();
        cout << "Введите процентную ставку в год" << endl;
        stavka = inputDouble();
        cout << "Введите срок кредита(в годах)" << endl;
        lengthYear = input();
        cin.clear();
        cin.sync();
        system("cls");
        mas.Set_Mas_Things(i, Surname, Name, SecondName, sum, stavka, lengthYear);
    }
    menu_print();
    cout << "Успешно заполнено" << endl;
}

void DataOutputConsole(CreditContainer& mas, int const& length) { // ready!
        mas.PrintAll();
}

/*void StrokaDelete(CreditContainer& mas, int& length) {
    cout << "Введите, какой элемент вы хотите удалить" << endl;
    int elDel = input();
    --elDel;
    cout << elDel;
    if (elDel >= 0 && elDel < length) {
        Credit* buffer = new Credit[length];
        for (int i = 0; i < length; i++) {
            buffer[i] = mas[i];
        }
        --length;
        int k = 0;
        mas = new Credit[length];
        for (int i = 0; i < (length + 1); i++) {
            if (i != elDel) {
                mas[k] = buffer[i];
                k++;
            }
        }
        delete[] buffer;
        cout << "Элемент удален" << endl;
    }
    else {
        cout << "Неккоректный ввод номера!" << endl;
    }
}*/

void FileEntry(int& length, char* file) {
    ifstream in(file);
    if (in.is_open()) {
        in >> length;
        for (int i = 0; i < length; i++) {
            char buff[255]{};
            in >> buff;
            char* Surname = new char[strlen(buff)];
            strcpy(Surname, buff);
            memset(buff, 0, 255);
            string Name = "";
            in >> Name;
            string SecondName = "";
            in >> SecondName;
            in >> sum;
            in >> stavka;
            in >> lengthYear;
        }
        menu_print();
        cout << "Чтение из файла произошло успешно" << endl;
    }
    else {
        menu_print();
        cout << "Что-то пошло не так, файл не открыт!" << endl;
    }
    in.close();
}

void FileOutput(Credit const* mas, int const& length, char* file) {
    ofstream out;
    out.open(file);
    if (out.is_open()) {
        out << length << endl;
        for (int i = 0; i < length; i++) {
            int x = i + 1;
            out << "+++++++++++++++++++++++++++++++++++++++++" << endl;
            out << "Клиент № " << x << endl;
            out << "Фамилия: " << mas[i].Surname << endl;
            out << "Имя: " << mas[i].Name << endl;
            out << "Отчество: " << mas[i].SecondName << endl;
            out << "Сумма кредита: " << mas[i].sum << " условных единиц" << endl;
            out << "Процентная ставка в год: " << mas[i].stavka << "%" << endl;
            out << "Срок кредита(в годах): " << mas[i].lengthYear << endl;;
            out << "Переплата по кредиту: " << mas[i].percentSum << " условных единиц" << endl;
            out << "+++++++++++++++++++++++++++++++++++++++++" << endl;
        }
        cout << "Запись в файл успешно завершена" << endl;
    }
    else {
        cout << "Ошибка, файл не открыт" << endl;
    }
    out.close();
}

bool compSurname(const Credit& p1, const Credit& p2) { return strncmp(p2.Surname, p1.Surname, 255) > 0; }
bool compName(Credit& p1, Credit& p2) { return strncmp(p2.Name, p1.Name, 255) > 0; }
bool compSecondName(Credit& p1, Credit& p2) { return strncmp(p2.SecondName, p1.SecondName, 255) > 0; }
bool compSum(Credit& p1, Credit& p2) { return p2.sum < p1.sum; }
bool compStavka(Credit& p1, Credit& p2) { return p2.stavka < p1.stavka; }
bool compLength(Credit& p1, Credit& p2) { return p2.lengthYear < p1.lengthYear; }
bool compPlatezh(Credit& p1, Credit& p2) { return p2.percentSum < p1.percentSum; }

void userSort(Credit*& mas, int const& length) {
    menu_for_sort();
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int x = input();
    bool t = false;
    do {
        switch (x) {
        case(1):
            sort(mas, mas + length, compSurname);
            t = true;
            break;
        case(2):
            sort(mas, mas + length, compName);
            t = true;
            break;
        case(3):
            sort(mas, mas + length, compSecondName);
            t = true;
            break;
        case(4):
            sort(mas, mas + length, compSum);
            t = true;
            break;
        case(5):
            sort(mas, mas + length, compStavka);
            t = true;
            break;
        case(6):
            sort(mas, mas + length, compLength);
            t = true;
            break;
        case(7):
            sort(mas, mas + length, compPlatezh);
            t = true;
            break;
        default:
            errmsg();
            break;
            t = false;
        }
    } while (t == false);
    menu_print();
    cout << "Отсортировано!" << endl;
}

void InputEntry(Credit*& mas, int& length) {
    cout << "1) Вручную" << endl;
    cout << "2) С файла" << endl;
    int x = input();
    switch (x) {
    case(1):
        ManualEntry(mas, length);
        break;
    case(2):
        cout << "Введите название файла(например: Input.txt)" << endl;
        cin.ignore(255, '\n');
        char* filename = inputString();
        FileEntry(mas, length, filename);
        break;
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    bool x = false;
    int l = 0;
    CreditContainer mas(l);
    menu_print();
    do {
        int k = input();
        switch (k) {
        case(1):
            if (l == 0) { InputEntry(m, l); }
            else { DeleteAll(m, l); InputEntry(m, l); }
            break;
        case(2):
            if (l != 0) { mas.PrintAll(); }
            break;
        case(3):
            if (l != 0) { userSort(m, l); }
            break;
        case(4):
            if (l != 0) { StrokaDelete(m, l); }
            break;
        case(5):
            if (l != 0) { DeleteAll(m, l); }
            break;
        case(6):
            if (l != 0) {
                char* file = NULL;
                cout << "Введите название выходного файла(например:Output.txt) не более 255 символов, учитывая расширение" << endl;
                cin.ignore(255, '\n');
                file = inputString();
                FileOutput(m, l, file);
            }
            break;
        case(7):
            if (l != 0) { DeleteAll(m, l); }
            x = true;
            break;
        default:
            menu_print();
            errmsg();
            break;
        }
    } while (x == false);
    return 0;
}
