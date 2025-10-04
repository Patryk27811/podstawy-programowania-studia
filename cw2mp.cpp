#include <iostream>
#include <cmath>
using namespace std;

class Stozek {
private:
    double wysokosc;
    double promien_podstawy;
    double tworzaca;

    // Prywatna metoda obliczająca długość tworzącej
    double oblicz_tworza() {
        return sqrt(pow(wysokosc, 2) + pow(promien_podstawy, 2));
    }

public:
    // Konstruktor
    Stozek(double h, double r) {
        wysokosc = h;
        promien_podstawy = r;
        tworzaca = oblicz_tworza();
    }

    // Metoda obliczająca pole powierzchni całkowitej
    double pole_powierzchni() {
        double pole_podstawy = M_PI * pow(promien_podstawy, 2);
        double pole_bocznej = M_PI * promien_podstawy * tworzaca;
        return pole_podstawy + pole_bocznej;
    }

    // Metoda obliczająca objętość
    double objetosc() {
        return (1.0 / 3.0) * M_PI * pow(promien_podstawy, 2) * wysokosc;
    }

    // Gettery
    double get_wysokosc() { return wysokosc; }
    double get_promien_podstawy() { return promien_podstawy; }
    double get_tworza() { return tworzaca; }
};

int main() {
    double wysokosc, promien_podstawy;

    // Wprowadzenie danych przez użytkownika
    cout << "Podaj wysokosc stozka: ";
    cin >> wysokosc;
    cout << "Podaj promien podstawy stozka: ";
    cin >> promien_podstawy;

    // Utworzenie obiektu klasy Stozek
    Stozek stozek(wysokosc, promien_podstawy);

    // Wyświetlenie wyników
    cout << "Wysokosc stozka: " << stozek.get_wysokosc() << endl;
    cout << "Promien podstawy stozka: " << stozek.get_promien_podstawy() << endl;
    cout << "Dlugosc tworzącej stozka: " << stozek.get_tworza() << endl;
    cout << "Pole powierzchni calkowitej stozka: " << stozek.pole_powierzchni() << endl;
    cout << "Objetosc stozka: " << stozek.objetosc() << endl;

    return 0;
}
