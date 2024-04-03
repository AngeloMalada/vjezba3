#include "Matrica.h"
#include <iostream>

using namespace std;


void Matrica::dodaj(int brStupaca, int* _redak)
{
	redak.push_back(_redak);
	stupac.push_back(brStupaca);
}

Matrica::Matrica(const Matrica& m)
{
	for (int i = 0; i < m.redak.size(); i++)
	{
		redak.push_back(new int[m.stupac[i]]);
		stupac.push_back(m.stupac[i]);

		for (int j = 0; j < stupac[i]; j++)
		{
			redak[i][j] = m.redak[i][j];
		}
	}
}

Matrica& Matrica::operator=(const Matrica& m)
{
	if (this != &m) {
		for (int i = 0; i < redak.size(); i++)
		{
			delete[] redak[i];
		}
		redak.clear();
		stupac.clear();

		for (int i = 0; i < m.redak.size(); i++)
		{
			redak.push_back(new int[m.stupac[i]]);
			stupac.push_back(m.stupac[i]);

			for (int j = 0; j < stupac[i]; j++)
			{
				redak[i][j] = m.redak[i][j];
			}
		}
	}
	return *this;
}

Matrica::Matrica(Matrica&& m)
{
	for (int i = 0; i < m.redak.size(); i++)	{
	redak.push_back(m.redak[i]);
	m.redak[i] = NULL;
	stupac.push_back(m.stupac[i]);
	}
}

void Matrica::ispis()
{
	for (int i = 0; i < redak.size(); i++)
	{
		for (int j = 0; j < stupac[i]; j++)
		{
			cout << redak[i][j] << " ";
		}
		cout << endl;
	}
}

Matrica::~Matrica()
{
	for (int i = 0; i < redak.size(); i++)
	{
		delete[] redak[i];
	}	

}
