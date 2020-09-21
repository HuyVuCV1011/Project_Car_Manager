#include "Car.h"
#include "bmp.h"
#include <sstream>

string Car::getID() { return ID; }
void Car::setID(string temp) { ID = temp; }
Date Car::getImportDate() { return ImportDate; }
int Car::getSoldNum() { return SoldNum; }
string Car::GetName() { return Name; }
int Car::GetPrice() { return salePrice; }
int Car::getFixedPrice() { return fixedPrice; }

void changeBmp(PixelArray &p)
{
	for (int i = 0; i < p.rowCount; i++)
		for (int j = 0; j < p.columnCount; j++)
		{
			Color *c = &p.pixels[i][j];
			if ((c->red == 255) && (c->blue == 0) && (c->green == 0))
			{
				c->blue = 255;
			}
		}
}

void demoReadBmp(string name)
{
	BmpFile bmpSource;

	string tmp = "car//" + name + ".bmp";
	const char* path = tmp.c_str();
	readBmpFile(path, bmpSource);

	changeBmp(bmpSource.pixelArray);
	drawBmp(bmpSource);

	releaseBmpPixelArray(bmpSource);


}


void LoadArrayFromFile(string path, vector<Car> &Stock)
{
	ifstream fin;
	fin.open(path.c_str());
	int day;
	int month;
	int year;
	while (fin.eof() == false)
	{
		Car temp;
		getline(fin, temp.ID, ',');
		if (temp.ID == "")
		{
			break;
		}
		getline(fin, temp.Name, ',');
		fin >> temp.fixedPrice;
		fin.ignore();
		fin >> temp.salePrice;
		fin.ignore();
		getline(fin, temp.Brand, ',');
		fin >> temp.Seat;
		fin.ignore();
		fin >> day;
		fin.ignore();
		fin >> month;
		fin.ignore();
		fin >> year;
		fin.ignore();
		temp.ImportDate.setDate(day, month, year);
		fin >> temp.Quantity;
		fin.ignore();
		fin >> temp.SoldNum;
		fin.ignore();
		Stock.push_back(temp);
	}
	fin.close();
}
void SaveArrayToFile(string path, vector<Car> Stock)
{
	ofstream fout;
	fout.open(path.c_str());
	for (int i = 0; i < (int)Stock.size(); i++)
	{
		fout << Stock[i].ID << ",";
		fout << Stock[i].Name << ",";
		fout << Stock[i].fixedPrice << ",";
		fout << Stock[i].salePrice << ",";
		fout << Stock[i].Brand << ",";
		fout << Stock[i].Seat << ",";
		fout << Stock[i].ImportDate.getDay() << ",";
		fout << Stock[i].ImportDate.getMonth() << ",";
		fout << Stock[i].ImportDate.getYear() << ",";
		fout << Stock[i].Quantity << ",";
		fout << Stock[i].SoldNum << "\n";
	}
	fout.close();
}


