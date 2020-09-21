#include "Bill.h"
#include "Car.h"

void BillDetail::SetID(string ID) { carID = ID; }
void BillDetail::SetName(string Name) { carName = Name; }
void BillDetail::SetSaleNum(int value) { saleNum = value; }
void BillDetail::SetPrice(int value) { unitPrice = value; }
string BillDetail::GetID() { return carID; }
string BillDetail::GetName() { return carName; }
int BillDetail::GetSaleNum() { return saleNum; }
int BillDetail::GetPrice() { return unitPrice; }
void Bill::SetID(string ID) { billID = ID; }
void Bill::SetDate(int day, int month, int year) { billDate.setDate(day, month, year); }
void Bill::SetPromtion(int value) { Promotion = value; }
void Bill::AddDetail(BillDetail temp) { detail.push_back(temp); }


void LoadBillFromFile(string path, vector<Bill>& bills)
{
	int num;
	ifstream fin1;
	fin1.open(path.c_str());
	bool check = fin1.is_open();
	fin1 >> num;
	fin1.close();

	for (int i = 0; i < num; i++)
	{
		string fileName = "BILLNO";
		char tempi[30];
		_itoa_s(i, tempi, 10);
		fileName = fileName + tempi;
		fileName = fileName + ".txt";
		ifstream fin2;
		fin2.open(fileName.c_str());
		Bill tempBill;
		getline(fin2, tempBill.billID, '\n');
		int day;
		int month;
		int year;
		fin2 >> day;
		fin2.ignore();
		fin2 >> month;
		fin2.ignore();
		fin2 >> year;
		fin2.ignore();
		tempBill.billDate.setDate(day, month, year);
		fin2 >> tempBill.Promotion;
		fin2.ignore();
		while (fin2.eof() == false)
		{

			BillDetail tempDetail;
			string tempStr;
			int tempInt;
			getline(fin2, tempStr, ',');
			if (tempStr == "\n" )
				break;
			tempDetail.SetID(tempStr);
			getline(fin2, tempStr, ',');
			tempDetail.SetName(tempStr);
			fin2 >> tempInt;
			fin2.ignore();
			tempDetail.SetPrice(tempInt);
			fin2 >> tempInt;
			fin2.ignore();
			tempDetail.SetSaleNum(tempInt);
			tempBill.detail.push_back(tempDetail);
			
		}
		bills.push_back(tempBill);

	}
	
}

void SaveBillToFile(string path,vector<Bill> bills)
{
	ofstream fout;
	fout.open(path.c_str());
	fout << bills.size();
	fout.close();
	ofstream fout2;

	for (int i = 0; i < bills.size(); i++)
	{
		string fileName = "BILLNO";
		char tempi[30];
		_itoa_s(i, tempi, 10);
		fileName = fileName + tempi;
		fileName = fileName + ".txt";
		fout2.open(fileName.c_str());
		fout2 << bills[i].billID << endl;
		fout2 << bills[i].billDate.getDay() << "," << bills[i].billDate.getMonth() << "," << bills[i].billDate.getYear() << endl;
		fout2 << bills[i].Promotion;
		for (int k = 0; k < bills[i].detail.size(); k++)
		{
			fout2 << endl;
			fout2 << bills[i].detail[k].GetID() << "," << bills[i].detail[k].GetName()<< "," << bills[i].detail[k].GetPrice();
			fout2 << "," << bills[i].detail[k].GetSaleNum();
		}
		fout2.close();
	}
}

void Bill::ShowBillWithID(string ID, vector<Bill> bills)
{
	int rs = 0;
	for (int i = 0; i < bills.size(); i++)
	{
		if (bills[i].billID == ID)
		{
			cout << bills[i].billID << endl;
			cout << bills[i].billDate.getDay() << "/" << bills[i].billDate.getMonth() << "/" << bills[i].billDate.getYear() << endl;
			for (int k = 0; k < bills[i].detail.size(); k++)
			{
				cout << bills[i].detail[k].GetID();
				cout << "     ";
				cout << bills[i].detail[k].GetName();
				cout << "     ";
				cout << bills[i].detail[k].GetSaleNum();
				cout << "     ";
				cout << bills[i].detail[k].GetPrice() << endl;
				rs = rs + bills[i].detail[k].GetSaleNum() *bills[i].detail[k].GetPrice();
			}
			cout << "Promotion: " << bills[i].Promotion << endl;
			rs -= bills[i].Promotion;
			cout << "Total: " << rs << endl;
		}
	}
}

Date Bill::getBillDate() {
	return billDate;
}

void BillDetail::displayBillDetail(int x, int y) {
	gotoxy(x, y); cout << carID;
	gotoxy(x += 16, y); cout << carName;
	gotoxy(x += 39, y); cout << unitPrice;
	gotoxy(x += 19, y); cout << saleNum;
}

int BillDetail::totalPrice() {
	return unitPrice * saleNum;
}

int Bill::totalPrice() {
	int total = 0;
	for (int i = 0; i < (int)detail.size(); i++) {
		total += detail[i].totalPrice();
	}
	return total - Promotion;
}

