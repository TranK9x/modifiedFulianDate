#include<iostream>
#include<iomanip>

void get_date(int& month, int& day, int& year);
void compute_mjd(int month, int day, int year, int& mjd);
void compute_dow(int month, int day, int year, int& dow);
void compute_days(int mjd1, int mjd2, int& days_between);
void display_date(int month, int day, int year);
void display_results(int today_month, int today_day, int today_year,
	int today_mjd, int birthday_month, int birthday_day,
	int birthday_year, int birthday_mjd,
	int birthday_dow, int days_between);

int main() {
	int today_month,
		today_day,
		today_year,
		today_mjd;
	int birthday_month,
		birthday_day,
		birthday_year,
		birthday_mjd;
	int birthday_dow,
		days_between;
	std::cout << "For today's date..." << std::endl;
	get_date(today_month, today_day, today_year);
	std::cout << "For your next birthday..." << std::endl;
	get_date(birthday_month, birthday_day, birthday_year);
	compute_mjd(today_month, today_day, today_year, today_mjd);
	compute_mjd(birthday_month, birthday_day, birthday_year, birthday_mjd);
	compute_dow(birthday_month, birthday_day, birthday_year, birthday_dow);
	compute_days(today_mjd,birthday_mjd,days_between);
	display_results(today_month, today_day, today_year, today_mjd, birthday_month, birthday_day, birthday_year, birthday_mjd, birthday_dow, days_between);


	/*
	Declare today_month, today_day, today_year, today_mjd as Integer
Declare birthday_month, birthday_day, birthday_year, birthday_mjd as Integer
Declare birthday_dow, days_between as Integer
Write "For today's date..."
Call get_date( today_month, today_day, today_year )
Write "For your next birthday..."
Call get_date( birthday_month, birthday_day, birthday_year )
Call compute_mjd( today_month, today_day, today_year, today_mjd )
Call compute_mjd( birthday_month, birthday_day, birthday_year, birthday_mjd )
Call compute_dow( birthday_month, birthday_day, birthday_year, birthday_dow )
Call compute_days( today_mjd, birthday_mjd, days_between )
Call display_results( today_month, today_day, today_year, today_mjd, birthday_month, birthday_day, birthday_year, birthday_mjd, birthday_dow, days_between)*/

}

//
// This module will get date from the user..
// 
void get_date(int &month, int &day,int &year) {
	std::cout << "Enter a month number (Jan=1, Feb=2,etc.): ";
	std::cin >> month;
	std::cout << "Enter a day number (1...31) " << std::setw(14) << " : ";
	std::cin >> day;
	std::cout << "Enter a year using four digits " << std::setw(11) << " : ";
	std::cin >> year;
	std::cout << std::endl;
	
}

//
//This module caculate n1...n4 and mjd number
//
void compute_mjd( int month, int day, int year, int &mjd)
{
	int n1, n2, n3, n4;
	n1 = (14 - month) / 12;
	n2 = (month - 3) + (12 * n1);
	n3 = year + 4800 - n1;
	n4 = (n3 / 4) - (n3 / 100) + (n3 / 400);
	mjd = day + (((153 * n2) + 2) / 5) + (365 * n3) + n4 - 2432046;
}
//
// This module computes day of week(dow)
//
void compute_dow(int month, int day, int year, int &dow) {
	int mjd;
	compute_mjd(month, day, year, mjd);
	dow = (mjd + 3) % 7;
}

//
// This module computes the number of days between two given MJDs
//
void compute_days(int mjd1, int mjd2, int& days_between) {
	std::cout << "mjd 1: "<<mjd1 << std::endl;
	std::cout << "mjd 2: " << mjd2 << std::endl;

	days_between = mjd2 - mjd1;
}

//
// This module displays date
//
void display_date(int month, int day, int year) {
	std::cout << month << "/" << day << "/" << year;
}

void display_results(int today_month, int today_day, int today_year, 
					int today_mjd, int birthday_month, int birthday_day,
					int birthday_year,int birthday_mjd,
					int birthday_dow,int days_between) {
	std::cout << "The MJD for ";
	display_date(today_month, today_day, today_year);
	std::cout << "is "<< today_mjd<<std::endl;
	std::cout << "The MJD for your next birthday on ";
	display_date(birthday_month, birthday_day, birthday_year);
	std::cout << " is "<< birthday_mjd <<std::endl;
	std::cout << "The DOW on your next birthday will be " << birthday_dow << " (0=Sun, 1=Mon, etc.)" << std::endl;
	std::cout << "Only " << days_between << " day(s) until your next birthday!";
}