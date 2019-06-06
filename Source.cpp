#include <iostream>
#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include <stdlib.h>
#include <vector>
#include <time.h>

#define ESC 27
#define FILAS 25
#define COLUMNAS 80
using namespace std;
using namespace System;

struct Pez {

	bool direccion;
	int *x = new int[2];
	int y;
	bool tiburon;


	Pez(bool direccion, int *x, int y, bool tiburon) {
		this->direccion = direccion;
		this->x = x;
		this->y = y;
		this->tiburon = tiburon;

	}

	void Imprimir() {

		Console::BackgroundColor = ConsoleColor::DarkBlue;
		Console::ForegroundColor = ConsoleColor::White;

		if (direccion) {

			Console::SetCursorPosition(x[0], y);
			cout << char(175);
			Console::SetCursorPosition(x[1], y);
			cout << char(254);

		}
		else {

			Console::SetCursorPosition(x[0], y);
			cout << char(254);
			Console::SetCursorPosition(x[1], y);
			cout << char(174);


		}
		if (tiburon) {
			Tiburon();
		}

		
	}

	void Tiburon() {

		Console::BackgroundColor = ConsoleColor::DarkBlue;
		Console::ForegroundColor = ConsoleColor::Black;

		if (direccion) {

			Console::SetCursorPosition(x[0], y);
			cout << char(175);
			Console::SetCursorPosition(x[1], y);
			cout << char(254);

		}
		else {

			Console::SetCursorPosition(x[0], y);
			cout << char(254);
			Console::SetCursorPosition(x[1], y);
			cout << char(174);
		}
	}

	void BorrarPez() {

		Console::ForegroundColor = ConsoleColor::DarkBlue;

		if (direccion) {

			Console::SetCursorPosition(x[0] - 2, y);
			cout << char(219);

		}
		else {

			Console::SetCursorPosition(x[1] + 2, y);
			cout << char(219);

		}
	}
	void BorrarLim() {
		if (direccion) {
			Console::ForegroundColor = ConsoleColor::DarkBlue;
			Console::SetCursorPosition(x[0] - 1, y);
			cout << char(219);

			Console::SetCursorPosition(x[0] - 2, y);
			cout << char(219);
		}
		else {
			Console::ForegroundColor = ConsoleColor::DarkBlue;
			Console::SetCursorPosition(x[1] + 2, y);
			cout << char(219);

			Console::SetCursorPosition(x[1] + 1, y);
			cout << char(219);


		}
	}

	void Movimiento() {

		if (direccion) {
			x[0]++;
			x[1]++;
		}
		else {
			x[0]--;
			x[1]--;

		}

	}
	void Direc() {
		if (direccion && x[1] + 1 >= 70) {
			BorrarLim();
			direccion = false;
		}
		else if (!direccion && x[0] - 1 <= 10) {
			BorrarLim();
			direccion = true;
		}

	}

};


struct Mapa {
	int matrix[25][80] = {
		{ 2,5,5,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2 },
		{ 2,6,6,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2 },
		{ 2,5,5,5,6,4,4,4,4,4,4,4,4,4,4,4,4,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2 },
		{ 5,5,5,2,2,5,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2 },
		{ 5,5,5,2,5,2,5,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2 },
		{ 2,5,5,5,2,2,5,5,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2 },
		{ 1,1,1,1,1,1,1,1,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3 },
		{ 1,1,1,3,3,1,1,1,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3 },
		{ 1,1,1,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 1,1,1,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 1,1,1,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 1,1,1,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 1,1,1,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 1,1,1,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 1,1,1,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 1,1,1,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 1,1,1,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 1,1,1,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 1,1,1,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 1,1,1,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 1,1,1,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 1,1,1,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 1,1,1,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 1,1,1,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 1,1,1,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	};

	Mapa() {}
	void Impresion() {
		Console::Clear;
		for (int i = 0; i < FILAS; i++) {
			for (int j = 0; j < COLUMNAS; j++) {
				Console::SetCursorPosition(j, i);
				if (matrix[i][j] == 0) {
					Console::ForegroundColor = ConsoleColor::DarkBlue;
					cout << char(219);
				}
				if (matrix[i][j] == 1) {
					Console::ForegroundColor = ConsoleColor::Black;
					cout << char(219);
				}
				if (matrix[i][j] == 2) {
					Console::ForegroundColor = ConsoleColor::Cyan;
					cout << char(219);
				}
				if (matrix[i][j] == 3) {
					Console::ForegroundColor = ConsoleColor::Blue;
					cout << char(219);
				}
				if (matrix[i][j] == 4) {
					Console::ForegroundColor = ConsoleColor::DarkGray;
					cout << char(219);
				}
				if (matrix[i][j] == 5) {
					Console::ForegroundColor = ConsoleColor::DarkRed;
					cout << char(219);
				}
				if (matrix[i][j] == 6) {
					Console::ForegroundColor = ConsoleColor::DarkMagenta;
					cout << char(219);
				}
			}
		}
	}
};


void CursorInvisible(bool bandera)
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO     cursorInfo;

	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = bandera;
	SetConsoleCursorInfo(out, &cursorInfo);
}



int main() {
	Console::SetWindowSize(80, 25);
	Console::SetBufferSize(80, 26);
	int peces = 6;
	int *x;
	int y;
	bool dir;
	bool tiburon;
	bool impreso = false;

	CursorInvisible(false);

	srand(time(NULL));

	vector<Pez*>pez = vector<Pez*>();
	Mapa* mapas = new Mapa();

	for (int i = 0; i < peces; i++) {
		x = new int[2];
		x[0] = 15 + rand() % 59;
		x[1] = x[0] + 1;
		y = 10 + rand() % 10;

		pez.push_back(new Pez(bool(rand() % 2), x, y, false));
		_sleep(100);

	}
	for (int i = 5; i < peces; i++) {
		x = new int[2];
		x[0] = 15 + rand() % 59;
		x[1] = x[0] + 1;
		y = 10 + rand() % 2;

		pez.push_back(new Pez(bool(rand() % 2), x, y, true));
		_sleep(100);

	}

	while (true) {
		if (!impreso) {
			mapas->Impresion();
			impreso = true;

		}

		for (int i = 0; i < pez.size(); i++) {
			pez.at(i)->Imprimir();
			pez.at(i)->Movimiento();
			pez.at(i)->Direc();
			pez.at(i)->BorrarPez();
			_sleep(50);
		}
	}

	_getch();
	return 0;
}