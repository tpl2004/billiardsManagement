#pragma once
#include "staff.h"

class Cashier : public Staff {
	public:
		static double salaryPerHour;
		Cashier();
		Cashier(std::string id, std::string fullName, int age, std::string sex, std::string address, std::string startDate, int hoursOfWork);
		void show();
		double getSalary();
};
