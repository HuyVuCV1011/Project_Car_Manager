#include "Menu.h"
#include "Table.h"

void SplashScreen() {
	int x, y;
	x = 50;
	y = 10;
	int i = 28;
	TextColor(14);
	gotoXY(x + i, y + 1); cout << ".----------------.  .----------------.  .----------------. ";
	gotoXY(x + i, y + 2); cout << "| .--------------. || .--------------. || .--------------. |";
	gotoXY(x + i, y + 3); cout << "| |     ______   | || |      __      | || |  _______     | |";
	gotoXY(x + i, y + 4); cout << "| |   .' ___  |  | || |     /  \\     | || | |_   __ \\    | |";
	gotoXY(x + i, y + 5); cout << "| |  / .'   \\_|  | || |    / /\\ \\    | || |   | |__) |   | |";
	gotoXY(x + i, y + 6); cout << "| |  | |         | || |   / ____ \\   | || |   |  __ /    | |";
	gotoXY(x + i, y + 7); cout << "| |  \\ `.___.'\\  | || | _/ /    \\ \\_ | || |  _| |  \\ \\_  | |";
	gotoXY(x + i, y + 8); cout << "| |   `._____.'  | || ||____|  |____|| || | |____| |___| | |";
	gotoXY(x + i, y + 9); cout << "| |              | || |              | || |              | |";
	gotoXY(x + i, y + 10); cout << "| '--------------' || '--------------' || '--------------' |";
	gotoXY(x + i, y + 11); cout << " '----------------'  '----------------'  '----------------' ";
	TextColor(9);
	gotoXY(x, y + 12); cout << " .----------------.  .----------------.  .----------------.  .----------------.  .----------------.  .----------------.";
	gotoXY(x, y + 13); cout << "| .--------------. || .--------------. || .--------------. || .--------------. || .--------------. || .--------------. |";
	gotoXY(x, y + 14); cout << "| |  ________    | || |  _________   | || |      __      | || |   _____      | || |  _________   | || |  _______     | |";
	gotoXY(x, y + 15); cout << "| | |_   ___ `.  | || | |_   ___  |  | || |     /  \\     | || |  |_   _|     | || | |_   ___  |  | || | |_   __ \\    | |";
	gotoXY(x, y + 16); cout << "| |   | |   `. \\ | || |   | |_  \\_|  | || |    / /\\ \\    | || |    | |       | || |   | |_  \\_|  | || |   | |__) |   | |";
	gotoXY(x, y + 17); cout << "| |   | |    | | | || |   |  _|  _   | || |   / ____ \\   | || |    | |   _   | || |   |  _|  _   | || |   |  __ /    | |";
	gotoXY(x, y + 18); cout << "| |  _| |___.' / | || |  _| |___/ |  | || | _/ /    \\ \\_ | || |   _| |__/ |  | || |  _| |___/ |  | || |  _| |  \\ \\_  | |";
	gotoXY(x, y + 19); cout << "| | |________.'  | || | |_________|  | || ||____|  |____|| || |  |________|  | || | |_________|  | || | |____| |___| | |";
	gotoXY(x, y + 20); cout << "| |              | || |              | || |              | || |              | || |              | || |              | |";
	gotoXY(x, y + 21); cout << "| '--------------' || '--------------' || '--------------' || '--------------' || '--------------' || '--------------' |";
	gotoXY(x, y + 22); cout << " '----------------'  '----------------'  '----------------'  '----------------'  '----------------'  '----------------' ";
	cout << endl;
	TextColor(7);
	noticeStart(98, 40);

}

