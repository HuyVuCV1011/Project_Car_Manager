#pragma once
#include "Table.h"

class Date {
private:
	int Day, Month, Year;
public:
	void setDate(int day, int month, int year) { Day = day; Month = month; Year = year; }
	int getDay() { return Day; }
	int getMonth() { return Month; }
	int getYear() { return Year; }
	bool isValid();
	void display();
};

void noticeTryAgain(int x, int y);

void noticeDone(int x, int y);

void noticeStart(int x, int y);

void noticeEnd(int x, int y);

int random(int, int);


