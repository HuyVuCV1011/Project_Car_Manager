#pragma once
#include"Setting.h"

class Car;
class BillDetail
{
private:
	string carID;
	string carName;
	int saleNum;
	int unitPrice;
public:
	void SetID(string ID);
	void SetName(string Name);
	void SetSaleNum(int value);
	void SetPrice(int value);
	string GetID();
	string GetName();
	int GetSaleNum();
	int GetPrice();

	void displayBillDetail(int x, int y);
	int totalPrice();
	int totalFixedPrice(vector <Car> Stock);
	void saveBillDetail(ofstream &fout);
};

class Bill {
private:
	string billID;
	vector<BillDetail> detail;
	Date billDate;
	int Promotion;
public:
	string GetBillID() { return billID; }
	int getPromotion() { return Promotion; }
public:
	void SetID(string ID);
	void SetDate(int day, int month, int year);
	void SetPromtion(int value);
	void AddDetail(BillDetail temp);
	friend void LoadBillFromFile(string path,vector<Bill> &bills);
	friend void SaveBillToFile(string path,vector<Bill> bills);
	void ShowBillWithID(string ID, vector<Bill> bills);

	Date getBillDate();
	void displayBill(int x, int y);
	void displayOneBill(int x, int y);
	int totalPrice();
	int totalFixedPrice(vector <Car> Stock);
	void saveBill(ofstream &fout);
};

void reportTotalReceipts(vector<Bill> bill, vector<Car> Stock);

