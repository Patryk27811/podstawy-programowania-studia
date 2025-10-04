#include <iostream>
using namespace std;

void przeliczFnaC()
{
    double f, c;
    cout << "Podaj temperaturę w stopniach Fahrenheita: ";
    cin >> f;
    if (f > -459.7)
    { // Sprawdzenie granicy fizycznej (zero absolutne)
        c = 5.0 / 9 * (f - 32);
        cout << f << " F = " << c << " C" << endl;
    }
    else
    {
        cout << "Błąd; podana temperatura jest mniejsza od zera bezwzględnego." << endl;
    }
}

void przeliczCnaF()
{
    double c, f;
    cout << "Podaj temperaturę w stopniach Celsjusza: ";
    cin >> c;
    if (c >= -273.15)
    { // Sprawdzenie granicy fizycznej (zero absolutne)
        f = (9.0 / 5) * c + 32;
        cout << c << " C = " << f << " F" << endl;
    }
    else
    {
        cout << "Błąd; podana temperatura jest mniejsza od zera bezwzględnego." << endl;
    }
}

void przeliczKnaC()
{
    double k, c;
    cout << "Podaj temperaturę w stopniach Kelwina: ";
    cin >> k;
    if (k >= 0)
    { // Sprawdzenie granicy fizycznej (0 K)
        c = k - 273.15;
        cout << k << " K = " << c << " C" << endl;
    }
    else
    {
        cout << "Błąd; temperatura w kelwinach nie może być mniejsza od zera." << endl;
    }
}

void przeliczCnaK()
{
    double c, k;
    cout << "Podaj temperaturę w stopniach Celsjusza: ";
    cin >> c;
    if (c >= -273.15)
    { // Sprawdzenie granicy fizycznej (zero absolutne)
        k = c + 273.15;
        cout << c << " C = " << k << " K" << endl;
    }
    else
    {
        cout << "Błąd; podana temperatura jest mniejsza od zera bezwzględnego." << endl;
    }
}

int main()
{
    cout << "Przeliczanie temperatury" << endl;
    cout << "F -> C <1> | C -> F <2> | K -> C <3> | C -> K <4>: ";
    int wybor;
    cin >> wybor;

    switch (wybor)
    {
    case 1:
        przeliczFnaC();
        break;
    case 2:
        przeliczCnaF();
        break;
    case 3:
        przeliczKnaC();
        break;
    case 4:
        przeliczCnaK();
        break;
    default:
        cout << "Nie ma takiej opcji." << endl;
    }

    return 0;
}
