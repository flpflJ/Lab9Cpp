#include <iostream>
#include <string>
#include <Windows.h>
#include <algorithm>
using namespace std;
// Задача следующая: Геттерами, сеттерами, и прочими методами инициализировать массив mas из поля private, заполнить его, а также вызывать. Сортировки, скорее всего, реализовать внутри класса.
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
    ~Credit() {
        delete[] mas;
    }
    void SetLen(int Arrlen) {
        this->len = Arrlen;
    }
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
    cout << "|Ïî êàêîìó ñòîëáöó îòñîðòèðîâàòü ìàññèâ?|" << endl;
    cout << "|1) Ôàìèëèÿ|" << endl;
    cout << "|2) Èìÿ|" << endl;
    cout << "|3) Îò÷åñòâî|" << endl;
    cout << "|4) Ñóììà|" << endl;
    cout << "|5) Ïðîöåíòíàÿ ñòàâêà|" << endl;
    cout << "|6) Ñðîê êðåäèòà|" << endl;
    cout << "|7) Ïåðåïëàòà ïî êðåäèòó|" << endl;
    cout << "|+++++++++++++++++++++++++++++|" << endl;
}

void menu_print() {
    system("cls");
    setlocale(LC_ALL, "Russian");
    cout << "|+++++++++++++++++++++++++++++|" << endl;
    cout << "|×òî âû õîòèòå ñäåëàòü?|" << endl;
    cout << "|1) Ââîä äàííûõ|" << endl;
    cout << "|2) Âûâåñòè äàííûå|" << endl;
    cout << "|3) Îòñîðòèðîâàòü ïî ïîëþ|" << endl;
    cout << "|4) Óäàëèòü îäèí ýëåìåíò|" << endl;
    cout << "|5) Óäàëèòü âñå äàííûå èç êëàññà(ïîâòîð ïðîãðàììû)|" << endl;
    cout << "|6) Çàïèñàòü äàííûå â ôàéë|" << endl;
    cout << "|7) Âûõîä|" << endl;
    cout << "|+++++++++++++++++++++++++++++|" << endl;
}

void errmsg() {
    cout << "Ïðîèçîøëà îøèáêà ïðè ââîäå äàííûõ, ââåäåíî íåäîïóñòèìîå çíà÷åíèå. Ïîâòîðèòå ïîïûòêó." << endl;
}

unsigned long long int input_long() {
    unsigned long long int c = 0;
    while (!(cin >> c)) {
        cin.clear();
        cin.sync();
        cin.ignore(1000, '\n');
        cout << "Íåâåðíîå ÷èñëî, ïîâòîðèòå ïîïûòêó" << endl;
    }
    return c;
}

double inputDouble() {
    double c = 0;
    while (!(cin >> c) || (c < 0) || (c > 100)) {
        cin.clear();
        cin.sync();
        cin.ignore(1000, '\n');
        cout << "Íåâåðíîå ÷èñëî, ïîâòîðèòå ïîïûòêó" << endl;
    }
    return c;
}

int input() {
    int c = 0;
    while (!(cin >> c) || (c <= 0)) {
        cin.clear();
        cin.sync();
        cin.ignore(1000, '\n');
        cout << "Íåâåðíîå ÷èñëî, ïîâòîðèòå ïîïûòêó" << endl;
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

/*void ManualEntry(Credit* m, int& length) {
    string Surname;
    string Name;
    string SecondName;
    unsigned long long int sum;
    double stavka;
    int lengthYear;
    long int percentSum;
    cout << "Ââåäèòå êîëè÷åñòâî êëèåíòîâ" << endl;
    length = input();
    cin.ignore(255, '\n');
    for (int i = 0; i < length; i++) {
        int x = i + 1;
        cout << "Ââîä ñòðîêè íîìåð " << x << endl;
        cout << "Ââåäèòå ôàìèëèþ" << endl;
        cin >> Surname;
        cout << "Ââåäèòå èìÿ" << endl;
        cin >> Name;
        cout << "Ââåäèòå îò÷åñòâî" << endl;
        cin >> SecondName;
        cout << "Ââåäèòå ñóììó êðåäèòà" << endl;
        sum = input_long();
        cout << "Ââåäèòå ïðîöåíòíóþ ñòàâêó â ãîä" << endl;
        stavka = inputDouble();
        cout << "Ââåäèòå ñðîê êðåäèòà(â ãîäàõ)" << endl;
        lengthYear = input();
        percentSum = CreditPlatezh(sum, stavka, lengthYear);
        cin.clear();
        cin.sync();
        m[i].SetAllThings(Surname, Name, SecondName, sum, stavka, lengthYear, percentSum);
        system("cls");
    }
    menu_print();
    cout << "Óñïåøíî çàïîëíåíî" << endl;
}*/
void ManualEntry(Credit m, int& length) {
    string Surname;
    string Name;
    string SecondName;
    unsigned long long int sum;
    double stavka;
    int lengthYear;
    long int percentSum;
    cout << "Ââåäèòå êîëè÷åñòâî êëèåíòîâ" << endl;
    length = input();
    cin.ignore(255, '\n');
    m.SetLen(length);
    m.SetArrThings();

}


int main()
{
    int n = 1;
    Credit m;
    ManualEntry(m,n);
}
