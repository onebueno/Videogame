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

struct Hilo {
	int x;
	int y;
	int iniciox;
	int inicioy;
	bool atrapar;
	char tecla;

	Hilo() {
		x = iniciox = 17;
		y = inicioy = 2;
		y = 15;
		atrapar = false;
		tecla = NULL;
	}

	void Impresion() {
		Console::ForegroundColor = ConsoleColor::Black;

		for (int i = y; i >= inicioy; --i) {
			Console::SetCursorPosition(iniciox, i);

			if (i <= 5)
				Console::BackgroundColor = ConsoleColor::Cyan;
			else if(i>5 && i <=7)
				Console::BackgroundColor = ConsoleColor::Blue;
			else
				Console::BackgroundColor = ConsoleColor::DarkBlue;

			if (i != y)
				cout << '|';
			else
				cout << '$';
		}
	}

	void Borrar() {
		Console::SetCursorPosition(iniciox, y);
		if (y <= 5)
			Console::ForegroundColor = ConsoleColor::Cyan;
		else if (y > 5 && y <= 7)
			Console::ForegroundColor = ConsoleColor::Blue;
		else
			Console::ForegroundColor = ConsoleColor::DarkBlue;

		cout << char(219);
	}

	void Movimiento() {
		if (_kbhit()) {
			tecla = _getch();
			tecla = toupper(tecla);

			if (tecla == 'W' && y > inicioy) {
				Borrar();
				y--;
				
			}
			if (tecla == 'S' && y < 20)
				y++;

			
		}
	}

};
struct Pez {

	bool direccion;//true derecha, false izquierda
	int* x = new int[2];
	int y;
	bool tiburon;
	bool atrapado;
	int xx;
	int yy;


	Pez(bool direccion, int* x, int y, bool tiburon, bool atrapado) {
		this->direccion = direccion;
		this->x = x;
		this->y = y;
		this->tiburon = tiburon;
		this->atrapado = false;
	}

	void Imprimir() {

		Console::BackgroundColor = ConsoleColor::DarkBlue;
		Console::ForegroundColor = ConsoleColor::White;

		if (direccion) {

			Console::SetCursorPosition(x[0], y);//añadir funciones
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

	void Cazado(Hilo* hilo) {
		for (int i = 0; i < 6; i++) {
			if (!atrapado) {
				if (int(x + xx) < 7 || int(x + 3) + xx > 68) {
					xx = -xx;
				}
				if ((y + yy) < 7 || y + yy > 32)
					yy = -yy;
				x += xx;
				y += yy;
			}
			else {
				if (direccion == true) {
					x[1] = hilo->x;
					y = hilo->y;
				}
				if (direccion == false) {
					x[0] = hilo->x;
					y = hilo->y;
				}

			}

		}
		for (int i = 0; i < 6; i++) {
			if (int(x + xx) < 7 || int(x + 3) + xx > 60) {
				xx = -xx;
			}
			if ((y + yy) < 7 || y + yy > 36)
				yy = -yy;
			x += xx;
			y += yy;
		}
	}




};


void Colision(Hilo* hilo, vector<Pez*> peces) {
	if (!hilo->atrapar) {
		for (int i = 0; i < peces.size(); i++) {
			if (peces.at(i)->direccion == true) {
				if (peces.at(i)->x[1] == hilo->x && peces.at(i)->y == hilo->y) {
					peces.at(i)->atrapado = true;
					hilo->atrapar = true;
					break;
				}
			}
			else if (peces.at(i)->direccion == false) {
				if (peces.at(i)->x[0] == hilo->x && peces.at(i)->y == hilo->y) {
					peces.at(i)->atrapado = true;
					hilo->atrapar = true;
					break;
				}
			}
		}
	}
}



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
	int* tib = new int;
	*tib = 6;
	int* x;
	int y;
	bool dir;
	bool tiburon;
	bool impreso = false;
	Hilo* hilo = new Hilo();
	Pez* fish = new Pez(bool(rand() % 2), x, y, false, false);

	CursorInvisible(false);

	srand(time(NULL));

	vector<Pez*>pez = vector<Pez*>();
	Mapa* mapas = new Mapa();
	


	for (int i = 0; i < peces; i++) {
		x = new int[2];
		x[0] = 15 + rand() % 59;
		x[1] = x[0] + 1;
		y = 10 + rand() % 10;

		pez.push_back(new Pez(bool(rand() % 2), x, y, false, false));
		_sleep(100);

	}
	for (int i = 5; i < peces; i++) {
		x = new int[2];
		x[0] = 15 + rand() % 59;
		x[1] = x[0] + 1;
		y = 8;

		pez.push_back(new Pez(bool(rand() % 2), x, y, true, false));
		_sleep(100);

	}

	while (true) {
		if (!impreso) {
			mapas->Impresion();
			impreso = true;

		}
		
		hilo->Movimiento();
		hilo->Impresion();
	//	hilo->Borrar();
		Colision(hilo, pez);
		fish->Cazado(hilo);

		for (int i = 0; i < pez.size(); i++) {
			pez.at(i)->Imprimir();
			pez.at(i)->Movimiento();
			pez.at(i)->Direc();
			pez.at(i)->BorrarPez();
			_sleep(10);
		}

	}

	_getch();
	return 0;
}