void addCar(vector<Car> &Stock) {
	system("cls");
	int x = WIDTH_OFFSET - 80 / 2, y = HEIGHT_OFFSET - 19 / 2;
	gotoxy(WIDTH_OFFSET - 19 / 2, y); cout << "ADD NEW INFORMATION";
	Car temp;
	temp.setID(inputID(x, y += 2, unexistingID, Stock));
	temp.inputName(x, y += 2);
	temp.inputBrand(x, y += 2);
	temp.inputSeat(x, y += 2);
	temp.inputFixedPrice(x, y += 2);
	temp.inputSalePrice(x, y += 2);
	temp.inputQuantity(x, y += 2);
	temp.inputImportDate(x, y += 2);
	Stock.push_back(temp);
	noticeDone(x, y);
	cin.ignore();
}
string inputID(int x, int y, bool(*check)(string, vector<Car>), vector<Car> Stock) {
	string temp;
label:
	gotoxy(x, y); cout << "ID:                                                  ";
	gotoxy(x + 4, y); getline(cin, temp);
	if (temp != "\0") {
		transform(temp.begin(), temp.end(), temp.begin(), ::toupper);
		if (check(temp, Stock))
			return temp;
	}
	noticeTryAgain(x, y);
	goto label;
}
bool existingID(string temp, vector<Car> Stock) {
	for (int i = 0; i < (int)Stock.size(); i++)
		if (Stock[i].getID() == temp)
			return true;
	return false;
}
bool unexistingID(string temp, vector<Car> Stock) {
	return !existingID(temp, Stock);
}
void Car::inputName(int x, int y) {
label:
	gotoxy(x, y); cout << "Name:                                                  ";
	gotoxy(x + 6, y); getline(cin, Name);
	Name = checkName(Name);
	if (Name == "\0") {
		noticeTryAgain(x, y);
		goto label;
	}
}
string checkName(string temp) {
	if (temp != "\0") {
		int size = temp.size();
		char *copy1 = new char[size + 1];
		copy1[size] = '\0';
		copy(temp.begin(), temp.end(), copy1);
		int indexBegin, indexEnd;
		for (indexBegin = 0; indexBegin < size; indexBegin++)
			if (copy1[indexBegin] != ' ') {
				copy1[indexBegin] = toupper(copy1[indexBegin]);
				break;
			}
		for (indexEnd = size - 1; indexEnd > indexBegin; indexEnd--)
			if (copy1[indexEnd] != ' ')
				break;
		for (int i = indexBegin + 1; i < indexEnd; i++) {
			int countSpace = 0;
			while (copy1[i + countSpace] == ' ') ++countSpace;
			if (countSpace-- > 0) {
				for (int k = i; k <= indexEnd - countSpace; k++)
					copy1[k] = copy1[k + countSpace];
				indexEnd -= countSpace;
				copy1[++i] = toupper(copy1[i]);
			}
		}
		size = indexEnd - indexBegin + 1;
		char *copy2 = new char[size + 1];
		copy2[size] = '\0';
		for (int i = 0; i < size; i++)
			copy2[i] = copy1[indexBegin++];
		temp = copy2;
		delete copy1, copy2;
	}
	return temp;
}
void Car::inputBrand(int x, int y) {
label:
	gotoxy(x, y); cout << "Brand:                                                  ";
	gotoxy(x + 7, y); getline(cin, Brand);
	Brand = checkName(Brand);
	if (Brand == "\0") {
		noticeTryAgain(x, y);
		goto label;
	}
}
void Car::inputSeat(int x, int y) {
label:
	gotoxy(x, y); cout << "Seat:                                                  ";
	gotoxy(x + 6, y); cin >> Seat;
	if (Seat < 1) {
		noticeTryAgain(x, y);
		goto label;
	}
}
void Car::inputQuantity(int x, int y) {
label:
	gotoxy(x, y); cout << "Quantity:                                                  ";
	gotoxy(x + 10, y); cin >> Quantity;
	if (Quantity < 1) {
		noticeTryAgain(x, y);
		goto label;
	}
}
void Car::inputSoldNum(int x, int y) {
label:
	gotoxy(x, y); cout << "Sold:                                                  ";
	gotoxy(x + 6, y); cin >> SoldNum;
	if (SoldNum < 0) {
		noticeTryAgain(x, y);
		goto label;
	}
}
void Car::inputImportDate(int x, int y) {
	int temp[3];
label:
	gotoxy(x, y); cout << "Import date - Day  :                                                  ";
	gotoxy(x + 21, y); cin >> temp[0];
	gotoxy(x, y); cout << "Import date - Month:                                                  ";
	gotoxy(x + 21, y); cin >> temp[1];
	gotoxy(x, y); cout << "Import date - Year :                                                  ";
	gotoxy(x + 21, y); cin >> temp[2];
	ImportDate.setDate(temp[0], temp[1], temp[2]);
	gotoxy(x, y); cout << "Import date: "; ImportDate.display(); cout << "                                       ";
	if (!ImportDate.isValid()) {
		noticeTryAgain(x, y);
		goto label;
	}
}
void Car::inputFixedPrice(int x, int y) {
label:
	gotoxy(x, y); cout << "Fixed price:                                                  ";
	gotoxy(x + 13, y); cin >> fixedPrice;
	if (fixedPrice < 0) {
		noticeTryAgain(x, y);
		goto label;
	}
}
void Car::inputSalePrice(int x, int y) {
label:
	gotoxy(x, y); cout << "Sale price:                                                  ";
	gotoxy(x + 12, y); cin >> salePrice;
	if (salePrice < 0) {
		noticeTryAgain(x, y);
		goto label;
	}
}


