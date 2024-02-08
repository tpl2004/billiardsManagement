#pragma once
#include "date.h"
#include <string>

class Infrastructure {
    public:
        Infrastructure();
        Infrastructure(std::string id, std::string manufacturer, double price, std::string dateOfManufacture, std::string type);

        void setID(std::string id);
        std::string getID();

        void setManufacturer(std::string manufacturer);
        std::string getManufacturer();
        
        void setPrice(double price);
        double getPrice();

        void setDateOfManufacture(std::string dateOfManufacture);
        Date getDateOfManufacture();

        void setType(std::string type);
        std::string getType();

        virtual void input();
        virtual void show();

        /*Tinh so thang su dung*/
        int numberOfMonthsUsed();

        /*Trang thai cua doi tuong*/
        virtual bool status() = 0;
    private:
        std::string id;
        std::string manufacturer;
        double price;
        Date dateOfManufacture;
        std::string type;
};