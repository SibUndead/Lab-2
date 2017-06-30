#include "Header.h"
#include <windows.h>
#include <conio.h>

#define ENTER 13
#define UP 72
#define DOWN 80
#define STAFF -32

#define MENU_SZ 16

void gotoxy(int x, int y) //������� ��������� �������
{
	HANDLE hs;
	COORD c = { x , y };

	hs = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hs, c);
}

void settextAtr(WORD atribute)	//������� ��������� ��������� ������
{
	HANDLE hs;
	hs = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hs, atribute);
}

void menuprint(int pos)	//������� ����
{
	gotoxy(1, 0);
	cout << "(*) - ��������, ��� ������� ��������� ����� �����������" << endl;
	
	char menu_items[MENU_SZ][45] = { "������ �����", "��������� �����", "������� � ������ ������ (� �����������)", "�������� �� ������ �����",
		"��������� �� ������ �����", "������� ����� �� �����", "������� �� ����� �������� �����", "��������� �������� ����� �� 1(*)", "��������� �������� ����� �� 1(*)", 
		"��������(*)","�������� �� �������� ������(*)", "��������� ������(*)", "����������� ����� (*)", "���� �����(*)", 
		"������� �������� ��������� � �����������(*)", "������� �������� �����(*)"};
	for (int i = 0; i < MENU_SZ; i++)
	{
		gotoxy(2, 1 + i);

		if (pos == i)
		{
			settextAtr(BACKGROUND_RED | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
		}
		else
		{
			settextAtr(FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
		}
		cout << menu_items[i];
	}
	settextAtr(FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
}

void menu(Drob *Elem)
{
	char ch;
	int pos = 0;
	while (true)
	{
		menuprint(pos);	//��������� ����
		ch = _getch();
		if (STAFF == ch)
		{
			ch = _getch();
		}
		switch (ch)
		{

		case DOWN:	pos = (pos + 1) % MENU_SZ;				break;	//����
		case UP:	pos = (MENU_SZ + pos - 1) % MENU_SZ;	break;	//�����
		case ENTER:													//��� ������� Enter:
			switch (pos)
			{
			case 0:
			{
				system("cls");
				gotoxy(2, 19);
				int C, Z;
				cout << "������� ��������� �����: ";
				cin >> C;
				cout << "������� ����������� �����: ";
				cin >> Z;
				if (Z == 0)
					cout << "����������� �� ����� ���� ����� ����. ������ �� 1" << endl;
				Elem = new Drob(C, Z);
				break;
			}
			case 1:
			{
				system("cls");
				Elem->Sokr();
				gotoxy(2, 19);
				cout << "���������� ����� ���������: ";
				Elem->Print();
				break;
			}
			case 2:
			{
				system("cls");
				int C, Z;
				gotoxy(2, 19);
				cout << "������� ��������� ������� ����������: ";
				cin >> C;
				cout << "������� ����������� ������� ����������: ";
				cin >> Z;
				if (Z == 0)
					cout << "����������� �� ����� ���� ����� ����. ������ �� 1" << endl;
				Drob a(C, Z);
				*Elem = Elem->Slogenie(a);
				Elem->Sokr();
				break;
			}
			case 3:
			{
				system("cls");
				int C, Z;
				gotoxy(2, 19);
				cout << "������� ��������� ����� ������� ���������: ";
				cin >> C;
				cout << "������� ����������� ����� ������� ���������: ";
				cin >> Z;
				if (Z == 0)
					cout << "����������� �� ����� ���� ����� ����. ������ �� 1" << endl;
				Drob a(C, Z);
				*Elem = Elem->Umnogenie(a);
				break;
			}
			case 4:
			{
				system("cls");
				int C, Z;
				gotoxy(2, 19);
				cout << "������� ��������� ��������: ";
				cin >> C;
				cout << "������� ����������� ��������: ";
				cin >> Z;
				if (Z == 0)
					cout << "����������� �� ����� ���� ����� ����. ������ �� 1" << endl;
				Drob a(C, Z);
				*Elem = Elem->Delenie(a);
				break;
			}
			case 5:
			{
				system("cls");
				gotoxy(2, 19);
				Elem->Print();
				break;
			}
			case 6:
			{
				system("cls");
				gotoxy(2, 19);
				cout << "�������� �����: " << Elem->value() << endl;
				break;
			}
			case 7:
			{
				system("cls");
				++*Elem;
				gotoxy(2, 19);
				cout << *Elem;
				break;
			}
			case 8:
			{
				system("cls");
				Drob a = (*Elem)--;
				*Elem = a;
				gotoxy(2, 19);
				cout << a;
				break;
			}
			case 9:
			{
				system("cls");
				int C, Z;
				gotoxy(2, 19);
				cout << "������� ��������� �����, � ������� ����� ��������� ��������: ";
				cin >> C;
				cout << "������� ����������� �����, � ������� ����� ��������� ��������: ";
				cin >> Z;
				if (Z == 0)
					cout << "����������� �� ����� ���� ����� ����. ������ �� 1" << endl;
				Drob a(C, Z);
				Drob c = *(Elem) + a;
				c.Sokr();
				*Elem = c;
				cout << c;
				break;
			}
			case 10:
			{
				system("cls");
				int C, Z;
				gotoxy(2, 19);
				cout << "������� ��������� �����, � ������� ����� ��������� ���������: ";
				cin >> C;
				cout << "������� ����������� �����, � ������� ����� ��������� ���������: ";
				cin >> Z;
				if (Z == 0)
					cout << "����������� �� ����� ���� ����� ����. ������ �� 1" << endl;
				Drob a(C, Z);
				if (*Elem == a)
					cout << "����� �����" << endl;
				else
					cout << "����� �� �����" << endl;
				break;
			}
			case 11:
			{
				system("cls");
				int C, Z;
				gotoxy(2, 19);
				cout << "������� ��������� �����, � ������� ����� ��������� ���������: ";
				cin >> C;
				cout << "������� ����������� �����, � ������� ����� ��������� ���������: ";
				cin >> Z;
				if (Z == 0)
					cout << "����������� �� ����� ���� ����� ����. ������ �� 1" << endl;
				Drob a(C, Z);
				if (*Elem > a)
					cout << "����� 1 ������, ��� ����� 2" << endl;
				else
					cout << "����� 1 ������, ��� �����2 ��� ��� �����" << endl;
				break;
			}
			case 12:
			{
				system("cls");
				int C, Z;
				gotoxy(2, 19);
				cout << "������� ��������� ����� 2: ";
				cin >> C;
				cout << "������� ����������� ����� 2: ";
				cin >> Z;
				if (Z == 0)
					cout << "����������� �� ����� ���� ����� ����. ������ �� 1" << endl;
				Drob a(C, Z);
				cout << "����������� � ����� 1." << endl;
				*Elem = a;
				cout << *Elem;
				break;
			}
			case 13:
			{
				system("cls");
				gotoxy(2, 19);
				cout << "������� ��������� � ����������� �����:" << endl;
				cin >> *Elem;
				break;
			}
			case 14:
			{
				system("cls");
				gotoxy(2, 19);
				cout << *Elem;
				break;
			}
			case 15:
			{
				system("cls");
				gotoxy(2, 19);
				cout << (double) *Elem;
				break;
			}
			}
		}
	}
}

void main()
{
	setlocale(LC_ALL, "Rus");
	Drob *Elem = new Drob;
	menu(Elem);
	delete[] Elem;
}