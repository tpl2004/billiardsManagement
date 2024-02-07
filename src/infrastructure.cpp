#include "../include/infrastructure.h"
#include "../include/myLib.h"
#include <iostream>
#include <ctime>

Infrastructure::Infrastructure() {
    this->id = "";
    this->manufacturer = "";
    this->price = -1;
    this->dateOfManufacture.day = 0;
    this->dateOfManufacture.month = 0;
    this->dateOfManufacture.year = 0;
    this->type = "";
}

Infrastructure::Infrastructure(std::string id, std::string manufacturer, double price, std::string dateOfManufacture, std::string type) {
    this->id = checkID(id) ? id : "";
    this->manufacturer = checkFullName(manufacturer) ? standardize(manufacturer) : "";
    this->price = price >= 0 ? price : -1;
    this->dateOfManufacture = checkDate(dateOfManufacture);
    this->type = checkFullName(type) ? standardize(type) : "";
}

void Infrastructure::setID(std::string id) {
    if(checkID(id)) this->id = id;
}

std::string Infrastructure::getID() {
    return this->id;
}

void Infrastructure::setManufacturer(std::string manufacturer) {
    if(checkFullName(manufacturer)) this->manufacturer = standardize(manufacturer);
}

std::string Infrastructure::getManufacturer() {
    return this->manufacturer;
}

void Infrastructure::setPrice(double price) {
    if(price >= 0) this->price = price;
}

double Infrastructure::getPrice() {
    return this->price;
}

void Infrastructure::setDateOfManufacture(std::string getDateOfManufacture) {
    Date tmp = checkDate(manufacturer);
    if(tmp.day != 0) this->dateOfManufacture = tmp;
}

Date Infrastructure::getDateOfManufacture() {
    return this->dateOfManufacture;
}

void Infrastructure::setType(std::string type) {
    if(checkFullName(type)) this->type = standardize(type);
}

std::string Infrastructure::getType() {
    return this->type;
}

void Infrastructure::input() {
    std::cout << "\tNhap vao ID: ";
    std::string id;
    std::cin >> id;
    if(checkID(id)) this->id = id;
    std::cin.ignore();
    std::cout << "\tNhap vao nha san xuat: ";
    std::string manufacturer;
    getline(std::cin, manufacturer);
    if(checkFullName(manufacturer)) this->manufacturer = standardize(manufacturer);
    std::cout << "\tNhap vao gia: ";
    double price;
    std::cin >> price;
    if(price >= 0) this->price = price;
    std::cout << "\tNhap vao ngay san xuat (dd/MM/yyyy): ";
    std::string dateOfManufacture;
    std::cin >> dateOfManufacture;
    Date tmp = checkDate(dateOfManufacture);
    if(tmp.day != 0) this->dateOfManufacture = tmp;
    std::cin.ignore();
    std::cout << "\tNhap vao loai: ";
    std::string type;
    getline(std::cin, type);
    if(checkFullName(type)) this->type = standardize(type);
}

void Infrastructure::show() {
    std::cout << "\tID: " << this->id << "\n";
    std::cout << "\tNha san xuat: " << this->manufacturer << "\n";
    std::cout << "\tGia: " << this->price << "\n";
    std::cout << "\tNgay san xuat (dd/MM/yyyy): " << this->dateOfManufacture.getDate() << "\n";
    std::cout << "\tLoai: " << this->type << "\n";
}

int Infrastructure::numberOfMonthsUsed() {
    std::time_t now = std::time(0);
    std::tm *currentTime = std::localtime(&now);
    int res = numberOfMonths(currentTime->tm_year + 1900 - 1, currentTime->tm_mon, currentTime->tm_mday) - numberOfMonths(this->dateOfManufacture.year, this->dateOfManufacture.month, this->dateOfManufacture.day);
    delete currentTime;
    return res;
}