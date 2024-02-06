#include <iostream>
#include "../include/cashier.h"

Cashier::Cashier() {}

Cashier::Cashier(std::string id, std::string fullName, int age, std::string sex, std::string address, std::string startDate, int hoursOfWork) : Staff(id, fullName, age, sex, address, startDate, hoursOfWork) {}

void Cashier::show() {
	Staff::show();
	std::cout << "\tLuong: " << this->getSalary() << "\n";
}

double Cashier::getSalary() {
	return salaryPerHour * this->getHoursOfWork();
}
