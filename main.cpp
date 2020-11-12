#include <iostream>
#include "input.cpp"

string strAb = "A";
string strBb = "B";
string strCb = "C";
string strAs = "a";
string strBs = "b";
string strCs = "c";

class FuzzyNumber {
private:
    float x0 = .0;
    float x1 = .0;
    float x2 = .0;
    float y1 = .0;
    float y2 = .0;
    string strPrint= "";
public:
    void GetNumber(string &, string &);
    void SetPrintNumber();
    void Plus(FuzzyNumber &, FuzzyNumber &);
    void Minus(FuzzyNumber &, FuzzyNumber &);
    void Multiplication(FuzzyNumber &, FuzzyNumber &);
    void Division(FuzzyNumber &, FuzzyNumber &);
    void Reverse(string &);
};

void printHelloUser();
void mainMenu(FuzzyNumber &, FuzzyNumber &, FuzzyNumber &);
void printChoiseMenu();

void FuzzyNumber :: GetNumber(string &strB, string &strS) {
    myInput(x0, "Введите " + strB + ": ", "Ошибка ввода типа данных.");
    myInput(y1, "Введите " + strS + "1: ", "Ошибка ввода типа данных.");
    x1 = x0 - y1;
    myInput(y2, "Введите " + strS + "2: ", "Ошибка ввода типа данных.");
    x2 = x0 + y2;
    strPrint = strB + " = (" + to_string(x1) + ", " + to_string(x0) + ", " + to_string(x2) + ");";
}

void FuzzyNumber :: SetPrintNumber() {
    cout << strPrint << endl;
}

/* A + B = (A + B - a1 - b1,
     A + B, A + B + a2 + b2); */
void FuzzyNumber :: Plus(FuzzyNumber &al, FuzzyNumber &bl) {
    x0 = al.x0 + bl.x0;
    x1 = al.x0 + bl.x0 - al.y1 - bl.y1;
    x2 = al.x0 + bl.x0 + al.y2 + bl.y2;
    y1 = x0 - x1;
    y2 = x2 - x0;
    strPrint = "A + B = (" + to_string(x1) + ", " + to_string(x0) + ", " + to_string(x2) + ");";
}

/* A - B = (A - B - a1 - b1,
     A - B, A - B + a2 + b2); */
void FuzzyNumber :: Minus(FuzzyNumber &al, FuzzyNumber &bl) {
    x0 = al.x0 - bl.x0;
    x1 = al.x0 - bl.x0 - al.y1 - al.y2;
    x2 = al.x0 - al.x0 + al.y2 + al.y2;
    y1 = x0 - x1;
    y2 = x2 - x0;
    strPrint = "A - B = (" + to_string(x1) + ", " + to_string(x0) + ", " + to_string(x2) + ");";
}

/* A * B = (A * B - B * a1 - A * b1 + a1 * b1,
     A * B, A * B + B * a1 + A * b1 + a1 * b1); */
void FuzzyNumber :: Multiplication(FuzzyNumber &al, FuzzyNumber &bl) {
    x0 = al.x0 * bl.x0;
    x1 = al.x0 * bl.x0 - bl.x0 * al.y1 - al.x0 * bl.y1 + al.y1 * bl.y1;
    x2 = al.x0 * bl.x0 + bl.x0 * al.y1 + al.x0 * bl.y1 + al.y1 * bl.y1;
    y1 = x0 - x1;
    y2 = x2 - x0;
    strPrint = "A * B = (" + to_string(x1) + ", " + to_string(x0) + ", " + to_string(x2) + ");";
}

/* A / B = ((A - a1) / (B + b2),
     A / B, (A + a2) / (B - b1)), B > 0; */
void FuzzyNumber :: Division(FuzzyNumber &al, FuzzyNumber &bl) {
    if ((bl.x0 > 0) && ((bl.x0 + bl.y2) != 0) && ((bl.x0 - bl.y1) != 0)) {
        x0 = al.x0 / bl.x0;
        x1 = (al.x0 - al.y1) / (bl.x0 + bl.y2);
        x2 = (al.x0 + al.y2) / (bl.x0 - bl.y1);
        y1 = x0 - x1;
        y2 = x2 - x0;
        strPrint = "A / B = (" + to_string(x1) + ", " + to_string(x0) + ", " + to_string(x2) + ");";
    } else {
        strPrint = "Частный случай. B > 0.";
    }

}

