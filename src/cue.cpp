#include "../include/cue.h"
#include "../include/myLib.h"
#include <iostream>

Cue::Cue() {
    this->material = "";
}

Cue::Cue(std::string id, std::string manufacturer, double price, std::string dateOfManufacture, std::string type, std::string material)
: Infrastructure(id, manufacturer, price, dateOfManufacture, type) {
    this->material = checkFullName(material) ? standardize(material) : "";
}

void Cue::setMaterial(std::string material) {
    if(checkFullName(material)) this->material = standardize(material);
}

std::string Cue::getMaterial() {
    return this->material;
}

void Cue::input() {
    Infrastructure::input();
    std::cout << "\tNhap vao chat lieu co: ";
    std::string material;
    getline(std::cin, material);
    if(checkFullName(material)) this->material = standardize(material);
}

void Cue::show() {
    Infrastructure::show();
    std::cout << "\tChat lieu co: " << this->material << "\n";
}

bool Cue::status() {
    return this->numberOfMonthsUsed() <= 24;
}