void Login(vector<Car>& a, vector<Bill> &bills, vector<BillRepair>& rebills) {
	bool check = false;
	system("cls");
	TextColor(11);
	gotoxy(95, 16);
	cout << ">>> LOGIN <<<";
	TextColor(10);
	gotoxy(95, 20);
	cout << "1. CUSTOMER";
	gotoxy(95, 22);
	cout << "2. STAFF";
	gotoxy(95, 24);
	cout << "3. EXIT";
	TextColor(7);
	gotoxy(95, 28);
	cout << "YOUR CHOICE: ";
	int c;
	cin >> c;
	while (c < 1 || c > 3)
	{
		gotoxy(42, 15);
		cout << "WRONG CHOICE! PLEASE CHOOSE AGAIN: ";
		cin >> c;
	}
	if (c == 1)
		CustomerMenu(a, bills, rebills, check);
	else if (c == 2)
		StaffMenu(a, bills, rebills, check);
	else if (c == 3)
		noticeEnd(85, 40);
	else return;
}


//---------------------------------------------CUSTOMER-----------------------------------------//

void CustomerMenu(vector<Car>& a, vector<Bill> &bills, vector<BillRepair>& rebills, bool &check)
{
	vector<Car> shoppingCart;
	system("cls");
	TextColor(12);
	gotoxy(95, 12);
	cout << "CAR DEALER";
	TextColor(7);
	gotoxy(92, 16);
	cout << "1. SEE ALL CARS";
	gotoxy(92, 18);
	cout << "2. SEARCH A CAR";
	gotoxy(92, 20);
	cout << "3. TOP BEST SELLERS";
	gotoxy(92, 22);
	cout << "4. PROMOTION";
	gotoxy(92, 24);
	cout << "5. SEE SHOPPING CART";
	gotoxy(92, 26);
	cout << "6. REPAIR CAR";
	gotoxy(92, 28);
	cout << "7. LOGOUT";
	TextColor(14);
	gotoxy(92, 32);
	cout << "YOUR CHOICE: ";
	int c;
	cin >> c;
	while (c < 1 || c > 7)
	{
		gotoxy(42, 21);
		cout << "WRONG CHOICE! PLEASE CHOOSE AGAIN: ";
		cin >> c;
	}
	TextColor(7);
	if (c == 1)
		SeeAllCar(a, bills, rebills, check);
	else if (c == 2)
	{
		system("cls");
		TextColor(14);
		gotoXY(92, 20);
		cout << "1.Name ";
		gotoXY(92, 22);
		cout << "2.Brand ";
		gotoXY(92, 24);
		cout << "3.Seats ";
		gotoXY(92, 26);
		cout << "4.Prices ";
		gotoXY(92, 28);
		cout << "5.Exit ";
		TextColor(7);
		gotoXY(92, 32);
		cout << "YOUR CHOICE: ";
		int choicex;
		cin >> choicex;
		if (choicex == 1)
		{
			FindNameCar(a, bills, check);
			CustomerMenu(a, bills, rebills, check);
		}
		else if (choicex == 2)
		{
			FindBrandCar(a, bills, check);
			CustomerMenu(a, bills, rebills, check);
		}
		else if (choicex == 3)
		{
			FindSeatCar(a, bills, check);
			CustomerMenu(a, bills, rebills, check);
		}
		else if (choicex == 4)
		{
			FindMoneyCar(a, bills, check);
			CustomerMenu(a, bills, rebills, check);
		}
		else if (choicex == 5)
		{
			CustomerMenu(a, bills, rebills, check);
		}
	}
	else if (c == 3)
	{
		reportBestSeller(a);
		CustomerMenu(a, bills, rebills, check);
	}
	else if (c == 4)
	{
		system("cls");
		SeePromotion();
		CustomerMenu(a, bills, rebills, check);
	}
	else if (c == 5)
	{
		ShoppingCart(a, bills, rebills, check);
		CustomerMenu(a, bills, rebills, check);
	}
	else if (c == 6)
	{
		system("cls");
		RepairCar(a, bills, rebills, check);

	}
	else if (c == 7)
		Login(a, bills, rebills);


}

