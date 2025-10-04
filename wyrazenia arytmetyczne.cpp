#include <iostream>
#include <iomanip>
#include <cmath>
//Patryk  D102
using namespace std;

int main() {
    int wybor;
    cout << "Wybierz operację: " << endl;
    cout << "1 - Konwersja temperatury (Celsjusz na Fahrenheit)" << endl;
    cout << "2 - Obliczenia dotyczące walca (objętość i pole powierzchni)" << endl;
    cout << "Twój wybór: ";
    cin >> wybor;

    switch (wybor) {
        case 1: {
            float c;
            cout << "Podaj temperaturę w stopniach Celsjusza: ";
            cin >> c;
            float f = (9.0 / 5.0) * c + 32;

            cout << fixed << setprecision(3);
            cout << "Temperatura w Fahrenheitach: " << f << "°F" << endl;
            break;
        }
        case 2: {
            const double PI = 3.141592653589793;
            double promien, wysokosc;

            cout << "Podaj promień podstawy walca (musi być dodatni): ";
            cin >> promien;

            cout << "Podaj wysokość walca (musi być dodatnia): ";
            cin >> wysokosc;

            if (promien <= 0 || wysokosc <= 0) {
                cout << "Promień i wysokość muszą być większe od zera." << endl;
                return 1;
            }

            double V = PI * pow(promien, 2) * wysokosc;
            double PP = PI * pow(promien, 2);
            double PB = 2 * PI * promien * wysokosc;
            double PC = 2 * PP + PB;

            cout << fixed << setprecision(3);
            cout << "Objętość walca (V): " << V << " m³" << endl;
            cout << "Pole powierzchni całkowitej walca (PC): " << PC << " m²" << endl;
            break;
        }
        default:
            cout << "Niepoprawny wybór. Spróbuj ponownie." << endl;
            break;
    }

    return 0;
}
