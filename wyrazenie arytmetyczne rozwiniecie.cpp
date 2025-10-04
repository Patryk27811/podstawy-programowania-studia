#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

// Stała PI
const double PI = 3.141592653589793;

// Funkcje dla walca
double objWalca(double promien, double wysokosc) {
    return PI * pow(promien, 2) * wysokosc;
}

double poleWalca(double promien, double wysokosc) {
    return 2 * PI * promien * (promien + wysokosc);
}

// Funkcje dla kuli
double objKuli(double promien) {
    return (4.0 / 3.0) * PI * pow(promien, 3);
}

double poleKuli(double promien) {
    return 4 * PI * pow(promien, 2);
}

// Funkcje dla stożka
double objStozka(double promien, double wysokosc) {
    return (1.0 / 3.0) * PI * pow(promien, 2) * wysokosc;
}

double poleStozka(double promien, double wysokosc) {
    double l = sqrt(pow(promien, 2) + pow(wysokosc, 2)); // tworząca stożka
    return PI * promien * (promien + l);
}

int main() {
    int wybor;
    cout << "Wybierz bryłę, aby obliczyć jej objętość i pole powierzchni całkowitej:" << endl;
    cout << "1 - Walec" << endl;
    cout << "2 - Kula" << endl;
    cout << "3 - Stożek" << endl;
    cout << "Twój wybór: ";
    cin >> wybor;

    switch (wybor) {
        case 1: { // Walec
            double promien, wysokosc;
            cout << "Podaj promień podstawy walca (musi być dodatni): ";
            cin >> promien;
            cout << "Podaj wysokość walca (musi być dodatnia): ";
            cin >> wysokosc;

            if (promien <= 0 || wysokosc <= 0) {
                cout << "Promień i wysokość muszą być większe od zera." << endl;
                return 1;
            }

            cout << fixed << setprecision(3);
            cout << "Objętość walca (V): " << objWalca(promien, wysokosc) << " m³" << endl;
            cout << "Pole powierzchni całkowitej walca (PC): " << poleWalca(promien, wysokosc) << " m²" << endl;
            break;
        }
        case 2: { // Kula
            double promien;
            cout << "Podaj promień kuli (musi być dodatni): ";
            cin >> promien;

            if (promien <= 0) {
                cout << "Promień musi być większy od zera." << endl;
                return 1;
            }

            cout << fixed << setprecision(3);
            cout << "Objętość kuli (V): " << objKuli(promien) << " m³" << endl;
            cout << "Pole powierzchni całkowitej kuli (PC): " << poleKuli(promien) << " m²" << endl;
            break;
        }
        case 3: { // Stożek
            double promien, wysokosc;
            cout << "Podaj promień podstawy stożka (musi być dodatni): ";
            cin >> promien;
            cout << "Podaj wysokość stożka (musi być dodatnia): ";
            cin >> wysokosc;

            if (promien <= 0 || wysokosc <= 0) {
                cout << "Promień i wysokość muszą być większe od zera." << endl;
                return 1;
            }

            cout << fixed << setprecision(3);
            cout << "Objętość stożka (V): " << objStozka(promien, wysokosc) << " m³" << endl;
            cout << "Pole powierzchni całkowitej stożka (PC): " << poleStozka(promien, wysokosc) << " m²" << endl;
            break;
        }
        default:
            cout << "Niepoprawny wybór. Spróbuj ponownie." << endl;
            break;
    }

    return 0;
}