void DrawTable(int CountL)
{

	CountL = CountLine() - 1;
	CountL++;
	int Width = 20;
	int n = 11 + 2 * CountL;
	int m = 10;
	int w = 0;
	w--;
	int q = w * 2 + 5;

	gotoXY(2, 2);
	putchar(218);
	for (int i = 1; i <= 76 + Width; i++)
		if (i == 10 + m || i == 30 + m) putchar(194);
		else putchar(196);
	printf("%c\n", 191);
	for (int i = 13; i <= n; i += 2)
	{
		//_getch();
		gotoXY(2, i - 10);
		putchar(179);
		gotoXY(79 + Width, i - 10);
		putchar(179);
		printf("\n");
		//
		gotoXY(12 + m, i - 10);
		putchar(179);
		gotoXY(32 + m, i - 10);
		putchar(179);


		gotoXY(2, i + 1 - 10);
		if (i == n) putchar(192);
		else putchar(195);
		if (i != n)
			for (int i = 1; i <= 76 + Width; i++)
				if (i == 10 + m || i == 30 + m) putchar(197);
				else putchar(196);
		else
			for (int i = 1; i <= 76 + Width; i++)
				if (i == 10 + m || i == 30 + m) putchar(193);
				else putchar(196);
		if (i == n) putchar(217); else putchar(180);

	}
	gotoXY(3, q);
	cout << "NO";
	gotoXY(24, q);
	cout << "ID";
	gotoXY(43, q);
	cout << "NAME";
	ReadData();
}
void SeeAllCar(vector<Car>& a, vector<Bill> &bills, vector<BillRepair>& rebills, bool &check) {
	system("cls");
	gotoxy(49, 2);
	cout << "ALL CARS";
	int i = 0;
	int x = CountLine();
	DrawTable(x);

	gotoxy(35, 73 + a.size());
	cout << "YOUR CHOICE: ";
	int c;
	cin >> c;

	while (c < 1 || c > a.size())
	{
		gotoxy(35,73  + a.size());
		cout << "WRONG CHOICE! PLEASE CHOOSE AGAIN: ";
		cin >> c;
	}

	system("cls");
	a[c - 1].OutPut();

	cout << endl;
	gotoXY(85, 30);
	cout << "1. ADD TO SHOPPING CART" << endl;
	gotoXY(85, 32);
	cout << "2. RETURN" << endl;
	gotoXY(85, 34);
	cout << "YOUR CHOICE: ";
	int choice;
	cin >> choice;
	while (choice < 1 || choice > 2)
	{
		cout << "WRONG CHOICE! PLEASE CHOOSE AGAIN: ";
		cin >> choice;
	}
	if (choice == 1)
	{
		BuyCar(a[c - 1], bills, check);
		noticeDone(85, 45);
		CustomerMenu(a, bills, rebills, check);
	}
	if (choice == 2)
		CustomerMenu(a, bills, rebills, check);
}

void BuyCar(Car& a, vector<Bill> &bills, bool &check) {
	gotoXY(72, 36);
	cout << "PLEASE ENTER THE NUMBER OF CARS YOU WANT TO ADD: ";
	int num;
	cin >> num;

	gotoXY(72, 40);
	bool tmp_check = a.AddToCart(num);
	if (tmp_check == false) {
		gotoXY(72, 40);
		cout << "NOT ENOUGHT CAR TO SELL";
	}
	else {
		addtobill(a, bills, num, check);
		gotoXY(72, 40);
		cout << "ADD TO SHOPPING CART SUCCESSFULLY";
	}
}


void FindNameCar(vector<Car>& a, vector<Bill> &bills, bool &check)
{
	system("cls");
	gotoxy(82, 20);
	string x;
	cout << "PLEASE INPUT NAME CAR YOU WANT CHOICE: ";
	cin.ignore(1);
	getline(cin, x);
	system("cls");
	int n;
	bool check1 = false;
	for (int i = 0; i < a.size(); i++)
	{
		if (x == a[i].GetName())
		{
			a[i].OutPut();
			n = i;
			check1 = true;
			break;
		}

	}

	if (check1 == false)
	{
		gotoXY(82, 22);
		cout << "SORRY, WE DON'T HAVE THIS CAR!";
		noticeDone(82, 25);
	}
	else if (check1 == true)
	{
		int choice;
		gotoXY(82, 25);
		cout << "1. Add to cart";
		gotoXY(82, 27);
		cout << "2. Exit";
		gotoXY(82, 29);
		cout << "YOUR CHOICE: ";
		cin >> choice;
		if (choice == 1)
		{
			BuyCar(a[n], bills, check);
			noticeDone(82, 42);
		}
		else if (choice == 2)
		{
			noticeDone(82, 42);
		}
	}
}

