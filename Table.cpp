#include "Table.h"


//------------------------------------Hàm tô màu chữ---------------------------------------------------------
void textcolor(int x)
{
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau, x);
}
//--------------------------------Hàm di chuyển đến vị trí x,y--------------------------------------------------------------
void gotoxy(short x, short y)
{
	HANDLE hConsoleOutput;
	COORD Cursor_an_Pos = { x, y };
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}
//-------------------------Screen-------------------------
void clrscr()
{
	CONSOLE_SCREEN_BUFFER_INFO	csbiInfo;
	HANDLE	hConsoleOut;
	COORD	Home = { 0,0 };
	DWORD	dummy;

	hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(hConsoleOut, &csbiInfo);

	FillConsoleOutputCharacter(hConsoleOut, ' ', csbiInfo.dwSize.X * csbiInfo.dwSize.Y, Home, &dummy);
	csbiInfo.dwCursorPosition.X = 0;
	csbiInfo.dwCursorPosition.Y = 0;
	SetConsoleCursorPosition(hConsoleOut, csbiInfo.dwCursorPosition);
}


//screen: goto [x,y]
void gotoXY(int column, int line)
{
	COORD coord;
	coord.X = column;
	coord.Y = line;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


//screen: get [x]
int whereX()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
		return csbi.dwCursorPosition.X;
	return -1;
}


//screen: get [y]
int whereY()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
		return csbi.dwCursorPosition.Y;
	return -1;
}


void TextColor(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}

//draw table
void displayData(int w, string s1, string s2)
{
	int q = w * 2 + 5;


	gotoXY(3, q);
	cout << w+1;

	gotoXY(24, q);
	cout << s1;

	gotoXY(43, q);
	cout << s2;
}

void ReadData()
{
	ifstream fin;
	fin.open("Stock.txt");
	int i = 0;

	while (!fin.eof())
	{
		string s1;
		string s2;
		getline(fin, s1, ',');
		getline(fin, s2, ',');
		if (fin.eof()) break;
		displayData(i, s1, s2);
		string ss;
		getline(fin, ss);
		i++;
	}
	cout << endl << endl;
	fin.close();
}

int CountLine()
{
	int tmp = 0;
	ifstream fin;
	fin.open("Stock.txt");
	while (!fin.eof())
	{
		string s;
		getline(fin, s);
		tmp++;
	}
	fin.close();
	return tmp;
}
