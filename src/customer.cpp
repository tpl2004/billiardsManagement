#include "../include/customer.h"
#include "../include/myLib.h"
#include "../include/douList.h"
#include <iostream>

Customer::Customer() {
    this->id = "";
    this->fullName = "";
    this->age = -1;
}

Customer::Customer(std::string id, std::string fullName, int age) {
    this->id = checkID(id) ? id : "";
    this->fullName = checkFullName(fullName) ? standardize(fullName) : "";
    this->age = age >= 0 ? age : -1;
}

void Customer::setID(std::string id) {
    if(checkID(id)) this->id = id;
}

std::string Customer::getID() {
    return this->id;
}

void Customer::setFullName(std::string fullName) {
    if(checkFullName(fullName)) this->fullName = standardize(fullName);
}

std::string Customer::getFullName() {
    return this->fullName;
}

void Customer::setAge(int age) {
    if(age >= 0) this->age = age;
}

int Customer::getAge() {
    return this->age;
}

void Customer::input() {
    std::cout << "\tNhap vao ID khach hang: ";
    std::string id;
    std::cin >> id;
    if(checkID(id)) this->id = id;\
    std::cin.ignore();
    std::cout << "\tNhap vao ho ten khach hang: ";
    std::string fullName;
    getline(std::cin, fullName);
    if(checkFullName(fullName)) this->fullName = standardize(fullName);
    std::cout << "\tNhap vao tuoi khach hang: ";
    int age;
    std::cin >> age;
    if(age >= 0) this->age = age;
}

void Customer::show() {
    std::cout << "\tID khach hang: " << this->id << "\n";
    std::cout << "\tHo ten khach hang: " << this->fullName << "\n";
    std::cout << "\tTuoi khach hang: " << this->age << "\n";
}

float Customer::totalOfHourPlay(const douList<Bill> &L, const std::string &id) {
    float res = 0;
    node<Bill> *p = L.head;
    while(p != NULL) {
        if(p->data.getID() == id) res += p->data.getNumberOfHour();
    }
    return res;
}