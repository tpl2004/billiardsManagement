#pragma once
#include "staff.h"

class Server : public Staff {
	public:
		static double salaryPerHour;
		Server();
		Server(std::string id, std::string fullName, int age, std::string sex, std::string address, std::string startDate, int hoursOfWork, int serviceArea);
		void setServiceArea(int serviceArea);
		int getServiceArea();
		void input();
		void show();
		double getSalary();
	private:
		int serviceArea;
};
