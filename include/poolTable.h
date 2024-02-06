#pragma once

#include "../include/infrastructure.h"
#include <string>

class PoolTable : public Infrastructure {
    public:
        PoolTable();
        PoolTable(std::string id, std::string manufacturer, double price, std::string dateOfManufacture, std::string type, std::string color, float length, float width);

        void setColor(std::string color);
        std::string getColor();

        void setLength(float length);
        float getLength();

        void setWidth(float width);
        float getWidth();

        void input();
        void show();

        bool status();    
    private:
        std::string color;
        float length;
        float width;
};
