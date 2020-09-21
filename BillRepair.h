#pragma once
#include "Setting.h"

class Car;

class BillRepair
{
private:
	string ID;
	string carName;
	string error;
	int type;
	int price;
	Date billDate;
public:
	void SetID(string ID);
	void SetName(string Name);
	void SetError(string errorName);
	void SetType(int value);
	void SetPrice(int value);
	void SetDate(int day, int month, int year);

	string GetID();
	string GetName();
	string GetError();
	int GetType();
	int GetPrice();
	Date GetBillDate();

	void displayBillDetail(int x, int y);
	int totalPrice();

	friend void LoadReBillFromFile(string path, vector<BillRepair>& bills);
	friend void SaveReBillToFile(string path, vector<BillRepair> bills);
};

//class BillRepair {
//private:
//	string billID;
//	vector<BillRepairDetail> detail;
//	Date billDate;
//public:
//	string GetBillID() { return billID; }
//
//public:
//
//	void SetID(string ID);
//	void SetDate(int day, int month, int year);
//	void AddDetail(BillRepairDetail temp);
//	
//	void ShowBillWithID(string ID, vector<BillRepair> bills);
//
//	Date getBillDate();
//	void displayBill(int x, int y);
//	void displayOneBill(int x, int y);
//	int totalPrice();
//};
//