void updateCar(vector<Car> &Stock) {
	system("cls");
	TextColor(9);
	int x = WIDTH_OFFSET - 80 / 2, y = HEIGHT_OFFSET - 16 / 2;
	gotoxy(WIDTH_OFFSET - 18 / 2, y - 3); cout << "UPDATE INFORMATION";
	TextColor(7);
	int indexCar = findIndexCar(Stock, inputID(x, y += 2, existingID, Stock)), item;
	while (1) {
		for (int i = 0; i < 9; i++) {
			gotoxy(x, y + i); cout << "                                                            ";
		}
		Stock[indexCar].displayFullInfo(x, y);
		do {
			gotoxy(x, y + 12); cout << "Choose one:(0: exit)                                                  ";
			gotoxy(x + 21, y + 12); cin >> item;
		} while (item < 0 || item > 8);
		if (item == 0)
			break;
		if (item == 1)
			Stock[indexCar].inputName(x, y + 12);
		else if (item == 2)
			Stock[indexCar].inputBrand(x, y + 12);
		else if (item == 3)
			Stock[indexCar].inputSeat(x, y + 12);
		else if (item == 4)
			Stock[indexCar].inputFixedPrice(x, y + 12);
		else if (item == 5)
			Stock[indexCar].inputSalePrice(x, y + 12);
		else if (item == 6)
			Stock[indexCar].inputQuantity(x, y + 12);
		else if (item == 7)
			Stock[indexCar].inputSoldNum(x, y + 12);
		else
			Stock[indexCar].inputImportDate(x, y + 12);
	}
	noticeDone(x, y + 12);
	cin.ignore();
}
int findIndexCar(vector<Car> Stock, string temp) {
	for (int i = 0; i < (int)Stock.size(); i++)
		if (Stock[i].getID() == temp)
			return i;
	return -1;
}
void Car::displayFullInfo(int x, int y) {
	gotoxy(x, y); cout << "0) ID: " << ID;
	gotoxy(x, ++y); cout << "1) Name: " << Name;
	gotoxy(x, ++y); cout << "2) Brand: " << Brand;
	gotoxy(x, ++y); cout << "3) Seats: " << Seat;
	gotoxy(x, ++y); cout << "4) Fixed price: " << fixedPrice;
	gotoxy(x, ++y); cout << "5) Sale price: " << salePrice;
	gotoxy(x, ++y); cout << "6) Quantity: " << Quantity;
	gotoxy(x, ++y); cout << "7) Sold: " << SoldNum;
	gotoxy(x, ++y); cout << "8) Import date: "; ImportDate.display();
}


void deleteCar(vector<Car> &Stock) {
	system("cls");
	int x = WIDTH_OFFSET - 80 / 2, y = HEIGHT_OFFSET - 5 / 2;
	gotoxy(WIDTH_OFFSET - 18 / 2, y); cout << "DELETE INFORMATION";
	int indexCar = findIndexCar(Stock, inputID(x, y += 2, existingID, Stock));
	Stock.erase(Stock.begin() + indexCar);
	noticeDone(x, y);
}

Date Car::inputRe()
{
	Date D;
	int x, y, z;
	gotoXY(90, 12);
	cout << "PLEASE INPUT INFORMATION OF YOUR CAR: ";
	gotoXY(90, 16);
	cout << "Name: ";
	cin.ignore(1);
	getline(cin, Name);
	gotoXY(90, 18);
	cout << "Date: ";
	cin >> x >> y >> z;
	D.setDate(x, y, z);
	return D;
}


void reportImportProcess(vector<Car> Stock) {
	system("cls");
	TextColor(9);
	ofstream fout;
	fout.open("REPORT - IMPORT PROCESS.csv");
	int x = WIDTH_OFFSET - 75 / 2, y = 2;
	gotoxy(WIDTH_OFFSET - 22 / 2, y); cout << "REPORT: IMPORT PROCESS"; fout << "REPORT: IMPORT PROCESS" << endl;
	TextColor(14);
	int year, month;
	do {
		gotoxy(x, y + 2); cout << "Year (0: show all):                                                  ";
		gotoxy(x + 20, y + 2); cin >> year;
	} while (year < 1950 && year != 0);
	do {
		gotoxy(x, y + 4); cout << "Month (0: show all):                                                  ";
		gotoxy(x + 21, y + 4); cin >> month;
	} while (month < 0 || month > 12);
	TextColor(7);
	fout << "Year: ";
	if (!year)
		fout << "All" << endl;
	else
		fout << year << endl;
	fout << "Month: ";
	if (!month)
		fout << "All" << endl;
	else
		fout << month << endl;
	fout << "ID,Quantity,Price,Import date" << endl;
	gotoxy(x, y += 6); cout << "+----------------+-------------+------------------+--------------------+";
	gotoxy(x, ++y); cout << "|       ID       |   Quantity  |       Price      |     Import date    |";
	gotoxy(x, ++y); cout << "+----------------+-------------+------------------+--------------------+";
	for (int i = 0; i < (int)Stock.size(); i++)
		if ((year == Stock[i].getImportDate().getYear() || year == 0) && ( month == Stock[i].getImportDate().getMonth() || month == 0)) {
			Stock[i].reportImportProcess(x, ++y);
			Stock[i].saveImportProcess(fout);
			gotoxy(x, ++y); cout << "+----------------+-------------+------------------+--------------------+";
		}
	gotoxy(x, ++y); cout << "|       -        |      -      |         -        |     --/--/----     |";
	gotoxy(x, ++y); cout << "+----------------+-------------+------------------+--------------------+";
	noticeDone(x, y);
	cin.ignore();
	fout.close();
}
void Car::reportImportProcess(int x, int y) {
	gotoxy(x, y); cout << "|     " << ID;
	gotoxy(x += 17, y); cout << "|     " << setfill('0') << setw(3) << Quantity;
	int temp = 0; for (int i = fixedPrice; i > 0; i /= 10) temp++;
	gotoxy(x += 14, y); cout << "|" << setfill(' ') << setw(9 + temp / 2) << fixedPrice;
	gotoxy(x += 19, y); cout << "|     "; ImportDate.display(); cout << "     |";
}

