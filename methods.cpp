#include "Header.h"

Drob::Drob()
{
	Chisl = 0;
	Znam = 1;
}

Drob::Drob(int C, int Z)
{
	Chisl = C;
	if (Z == 0)
	{
		Znam = 1;
	}
	else
	{
		Znam = Z;
	}
}

Drob::Drob(const Drob &a)
{
	Chisl = a.Chisl;
	Znam = a.Znam;
}

Drob::~Drob()
{
}

void Drob::Sokr()
{
	int p = 0;
	int m = Chisl;
	int n = Znam;
	if (n > m)
	{
		p = m;
		m = n;
		n = p;
	}
	while (n != 0)
	{
		p = m%n;
		m = n;
		n = p;
	}

	Chisl /= m;
	Znam /= m;
}

double Drob::value()
{
	return (double)Chisl / Znam;
}

Drob Drob::Umnogenie(const Drob &Drob2) const
{
	Drob res = *this;
	res.Chisl *= Drob2.Chisl;
	res.Znam *= Drob2.Znam;
	return res;
}

Drob Drob::Delenie(const Drob &Drob2) const
{
	Drob res = *this;
	res.Chisl *= Drob2.Znam;
	res.Znam *= Drob2.Chisl;
	return res;
}

Drob Drob::Slogenie(const Drob &Drob2) const
{
	Drob res = *this;
	res.Chisl = res.Chisl * Drob2.Znam + Drob2.Chisl * res.Znam;
	res.Znam *= Drob2.Znam;
	return res;
}

Drob Drob::operator++() 
{
	Chisl+=Znam;
	return *this;
}

Drob Drob::operator--(int)
{
	Drob res =*this;
	res.Chisl -= res.Znam;
	return res;
}

Drob Drob::operator+(Drob &Drob2)
{
	Drob res;
	res.Chisl = Chisl * Drob2.Znam + Drob2.Chisl * Znam;
	res.Znam = Znam * Drob2.Znam;
	return res;
}

bool Drob::operator==(Drob &Drob2)
{
	if ((double)Chisl/Znam == (double)Drob2.Chisl/Drob2.Znam)
		return true;
	else
		return false;
}

bool Drob::operator>(Drob &Drob2)
{
	if ((double)Chisl / Znam > (double)Drob2.Chisl / Drob2.Znam)
		return true;
	else
		return false;
}

Drob &Drob::operator=(Drob &Drob2)
{
	if (*this == Drob2)
		return *this;
	Chisl = Drob2.Chisl;
	Znam = Drob2.Znam;
	return *this;
}

ostream& operator << (ostream&out, Drob&Drob2)
{
	out << Drob2.Chisl << "/" << Drob2.Znam << endl;
	return out;
}

istream& operator >> (istream&in, Drob&Drob2)
{
	in >> Drob2.Chisl;
	in >> Drob2.Znam;
	return in;
}

Drob::operator double()
{
	return (double)Chisl / Znam;
}

void Drob::Print()
{
	cout << Chisl << "/" << Znam << endl;
}