#include <string>
#include <iostream>
#include <cctype>
#include <algorithm>
#include "../include/staff.h"
#include "../include/myLib.h"
#include "../include/date.h"

Staff::Staff() {
	this->id = "";
	this->fullName = "";
	this->age = -1;
	this->sex = 1;
	this->address = "";
	this->startDate.day = 0;
	this->startDate.month = 0;
	this->startDate.year = 0;
	this->hoursOfWork = 0;
}

Staff::Staff(std::string id, std::string fullName, int age, std::string sex, std::string address, std::string startDate, int hoursOfWork) {
	this->id = checkID(id) == 1 ? id : "";
	this->fullName = checkFullName(fullName) == 1 ? standardize(fullName) : "";
	this->age = age >= 0 ? age : -1;
	std::transform(sex.begin(), sex.end(), sex.begin(), ::tolower);
	this->sex = sex == "nam" ? 0 : 1;
	this->address = checkFullName(address) == 1 ? standardize(address) : "";
	this->startDate = checkDate(startDate);
	this->hoursOfWork = hoursOfWork < 0 ? 0 : hoursOfWork;
}

void Staff::setID(std::string id) {
	if(checkID(id) == 1) this->id = id;
}

std::string Staff::getID() {
	return this->id;
}

void Staff::setFullName(std::string fullName) {
	if(checkFullName(fullName) == 1) this->fullName = standardize(fullName);
}

std::string Staff::getFullName() {
	return this->fullName;
}

void Staff::setAge(int age) {
	if(age >= 0) this->age = age;
}

int Staff::getAge() {
	return this->age;
}

void Staff::setSex(std::string sex) {
	std::transform(sex.begin(), sex.end(), sex.begin(), ::tolower);
	if(sex == "nam") this->sex = 0;
	else if(sex == "nu") this->sex = 1;
}

bool Staff::getSex() {
	return this->sex;
}

void Staff::setAddress(std::string address) {
	if(checkFullName(address) == 1) this->address = standardize(address);
}

std::string Staff::getAddress() {
	return this->address;
}

void Staff::setStartDate(std::string startDate) {
	Date tmp = checkDate(startDate);
	if(tmp.day != 0) this->startDate = tmp;
}

Date Staff::getStartDate() {
	return this->startDate;
}

void Staff::setHoursOfWork(int hoursOfWork) {
	if(hoursOfWork >= 0) this->hoursOfWork = hoursOfWork;
}

int Staff::getHoursOfWork() {
	return this->hoursOfWork;
}

void Staff::input() {
	//std::cin.ignore();
	std::string id;
	std::cout << "\tNhap vao ma nhan vien: ";
	getline(std::cin, id);
	if(checkID(id) == 1) this->id = id;
	std::string fullName;
	std::cout << "\tNhap vao ho ten: ";
	getline(std::cin, fullName);
	if(checkFullName(fullName) == 1) this->fullName = standardize(fullName);
	int age;
	std::cout << "\tNhap vao tuoi: ";
	std::cin >> age;
	if(age >= 0) this->age = age;
	std::cin.ignore();
	std::string sex;
	std::cout << "\tNhap vao gioi tinh: ";
	getline(std::cin, sex);
	std::transform(sex.begin(), sex.end(), sex.begin(), ::tolower);
	if(sex == "nam") this->sex = 0;
	else if(sex == "nu") this->sex = 1;
	std::string address;
	std::cout << "\tNhap vao que quan: ";
	getline(std::cin, address);
	if(checkFullName(address) == 1) this->address = standardize(address);	
	std::string startDate;
	std::cout << "\tNhap vao ngay bat dau lam viec (dd/MM/yyyy): ";
	getline(std::cin, startDate);
	this->setStartDate(startDate);
	int hoursOfWork;
	std::cout << "\tNhap vao so gio lam viec: ";
	std::cin >> hoursOfWork;
	if(hoursOfWork >= 0) this->hoursOfWork = hoursOfWork;
}

void Staff::show() {
	std::cout << "\tMa nhan vien: " << this->id << "\n";
	std::cout << "\tHo ten: " << this->fullName << "\n";
	std::cout << "\tTuoi: " << this->age << "\n";
	std::cout << "\tGioi tinh: ";
	this->sex == 1 ? std::cout << "nu\n" : std::cout << "nam\n";
	std::cout << "\tQue quan: " << this->address << "\n";
	std::cout << "\tNgay bat dau lam viec: " << this->getStartDate().getDate() << "\n";
	std::cout << "\tSo gio lam viec: " << this->hoursOfWork << "\n";
}
