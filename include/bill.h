#pragma once

#include "../include/date.h"
#include "../include/douList.h"
#include <string>
#include "douList.h"

class Bill {
    public:
        static double paymentOfHour;

        Bill();
        Bill(std::string id, std::string idOfPoolTable, std::string idOfCustomer, float numberOfHour, std::string dateOfBill);

        void setID(std::string id);
        std::string getID();

        void setIDOfPoolTable(std::string idOfPoolTable);
        std::string getIDOfPoolTable();

        void setIDOfCustomer(std::string idOfCustomer);
        std::string getIDOfCustomer();

        void setNumberOfHour(float numberOfHour);
        float getNumberOfHour();

        void setDateOfBill(std::string dateOfBill);
        Date getDateOfBill();

        void input();
        void show();

        /*Tinh % giam gia*/
        float discount(const douList<Bill> &L);

        /*Tinh tong tien phai tra*/
        double totalPayment(const douList<Bill> &L);
    private:
        std::string id;
        std::string idOfPoolTable;
        std::string idOfCustomer;
        float numberOfHour;
        Date dateOfBill;
};
