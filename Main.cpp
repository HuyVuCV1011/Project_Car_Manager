#include "Menu.h"

int main()
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, 0);

	vector<Car> Stock;
	vector<Bill> bills;
	vector<BillRepair> rebills;
	
	SplashScreen();
	
	LoadArrayFromFile("Stock.txt", Stock);
	LoadBillFromFile("Num.txt", bills);
	LoadReBillFromFile("REPAIRBILL.txt", rebills);



	Login(Stock, bills, rebills);


	SaveArrayToFile("Stock.txt", Stock);
	SaveBillToFile("Num.txt", bills);
	SaveReBillToFile("REPAIRBILL.txt", rebills);

	return 0;
}