void Car::saveImportProcess(ofstream &fout) {
	fout << ID << ",";
	fout << Quantity << ",";
	fout << fixedPrice << ",";
	fout << ImportDate.getDay() << "/" << ImportDate.getMonth() << "/" << ImportDate.getYear() << endl;
}


void reportBestSeller(vector<Car> Stock) {
	ofstream fout;
	fout.open("REPORT - BEST SELLER.csv");
	system("cls");
	int x = WIDTH_OFFSET - 80 / 2, y = 2;
	TextColor(14);
	gotoxy(WIDTH_OFFSET - 19 / 2, y); cout << "REPORT: BEST SELLER"; fout << "REPORT: BEST SELLER" << endl;

	TextColor(7);
	int sold[3] = { -1 };
	for (int i = 0; i < (int)Stock.size(); i++)
		for (int j = 0; j < 3; j++)
			if (Stock[i].getSoldNum() >= sold[j]) {
				sold[j] = Stock[i].getSoldNum();
				break;
			}
	for (int i = 0; i < 3; i++) {
		if (sold[i] == -1) break;
		gotoxy(x, y += 2); cout << "________________________________________________________________________________";
		TextColor(11);
		gotoxy(x, y += 2); cout << "NO." << i + 1;
		fout << "NO." << i + 1 << ": " << sold[i] << " cars" << endl << "ID,Name,Sale price, Brand, Seat" << endl;
		TextColor(7);
		for (int j = 0; j < (int)Stock.size(); j++)
			if (Stock[j].getSoldNum() == sold[i]) {
				Stock[j].displayInfo(x, y+=2);
				Stock[j].saveBestSeller(fout);
				y += 5;
	
			}
	}
	TextColor(7);
	fout.close();
	noticeDone(x, y); 
}
void addtobill(Car info, vector<Bill>& bills, int SaleNum, bool &check)
{
	if (check == false) {
		Bill tempBill;
		BillDetail tempDetail;
		char tempChar[10];
		_itoa_s(bills.size(), tempChar, 10);
		string tempStr = "BILLNO";
		tempStr = tempStr + tempChar;
		tempBill.SetID(tempStr);
		int day;
		int month;
		int year;
		Date temp;
		do
		{
			gotoXY(72, 38);
			cout << "ENTER DATE:    /  /";
			gotoXY(85, 38);
			cin >> day;
			gotoXY(88, 38);
			cin >> month;
			gotoXY(91, 38);
			cin >> year;
			temp.setDate(day, month, year);
		} while (temp.isValid() == false);
		tempBill.SetDate(day, month, year);
		tempDetail.SetID(info.getID());
		tempDetail.SetName(info.GetName());
		tempDetail.SetPrice(info.GetPrice());
		tempDetail.SetSaleNum(SaleNum);
		tempBill.AddDetail(tempDetail);
		bills.push_back(tempBill);
		check = true;
	}
	else
	{
		BillDetail tempDetail;
		tempDetail.SetID(info.getID());
		tempDetail.SetName(info.GetName());
		tempDetail.SetPrice(info.GetPrice());
		tempDetail.SetSaleNum(SaleNum);
		bills[bills.size() - 1].AddDetail(tempDetail);
	}
}
void Car::displayInfo(int x, int y) {
	gotoxy(x, y); cout << "1) ID: " << ID;
	gotoxy(x, ++y); cout << "2) Name: " << Name;
	gotoxy(x, ++y); cout << "3) Brand: " << Brand;
	gotoxy(x, ++y); cout << "4) Seats: " << Seat;
	gotoxy(x, ++y); cout << "5) Price: " << salePrice << "$";
	gotoxy(x, ++y); cout << "6) Quantity: " << Quantity;
}

