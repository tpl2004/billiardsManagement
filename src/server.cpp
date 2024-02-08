#include <iostream>
#include "../include/server.h"

Server::Server() {
	this->serviceArea = -1;
}

Server::Server(std::string id, std::string fullName, int age, std::string sex, std::string address, std::string startDate, int hoursOfWork, int serviceArea) : Staff(id, fullName, age, sex, address, startDate, hoursOfWork) {
	this->serviceArea = serviceArea >= 0 ? serviceArea : -1;
}

void Server::setServiceArea(int serviceArea) {
	if(serviceArea >= 0) this->serviceArea = serviceArea;
}

int Server::getServiceArea() {
	return this->serviceArea;
}

void Server::input() {
	Staff::input();
	int serviceArea;
	std::cout << "\tNhap vao khu vuc phuc vu: ";
	std::cin >> serviceArea;	
	if(serviceArea >= 0) this->serviceArea = serviceArea;
}

void Server::show() {
	Staff::show();
	std::cout << "\tKhu vuc phu vu: " << this->serviceArea << "\n";
	std::cout << "\tLuong: " << this->getSalary() << "\n";
}

double Server::getSalary() {
	return salaryPerHour * this->getHoursOfWork();
}
