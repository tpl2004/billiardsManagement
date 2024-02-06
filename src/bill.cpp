#include "../include/bill.h"
#include "../include/customer.h"
#include "../include/myLib.h"
#include <string>
#include <iostream>

Bill::Bill() {
    this->id = "";
    this->idOfPoolTable = "";
    this->idOfCustomer = "";
    this->numberOfHour = 0;
    this->dateOfBill.day = 0;
    this->dateOfBill.month = 0;
    this->dateOfBill.year = 0;
}

Bill::Bill(std::string id, std::string idOfPoolTable, std::string idOfCustomer, float numberOfHour, std::string dateOfBill) {
    this->id = checkID(id) ? id : "";
    this->idOfPoolTable = checkID(idOfPoolTable) ? idOfPoolTable : "";
    this->idOfCustomer = checkID(idOfCustomer) ? idOfCustomer : "";
    this->numberOfHour = numberOfHour >= 0 ? numberOfHour : 0;
    this->dateOfBill = checkDate(dateOfBill);
}

void Bill::setID(std::string id) {
    if(checkID(id)) this->id = id;
}

std::string Bill::getID() {
    return this->id;
}

void Bill::setIDOfPoolTable(std::string idOfPoolTable) {
    if(checkID(idOfPoolTable)) this->idOfPoolTable = idOfPoolTable;
}

std::string Bill::getIDOfPoolTable() {
    return this->idOfPoolTable;
}

void Bill::setIDOfCustomer(std::string idOfCustomer) {
    if(checkID(idOfCustomer)) this->idOfCustomer = idOfCustomer;
}

std::string Bill::getIDOfCustomer() {
    return this->idOfCustomer;
}

void Bill::setNumberOfHour(float numberOfHour) {
    if(numberOfHour >= 0) this->numberOfHour = numberOfHour;
}

float Bill::getNumberOfHour() {
    return this->numberOfHour;
}

void Bill::setDateOfBill(std::string dateOfBill) {
    Date tmp = checkDate(dateOfBill);
    if(tmp.day != 0) this->dateOfBill = tmp;
}

Date Bill::getDateOfBill() {
    return this->dateOfBill;
}

void Bill::input() {
    std::cout << "\tNhap vao ID bill: ";
    std::string id;
    std::cin >> id;
    if(checkID(id)) this->id = id;
    std::cout << "\tNhap vao ID ban: ";
    std::string idOfPoolTable;
    std::cin >> idOfPoolTable;
    if(checkID(idOfPoolTable)) this->idOfPoolTable = idOfPoolTable;
    std::cout << "\tNhap vao ID khach hang: ";
    std::string idOfCustomer;
    std::cin >> idOfCustomer;
    if(checkID(idOfCustomer)) this->idOfCustomer = idOfCustomer;
    std::cout << "\tNhap vao so gio choi: ";
    float numberOfHour;
    std::cin >> numberOfHour;
    if(numberOfHour >= 0) this->numberOfHour = numberOfHour;
    std::cout << "\tNhap vao so ngay lap bill (dd//MM/yyyy): ";
    std::string dateOfBill;
    Date tmp = checkDate(dateOfBill);
    if(tmp.day != 0) this->dateOfBill = tmp;
}

void Bill::show() {
    std::cout << "\tID bill: " << this->id << "\n";
    std::cout << "\tID ban: " << this->idOfPoolTable << "\n";
    std::cout << "\tID khach hang: " << this->idOfCustomer << "\n";
    std::cout << "\tTong so gio choi: " << this->numberOfHour << "\n";
    std::cout << "\tNgay lap bill (dd/MM/yyyy): " << this->dateOfBill.getDate() << "\n";
}

float Bill::discount(const douList<Bill> &L) {
    float tmp = Customer::totalOfHourPlay(L, this->idOfCustomer);
    if(tmp >= 50 && tmp < 100) return 0.05;
    else if(tmp >= 100) return 0.1;
    else return 0;
}

double Bill::totalPayment(const douList<Bill> &L) {
    return paymentOfHour * this->numberOfHour - this->discount(L) * paymentOfHour * this->numberOfHour;
}