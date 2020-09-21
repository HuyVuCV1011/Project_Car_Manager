#pragma once
#include "Car.h"
#include "Bill.h"
#include "BillRepair.h"

void SplashScreen();
void Login(vector<Car>& a, vector<Bill>& bills, vector<BillRepair>& rebills);
void CustomerMenu(vector<Car>& a, vector<Bill>& bills, vector<BillRepair>& rebills, bool& check);
void StaffMenu(vector<Car>& a, vector<Bill>& bills, vector<BillRepair>& rebills, bool check);
void SeeAllCar(vector<Car>& a, vector<Bill>& bills, vector<BillRepair>& rebills, bool& check);
void BuyCar(Car& a, vector<Bill>& bills, bool& check);
void ShoppingCart(vector<Car>& a, vector<Bill>& bills, vector<BillRepair>& rebills, bool& check);
void SellCar(vector<Car>& a);
void DrawTable(int CountL);
void FindIDCar(vector<Car>& a, vector<Bill>& bills, vector<BillRepair>& rebills, bool& check);		//only in staff
void FindNameCar(vector<Car>& a, vector<Bill>& bills, bool& check);
void FindBrandCar(vector<Car>& a, vector<Bill>& bills, bool& check);
void FindSeatCar(vector<Car>& a, vector<Bill>& bills, bool& check);
//vector<string> ErrorFile(const char*);
void RepairCar(vector<Car>& a, vector<Bill>& bills, vector<BillRepair>& rebills, bool& check);
void showOneBill(vector<Car>& a, vector<Bill>& bills, bool& check);
void ImportCar(vector<Car>& a);

void randomGift(vector<Car>& a, vector<Bill>&bills, bool &check);
void FindMoneyCar(vector<Car>& a, vector<Bill>& bills, bool& check);