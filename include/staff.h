#pragma once

#include <string>
#include "../include/date.h"

class Staff {
	public:
		Staff();
		Staff(std::string id, std::string fullName, int age, std::string sex, std::string address, std::string startDate, int hoursOfWork);
		void setID(std::string id);
		std::string getID();
		void setFullName(std::string fullName);
		std::string getFullName();
		void setAge(int age);
		int getAge();
		void setSex(std::string sex);
		bool getSex();
		void setAddress(std::string address);
		std::string getAddress();
		void setStartDate(std::string startDate);
		Date getStartDate();
		void setHoursOfWork(int hoursOfWork);
		int getHoursOfWork();
		virtual void input();
		virtual void show();
		virtual double getSalary() = 0;
	private:
		std::string id;
		std::string fullName;
		int age;
		bool sex;
		std::string address;
		Date startDate;
		int hoursOfWork;
};