void Bill::displayBill(int x, int y) {
	gotoxy(x, y); cout << "*Bill ID: " << billID;
	gotoxy(x, ++y); cout << "*Date: "; billDate.display();
	gotoxy(x, ++y); cout << "Car ID";
	gotoxy(x + 16, y); cout << "Name";
	gotoxy(x + 55, y); cout << "Unit price";
	gotoxy(x + 74, y); cout << "Quantity";
	for (int i = 0; i < (int)detail.size(); i++)
		detail[i].displayBillDetail(x, ++y);
	gotoxy(x, ++y); cout << "*Promotion: " << Promotion << "$";
	gotoxy(x, ++y); cout << "*Total: " << totalPrice() << "$";
}

int BillDetail::totalFixedPrice(vector <Car> Stock) {
	int price = -1;
	for (int i = 0; price==-1; i++)
		if (carID == Stock[i].getID())
			price = Stock[i].getFixedPrice();
	return price * saleNum;
}

int Bill::totalFixedPrice(vector <Car> Stock) {
	int total = 0;
	for (int i = 0; i < (int)detail.size(); i++)
		total += detail[i].totalFixedPrice(Stock);
	return total;
}

void reportTotalReceipts(vector<Bill> bill, vector<Car> Stock) {
	system("cls");
	ofstream fout;
	fout.open("REPORT - TOTAL RECEIPTS.csv");
	int x = WIDTH_OFFSET - 80 / 2, y = 2;
	int year, month;
	TextColor(14);
	gotoxy(WIDTH_OFFSET - 22 / 2, y); cout << "REPORT: TOTAL RECEIPTS"; fout << "REPORT: TOTAL RECEIPTS" << endl;
	TextColor(9);
	do {
		gotoxy(x, y + 2); cout << "Year (0: show all):                                                  ";
		gotoxy(x + 20, y + 2); cin >> year;
	} while (year < 1950 && year != 0);
	do {
		gotoxy(x, y + 4); cout << "Month (0: show all):                                                  ";
		gotoxy(x + 21, y + 4); cin >> month;
	} while (month < 0 || month > 12);
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
	TextColor(7);
	gotoxy(x, y += 6); cout << "__________________________________________________________________________________";
	int totalPrice_ = 0, totalFixedPrice_ = 0;
	for (int i = 0; i < (int)bill.size(); i++)
		if ((year == bill[i].getBillDate().getYear() || year == 0) && (month == bill[i].getBillDate().getMonth() || month == 0)) {
			totalFixedPrice_ += bill[i].totalFixedPrice(Stock);
			totalPrice_ += bill[i].totalPrice();
		}
	TextColor(14);
	gotoxy(WIDTH_OFFSET - 11 / 2, y += 2); cout << "[ General ]"; fout << "[ General ]" << endl;
	TextColor(10);
	gotoxy(x, ++y); cout << "*Total sales: " << totalPrice_ << "$";
	fout << "*Total sales: " << totalPrice_ << "$" << endl;
	gotoxy(x, y += 2); cout << "*Total profit: " << totalPrice_ - totalFixedPrice_ << "$";
	fout << "*Total profit: " << totalPrice_ - totalFixedPrice_ << "$" << endl;
	TextColor(7);
	gotoxy(x, y += 2); cout << "__________________________________________________________________________________";

	TextColor(14);
	gotoxy(WIDTH_OFFSET - 10 / 2, y += 2); cout << "[ Detail ]"; fout << "[ Detail ]" << endl;
	for (int i = 0; i < (int)bill.size(); i++)
		if ((year == bill[i].getBillDate().getYear() || year == 0) && (month == bill[i].getBillDate().getMonth() || month == 0)) {
			bill[i].displayBill(x, y += 2);
			bill[i].saveBill(fout);
			y += 10;
		}
	noticeDone(x, y);
	fout.close();
}

void Bill::displayOneBill(int x, int y)
{
	system("cls");
	TextColor(9);
	gotoxy(88, y); cout << "*Bill ID: " << billID;
	gotoxy(88, ++y); cout << "*Date: "; billDate.display();
	TextColor(14);
	gotoxy(x, y + 3); cout << "Car ID";
	gotoxy(x + 16, y + 3); cout << "Name";
	gotoxy(x + 55, y + 3); cout << "Unit price";
	gotoxy(x + 74, y + 3); cout << "Quantity";
	for (int i = 0; i < (int)detail.size(); i++)
		detail[i].displayBillDetail(x, ++y + 3);
	gotoxy(x, ++y + 4); cout << "*Promotion: " << Promotion << "$";
	gotoxy(x, ++y + 4); cout << "*Total: " << totalPrice() << "$";
	TextColor(7);
}

void Bill::saveBill(ofstream &fout) {
	fout << "*Bill ID: " << billID << endl;
	fout << "*Date: " << billDate.getDay() << "/" << billDate.getMonth() << "/" << billDate.getYear() << endl;
	fout << "Car ID,Name,Unit price,Quantity" << endl;
	for (int i = 0; i < (int)detail.size(); i++)
		detail[i].saveBillDetail(fout);
	fout << "*Promotion: " << Promotion << "$" << endl;
	fout << "*Total: " << totalPrice() << "$" << endl;
}

void BillDetail::saveBillDetail(ofstream &fout) {
	fout << carID << "," << carName << "," << unitPrice << "," << saleNum << endl;
}