void FindBrandCar(vector<Car>& a, vector<Bill> &bills, bool &check)
{
	system("cls");
	gotoxy(82, 10);
	string x;
	cout << "PLEASE INPUT BRAND NAME OF CAR YOU WANT CHOICE: ";
	cin.ignore(1);
	getline(cin, x);
	bool check1 = false;
	int j = 1;
	int line = 1;
	TextColor(14);
	gotoXY(78, 14);
	cout << "No";
	gotoXY(82, 14);
	cout << "Name";
	gotoXY(120, 14);
	cout << "Quanity";
	gotoXY(130, 14);
	cout << "Prices";
	TextColor(7);
	for (int i = 0; i < a.size(); i++)
	{
		string tmp = a[i].GetName().substr(0, x.length());
		if (x == tmp)
		{

			gotoXY(78, 16 + line);
			cout << j++ << ". ";
			gotoXY(82, 16 + line);
			cout << a[i].GetName();
			gotoXY(120, 16 + line);
			cout << a[i].getQuanity();
			gotoXY(130, 16 + line);
			cout << a[i].GetPrice() << "$";
			check1 = true;
			line++;
		}
	}
	if (check1 == false)
	{
		system("cls");
		gotoXY(85, 14);
		cout << "SORRY, WE DON'T HAVE THIS CAR!";
	}
	cout << endl;
	noticeDone(85, 35);

}

void FindSeatCar(vector<Car>& a, vector<Bill> &bills, bool &check)
{
	system("cls");
	gotoxy(82, 10);
	int x;
	cout << "PLEASE INPUT SEAT OF CAR YOU WANT CHOICE: ";
	bool check1 = false;
	cin >> x;
	int j = 1;
	int line = 1;
	TextColor(14);
	gotoXY(78, 14);
	cout << "No";
	gotoXY(82, 14);
	cout << "Name";
	gotoXY(120, 14);
	cout << "Quanity";
	gotoXY(130, 14);
	cout << "Prices";
	TextColor(7);
	for (int i = 0; i < a.size(); i++)
	{
		if (x == a[i].getSeat())
		{
			gotoXY(78, 16 + line);
			cout << j++ << ". ";
			gotoXY(82, 16 + line);
			cout << a[i].GetName();
			gotoXY(120, 16 + line);
			cout << a[i].getQuanity();
			gotoXY(130, 16 + line);
			cout << a[i].GetPrice() << "$";
			line++;
			check1 = true;
		}
	}
	if (check1 == false)
	{
		system("cls");
		gotoXY(85, 14);
		cout << "SORRY, WE DON'T HAVE THIS CAR!";
	}
	cout << endl;
	noticeDone(85, 45);

}

void FindMoneyCar(vector<Car>& a, vector<Bill> &bills, bool &check)
{
	system("cls");
	gotoxy(82, 10);
	int x;
	int y;
	cout << "PLEASE INPUT THE MONEY'S LIMITATION(x, y): ";
	bool check1 = false;
	cin >> x;
	cin >> y;
	int j = 1;
	int line = 1;
	TextColor(14);
	gotoXY(78, 14);
	cout << "No";
	gotoXY(82, 14);
	cout << "Name";
	gotoXY(120, 14);
	cout << "Quanity";
	gotoXY(130, 14);
	cout << "Prices";
	TextColor(7);
	for (int i = 0; i < a.size(); i++)
	{
		if (y >= a[i].GetPrice() && x <= a[i].GetPrice())
		{
			gotoXY(78, 16 + line);
			cout << j++ << ". ";
			gotoXY(82, 16 + line);
			cout << a[i].GetName();
			gotoXY(120, 16 + line);
			cout << a[i].getQuanity();
			gotoXY(130, 16 + line);
			cout << a[i].GetPrice() << "$";
			line++;
			check1 = true;
		}
	}
	if (check1 == false)
	{
		system("cls");
		gotoXY(85, 14);
		cout << "SORRY, WE HAVE NO THIS CAR WITH THAT PRICES !";
	}
	cout << endl;
	noticeDone(85, 35);
}

