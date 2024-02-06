#include "../include/poolTable.h"
#include "../include/myLib.h"
#include <iostream>

PoolTable::PoolTable() {
    this->color = "";
    this->length = 0;
    this->width = 0;
}

PoolTable::PoolTable(std::string id, std::string manufacturer, double price, std::string dateOfManufacture, std::string color, std::string type, float length, float width)
: Infrastructure(id, manufacturer, price, dateOfManufacture, type) {
    this->color = checkFullName(color) ? standardize(color) : "";
    this->length = length > 0 ? length : 0;
    this->width = width > 0 ? width : 0;
}

void PoolTable::setColor(std::string color) {
    if(checkFullName(color)) this->color = standardize(color);
}

std::string PoolTable::getColor() {
    return this->color;
}

void PoolTable::setLength(float length) {
    if(length > 0) this->length = length;
}

float PoolTable::getLength() {
    return this->length;
}

void PoolTable::setWidth(float width) {
    if(width > 0) this->width = width;
}

float PoolTable::getWidth() {
    return this->width;
}

void PoolTable::input() {
    Infrastructure::input();
    std::cout << "\tNhap vao mau sac: ";
    std::string color;
    getline(std::cin, color);
    if(checkFullName(color)) this->color = color;
    std::cout << "\tNhap vao chieu dai: ";
    float length;
    std::cin >> length;
    if(length > 0) this->length = length;
    std::cout << "\tNhap vao chieu rong: ";
    float width;
    std::cin >> width;
    if(width > 0) this->width = width;
}

void PoolTable::show() {
    Infrastructure::show();
    std::cout << "\tMau sac: " << this->color << "\n";
    std::cout << "\tChieu dai: " << this->length << "\n";
    std::cout << "\tChieu rong: " << this->width << "\n";
}

bool PoolTable::status() {
    return this->numberOfMonthsUsed() <= 48;
}