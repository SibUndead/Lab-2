#include <iostream>

using namespace std;
class Drob
{
	int Chisl;
	int Znam;
public:
	Drob();
	Drob(int C, int Z);
	Drob(const Drob &a);
	~Drob();
	void Sokr();
	double value();
	Drob Slogenie(const Drob &Drob2) const;
	Drob Umnogenie(const Drob &Drob2) const;
	Drob Delenie(const Drob &Drob2) const;
	void Print();
	Drob operator++(); //Префиксный инкремент
	Drob operator--(int); //Постфиксный декремент
	Drob operator +(Drob &Drob2);
	bool operator== (Drob &Drob2);
	bool operator> (Drob &Drob2);
	Drob &operator=(Drob &Drob2);
	friend ostream& operator <<(ostream&out, Drob &Drob2);
	friend istream& operator >>(istream&in, Drob &Drob2);
	operator double();
};