void randomGift(vector<Car>& a, vector<Bill> &bills, bool &check)
{
	system("cls");
	srand((int)time(0));
	int r = random(1, 100);
	gotoXY(85, 25);
	if (r > 0 & r < 30)
	{
		cout << "CONGRATULATION! YOUR GIFT IS A RAINCOAT!!!";
	}
	if (r >= 30 && r < 40)
	{
		cout << "CONGRATULATION YOUR GIFT IS A CANDY";
	}
	if (r >= 40 & r < 70)
	{
		cout << "CONGRATULATION! YOUR GIFT IS A UMBRELLA!!!";
	}
	if (r >= 70 & r < 100)
	{
		cout << "CONGRATULATION! YOUR GIFT IS A HELMETS!!!";
	}
	if (r == 100)
	{
		cout << "CONGRATULATION! YOUR GIFT IS A A KISS FROM NHAT MINH!!!";
	}
}

void ShoppingCart(vector<Car>& a, vector<Bill> &bills, vector<BillRepair>& rebills, bool &check) {
	system("cls");
	gotoxy(95, 3);
	TextColor(12);
	cout << "SHOPPING CART";
	TextColor(7);
	int j = 1;
	int temp_money = 0;
	for (int i = 0; i < a.size(); i++)
	{
		if (a[i].inCart != 0) {
			temp_money += a[i].GetPrice() * a[i].inCart;
			int k = j + 6;
			gotoxy(70, k);
			cout << j << ". " << a[i].inCart << "X " << a[i].GetName() << ":";
			gotoxy(110, k);
			cout << a[i].GetPrice() * a[i].inCart << "$";
			j++;
		}
	}

	int promotion = Promotion(a);
	int total = temp_money - promotion;

	TextColor(11);
	gotoxy(70, j + 9);
	cout << "TEMPORARILY MONEY: " << temp_money << "$";
	gotoxy(70, j + 11);
	cout << "PROMOTION: " << promotion << "$";
	gotoxy(70, j + 13);
	cout << "TOTAL MONEY: " << total << "$";
	gotoxy(70, j + 16);
	TextColor(7);
	cout << "1. AGREE TO PAY";
	gotoxy(70, j + 18);
	cout << "2. CANCEL";
	gotoxy(70, j + 20);
	TextColor(14);
	cout << "YOUR CHOICE: ";
	int c;
	cin >> c;
	while (c < 1 || c > 2)
	{
		gotoxy(70, j + 22);
		cout << "WRONG CHOICE! PLEASE CHOOSE AGAIN: ";
		cin >> c;
	}
	if (c == 1) {
		for (int i = 0; i < a.size(); i++) {
			if (a[i].inCart != 0) {
				a[i].sell();
				a[i].inCart = 0;
			}
		}
		TextColor(7);
		gotoxy(70, j + 24);
		cout << "PAY SUCCESSFULLY" << endl;
		randomGift(a, bills, check);
		check = false;
		noticeDone(85, 28);
	}
	else if (c == 2)
	{
		bills.pop_back();
		return;
	}
	TextColor(7);
}