// Car function

void Car::addToStock(int num) {
	Quantity += num;
}

bool Car::AddToCart(int num)
{
	if (num > Quantity)
		return false;
	inCart = num;
	return true;
}

void Car::sell() {
	Quantity -= inCart;
	SoldNum += inCart;
	inCart = 0;
}

void Car::OutPut()
{
	TextColor(9);
	gotoXY(82, 6);
	cout << " ______________________________";
	gotoXY(85, 8);
	TextColor(14);
	cout << ">> ID: " << ID << endl;
	TextColor(9);
	for (int i = 7; i < 20; i++)
	{
		gotoXY(113, i);
		cout << "|";
		gotoXY(82, i);
		cout << "|";
	}
	TextColor(14);
	gotoXY(85, 10);
	cout << ">> Brand: " << Brand << endl;
	gotoXY(85, 12);
	cout << ">> Name: " << Name << endl;
	gotoXY(85, 14);
	cout << ">> Seat: " << Seat << endl;
	gotoXY(85, 16);
	cout << ">> Available: " << Quantity << endl;
	gotoXY(85, 18);
	cout << ">> Price: " << salePrice << "$" << endl;
	gotoXY(82, 19);
	TextColor(9);
	cout << "|______________________________";
	TextColor(7);
	demoReadBmp(ID);
}

// Promotion

void SeePromotion() {
	TextColor(14);
	gotoxy(95, 20);
	cout << "PROMOTION";
	TextColor(10);
	gotoxy(80, 23);
	cout << "1. Bought two similar cars, discount 2%";
	gotoxy(80, 25);
	cout << "2. Bill over 100000$, discount 1%" << endl << endl << endl << endl << endl << endl;
	TextColor(7);
	noticeDone(90, 30);
}

int Promotion(vector<Car>& a) {
	int percent = 0;
	int total = 0;
	for (int i = 0; i < a.size(); i++) {
		if (a[i].inCart >= 2) {
			percent += 2;
			break;
		}
		if (a[i].inCart != 0)
			total += a[i].GetPrice() * a[i].inCart;
	}
	if (total >= 100000)
		percent += 1;
	return total * percent / 100;
}

void Car::saveBestSeller(ofstream &fout) {
	fout << ID << ",";
	fout << Name << ",";
	fout << salePrice << ",";
	fout << Brand << ",";
	fout << Seat << endl;
}

// repair
void AddToRepairBill(Car info, int type, Date d, vector<BillRepair>& rebills) {
	vector<string> E = ErrorFile("Error.txt");

	BillRepair temp;


	int pr = info.GetPrice();

	switch (type)
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
	if (info.GetPrice() < 50000)
		pr = pr;
	else if (info.GetPrice() >= 50000 && info.GetPrice() < 100000)
		pr = pr * 1.5;
	else if (info.GetPrice() >= 100000 && info.GetPrice() < 200000)
		pr = pr * 2;
	else if (info.GetPrice() >= 200000 && info.GetPrice() < 300000)
		pr = pr * 2.5;
	else if (info.GetPrice() >= 300000)
		pr = pr * 3;



	int day = d.getDay();
	int month = d.getMonth();
	int year = d.getYear();
	/*Date d2;
	do
	{
		gotoXY(72, 38);
		cout << "ENTER DATE:    /  /";
		gotoXY(85, 38);
		cin >> day;
		gotoXY(88, 38);
		cin >> month;
		gotoXY(91, 38);
		cin >> year;
		d.setDate(day, month, year);
	} while (d.isValid() == false);*/

	stringstream ss;
	ss << rebills.size() + 1;

	temp.SetID("RE" + ss.str());
	temp.SetName(info.GetName());
	temp.SetType(type);
	temp.SetError(E[type - 1]);
	temp.SetPrice(pr);
	temp.SetDate(day, month, year);

	rebills.push_back(temp);
}

vector<string> ErrorFile(const char* File)
{
	ifstream fin;
	vector<string> E;
	fin.open(File);
	if (!fin.is_open())
		cout << "Can't not open file!";
	while (!fin.eof())
	{
		string error;
		fin.ignore(0);
		getline(fin, error, '\n');
		E.push_back(error);
	}
	return E;
}