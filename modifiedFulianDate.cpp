// Program    : Modified Julian Date
// Author	  : Kien Tran Vong
// Date		  : Fall 2024
// Description: This program will promt user to input date, month, and year, 
//				then computes and displays the corresponding MJD.

#include <iostream>
#include <iomanip>


void user_input(int& ngay, int& thang, int& nam);
void caculate_all_num(int& n1, int& n2, int& n3, int& n4,
					  int& mjd, int month, int day, int year);
void print_result(int day, int month, int year, int MJD);

int main() {
	int month,		//
		day,		//input by user
		year,		//
		n1, 
		n2, 
		n3, 
		n4, 
		mjd;		//the corresponding MJD
	user_input(day, month, year);
	caculate_all_num(n1, n2, n3, n4, mjd, month, day, year);
	print_result(day, month, year, mjd);

}

//
//This module will get input from user(day, month, year)
//
void user_input(int &ngay, int &thang, int &nam) {
	std::cout << "Enter a month number (Jan=1, Feb=2,etc.): ";
	std::cin >> thang;
	std::cout << "Enter a day number (1...31) " << std::setw(14)<< " : ";
	std::cin >> ngay;
	std::cout << "Enter a year using four digits " << std::setw(11)<< " : ";
	std::cin >> nam;
}	

//
//This module caculate n1...n4 and mjd number
//
void caculate_all_num(int &n1, int &n2, int &n3, int &n4,
					  int &mjd, int month, int day, int year) 
{
	n1 =(14-month)/12;
	n2 = (month - 3) + (12 * n1);
	n3 = year + 4800 - n1;			
	n4 = (n3 / 4) - (n3 / 100) + (n3 / 400);						
	mjd = day + (((153 * n2) + 2) / 5) + (365 * n3) + n4 - 2432046;
}

//
//This module will print out the result
//
void print_result(int day, int month, int year, int MJD) {
	std::cout << std::endl;
	std::cout << "The MJD for " 
		<< month << "/" 
		<< day << "/" 
		<< year 
		<< " is " 
		<< MJD;
}

