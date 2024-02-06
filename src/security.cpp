#include <iostream>
#include <string>
#include "../include/security.h"

Security::Security() {
	this->high = 0;
	this->weight = 0;
}

Security::Security(std::string id, std::string fullName, int age, std::string sex, std::string address, std::string startDate, int hoursOfWork, float high, float weight) : Staff(id, fullName, age, sex, address, startDate, hoursOfWork) {
	this->high = high >= 0 ? high : 0;
	this->weight = weight >= 0 ? weight : 0;
}

void Security::setHigh(float high) {
	if(high >= 0) this->high = high;
}

float Security::getHigh() {
	return this->high;
}

void Security::setWeight(float weight) {
	if(weight >= 0) this->weight = weight;
}

float Security::getWeight() {
	return this->weight;
}

void Security::input() {
	Staff::input();
	float high;
	std::cout << "\tNhap vao chieu cao: ";
	std::cin >> high;
	if(high >= 0) this->high = high;
	float weight;
	std::cout << "\tNhap vao can nang: ";
	std::cin >> weight;
	if(weight >= 0) this->weight = weight;	
}

void Security::show() {
	Staff::show();
	std::cout << "\tChieu cao: " << this->high << "\n";
	std::cout << "\tCan nang: " << this->weight << "\n";
	std::cout << "\tDanh gia: ";
	this->evaluate() == 1 ? std::cout << "du tieu chuan\n" : std::cout << "khong du tieu chuan\n";
	std::cout << "\tLuong: " << this->getSalary() << "\n";
}

double Security::getSalary() {
	return salaryPerHour * this->getHoursOfWork();
}

bool Security::evaluate() {
	if(this->high >= 1.7 && this->weight >= 60) return 1;
	return 0;
}
