#include "BillRepair.h"
#include "Car.h"

void BillRepair::SetID(string id) { ID = id; }
void BillRepair::SetName(string Name) { carName = Name; }
void BillRepair::SetError(string errorName) { error = errorName; }
void BillRepair::SetType(int value) { type = value; }
void BillRepair::SetPrice(int value) { price = value; }
void BillRepair::SetDate(int day, int month, int year) { billDate.setDate(day, month, year); }

string BillRepair::GetID() { return ID; }
string BillRepair::GetName() { return carName; }
string BillRepair::GetError() { return error; }
int BillRepair::GetType() { return type; }
int BillRepair::GetPrice() { return price; }
Date BillRepair::GetBillDate() { return billDate; }

//void BillRepair::SetID(string ID) { billID = ID; }
//void BillRepair::SetDate(int day, int month, int year) { billDate.setDate(day, month, year); }
//void BillRepair::AddDetail(BillRepairDetail temp) { detail.push_back(temp); }


void LoadReBillFromFile(string path, vector<BillRepair>& bills)
{
	ifstream fin;
	fin.open(path);
	if (!fin.is_open())
	{
		cout << "Can not open file";
		return;
	}

	BillRepair rebill;

	int i = 0;
	while (!fin.eof()) {
		getline(fin, rebill.ID, ',');
		getline(fin, rebill.carName, ',');
		getline(fin, rebill.error, ',');
		fin >> rebill.type;
		fin.ignore(1);
		fin >> rebill.price;
		int d, m, y;
		fin.ignore(1);
		fin >> d;
		fin.ignore(1);
		fin >> m;
		fin.ignore(1);
		fin >> y;
		rebill.SetDate(d, m, y);

		bills.push_back(rebill);
		fin.ignore(1);
	}

	fin.close();
}

void SaveReBillToFile(string path, vector<BillRepair> bills)
{
	ofstream fout;
	fout.open(path);
	if (!fout.is_open()) {
		cout << "Can not open file";
		return;
	}

	for (int i = 0; i < bills.size(); i++) {
		fout << bills[i].ID << ",";
		fout << bills[i].carName << ",";
		fout << bills[i].error << ",";
		fout << bills[i].type << ",";
		fout << bills[i].price << ",";
		fout << bills[i].billDate.getDay() << ",";
		fout << bills[i].billDate.getMonth() << ",";
		fout << bills[i].billDate.getYear();
		if (i != bills.size() - 1)
			fout << "\n";
	}

	fout.close();
}

void BillRepair::displayBillDetail(int x, int y) {
	gotoxy(x, y); cout << ID;
	gotoxy(x += 16, y); cout << carName;
	gotoxy(x += 39, y); cout << error;
	gotoxy(x += 19, y); cout << price;
	gotoxy(x += 15, y); billDate.display();
}