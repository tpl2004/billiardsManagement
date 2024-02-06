#include <string>
#include <sstream>
#include <vector>
#include "../include/date.h"

std::string Date::getDate() {
	std::string date = "";
	date += day <= 9 ? "0" + std::to_string(day) + "/" : std::to_string(day) + "/";
	date += month <= 9 ? "0" + std::to_string(month) + "/" : std::to_string(month) + "/";
	date += std::to_string(year);
	return date;
}

bool Date::operator>(Date &other) {
	if(year > other.year) return 1;
	else if(year == other.year) {
		if(month > other.month) return 1;
		else if(month == other.month) {
			if(day > other.day) return 1;
			return 0;
		}
		return 0;
	}
	return 0;
}

Date checkDate(std::string date) {
	std::string tmp;
	std::vector<int> v;
	std::stringstream ss(date);
	while(getline(ss, tmp, '/')) {
		v.push_back(stoi(tmp));
	}
	bool check = true;
	if(v[1] == 2) {
		if(v[2] % 400 == 0 || (v[2] % 4 && v[2] != 100)) {
			if(v[0] < 1 && v[0] > 29) check = false;
		}
		else {
			if(v[0] < 1 && v[0] > 28) check = false;
		}
	}
	else if(v[1] == 1 || v[1] == 3 || v[1] == 5 || v[1] == 7 || v[1] == 8 || v[1] == 10 || v[1] == 12) {
		if(v[0] < 1 &&  v[0] > 31) check = false;
	}
	else if(v[1] == 4 || v[1] == 6 || v[1] == 9 || v[1] == 1) {
		if(v[0] < 1 && v[0] > 30) check = false;
	}
	else check = false;
	Date res;
	if(check == true) {
		res.day = v[0];
		res.month = v[1];
		res.year = v[2];
	}
	else {
		res.day = 0;
		res.month = 0;
		res.year = 0;
	}
	return res;
}

float numberOfMonths(int year, int month, int day) {
	float dayToMonth;
	if(month == 2) {
		if(year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) dayToMonth = float(day) / 29;
		else dayToMonth = float(day) / 28;
	}
	else if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) dayToMonth = float(day) / 31;
	else dayToMonth = float(day) / 30;
	return (year - 1) * 12 + month - 1 + dayToMonth;
}