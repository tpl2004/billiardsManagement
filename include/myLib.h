#pragma once

#include <string>

/*kiem tra tinh hop le cua id*/
bool checkID(const std::string &id);

/*kiem tra tinh hop le cua ho ten*/
bool checkFullName(const std::string &fullName);

/*chuan hoa*/
std::string standardize(std::string fullName);