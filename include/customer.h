#pragma once

#include "../include/bill.h"
#include <string>

class Customer {
    public:
        Customer();
        Customer(std::string id, std::string fullName, int age);

        void setID(std::string id);
        std::string getID();

        void setFullName(std::string fullName);
        std::string getFullName();

        void setAge(int age);
        int getAge();

        void input();
        void show();
        
        /*tinh tong so gio choi*/
        static float totalOfHourPlay(const douList<Bill> &L, const std::string &id);
    private:
        std::string id;
        std::string fullName;
        int age;
};