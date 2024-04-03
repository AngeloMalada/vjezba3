#include <iostream>
#include <vector>
#include <algorithm>
#include <string> 
#include <cstring>

using namespace std;

class Stan {
public:
	string vlasnik;
	int velicina;
	int brojSoba;
	Stan(string _vlasnik, int _velicina, int _brojSoba) : vlasnik(_vlasnik), velicina(_velicina), brojSoba(_brojSoba) {
		cout << "Stan constructor called\n";
	}
	~Stan() {
		cout << "Stan destructor called\n";
	}


};

class Zgrada {
private:
	string naziv;
	int brojKatova;
	string adresa;
	vector<Stan> stan;
public:
	Zgrada(string _naziv, int _brojKatova, string _adresa) : brojKatova(_brojKatova), adresa(_adresa) {
		if (_naziv.length() > 4) {
			naziv = _naziv;
		}
		else
			cout << "Premalo slova u nazivu firme";
	}

	Stan nadjiStan1(string _vlasnik) {
		int brojStana;
		for (int i = 0; i < stan.size(); i++) {
			if (stan[i].vlasnik == _vlasnik) {
				brojStana = i;
				break;
			}
		}
		cout << "Izmijeniti ime vlasnika\n";
		cin >> stan[brojStana].vlasnik;

		cout << "Izmijeniti broj soba\n";
		cin >> stan[brojStana].brojSoba;

		cout << "Izmijeniti velicinu\n";
		cin >> stan[brojStana].velicina;

		return stan[brojStana];
	}
	Stan* nadjiStan2(string _vlasnik) {
		int brojStana;
		for (int i = 0; i < stan.size(); i++) {
			if (stan[i].vlasnik == _vlasnik) {
				brojStana = i;
				break;
			}
		}
		cout << "Izmijeniti ime vlasnika\n";
		cin >> stan[brojStana].vlasnik;

		cout << "Izmijeniti broj soba\n";
		cin >> stan[brojStana].brojSoba;

		cout << "Izmijeniti velicinu\n";
		cin >> stan[brojStana].velicina;

		return &stan[brojStana];
	}
	Stan& nadjiStan3(string _vlasnik) {
		int brojStana;
		for (int i = 0; i < stan.size(); i++) {
			if (stan[i].vlasnik == _vlasnik) {
				brojStana = i;
				break;
			}
		}
		cout << "Izmijeniti ime vlasnika\n";
		cin >> stan[brojStana].vlasnik;

		cout << "Izmijeniti broj soba\n";
		cin >> stan[brojStana].brojSoba;

		cout << "Izmijeniti velicinu\n";
		cin >> stan[brojStana].velicina;

		return stan[brojStana];
	}


	Zgrada& dodajStan1(Stan z) {
		stan.push_back(z);
		return *this;
	}
	Zgrada& dodajStan2(Stan& z) {
		stan.push_back(z);
		return *this;
	}
	Zgrada& dodajStan3(Stan* z) {
		stan.push_back(*z);
		return *this;
	}
	void setNaziv(string _naziv) {

	}
	string getNaziv() const {
		return naziv;
	}
	void setBrojKatova(int _brojKatova) {
		if (_brojKatova > 0)
			brojKatova = _brojKatova;
		else
			cout << "Broj katova ne moze biti 0";
	}
	int getBrojKatova() const {
		return brojKatova;
	}
	void IspisSvihStanova() {
		for (int i = 0; i < stan.size(); i++) {
			cout << stan[i].vlasnik << " " << stan[i].velicina << "m2 \n";
		}
	}
};


int main() {
	Zgrada z1("FIRMA", 5, "Lopatinecka 19");
	Stan s1("Luka", 50, 2);
	Stan s2("Tomo", 60, 3);
	Stan s3("Joso", 45, 1);
	Stan s4("Pero", 80, 3);

	Stan* ps1 = &s1;
	z1.dodajStan2(s1).dodajStan2(s2).dodajStan2(s3).dodajStan2(s4);

	z1.nadjiStan1("Luka");


	z1.IspisSvihStanova();






}