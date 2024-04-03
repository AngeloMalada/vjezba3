#include <iostream>
#include <vector>
#include <string>


using namespace std;


//klasa cvijet
class Cvijet {
public:
	string vrsta;
	string boja;
	int kolicina;



	Cvijet(string v, string b, int k) : vrsta(v), boja(b), kolicina(k) {
		cout << "Cvijet constructor called" << endl;
	}



	~Cvijet() {
		cout << "Cvijet destructor called " << vrsta << endl;
	}
};

//klasa vrt
class Vrt {
private:
	string adresa;
	string vlasnik;
	double sirina;
	double duljina;
	vector<Cvijet> cvjetovi;

public:
	Vrt(string adr, string vlas, double sir, double dul) : adresa(adr), sirina(sir), duljina(dul) {
		//provjere pravila u konstruktoru
		//provjera površine
		if (sir * dul < 10) {
			cout << "Povrsina vrta mora biti veca od 10m^2" << endl;
		}
		//provjera pocinje li vlasnik velikim slovom
		//funkcija isupper provjerava je li slovo uppercase
		if (!isupper(vlas[0])) {
			cout << "Vlasnik mora poceti velikim slovom." << endl;
		}
		vlasnik = vlas;
	}
	//push back dodaje na kraj vektora
	void dodajCvijet1(Cvijet z) {
		cvjetovi.push_back(z);
		cout << "metoda 1 gotova" << endl;
	}

	void dodajCvijet2(Cvijet& z) {
		cvjetovi.push_back(z);
		cout << "metoda 1 gotova" << endl;
	}

	void dodajCvijet3(Cvijet* z) {
		cvjetovi.push_back(*z);
		cout << "metoda 1 gotova" << endl;
	}

	void ispisSvihCvijetova() {
		//const auto& cvijet : cvjetovi pojednostavljena sintaksa za prolazak kroz sve clanove 
		for (const auto& cvijet : cvjetovi) {
			cout << cvijet.vrsta << " " << cvijet.boja << " " << cvijet.kolicina << endl;
		}
	}

	Cvijet nadjiCvijet1(string vrsta) {
		for (int i = 0; i < cvjetovi.size(); i++) {
			if (cvjetovi[i].vrsta == vrsta) {
				return cvjetovi[i];
			}
		}

		return Cvijet("nepostoji", "nepostoji", 0);


	}

	Cvijet* nadjiCvijet2(string vrsta) {
		for (int i = 0; i < cvjetovi.size(); i++) {
			if (cvjetovi[i].vrsta == vrsta) {
				return &cvjetovi[i];
			}
		}

		return nullptr;
	}

	Cvijet& nadjiCvijet3(string vrsta) {
		for (int i = 0; i < cvjetovi.size(); i++) {
			if (cvjetovi[i].vrsta == vrsta) {
				return cvjetovi[i];
			}


		}
		static Cvijet nepostojeci("nepostoji", "nepostoji", 0);
		return nepostojeci;

	}
	~Vrt() {
		cout << "Vrt je unisten" << endl;
	}
};

int main() {

	Vrt vrt("Adresa", "Vlasnik", 10, 10);
	Cvijet cvijet1("ruza", "zelena", 5);
	Cvijet cvijet2("ljiljan", "zuta", 3);
	Cvijet cvijet3("macuhica", "bijela", 18);

	vrt.dodajCvijet1(cvijet1);
	vrt.dodajCvijet2(cvijet2);
	vrt.dodajCvijet3(&cvijet3);


	vrt.nadjiCvijet1("ruza").boja = "narancasta";
	vrt.nadjiCvijet2("ljiljan")->boja = "narancasta";
	vrt.nadjiCvijet3("macuhica").boja = "narancasta";

	//primjecujemo da ukoliko ne vracamo referencu ili pointer, dobijemo kopiju izvordnog cvijeta iz vektora cvjetovi pa kada promjenimo boju u ispisu svih cvjetova necemo vidjeti promjenu

	vrt.ispisSvihCvijetova();

	return 0;
}
