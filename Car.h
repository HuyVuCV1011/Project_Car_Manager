#pragma once
#include "Setting.h"
#include "Bill.h"
#include "BillRepair.h"

class Car {
private:
	string ID;
	string Name;
	string Brand;
	int Seat;
	int Quantity; 
	int SoldNum = 0;
	Date ImportDate;
	int fixedPrice;
	int salePrice;

public:
	friend void LoadArrayFromFile(string path, vector<Car> & Stock);
	friend void SaveArrayToFile(string path, vector<Car> Stock);

	string getID();
	int getQuanity() { return Quantity; }
	int getSeat() { return Seat; }
	void setID(string temp);
	Date getImportDate();
	int getSoldNum();
	string GetName();
	int GetPrice();
	int getFixedPrice();

	int inCart = 0;
	bool AddToCart(int num);
	void addToStock(int num);
	void sell();
	void OutPut();
	void inputName(int x, int y);
	void inputBrand(int x, int y);
	void inputSeat(int x, int y);
	void inputQuantity(int x, int y);
	void inputSoldNum(int x, int y);
	void inputImportDate(int x, int y);
	void inputFixedPrice(int x, int y);
	void inputSalePrice(int x, int y);
	void displayFullInfo(int x, int y);
	int repairCar(int status);
	void reportImportProcess(int x, int y);
	void displayInfo(int x, int y);

	void saveBestSeller(ofstream &fout);
	void saveImportProcess(ofstream &fout);
	Date inputRe();
};

void SeePromotion();
int Promotion(vector<Car>& a);
void addCar(vector<Car> &Stock);
string inputID(int x, int y, bool(*check)(string, vector<Car>), vector<Car>Stock);
bool existingID(string temp, vector<Car> Stock);
bool unexistingID(string temp, vector<Car> Stock);
string checkName(string temp);
void updateCar(vector<Car> &Stock);
int findIndexCar(vector <Car> Stock, string temp);
void deleteCar(vector<Car> &Stock);
void repairCar(vector<Car> Stock);
void reportImportProcess(vector<Car> Stock);
void reportBestSeller(vector<Car> Stock);
void addtobill(Car info, vector<Bill> &bills, int SaleNum, bool &check);
void AddToRepairBill(Car info, int type, Date d, vector<BillRepair>& rebills);
vector<string> ErrorFile(const char* File);