// A = (1 / (A + a2), 1 / A, 1 / (A - a1)), A > 0;
void FuzzyNumber :: Reverse(string &str) {
    if ((x0 > 0) && ((x0 + y2) != 0) && ((x0 - y1) != 0)) {
        x0 = 1 / x0;
        x1 = 1 / (x0 + y2);
        x2 = 1 / (x0 - y1);
        y1 = x0 - x1;
        y2 = x2 - x0;
        strPrint = "!" + str + " = (" + to_string(x1) + ", " + to_string(x0) + ", " + to_string(x2) + ");";
    } else {
        strPrint = "Частный случай. " + str + " > 0.";
    }
}

int main() {

    FuzzyNumber a, b, c;
    printHelloUser();
    mainMenu(a, b, c);

    return 0;
}

void mainMenu(FuzzyNumber &a, FuzzyNumber &b, FuzzyNumber &c) {

    bool workMenu = true;
    while (workMenu) {
        printChoiseMenu();
        int choiseKeyInt = 0;
        string choiseKeyStr = "";
        getline(cin, choiseKeyStr);
        choiseKeyInt = myConStrInt(choiseKeyStr);

        switch (choiseKeyInt) {
            case 1:
                a.GetNumber(strAb, strAs);
                b.GetNumber(strBb, strBs);
                a.SetPrintNumber();
                b.SetPrintNumber();
                break;
            case 2:
                c.Plus(a, b);
                c.SetPrintNumber();
                break;
            case 3:
                c.Minus(a, b);
                c.SetPrintNumber();
                break;
            case 4:
                c.Multiplication(a, b);
                c.SetPrintNumber();
                break;
            case 5:
                c.Division(a, b);
                c.SetPrintNumber();
                break;
            case 6:
                a.Reverse(strAb);
                a.SetPrintNumber();
                b.Reverse(strBb);
                b.SetPrintNumber();
                break;
            default:
                workMenu = false;
                break;
        }
    }
}

void printChoiseMenu() {
    cout << "\n\tВыбор действия:\n";
    cout << "1.Ввод чисел.\t(A и B)\n";
    cout << "2.Сложение.\t(A + B)\n";
    cout << "3.Вычитание.\t(A - B)\n";
    cout << "4.Умножение.\t(A * B)\n";
    cout << "5.Деление.\t(A / B)\n";
    cout << "6.Обратные.\t(A и B)\n";
    cout << "7.Выход.\t(или введите любое)\n\n";
    cout << "Ожидание ввода: ";
}

void printHelloUser () {
    system("clear");
    cout << "\tРеализовать класс FuzzyNumber для работы с нечеткими числами,\n";
    cout << "\tкоторые представляются тройками чисел (x - e1, x, x + e2).\n";
    cout << "\tДля чисел A = (A - a1, A, A + a2) и B = (B - b1, B, B + b2)\n";
    cout << "\taрифметические операции выполняются по следующим формулам:\n\n";
    cout << "-сложение\tA + B = (A + B - a1 - b1, A + B, A + B + a2 + b2);\n";
    cout << "-вычитание\tA - B = (A - B - a1 - b1, A - B, A - B + a2 + b2);\n";
    cout << "-умножение\tA * B = (A * B - B * a1 - A * b1 + a1 * b1, A * B, A * B + B * a1 + A * b1 + a1 * b1);\n";
    cout << "-обратное число\tA = (1 / (A + a2), 1 / A, 1 / (A - a1)), A > 0;\n";
    cout << "-деление\tA / B = ((A - a1) / (B + b2), A / B, (A + a2) / (B - b1)), B > 0;\n\n";
    cout << "Введите любое что-бы продолжить: ";
    string lol;
    getline(cin, lol);
    system("clear");
}
