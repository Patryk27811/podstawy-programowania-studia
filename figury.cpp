#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Figura {
public:
    virtual float pole_pow() = 0;
    virtual float obwod() = 0;
    virtual void wypisz() = 0;
    virtual ~Figura() {}
};

class Kolo : public Figura {
    float r;
public:
    Kolo(float r) : r(r) {}
    float pole_pow() override {
        return 3.14f * r * r;
    }
    float obwod() override {
        return 2 * 3.14f * r;
    }
    void wypisz() override {
        cout << "Kolo: r = " << r << endl;
    }
};

class Prostokat : public Figura {
    float a, b;
public:
    Prostokat(float a, float b) : a(a), b(b) {}
    float pole_pow() override {
        return a * b;
    }
    float obwod() override {
        return 2 * (a + b);
    }
    void wypisz() override {
        cout << "Prostokat: a = " << a << ", b = " << b << endl;
    }
};

class Trojkat : public Figura {
    float a, b, c;
public:
    Trojkat(float a, float b, float c) : a(a), b(b), c(c) {}
    float pole_pow() override {
        float s = (a + b + c) / 2;
        return sqrt(s * (s - a) * (s - b) * (s - c));
    }
    float obwod() override {
        return a + b + c;
    }
    void wypisz() override {
        cout << "Trojkat: a = " << a << ", b = " << b << ", c = " << c << endl;
    }
};

class MagazynFigur {
    vector<Figura*> figury;
public:
    void dodaj(Figura* figura) {
        figury.push_back(figura);
    }
    void pokaz_figury() {
        for (auto f : figury) {
            f->wypisz();
            cout << "Pole powierzchni: " << f->pole_pow() << endl;
            cout << "Obwod: " << f->obwod() << "\n\n";
        }
    }
    ~MagazynFigur() {
        for (auto f : figury)
            delete f;
    }
};

int main() {
    MagazynFigur magazyn;
    int wybor;

    do {
        cout << "\nWybierz figurę:\n1. Koło\n2. Prostokąt\n3. Trójkąt\n4. Pokaż figury i zakończ\nTwój wybór: ";
        cin >> wybor;

        if (wybor == 1) {
            float r;
            cout << "Podaj promień: ";
            cin >> r;
            magazyn.dodaj(new Kolo(r));
        } else if (wybor == 2) {
            float a, b;
            cout << "Podaj bok a: ";
            cin >> a;
            cout << "Podaj bok b: ";
            cin >> b;
            magazyn.dodaj(new Prostokat(a, b));
        } else if (wybor == 3) {
            float a, b, c;
            cout << "Podaj bok a: ";
            cin >> a;
            cout << "Podaj bok b: ";
            cin >> b;
            cout << "Podaj bok c: ";
            cin >> c;
            if (a + b > c && a + c > b && b + c > a)
                magazyn.dodaj(new Trojkat(a, b, c));
            else
                cout << "Z tych boków nie da się zbudować trójkąta!\n";
        } else if (wybor == 4) {
            cout << "\nFigury w magazynie:\n";
            magazyn.pokaz_figury();
        } else {
            cout << "Niepoprawny wybór!\n";
        }
    } while (wybor != 4);

    return 0;
}
