#pragma once

#include "../include/infrastructure.h"
#include <string>

class Cue : public Infrastructure {
    public:
        Cue();
        Cue(std::string id, std::string manufacturer, double price, std::string dateOFManufacture, std::string type, std::string material);

        void setMaterial(std::string material);
        std::string getMaterial();

        void input();
        void show();

        bool status();
    private:
        std::string material;
};