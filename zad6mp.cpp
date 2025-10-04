#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<exception>
using namespace std;

class Ksiazka {
	string tytul;
	string autor;
	float cena;
public:
	void wpisz() {
		cout << "\nPodaj informacje o ksiazce\n";
		cout << "Tytul: ";
		cin >> ws;
		getline(cin, tytul);
		cout << "Autor: ";
		getline(cin, autor);
		cout << "Cena: ";
		cin >> cena;
	}

	void pokaz() const {
		cout << "\n\"" << tytul << "\", " << autor << ", " << cena << " zl.";
	}

	float daj_cene() const {
		return cena;
	}

	string daj_tytul() const {
		return tytul;
	}

	friend ostream& operator<<(ostream& os, const Ksiazka& k) {
		os << k.tytul << '\n' << k.autor << '\n' << k.cena << '\n';
		return os;
	}

	friend istream& operator>>(istream& is, Ksiazka& k) {
		getline(is, k.tytul);
		getline(is, k.autor);
		is >> k.cena;
		is.ignore();
		return is;
	}
};

class Sklepik {
	vector<Ksiazka> ksiazki;
public:
	void dodaj() {
		string decyzja = "t";
		while (decyzja == "t") {
			Ksiazka nowa;
			nowa.wpisz();
			ksiazki.push_back(nowa);
			cout << "\nCzy chcesz dodac nowa ksiazke (t/n)? ";
			getline(cin >> ws, decyzja);
			while (decyzja != "t" && decyzja != "n") {
				cout << "Niepoprawna odpowiedz. Podaj 't' lub 'n': ";
				getline(cin >> ws, decyzja);
			}
		}
	}

	void pokaz() const {
		if (ksiazki.empty()) {
			cout << "Brak ksiazek w sklepie." << endl;
			return;
		}
		for (const auto& k : ksiazki) {
			k.pokaz();
		}
	}

	int ile() const {
		return ksiazki.size();
	}

	void wstaw_na_pozycje(int indeks) {
		if (indeks < 0 || indeks > ksiazki.size()) {
			cout << "Niepoprawny indeks!" << endl;
			return;
		}
		Ksiazka nowa;
		nowa.wpisz();
		ksiazki.insert(ksiazki.begin() + indeks, nowa);
		cout << "Ksiazka zostala dodana na pozycji " << indeks << ".\n";
	}

	void usun_z_pozycji(int indeks) {
		try {
			ksiazki.at(indeks);
			ksiazki.erase(ksiazki.begin() + indeks);
			cout << "Ksiazka zostala usunieta z pozycji " << indeks << ".\n";
		}
		catch (const out_of_range& e) {
			cout << "Blad: " << e.what() << endl;
		}
	}

	void filtruj_po_cenie(float cena_min) {
		cout << "\nKsiazki, ktore kosztuja powyzej " << cena_min << " zl:\n";
		for (const auto& k : ksiazki) {
			if (k.daj_cene() > cena_min) {
				k.pokaz();
			}
		}
	}

	void filtruj_po_tytule(const string& fragment_tytulu) {
		cout << "\nKsiazki, ktore zawieraja \"" << fragment_tytulu << "\" w tytule:\n";
		for (const auto& k : ksiazki) {
			if (k.daj_tytul().find(fragment_tytulu) != string::npos) {
				k.pokaz();
			}
		}
	}

	void zapisz_do_pliku(const string& nazwa_pliku) const {
		ofstream plik(nazwa_pliku);
		if (!plik) {
			cout << "Nie mozna otworzyc pliku do zapisu!\n";
			return;
		}
		for (const auto& k : ksiazki) {
			plik << k;
		}
		cout << "Zapisano dane do pliku \"" << nazwa_pliku << "\".\n";
	}

	void wczytaj_z_pliku(const string& nazwa_pliku) {
		ifstream plik(nazwa_pliku);
		if (!plik) {
			cout << "Nie mozna otworzyc pliku do odczytu!\n";
			return;
		}
		ksiazki.clear();
		while (!plik.eof()) {
			Ksiazka k;
			plik >> k;
			if (plik) {
				ksiazki.push_back(k);
			}
		}
		cout << "Wczytano dane z pliku \"" << nazwa_pliku << "\".\n";
	}
};

int main() {
	Sklepik sklepik;
	int wybor;
	do {
		cout << "\nWybierz operacje:";
		cout << "\n1. Dodaj ksiazki";
		cout << "\n2. Pokaz wszystkie ksiazki";
		cout << "\n3. Wstaw ksiazke na wskazana pozycje";
		cout << "\n4. Usun ksiazke ze wskazanej pozycji";
		cout << "\n5. Filtrowanie ksiazek po cenie";
		cout << "\n6. Filtrowanie ksiazek po tytule";
		cout << "\n7. Zapisz ksiazki do pliku";
		cout << "\n8. Wczytaj ksiazki z pliku";
		cout << "\n9. Zakoncz\n";
		cin >> wybor;

		switch (wybor) {
		case 1:
			sklepik.dodaj();
			break;
		case 2:
			sklepik.pokaz();
			break;
		case 3: {
			int indeks;
			cout << "Podaj indeks, na ktora pozycje wstawic ksiazke: ";
			cin >> indeks;
			sklepik.wstaw_na_pozycje(indeks);
			break;
		}
		case 4: {
			int indeks;
			cout << "Podaj indeks ksiazki do usuniecia: ";
			cin >> indeks;
			sklepik.usun_z_pozycji(indeks);
			break;
		}
		case 5: {
			float cena_min;
			cout << "Podaj minimalna cene do filtrowania: ";
			cin >> cena_min;
			sklepik.filtruj_po_cenie(cena_min);
			break;
		}
		case 6: {
			string tytul;
			cout << "Podaj czesc tytulu do filtrowania: ";
			cin >> ws;
			getline(cin, tytul);
			sklepik.filtruj_po_tytule(tytul);
			break;
		}
		case 7: {
			string nazwa;
			cout << "Podaj nazwe pliku do zapisu: ";
			cin >> ws;
			getline(cin, nazwa);
			sklepik.zapisz_do_pliku(nazwa);
			break;
		}
		case 8: {
			string nazwa;
			cout << "Podaj nazwe pliku do odczytu: ";
			cin >> ws;
			getline(cin, nazwa);
			sklepik.wczytaj_z_pliku(nazwa);
			break;
		}
		case 9:
			cout << "Zamykam program." << endl;
			break;
		default:
			cout << "Niepoprawny wybor, sproboj ponownie." << endl;
		}
	} while (wybor != 9);

	return 0;
}
