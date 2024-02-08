#pragma once
#include "staff.h"

class Manager : public Staff {
	public:
		static double salaryPerHour;
		Manager();
		Manager(std::string id, std::string fullName, int age, std::string sex, std::string address, std::string startDate, int hoursOfWork, std::string position);
		void setPosition(std::string position);
		bool getPosition();
		void input();
		void show();
		double getSalary();
	private:
		bool position;
};
