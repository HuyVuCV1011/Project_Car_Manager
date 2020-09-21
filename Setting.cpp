#include "Setting.h"

bool Date::isValid() {
	if (Day < 1 || Day > 31 || Month < 1 || Month > 12 || Year < 1950)
		return false;
	if (Month == 2 && Year % 400 == 0 && Day > 29)
		return false;
	if (Month == 2 && Year % 400 != 0 && Day > 28)
		return false;
	if ((Month == 4 || Month == 6 || Month == 9 || Month == 11) && Day > 30)
		return false;
	return true;
}

void Date::display() {
	cout << setfill('0') << setw(2) << Day << "/";
	cout << setfill('0') << setw(2) << Month << "/";
	cout << setfill('0') << setw(4) << Year;
}

void noticeTryAgain(int x, int y) {
	gotoxy(x, y + 1); cout << "Input is not valid. Press to try again!";
	system("pause>nul");
	gotoxy(x, y + 1); cout << "                                       ";
}

void noticeDone(int x, int y) {
	gotoxy(x, y + 2); cout << "                                                  ";
	gotoxy(x, y + 2); cout << "Done. Press to back!";
	system("pause>nul");
}

void noticeStart(int x, int y)
{
	gotoxy(x, y + 2); cout << "                                                  ";
	gotoxy(x, y + 2); cout << "PRESS TO START";
	system("pause>nul");
}

void noticeEnd(int x, int y)
{
	gotoxy(x, y + 2); cout << "                                                  ";
	gotoxy(x, y + 2); cout << "DO YOU SURE YOU WANT TO EXIT";
	system("pause>nul");
}

int random(int min, int max)
{
	return min + rand() % (max + 1 - min);
}

