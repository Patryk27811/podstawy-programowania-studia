#include<iostream>
#include<string>
#include<stdexcept> // dla std::runtime_error
using namespace std;

class Wektor {
    friend ostream& operator<<(ostream&, const Wektor&);
    friend istream& operator>>(istream&, Wektor&);
    const static int N = 10;
    float wspolrzedne[N];
    int rozmiar = 0;
public:
    void wpisz() {
        cout << endl << "Podaj liczbę współrzędnych (<=" << N << "): ";
        cin >> rozmiar;
        cout << "Podaj współrzędne wektora (" << rozmiar << "): ";
        for (int i = 0; i < rozmiar; i++) {
            cin >> wspolrzedne[i];
        }
    }

    // Operator dodawania wektorów
    Wektor operator+(const Wektor& w) const {
        int r = min(rozmiar, w.rozmiar);
        Wektor wynikowy;
        wynikowy.rozmiar = r;
        for (int i = 0; i < r; i++) {
            wynikowy.wspolrzedne[i] = wspolrzedne[i] + w.wspolrzedne[i];
        }
        return wynikowy;
    }

    // Operator +=
    void operator+=(const Wektor& w) {
        int r = min(rozmiar, w.rozmiar);
        for (int i = 0; i < r; i++) {
            wspolrzedne[i] += w.wspolrzedne[i];
        }
    }

    // Operator przypisania
    Wektor& operator=(const Wektor& w) {
        if (this != &w) {
            rozmiar = w.rozmiar;
            for (int i = 0; i < rozmiar; i++) {
                wspolrzedne[i] = w.wspolrzedne[i];
            }
        }
        return *this;
    }

    // a) Operator -
    Wektor operator-(const Wektor& w) const {
        int r = min(rozmiar, w.rozmiar);
        Wektor wynik;
        wynik.rozmiar = r;
        for (int i = 0; i < r; i++) {
            wynik.wspolrzedne[i] = wspolrzedne[i] - w.wspolrzedne[i];
        }
        return wynik;
    }

    // a) Operator -=
    void operator-=(const Wektor& w) {
        int r = min(rozmiar, w.rozmiar);
        for (int i = 0; i < r; i++) {
            wspolrzedne[i] -= w.wspolrzedne[i];
        }
    }

    // b) Operator * skalar
    Wektor operator*(float skalar) const {
        Wektor wynik;
        wynik.rozmiar = rozmiar;
        for (int i = 0; i < rozmiar; i++) {
            wynik.wspolrzedne[i] = wspolrzedne[i] * skalar;
        }
        return wynik;
    }

    // b) Operator / skalar
    Wektor operator/(float skalar) const {
        if (skalar == 0) throw runtime_error("Dzielenie przez zero!");
        Wektor wynik;
        wynik.rozmiar = rozmiar;
        for (int i = 0; i < rozmiar; i++) {
            wynik.wspolrzedne[i] = wspolrzedne[i] / skalar;
        }
        return wynik;
    }

    // c) Operator []
    float& operator[](int index) {
        if (index < 0 || index >= rozmiar) throw out_of_range("Nieprawidłowy indeks!");
        return wspolrzedne[index];
    }

    const float& operator[](int index) const {
        if (index < 0 || index >= rozmiar) throw out_of_range("Nieprawidłowy indeks!");
        return wspolrzedne[index];
    }
};

// d) Operator <<
ostream& operator<<(ostream& o, const Wektor& w) {
    for (int i = 0; i < w.rozmiar; i++) {
        o << w.wspolrzedne[i] << " ";
    }
    return o;
}

// d) Operator >>
istream& operator>>(istream& in, Wektor& w) {
    cout << "Podaj liczbę współrzędnych (<=" << Wektor::N << "): ";
    in >> w.rozmiar;
    if (w.rozmiar > Wektor::N) w.rozmiar = Wektor::N;

    cout << "Podaj współrzędne: ";
    for (int i = 0; i < w.rozmiar; i++) {
        in >> w.wspolrzedne[i];
    }

    // Wyczyść resztę linii, jeśli użytkownik wpisał za dużo liczb
    string rest;
    getline(in, rest); // usuwa wszystko do końca linii

    return in;
}



// Funkcja main do testów
int main() {
    Wektor a, b;
    cin >> a >> b;

    cout << endl << "a: " << a;
    cout << endl << "b: " << b;

    Wektor c = a + b;
    cout << endl << "a + b: " << c;

    c = a - b;
    cout << endl << "a - b: " << c;

    float skalarMnozenie;
cout << endl << "Podaj skalar, przez który chcesz pomnożyć wektor a: ";
cin >> skalarMnozenie;
c = a * skalarMnozenie;
cout << "a * " << skalarMnozenie << ": " << c;


    try {
    float skalar;
    cout << endl << "Podaj skalar, przez który chcesz podzielić wektor a: ";
    cin >> skalar;
    c = a / skalar;
    cout << "a / " << skalar << ": " << c;
} catch (const exception& e) {
    cout << "Błąd: " << e.what();
}


    cout << endl << "a[1]: " << a[1];

    return 0;
}

