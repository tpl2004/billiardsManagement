#include <algorithm>
#include <cctype>
#include <iostream>
#include "../include/manager.h"

Manager::Manager() {
	this->position = 1;
}

Manager::Manager(std::string id, std::string fullName, int age, std::string sex, std::string address, std::string startDate, int hoursOfWork, std::string position) : Staff(id, fullName, age, sex, address, startDate, hoursOfWork) {
	std::transform(position.begin(), position.end(), position.begin(), ::tolower);
	this->position = position == "pho" ? 0 : 1;
}

void Manager::setPosition(std::string position) {
	std::transform(position.begin(), position.end(), position.begin(), ::tolower);
	if(position == "truong") this->position = 1;
	else if(position == "pho") this->position = 0;
}

bool Manager::getPosition() {
	return this->position;
}

void Manager::input() {
	Staff::input();
	std::string position;
	std::cin.ignore();
	std::cout << "\tNhap vao chuc vu (truong/pho): ";
	getline(std::cin, position);
	std::transform(position.begin(), position.end(), position.begin(), ::tolower);
	if(position == "truong") this->position = 1;
	else if(position == "pho") this->position = 0;
}

void Manager::show() {
	Staff::show();
	std::cout << "\tChuc vu: ";
	this->position == 1 ? std::cout << "truong\n" : std::cout << "pho\n";
	std::cout << "\tLuong: " << this->getSalary() << "\n";
}

double Manager::getSalary() {
	return salaryPerHour * this->getHoursOfWork();
}
