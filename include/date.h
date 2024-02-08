#pragma once
#include <string>

struct Date {
	int day;
	int month;
	int year;

	/*Lay thoi gian o dang chuoi*/
	std::string getDate();

	bool operator >(Date &other);
};

/*Kiem tra tinh hop le cua ngay gio va tra ve ngay gio hop ly*/
Date checkDate(std::string date);

/*Doi thoi gian ra thang*/
float numberOfMonths(int year, int month, int day);