void RepairCar(vector<Car>& a, vector<Bill>& bills, vector<BillRepair>& rebills, bool& check)
{
	Car C;
	Date d = C.inputRe();
	system("cls");
	vector<string> E = ErrorFile("Error.txt");

	int j = 1;
	int countLine = 0;
	for (int i = 0; i < E.size(); i++)
	{
		TextColor(10);
		gotoXY(80, 10);
		cout << "No";
		gotoXY(92, 10);
		cout << "Error Name";
		TextColor(7);
		gotoXY(80, 12 + i);
		cout << j << ".";
		gotoXY(92, 12 + i);
		cout << E[i] << endl;
		countLine = i;
		j++;
	}
	double pr = 0;		//Price Repair
	int x = 0;
	gotoXY(92, countLine + 14);
	cout << "WHAT IS PROLEM WITH YOUR CAR?: ";
	cin >> x;
	switch (x)
	{
	case 1:
	{
		pr = 200;
		break;
	}
	case 2:
	{
		pr = 50;
		break;
	}
	case 3:
	{
		pr = 150;
		break;
	}
	case 4:
	{
		pr = 100;
		break;
	}
	case 5:
	{
		pr = 10;
		break;
	}
	case 6:
	{
		pr = 50;
		break;
	}
	case 7:
	{
		pr = 30;
		break;
	}
	case 8:
	{
		pr = 20;
		break;
	}
	case 9:
	{
		pr = 10;
		break;
	}
	case 10:
	{
		pr = 20;
		break;
	}
	case 11:
	{
		pr = 100;
		break;
	}
	case 12:
	{
		pr = 50;
		break;
	}
	case 13:
	{
		pr = 10;
		break;
	}
	case 14:
	{
		pr = 100;
		break;
	}
	}
	if (C.GetPrice() < 50000)
		pr = pr;
	else if (C.GetPrice() >= 50000 && C.GetPrice() < 100000)
		pr = pr * 1.5;
	else if (C.GetPrice() >= 100000 && C.GetPrice() < 200000)
		pr = pr * 2;
	else if (C.GetPrice() >= 200000 && C.GetPrice() < 300000)
		pr = pr * 2.5;
	else if (C.GetPrice() >= 300000)
		pr = pr * 3;
	system("cls");
	TextColor(14);
	gotoXY(92, 24);
	cout << "YOUR CAR REPAIR FEE IS: " << pr;
	TextColor(7);
	gotoXY(92, 26);
	cout << "DO YOU WANT REPAIR? ";
	gotoXY(92, 27);
	cout << "1. YES";
	gotoXY(92, 28);
	cout << "2. No";
	gotoXY(92, 30);
	TextColor(9);
	cout << "YOUR CHOICE: ";
	TextColor(7);

	int choice;
	cin >> choice;

	if (choice == 1)
	{
		AddToRepairBill(C, x, d, rebills);
		noticeDone(92, 32);
		CustomerMenu(a, bills, rebills, check);
	}
	if (choice == 2)
	{
		CustomerMenu(a, bills, rebills, check);
	}

}


//---------------------------------------------------- STAFF-------------------------------------------------//

