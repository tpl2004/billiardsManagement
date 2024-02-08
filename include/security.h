#pragma once
#include "staff.h"

class Security : public Staff {
	public:
		static double salaryPerHour;
		Security();
		Security(std::string id, std::string fullName, int age, std::string sex, std::string address, std::string startDate, int hoursOfWork, float high, float weight);
		void setHigh(float high);
		float getHigh();
		void setWeight(float weight);
		float getWeight();
		void input();
		void show();
		double getSalary();
		bool evaluate();
	private:
		float high;
		float weight;
};
