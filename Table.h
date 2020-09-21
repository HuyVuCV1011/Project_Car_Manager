#pragma once
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <Windows.h>
#include <fstream>
#include <algorithm>
#include <iomanip>

using namespace std;

#define WIDTH_OFFSET 211 / 2
#define HEIGHT_OFFSET 53 / 2

#define ColorCode_Back			0
#define ColorCode_DarkBlue		1
#define ColorCode_DarkGreen		2
#define ColorCode_DarkCyan		3
#define ColorCode_DarkRed		4
#define ColorCode_DarkPink		5
#define ColorCode_DarkYellow	6
#define ColorCode_DarkWhite		7
#define ColorCode_Grey			8
#define ColorCode_Blue			9
#define ColorCode_Green			10
#define ColorCode_Cyan			11
#define ColorCode_Red			12
#define ColorCode_Pink			13
#define ColorCode_Yellow		14
#define ColorCode_White			15
#define ColorCode_BackgroundOrange		30

#define default_ColorCode		7


#define KEY_UP 72

#define KEY_DOWN 80

#define KEY_LEFT 75

#define KEY_RIGHT 77

#define KEY_ENTER 13

#define KEY_SPACE 32

#define KEY_ESC 27
#define key_none -1
//--------------------------------------------------------
#pragma once
#include <windows.h>
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<iostream>
#include<Windows.h>
#include<fstream>
#include <ctype.h> 
#include<stdlib.h>
#include <string>
using namespace std;
//--------------------------------------------------------

int inputKey();

//-------------------------Screen-------------------------
void clrscr();

//screen: goto [x,y]
void gotoXY(int column, int line);

//screen: get [x]
int whereX();

//screen: get [y]
int whereY();

void TextColor(int color);
//end----------------------Screen----------------------end
void resizeConsole(int width, int height);

//
void gotoxy(short x, short y);

//
void displayData(int w, string s1, string s2);

void ReadData();

int CountLine();