void StaffMenu(vector<Car>& a, vector<Bill> &bills, vector<BillRepair>& rebills, bool check) {
	system("cls");
	TextColor(14);
	gotoxy(95, 12);
	cout << "CAR DEALER";
	TextColor(7);
	gotoxy(92, 16);
	cout << "1. SELL CARS";
	gotoxy(92, 18);
	cout << "2. IMPORT CARS";
	gotoXY(92, 20);
	cout << "3. FIND CARS";
	gotoXY(92, 22);
	cout << "4. FIND BILLS";
	gotoXY(92, 24);
	cout << "5. UPDATE INFORMATION OF CAR";
	gotoXY(92, 26);
	cout << "6. REPORT";
	gotoxy(92, 28);
	cout << "7. LOGOUT";
	TextColor(12);
	gotoxy(92, 32);
	cout << "YOUR CHOICE: ";
	int c;
	cin >> c;
	cin.ignore();
	while (c < 1 || c > 7)
	{
		gotoxy(92, 28);
		cout << "WRONG CHOICE! PLEASE CHOOSE AGAIN: ";
		cin >> c;
	}
	TextColor(7);
	if (c == 1) {
		SellCar(a);
		StaffMenu(a, bills, rebills, check);
	}
	else if (c == 2) {
		ImportCar(a);
		StaffMenu(a, bills, rebills, check);
	}
	else if (c == 3)
	{
		system("cls");
		TextColor(14);
		gotoXY(92, 20);
		cout << "1.ID ";
		gotoXY(92, 22);
		cout << "2.Name ";
		gotoXY(92, 24);
		cout << "3.Brand ";
		gotoXY(92, 26);
		cout << "4.Seats ";
		gotoXY(92, 28);
		cout << "5.Exit ";
		TextColor(7);
		gotoXY(92, 32);
		cout << "YOUR CHOICE: ";
		int choicex;
		cin >> choicex;
		if (choicex == 1)
		{
			FindIDCar(a, bills, rebills, check);
		}
		else if (choicex == 2)
		{
			FindNameCar(a, bills, check);
			StaffMenu(a, bills, rebills, check);
		}
		else if (choicex == 3)
		{
			FindBrandCar(a, bills, check);
			StaffMenu(a, bills, rebills, check);
		}
		else if (choicex == 4)
		{
			FindSeatCar(a, bills, check);
			StaffMenu(a, bills, rebills, check);
		}
		else if (choicex == 5)
		{
			StaffMenu(a, bills, rebills, check);
		}
	}
	else if (c == 4)
	{
		showOneBill(a, bills, check);
		StaffMenu(a, bills, rebills, check);
	}
	else if (c == 5) {
		updateCar(a);
		StaffMenu(a, bills, rebills, check);
	}
	else if (c == 6) {
		system("cls");
		gotoxy(95, 20);
		cout << "REPORT";
		TextColor(14);
		gotoXY(92, 22);
		cout << "1. IMPORT PROCESS REPORT";
		gotoXY(92, 24);
		cout << "2. BEST SELLER REPORT";
		gotoXY(92, 26);
		cout << "3. TOTAL RECEIPTS REPORT";
		TextColor(7);
		gotoXY(92, 28);
		cout << "YOUR CHOICE: ";
		int choice;
		cin >> choice;
		while (choice < 1 || choice > 3) {
			gotoxy(92, 28);
			cout << "WRONG CHOICE! PLEASE CHOOSE AGAIN: ";
			cin >> choice;
		}
		if (choice == 1)
			reportImportProcess(a);
		if (choice == 2)
			reportBestSeller(a);
		if (choice == 3)
			reportTotalReceipts(bills, a);

		StaffMenu(a, bills, rebills, check);
	}
	else if (c == 7) {
		Login(a, bills, rebills);
	}
	
}

void FindIDCar(vector<Car>& a, vector<Bill> &bills, vector<BillRepair>& rebills, bool &check)
{
	system("cls");
	gotoxy(82, 20);
	string x;
	cout << "PLEASE INPUT ID CAR YOU WANT CHOICE: ";
	cin.ignore(1);
	getline(cin, x);
	system("cls");
	int n;
	bool check1 = false;
	for (int i = 0; i < a.size(); i++)
	{
		if (x == a[i].getID())
		{
			a[i].OutPut();
			n = i;
			check1 = true;
			break;
		}

	}

	if (check1 == false)
	{
		gotoXY(82, 22);
		cout << "SORRY, WE DON'T HAVE THIS CAR!";
	}

	int choice;
	gotoXY(82, 25);
	cout << "1. Add to cart";
	gotoXY(82, 27);
	cout << "2. Exit";
	gotoXY(82, 29);
	cout << "YOUR CHOICE: ";
	cin >> choice;
	if (choice == 1)
	{
		BuyCar(a[n], bills, check);
	}
	else if (choice == 2)
	{
		StaffMenu(a, bills, rebills, check);
	}
}

void SellCar(vector<Car>& a) {
	system("cls");
	gotoxy(49, 2);
	cout << "ALL CARS";
	int i = 0;
	int x = CountLine();
	DrawTable(x);

	gotoxy(35, 73 + a.size());
	cout << "YOUR CHOICE: ";
	int c;
	cin >> c;
	while (c < 1 || c > a.size())
	{
		gotoxy(35, 75 + a.size());
		cout << "WRONG CHOICE! PLEASE CHOOSE AGAIN: ";
		cin >> c;
	}

	system("cls");
	a[c - 1].OutPut();

	cout << endl;
	gotoXY(85, 30);
	cout << "1. SELL" << endl;
	gotoXY(85, 32);
	cout << "2. RETURN" << endl;
	gotoXY(85, 34);
	cout << "YOUR CHOICE: ";
	int choice;
	cin >> choice;
	while (choice < 1 || choice > 2)
	{
		gotoXY(85, 36);
		cout << "WRONG CHOICE! PLEASE CHOOSE AGAIN: ";
		cin >> choice;
		cin.ignore();
	}

	if (choice == 1)
	{
		gotoXY(85, 36);
		cout << "ENTER NUMBER OF CARS TO SELL: ";
		int num;
		cin >> num;
		cin.ignore();
		a[c - 1].AddToCart(num);
		a[c - 1].sell();
	}
	noticeDone(85, 40);
}

void showOneBill(vector<Car>& a, vector<Bill>&bills, bool &check)
{
	system("cls");
	int x = 60;
	int y = 20;

	string numBill;
	gotoXY(82, 25);
	cout << "PLEASE INPUT ID BILL YOU WANT TO FIND: ";
	cin.ignore(0);
	getline(cin, numBill);

	bool checkx = false;
	for (int i = 0; i < bills.size(); i++)
	{
		if (numBill == bills[i].GetBillID())
		{
			bills[i].displayOneBill(x, y);
			checkx = true;
		}
	}
	if (checkx == false)
	{
		gotoXY(82, 27);
		cout << "WE DON'T HAVE THIS BILL";
	}
	cout << endl;
	system("pause");
}

void ImportCar(vector<Car>& a)
{
	system("cls");
	int x = WIDTH_OFFSET - 80 / 2, y = HEIGHT_OFFSET - 19 / 2;

	gotoxy(WIDTH_OFFSET - 19 / 2, y - 4);
	cout << "1. ADD A NEW CAR";
	gotoxy(WIDTH_OFFSET - 19 / 2, y - 2);
	cout << "2. ADD AN EXISTING CAR";
	gotoxy(WIDTH_OFFSET - 19 / 2, y);
	cout << "YOUR CHOICE: ";
	int c;
	cin >> c;
	while (c < 1 || c > 2)
	{
		gotoxy(WIDTH_OFFSET - 19 / 2, y);
		cout << "WRONG CHOICE! PLEASE CHOOSE AGAIN: ";
		cin >> c;
	}
	if (c == 1)
	{
		system("cls");
		addCar(a);
	}
	else if (c == 2)
	{
		system("cls");
		gotoxy(49, 2);
		cout << "ALL CARS";
		int i = 0;
		int x = CountLine();
		DrawTable(x);

		gotoxy(35, 73 + a.size());
		cout << "YOUR CHOICE: ";
		int c;
		cin >> c;

		while (c < 1 || c > a.size())
		{
			gotoxy(35, 73 + a.size());
			cout << "WRONG CHOICE! PLEASE CHOOSE AGAIN: ";
			cin >> c;
		}
		system("cls");
		a[c - 1].OutPut();

		gotoXY(85, 30);
		cout << "ENTER NUMBER YOU WANT TO IMPORT: ";
		int num;
		cin >> num;
		while (num < 1) {
			noticeTryAgain(85, 30);
			gotoXY(85, 30);
			cout << "ENTER NUMBER YOU WANT TO IMPORT: ";
			int num;
		}
		a[c - 1].addToStock(num);
		noticeDone(85, 32);
	}
}